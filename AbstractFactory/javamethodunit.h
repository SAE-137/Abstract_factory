#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include"methodunit.h"
#include"abstractproductunit.h"
class JavaMethodUnit : public MethodUnit {
public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}
    void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags = 0) override {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        if (m_flags & STATIC) result += "static ";
        if (m_flags & ABSTRACT) result += "abstract ";
        if (m_flags & FINAL) result += "final ";
        result += ACCESS_MODIFIERS[0] + " " + m_returnType + " " + m_name + "()";
        if (m_flags & ABSTRACT) {
            result += ";\n";
        } else {
            result += " {\n";
            for (const auto& b : m_body) {
                result += b->compile(level + 1);
            }
            result += generateShift(level) + "}\n";
        }
        return result;
    }
}; //TODO

#endif // JAVAMETHODUNIT_H
