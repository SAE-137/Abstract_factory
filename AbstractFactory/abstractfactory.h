#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "abstractproductunit.h"


class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual std::shared_ptr<AbstractProductUnit> createClass(const std::string &name,
                                                         AbstractProductUnit::Flags flags,
                                                         AbstractProductUnit::Flags accessModifier
                                                         ) const = 0;

    virtual std::shared_ptr<AbstractProductUnit> createMethod(const std::string &name,
                                                          const std::string &returnType,
                                                          AbstractProductUnit::Flags flags
                                                          ) const = 0;

    virtual std::shared_ptr<AbstractProductUnit> createPrintOperator(const std::string &text) const = 0;
};

#endif // ABSTRACTFACTORY_H
