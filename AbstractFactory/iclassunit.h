#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <vector>
#include "AbstractProductUnit.h"

class IClassUnit : public AbstractProductUnit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

    explicit IClassUnit(const std::string& name, size_t fields_size)
        : m_name(name), m_fields(fields_size) {}

    virtual ~IClassUnit() = default;

protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<AbstractProductUnit>>;
    std::vector<Fields> m_fields;
};

#endif // ICLASSUNIT_H
