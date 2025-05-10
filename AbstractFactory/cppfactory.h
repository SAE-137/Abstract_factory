#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include"abstractfactory.h"
#include"abstractproductunit.h"
#include"cppclassunit.h"
#include"cppmethodunit.h"
#include"cppprintoperatorunit.h"

class CppFactory : public AbstractFactory
{
public:
    std::shared_ptr<AbstractProductUnit> createClass(const std::string& name,
                                                     AbstractProductUnit::Flags /*flags*/,
                                                     AbstractProductUnit::Flags /*accessModifier*/) const override
    {
        return std::make_shared<CppClassUnit>(name);
    }

    std::shared_ptr<AbstractProductUnit> createMethod(const std::string& name,
                                                      const std::string& returnType,
                                                      AbstractProductUnit::Flags flags) const override
    {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<AbstractProductUnit> createPrintOperator(const std::string& text) const override
    {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};


#endif // CPPFACTORY_H
