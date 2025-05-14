#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include"abstractproductunit.h"
class CSharpPrintOperatorUnit : public AbstractProductUnit {
public:
    explicit CSharpPrintOperatorUnit(const std::string& text) : m_text(text) {}
    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }
private:
    std::string m_text;
};

#endif // CSHARPPRINTOPERATORUNIT_H
