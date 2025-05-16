#ifndef ABSTRACTPRODUCTUNIT_H
#define ABSTRACTPRODUCTUNIT_H

#include <memory>
#include <string>

class AbstractProductUnit {
public:
    using Flags = unsigned int;

    virtual ~AbstractProductUnit() = default;

    virtual void add(const std::shared_ptr<AbstractProductUnit>&, Flags) {
        throw std::runtime_error("Not supported");
    }

    virtual std::string compile(unsigned int lvl = 0) const = 0;

protected:
    std::string generateShift(unsigned int lvl) const {
        static const auto DEFAULT_INDENT = "    ";

        std::string res;
        for (size_t i = 0; i < lvl; i++)
        {
            res += DEFAULT_INDENT;
        }

        return res;
    }
};

#endif // ABSTRACTPRODUCTUNIT_H

