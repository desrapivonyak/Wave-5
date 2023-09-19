#ifndef SPREADSHEET
#define SPREADSHEET

#include "IntCEll.hpp"
#include "DoubleCell.hpp"
#include "StringCell.hpp"

class Spreadsheet{
public:
    Spreadsheet();
    Spreadsheet(const int, const int);
    ~Spreadsheet();

public:
    void setCell(const int, const int, AbstractCell*);
    void setCell(const int, const int, AbstractCell*);
    AbstractCell* getCell(const int, const int) const;
    int getRow() const;
    int getColumn() const;
    void addRow(const int);
    void addColumn(const int);
    void removeRow(const int);
    void removeColumn(const int);
    Spreadsheet& operator=(const Spreadsheet&);
    AbstractCell* operator[](const int);
    AbstractCell* operator[](const SpreadsheetCell&);

private:
    void checkIndexes(const int, const int) const;

private:
    int mRow;
    int mColumn;
    AbstractCell** mCell;
};

Spreadsheet operator+(const Spreadsheet&, const Spreadsheet&);
std::ostream& operator<<(std::ostream&, const Spreadsheet&);

#endif