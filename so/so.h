#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef SO_EXPORTS
#define SO_EXPORT __declspec(dllexport)
#else
#define SO_EXPORT __declspec(dllimport)
#endif
#else
#define SO_EXPORT __attribute__((visibility("default")))
#endif


#include <functional>
#include <string>
#include <string_view>

struct alignas(32) AStruct
{
    using Formatter = std::function<std::string(const AStruct&)>;
    
    ~AStruct();
    AStruct(std::string_view name, std::string_view readable, Formatter&& formatter = Formatter{});
    
    const std::string& name() const noexcept
    {
        return m_name;
    }

    const std::string& readable() const noexcept
    {
        return m_readable;
    }

    void say() const;

private:
    const std::string m_name;
    const std::string m_readable;
    const Formatter m_formatter;
};


SO_EXPORT AStruct::Formatter defaultFormatter();
SO_EXPORT void say();

extern const SO_EXPORT AStruct aaa;
extern const SO_EXPORT AStruct bbb;


