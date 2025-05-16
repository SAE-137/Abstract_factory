#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "iclassunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr<IClassUnit> createClassUnit(const std::string& name) const = 0;

    virtual std::shared_ptr<MethodUnit> createMethodUnit(
        const std::string& name,
        const std::string& returnType,
        AbstractProductUnit::Flags flags) const = 0;

    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const = 0;
};

#endif // ABSTRACTFACTORY_H
