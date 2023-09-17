#ifndef SPREADSHEET
#define SPREADSHEET

#include "SpreadSheetCell.h"

class Spreadsheet{
public:
    Spreadsheet();
    Spreadsheet(const int, const int);
    ~Spreadsheet();

public:
    void setCell(const int, const int, const std::string&);
    void setCell(const int, const int, SpreadsheetCell);
    SpreadsheetCell* getCell(const int, const int) const;
    int getRow() const;
    int getColumn() const;
    void addRow(const int);
    void addColumn(const int);
    void removeRow(const int);
    void removeColumn(const int);
    Spreadsheet& operator=(const Spreadsheet&);
    SpreadsheetCell* operator[](const int);
    SpreadsheetCell* operator[](const SpreadsheetCell&);

private:
    void checkIndexes(const int, const int) const;

private:
    int mRow;
    int mColumn;
    SpreadsheetCell** mCell;
};

Spreadsheet operator+(const Spreadsheet&, const Spreadsheet&);
std::ostream& operator<<(std::ostream&, const Spreadsheet&);

#endif