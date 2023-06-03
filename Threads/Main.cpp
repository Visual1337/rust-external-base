#include "Includes.hpp"


int main() 
{
	

	while (!FindWindowA(_("UnityWndClass"), _("Rust")))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	system(_("cls"));

	Utils::CheckFileSystem();
	printf(_("[+] Found Rust!\n"));
	printf(_("[+] Checked File System\n"));

#if HV == true

	if (!driver.initialize()) {
		printf(_("[!] hypervisor is not loaded\n"));
		return 1;
	}

	if (!driver.attach(_("RustClient.exe")))
	{
		printf(_("[!] failed to attach to RustClient.exe\n"));
		return 1;
	}

	global.unity_player = driver.mod(_(L"UnityPlayer.dll"));

	global.game_assembly = driver.mod(_(L"GameAssembly.dll"));

	printf("[+] Found UnityPlayer.dll -> %p\n", global.unity_player);
	printf("[+] Found GameAssembly.dll -> %p\n", global.game_assembly);

#elif HV == false
	if (!driver.driver_init()) {
		printf(_("[!] hypervisor is not loaded\n"));
		return 1;
	}

	if (!driver.GetProcessID(_(L"RustClient.exe")))
	{
		printf(_("[!] failed to attach to RustClient.exe\n"));
		return 1;
	}

	driver.pid = driver.GetProcessID(_(L"RustClient.exe"));

	global.unity_player = driver.GetBaseAddress(_("UnityPlayer.dll"));

	global.game_assembly = driver.GetBaseAddress(_("GameAssembly.dll"));

	printf("[+] Found UnityPlayer.dll -> %p\n", global.unity_player);
	printf("[+] Found GameAssembly.dll -> %p\n", global.game_assembly);
#endif // HV == true

	reinterpret_cast<Movement*>(0)->BlockCommands();

	std::thread([&]() {UpdateLists();}).detach();
	std::thread([&]() {UpdatePositions();}).detach();
	std::thread([&]() {Aimbot();}).detach();
	std::thread([&]() {Misc();}).detach();

	printf("[+] Thread 5 Started\n");
    Overlay();

    return -1;
}  

