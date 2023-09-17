#ifndef SPREADSHEETCELL
#define SPREADSHEETCELL

#include <string>

class SpreadsheetCell {
public:
    SpreadsheetCell();
    explicit SpreadsheetCell(const std::string&);
    explicit SpreadsheetCell(const double);
    explicit SpreadsheetCell(const int);
    SpreadsheetCell(const SpreadsheetCell&) = default;
    SpreadsheetCell(SpreadsheetCell&&) = default;
    ~SpreadsheetCell() = default;
    SpreadsheetCell& operator=(const SpreadsheetCell&);
    void operator++();
    void operator--();
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

std::ostream& operator<<(std::ostream&, const SpreadsheetCell&);

#endif