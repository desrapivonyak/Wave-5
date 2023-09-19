#include "StringCell.hpp"

#include <sstream>
#include <iostream>

StringCell::StringCell(const std::string& str) : mValue {str} {}

StringCell::operator int() const{
    return getIntValue();
} 

StringCell::operator double() const{
    return getDoubleValue();
}


void StringCell::setStringValue(const std::string& str) {
    mValue = str;
}

std::string StringCell::getStringValue() const {
    return mValue;
}

double StringCell::getDoubleValue() const {
    std::stringstream ss(mValue);
    double num;
    ss >> num;
    if (ss.fail()) {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return 1;  // Exit with error code
    }
    return num;
}

int StringCell::getIntValue() const {
    std::stringstream ss(mValue);
    int num;
    ss >> num;
    if (ss.fail()) {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return 1;  // Exit with error code
    }
    return num;
}

//none member function
std::ostream& operator<<(std::ostream& out, const StringCell& cell) {
    out << cell.getStringValue();
    return out;
}