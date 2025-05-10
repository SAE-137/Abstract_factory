#ifndef ABSTRACTPRODUCTUNIT_H
#define ABSTRACTPRODUCTUNIT_H
#include<memory>


class AbstractProductUnit
{
public:
    using Flags = unsigned int;

    virtual ~AbstractProductUnit() = default;
    void add(const std::shared_ptr<AbstractProductUnit>&, Flags);

    virtual std::string compile(unsigned int lvl = 0) const = 0;
protected:
     std::string generateShift(unsigned int lvl) const;
     std::string generateTabulation(unsigned int lvl) const;

};

#endif // ABSTRACTPRODUCTUNIT_H


