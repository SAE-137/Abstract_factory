#include "abstractproductunit.h"

void AbstractProductUnit::add(const std::shared_ptr<AbstractProductUnit>&, Flags)
{
    throw std::runtime_error( "Not supporterrrd");
}

std::string AbstractProductUnit::generateShift(unsigned int lvl = 0) const
{
    return std::string(lvl * 4, ' ');
}
