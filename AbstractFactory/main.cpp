#include <iostream>
#include <memory>
#include <ostream>
#include <vector>



#include "csharpfactory.h"
#include"iclassunit.h"
#include"cppfactory.h"
#include"javafactory.h"


std::string GenerateProgram(const std::shared_ptr<AbstractFactory> &factory)
{
    auto class_a = factory->createClassUnit("firstClass");

    auto class_b = factory->createClassUnit("inside class");

    class_b->add(factory->createMethodUnit("testFunc1", "void", 0), IClassUnit::PUBLIC);
    class_a->add(class_b, IClassUnit::PUBLIC);
    class_a->add(factory->createMethodUnit("testFunc2", "void", MethodUnit::STATIC), IClassUnit::PRIVATE);
    auto method = factory->createMethodUnit("testFunc4", "void", MethodUnit::STATIC);

    method->Add(factory->createPrintOperatorUnit("Hello, world!"));
    class_a->add(method, IClassUnit::PROTECTED);
    class_a->add(factory->createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST), IClassUnit::PUBLIC);
    return class_a->compile();
}

int main()
{
    // C++
    std::cout << "C++:" << std::endl;
        std::cout << GenerateProgram(std::make_shared<CppFactory>()) << std::endl;

    // C#
    std::cout << "C#:" << std::endl;
        std::cout << GenerateProgram(std::make_shared<CSharpFactory>()) << std::endl;


    // Java
    std::cout << "Java:" << std::endl;
        std::cout << GenerateProgram(std::make_shared<JavaFactory>()) << std::endl;


    return 0;
}














































