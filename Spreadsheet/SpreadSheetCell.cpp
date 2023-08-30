#include "SpreadSheetCell.h"

#include <sstream>
#include <iostream>

SpreadsheetCell::SpreadsheetCell() : mValue{""} {}

SpreadsheetCell::SpreadsheetCell(const std::string& str) : mValue {str} {}

SpreadsheetCell::SpreadsheetCell(const double dnum) : mValue {std::to_string(dnum)} {}

SpreadsheetCell::SpreadsheetCell(const int inum) : mValue {std::to_string(inum)} {}

void SpreadsheetCell::setStringValue(const std::string& str) {
    mValue = str;
}

std::string SpreadsheetCell::getStringValue() const {
    return mValue;
}

double SpreadsheetCell::getDoubleValue() const {
    std::stringstream ss(mValue);
    double num;
    ss >> num;
    if (ss.fail()) {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return 1;  // Exit with error code
    }
    return num;
}

int SpreadsheetCell::getIntValue() const {
    std::stringstream ss(mValue);
    int num;
    ss >> num;
    if (ss.fail()) {
        std::cout << "Conversion failed: invalid format" << std::endl;
        return 1;  // Exit with error code
    }
    return num;
}