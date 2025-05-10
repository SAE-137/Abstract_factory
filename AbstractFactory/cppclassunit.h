#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "IClassUnit.h"

class CppClassUnit : public IClassUnit {
public:
    enum CppAccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        CPP_MODIFIER_COUNT
    };

    explicit CppClassUnit(const std::string& name) : IClassUnit(name) {
        m_fields.resize(CPP_MODIFIER_COUNT);
    }

    void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags) override;

    const std::vector<std::string>& getAccessModifiers() const override {
        static const std::vector<std::string> MODIFIERS = {
            "public", "protected", "private"
        };
        return MODIFIERS;
    }

    std::string compile(unsigned int level = 0) const override;
};

#endif // CPPCLASSUNIT_H
