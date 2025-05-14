#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "abstractproductunit.h"


class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;
    virtual std::shared_ptr<AbstractProductUnit> createClassUnit(const std::string& name) const = 0;

    virtual std::shared_ptr<AbstractProductUnit> createMethodUnit(const std::string& name,
                                                                  const std::string& returnType,
                                                                  AbstractProductUnit::Flags flags) const = 0;
    virtual std::shared_ptr<AbstractProductUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};

#endif // ABSTRACTFACTORY_H
