#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <vector>
#include <memory>
#include <string>
#include "AbstractProductUnit.h"

class IClassUnit : public AbstractProductUnit {
public:
   enum AccessModifier { PUBLIC, PROTECTED, PRIVATE, INTERNAL, PROTECTED_INTERNAL };
   static const std::vector<std::string> ACCESS_MODIFIERS;

protected:
    std::string m_name;
    std::vector<std::vector<std::shared_ptr<AbstractProductUnit>>> m_fields;
    explicit IClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(ACCESS_MODIFIERS.size());
    }
};

#endif // ICLASSUNIT_H
