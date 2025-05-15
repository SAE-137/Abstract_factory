#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include"abstractproductunit.h"

class PrintOperatorUnit : public AbstractProductUnit
{
public:
    explicit PrintOperatorUnit(const std::string& text) : m_text(text) {}

    virtual ~PrintOperatorUnit() = default;

protected:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_H
