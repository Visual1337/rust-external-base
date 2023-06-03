namespace Utils
{
    inline auto ValidPointer(uintptr_t pointer) -> bool
    {
        return (pointer && pointer > 0xFFFFFF && pointer < 0x7FFFFFFFFFFF);
    }

    unsigned HashString(const std::string& str)
    {
        unsigned int hash = 1315423911;

        for (std::size_t i = 0; i < str.length(); i++)
        {
            hash ^= ((hash << 5) + str[i] + (hash >> 2));
        }

        return (hash & 0x7FFFFFFF);
    }

    std::string GetBasePath(std::string const& path)
    {
        std::string removed_path = path.substr(path.find_last_of(_("/\\")) + 1);
        return removed_path.substr(0, removed_path.find_last_of(_(".\\")));
    }

    int StringToInt(std::string text)
    {
        int result = 0;

        for (const auto& item : text)
        {
            result += int(item);
        }
        return result;
    }

    std::string ToLower(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
        return s;
    }

    void CheckFileSystem()
    {
        std::filesystem::path config_path = std::string(getenv(_("APPDATA")) + std::string(_("\\Amplitude-Rust\\Configs")));

        if (!std::filesystem::exists(config_path))
        {
            std::filesystem::create_directories(config_path);
        }
    }
}