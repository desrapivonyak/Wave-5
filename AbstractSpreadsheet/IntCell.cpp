#include "IntCell.hpp"

IntCell::IntCell(int num)
        : mValue {num} 
{
}

int IntCell::getValue() const {
    return mValue;
}

void IntCell::setValue(int val) {
    mValue {val};
}

void IntCell::operator++() {
    return ++mValue;
}

void IntCell::operator--() {
    return --mValue;
}

IntCell::operator double() {
    return static_cast<double>(mValue);
}

std::ostream& operator<<(std::ostream& out, const IntCell& cell) {
    out << cell.getValue();
    return out;
}