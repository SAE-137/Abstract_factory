#include "abstractproductunit.h"

void AbstractProductUnit::add(std::shared_ptr<AbstractProductUnit>&, Flags)
{
    throw std::runtime_error( "Not supported");
}

std::string AbstractProductUnit::generateShift(unsigned int lvl = 0) const
{
    std::string result;
    static const char* DEFAULT_SHIFT = " ";
    for(int i = 0; i < lvl; ++i)
        result += DEFAULT_SHIFT;

    return result;
}

std::string AbstractProductUnit::generateTabulation(unsigned int lvl = 0) const
{
    std::string result;
    for(int i = 0; i < lvl; ++i)
        result += generateShift(4);

    return result;
}
