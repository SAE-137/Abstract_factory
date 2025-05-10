#ifndef ICLASSUNIT_H
#define ICLASSUNIT_H

#include <vector>
#include <memory>
#include <string>
#include "AbstractProductUnit.h"

class IClassUnit : public AbstractProductUnit {
public:
    using Flags = unsigned int;

    explicit IClassUnit(const std::string& name) : m_name(name) {}
    virtual ~IClassUnit() = default;


    virtual void add(const std::shared_ptr<AbstractProductUnit>& unit, Flags flags) = 0;


    virtual const std::vector<std::string>& getAccessModifiers() const = 0;


    virtual std::string compile(unsigned int level = 0) const override = 0;

protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<AbstractProductUnit>>;
    std::vector<Fields> m_fields;
};

#endif // ICLASSUNIT_H
