#include "cppclassunit.h"




void CppClassUnit::add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags)
{
    if(flags >= CPP_MODIFIER_COUNT) {
        flags = PRIVATE;
    }
    m_fields[flags].push_back(unit);
}


std::string CppClassUnit::compile(unsigned int lvl) const {
    const auto& modifiers = getAccessModifiers();

    if (modifiers.size() != CPP_MODIFIER_COUNT || m_fields.size() != CPP_MODIFIER_COUNT) {
        throw std::runtime_error("Internal error: modifiers/fields size mismatch");
    }

    std::string result = generateShift(lvl) + "class " + m_name + " {\n";

    for (size_t i = 0; i < CPP_MODIFIER_COUNT; ++i) {

        if (m_fields[i].empty()) {
            continue;
        }

        result += modifiers[i] + ":\n";


        for (const auto& unit : m_fields[i]) {
            if (!unit) {
                throw std::runtime_error("Error: null unit in class section");
            }
            result += unit->compile(lvl + 1);
        }
        result += "\n";
    }

    result += generateShift(lvl) + "};\n";
    return result;
}
