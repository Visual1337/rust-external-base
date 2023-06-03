#include "includes.hpp"

static ID3D11Device* g_pd3dDevice = NULL;
static ID3D11DeviceContext* g_pd3dDeviceContext = NULL;
static IDXGISwapChain* g_pSwapChain = NULL;
static ID3D11RenderTargetView* g_mainRenderTargetView = NULL;

HWND GameWnd = 0, MyWnd = 0;
RECT GameRect = {};

void Update();

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
int Overlay()
{

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), 0, WndProc, 0, 0, nullptr, LoadIcon(nullptr, IDI_APPLICATION), LoadCursor(nullptr, IDC_ARROW), nullptr, nullptr, _("CEF-OSC-WIDGET"), LoadIcon(nullptr, IDI_APPLICATION) };
    RegisterClassEx(&wc);

    GameWnd = FindWindowA(_("UnityWndClass"), _("Rust"));//UnityWndClass, 0x10734, Rust, RustClient.exe (16204): 10560

    ShowWindow(GameWnd, SW_SHOWDEFAULT);

    ZeroMemory(&GameRect, sizeof(GameRect));
    GetWindowRect(GameWnd, &GameRect);

    global.screen_width = GameRect.right - GameRect.left;
    global.screen_height = GameRect.bottom - GameRect.top;

    MyWnd = CreateWindowEx(NULL, _("CEF-OSC-WIDGET"), _("NVIDIA GeForce Overlay DT"), WS_POPUP | WS_VISIBLE, GameRect.left - 4.f, GameRect.top - 4.f, global.screen_width + 4.f, global.screen_height + 4.f, NULL, NULL, wc.hInstance, NULL);
    MARGINS Margin = { GameRect.left - 4.f, GameRect.top - 4.f, global.screen_width + 4.f, global.screen_height + 4.f };
    DwmExtendFrameIntoClientArea(MyWnd, &Margin);

    SetWindowLong(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);

    bool create_device = false;

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = MyWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT create_device_flags = 0;
    D3D_FEATURE_LEVEL feature_level;
    const D3D_FEATURE_LEVEL feature_level_array[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    if (D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, create_device_flags, feature_level_array, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &feature_level, &g_pd3dDeviceContext) != S_OK)
    {
        create_device = false;
    }
    else
    {
        create_device = true;
    }

    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
    pBackBuffer->Release();

    if (!create_device)
    {
        if (g_mainRenderTargetView)
        {
            g_mainRenderTargetView->Release();
            g_mainRenderTargetView = NULL;
        }

        if (g_pSwapChain)
        {
            g_pSwapChain->Release();
            g_pSwapChain = NULL;
        }

        if (g_pd3dDeviceContext)
        {
            g_pd3dDeviceContext->Release();
            g_pd3dDeviceContext = NULL;
        }

        if (g_pd3dDevice)
        {
            g_pd3dDevice->Release();
            g_pd3dDevice = NULL;
        }
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(MyWnd, SW_SHOWDEFAULT);
    UpdateWindow(MyWnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = NULL;
    ImGui::AmplitudeStyle();
    ImGui_ImplWin32_Init(MyWnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    io.Fonts->AddFontFromFileTTF(_("C:\\Windows\\Fonts\\courbd.ttf"), 15.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    ImFontConfig font_cfg;
    font_cfg.FontDataOwnedByAtlas = false;

    global.icons = io.Fonts->AddFontFromMemoryTTF(icon, sizeof(icon), 25.f, &font_cfg);
    global.title = io.Fonts->AddFontFromMemoryTTF(verdana_bold, sizeof(verdana_bold), 35.0f, &font_cfg);
    global.radar = io.Fonts->AddFontFromMemoryTTF(verdana_bold, sizeof(verdana_bold), 10.0f, &font_cfg);
    //global.tiny = io.Fonts->AddFontFromFileTTF(_("C:\\Windows\\Fonts\\courbd.ttf"), 12.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    global.medium = io.Fonts->AddFontFromMemoryTTF(verdana_bold, sizeof(verdana_bold), 20.0f, &font_cfg);
    global.large = io.Fonts->AddFontFromFileTTF(_("C:\\Windows\\Fonts\\courbd.ttf"), 35.0f, NULL, io.Fonts->GetGlyphRangesJapanese());

    IM_ASSERT(font != NULL);

    D3DX11_IMAGE_LOAD_INFO info;
    ID3DX11ThreadPump* pump{ nullptr };
    D3DX11CreateShaderResourceViewFromMemory(g_pd3dDevice, background_image, sizeof(background_image), &info, pump, &global.Image, 0);

    bool done = false;

    std::mutex thread_lock;
    thread_lock.lock();

    auto target_tp = std::chrono::steady_clock::now();

    while (!done)
    {
        if (global.limit_fps)
        {
            auto time_between_frames = std::chrono::microseconds(std::chrono::seconds(1)) / (int)global.target_fps;
            target_tp += time_between_frames;
            std::this_thread::sleep_until(target_tp);
        }


        HWND hwnd_active = GetForegroundWindow();
        if (hwnd_active == GameWnd)
        {
            HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
            SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            global.is_focused_window = true;
        }
        else
        {
            global.is_focused_window = false;
        }
        MSG msg;
        while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (msg.message == WM_QUIT) done = true;
        }

        if (done) break;

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        Update();
        Esp();
        MiscDrawing();
        Menu();

        ImGui::Render();

        const float clear_color_with_alpha[4] = { 0,0,0,0 };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, NULL);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        g_pSwapChain->Present((int)global.vsync, 0);
    }
    thread_lock.unlock();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    if (g_mainRenderTargetView)
    {
        g_mainRenderTargetView->Release();
        g_mainRenderTargetView = NULL;
    }

    if (g_pSwapChain)
    {
        g_pSwapChain->Release();
        g_pSwapChain = NULL;
    }

    if (g_pd3dDeviceContext)
    {
        g_pd3dDeviceContext->Release();
        g_pd3dDeviceContext = NULL;
    }

    if (g_pd3dDevice)
    {
        g_pd3dDevice->Release();
        g_pd3dDevice = NULL;
    }

    DestroyWindow(MyWnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

void Update()
{
    HWND activeWnd = GetForegroundWindow();
    if (activeWnd == MyWnd)
    {
        HWND hwndtest = GetWindow(activeWnd, GW_HWNDPREV);
        SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }

    ZeroMemory(&GameRect, sizeof(GameRect));
    GetWindowRect(GameWnd, &GameRect);

    global.screen_width = GameRect.right - GameRect.left;
    global.screen_height = GameRect.bottom - GameRect.top;

    DWORD dwStyle = GetWindowLong(GameWnd, GWL_STYLE);
    if (dwStyle & WS_BORDER)
    {
        GameRect.top += 32;
        global.screen_height -= 39;
    }

    MoveWindow(MyWnd, GameRect.left - 4.f, GameRect.top - 4.f, global.screen_width + 4.f, global.screen_height + 4.f, true);

    if (GetAsyncKeyState(VK_INSERT) & 1)
    {
        global.menu = !global.menu;
        if (global.menu)
        {
            SetWindowLongA(MyWnd, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
            SetForegroundWindow(MyWnd);
        }
        else
        {
            SetWindowLongA(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
        }
    }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            if (g_mainRenderTargetView)
            {
                g_mainRenderTargetView->Release(); g_mainRenderTargetView = NULL;
            }

            g_pSwapChain->ResizeBuffers(0, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam), DXGI_FORMAT_UNKNOWN, 0);

            ID3D11Texture2D* pBackBuffer;
            g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
            g_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &g_mainRenderTargetView);
            pBackBuffer->Release();

        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}