#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H

#include "abstractfactory.h"
#include "csharpclassunit.h"
#include "csharpmethodunit.h"
#include "csharpprintoperatorunit.h"

class CSharpFactory : public AbstractFactory {
public:
    std::shared_ptr<IClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<CSharpClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(
        const std::string& name,
        const std::string& returnType,
        AbstractProductUnit::Flags flags) const override
    {
        return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const override
    {
        return std::make_shared<CSharpPrintOperatorUnit>(text);
    }
};

#endif // CSHARPFACTORY_H
