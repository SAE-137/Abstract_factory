#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "IClassUnit.h"


class CppClassUnit : public IClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CppClassUnit(const std::string& name)
        : IClassUnit(name, ACCESS_MODIFIERS.size()) {}

    void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags)  {
        if (!unit) {
            throw std::runtime_error("Unit is nullptr");
        }
        size_t access = (flags < ACCESS_MODIFIERS.size()) ? flags : PRIVATE;
        m_fields[access].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const {
        std::string result = generateShift(level) + "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty()) continue;
            result += generateShift(level) + ACCESS_MODIFIERS[i] + ":\n";
            for (const auto& f : m_fields[i]) {
                result += f->compile(level + 1);
            }
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // CPPCLASSUNIT_H
