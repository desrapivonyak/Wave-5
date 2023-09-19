#ifndef SPREADSHEETCELL
#define SPREADSHEETCELL
#ifndef STRING_CELL
#define STRING_CELL

#include "AbstractCell.hpp"

#include <string>

class StringCell : public AbstractCell {
public:
    explicit StringCell(const std::string&);
    StringCell& operator=(const StringCell&) = default;
    operator int() const;
    operator double() const;

public:
    void setStringValue(const std::string&);
    std::string getStringValue() const;
    int getIntValue() const;
    double getDoubleValue() const;

private:
    std::string mValue;
};

std::ostream& operator<<(std::ostream&, const StringCell&);

#endif #STRING_CELL