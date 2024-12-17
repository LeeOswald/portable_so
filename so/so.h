#pragma once

#define SO_EXPORT __attribute__((visibility("default")))

#include <functional>
#include <string>

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


