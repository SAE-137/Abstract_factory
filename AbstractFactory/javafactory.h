#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H

#include "abstractfactory.h"
#include "javaclassunit.h"
#include "javamethodunit.h"
#include "javaprintoperatorunit.h"

class JavaFactory : public AbstractFactory {
public:
    std::shared_ptr<IClassUnit> createClassUnit(const std::string& name) const override {
        return std::make_shared<JavaClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(
        const std::string& name,
        const std::string& returnType,
        AbstractProductUnit::Flags flags) const override
    {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(
        const std::string& text) const override
    {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};

#endif // JAVAFACTORY_H
