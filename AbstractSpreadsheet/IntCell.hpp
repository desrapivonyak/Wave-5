#ifndef INT_CELL
#define INT_CELL

#include "AbstractCell.hpp"

class IntCell : public AbstractCell {
public:   
    IntCell() = default;
    explicit IntCell(int);
    int getValue() const;
    void setValue(int);
    void operator++();
    void operator--();
    operator double();
    IntCell& operator=(const IntCell&) = default;

private:
    int mValue;
};

std::ostream& operator<<(std::ostream&, const IntCell&);

#endif //INT_CELL