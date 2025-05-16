#ifndef METHODUNIT_H
#define METHODUNIT_H
#include<vector>
#include"abstractproductunit.h"

class MethodUnit : public AbstractProductUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTRACT = 1 << 3,
        FINAL = 1 << 4,
        SEALED = 1 << 5,
        OVERRIDE = 1 << 6
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags) {}

    virtual ~MethodUnit() = default;

    void Add(const std::shared_ptr<AbstractProductUnit>& unit, Flags /* flags */ = 0)
    {
        if (unit == nullptr)
        {
            throw std::runtime_error("ERROR, unit is nullptr.");
        }

        m_body.push_back(unit);
    }
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<AbstractProductUnit>> m_body;

};

#endif // METHODUNIT_H
