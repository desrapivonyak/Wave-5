#ifndef DOUBLE_CELL
#define DOUBLE_CELL

#include "AbstractCell.hpp"

class DoubleCell : public AbstractCell {
public:   
    DoubleCell() = default;
    explicit DoubleCell(double);
    double getValue() const;
    void setValue(double);
    void operator++();
    void operator--();
    operator int();
    DoubleCell& operator=(const DoubleCell&) = default;

private:
    int mValue;
};

std::ostream& operator<<(std::ostream&, const DoubleCell&);

#endif //DOUBLE_CELL