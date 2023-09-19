#include "DoubleCell.hpp"

DoubleCell::IntCell(double num)
        : mValue {num} 
{
}

double DoubleCell::getValue() const {
    return mValue;
}

void DoubleCell::setValue(double val) {
    mValue {val};
}

void DoubleCell::operator++() {
    return ++mValue;
}

void DoubleCell::operator--() {
    return --mValue;
}

DoubleCell::operator int() {
    return static_cast<int>(mValue);
}

std::ostream& operator<<(std::ostream& out, const DoubleCell& cell) {
    out << cell.getValue();
    return out;
}