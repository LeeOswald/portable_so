#include "so.h"

#include <iostream>
#include <sstream>
#include <unordered_set>


std::unordered_set<const AStruct*> g_set; 

std::string formatter(const AStruct& a)
{
    std::ostringstream ss;
    ss << (const void*)&a;
    ss << "->" << a.name() << "(" << a.readable() << ")";
    return ss.str();
}


SO_EXPORT AStruct::Formatter defaultFormatter()
{
    return {formatter};
}

AStruct::~AStruct()
{
    g_set.erase(this);
}

AStruct::AStruct(std::string_view name, std::string_view readable, Formatter&& formatter)
    : m_name(name)
    , m_readable(readable)
    , m_formatter(std::move(formatter))
{
    g_set.insert(this);
}

void AStruct::say() const
{
    std::cout << m_formatter(*this) << "\n";
}

SO_EXPORT void say()
{
    for (auto& e: g_set)
    {
        e->say();
    }
}

const AStruct aaa{ "aaa", "Uncle Bob", defaultFormatter() };
const AStruct bbb{ "bbb", "Mary Jane", defaultFormatter() };