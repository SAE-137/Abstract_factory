#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include"iclassunit.h"
#include"AbstractProductUnit.h"

class JavaClassUnit : public IClassUnit {
public:
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit JavaClassUnit(const std::string& name)
        : IClassUnit(name, ACCESS_MODIFIERS.size()) {}

    void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags = 0) override {
        size_t access = (flags < ACCESS_MODIFIERS.size()) ? flags : PRIVATE;
        m_fields[access].push_back(unit);
    }
    std::string compile(unsigned int lvl = 0) const
    {
        std::string result = "class " + m_name + " {\n";

        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); i++)
        {
            for (const auto& f : m_fields[i])
            {
                result += generateShift(lvl + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(lvl + 1);
            }
        }

        result += generateShift(lvl) + "};\n";

        return result;
    }
};


#endif // JAVACLASSUNIT_H
