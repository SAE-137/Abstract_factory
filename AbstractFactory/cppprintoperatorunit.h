#ifndef CPPPRINTOPERATORUNIT_H
#define CPPPRINTOPERATORUNIT_H

#include"abstractproductunit.h"

class CppPrintOperatorUnit : public AbstractProductUnit {
public:
    explicit CppPrintOperatorUnit(const std::string& text) : m_text(text) {}
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "printf(\"" + m_text + "\");\n";
    }
private:
    std::string m_text;
};

#endif // CPPPRINTOPERATORUNIT_H

