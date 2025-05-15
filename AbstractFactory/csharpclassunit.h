#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include"iclassunit.h"

class CSharpClassUnit : public IClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit CSharpClassUnit(const std::string& name)
        : IClassUnit(name, ACCESS_MODIFIERS.size()) {}

    void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags) override {
        size_t access = (flags < ACCESS_MODIFIERS.size()) ? flags : PRIVATE;
        m_fields[access].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + "public class " + m_name + " {\n";
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            if (m_fields[i].empty()) continue;
            for (const auto& f : m_fields[i]) {
               result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level + 1);
            }
        }
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CSHARPCLASSUNIT_H
