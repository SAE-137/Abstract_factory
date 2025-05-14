#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include"abstractproductunit.h"

class JavaPrintOperatorUnit : public AbstractProductUnit{
public:
    explicit JavaPrintOperatorUnit(const std::string& text) : m_text(text) {}
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
private:
    std::string m_text;
};

#endif // JAVAPRINTOPERATORUNIT_H
