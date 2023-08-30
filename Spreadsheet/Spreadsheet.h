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
    void addRow(const int);
    void addColumn(const int);
    void removeRow(const int);
    void removeColumn(const int);
    void printCells();

private:
    void checkIndexes(const int, const int) const;

private:
    int mRow;
    int mColumn;
    SpreadsheetCell** mCell;
};

#endif