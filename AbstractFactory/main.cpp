#include <iostream>
#include <memory>
#include <ostream>
#include <vector>




#include"abstractfactory.h"
#include "csharpfactory.h"
#include"iclassunit.h"
#include"cppfactory.h"
#include"javafactory.h"


const std::vector<std::string> IClassUnit::ACCESS_MODIFIERS = {
    "public", "protected", "private", "internal", "protected internal"
};

const std::vector<std::string> MethodUnit::ACCESS_MODIFIERS = {
    "static", "const", "virtual", "abstract", "final", "sealed", "override"
};

std::string generateProgram(const AbstractFactory& factory) {
    auto myClass = factory.createClassUnit("MyClass");

    myClass->add(factory.createMethodUnit("testFunc1", "void", 0), IClassUnit::PUBLIC);
    myClass->add(factory.createMethodUnit("testFunc2", "void", MethodUnit::FINAL), IClassUnit::PRIVATE);
    myClass->add(factory.createMethodUnit("testFunc3", "void", MethodUnit::VIRTUAL), IClassUnit::PUBLIC);

    auto method = factory.createMethodUnit("testFunc4", "void", MethodUnit::STATIC);
    method->add(factory.createPrintOperatorUnit("Hello, world!"),0);
    myClass->add(method, IClassUnit::PROTECTED);

    return myClass->compile();
}


int main() {
    CppFactory cppFactory;
    CSharpFactory csharpFactory;
    JavaFactory javaFactory;

    std::cout << "C++ Code:\n" << generateProgram(cppFactory) << "\n";
    std::cout << "C# Code:\n" << generateProgram(csharpFactory) << "\n";
    std::cout << "Java Code:\n" << generateProgram(javaFactory) << "\n";

    return 0;
}














































