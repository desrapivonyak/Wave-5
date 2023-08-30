#include "Spreadsheet.h"

#include <stdexcept>
#include <iostream>
#include <iomanip>

Spreadsheet::Spreadsheet()
    : mRow {}
    , mColumn {}
{
}

Spreadsheet::Spreadsheet(const int row, const int column)
    : mRow {row}
    , mColumn {column}
{
    mCell = new SpreadsheetCell*[mRow];
    for (int i = 0; i < mRow; ++i) {
        mCell[i] = new SpreadsheetCell[mColumn];
    }
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < mRow; ++i) {
        delete[] mCell[i];
    }
    delete[] mCell;
}

void Spreadsheet::setCell(const int row, const int column, const std::string& str) {
    checkIndexes(row, column);
    mCell[row][column].setStringValue(str);
}

void Spreadsheet::setCell(const int row, const int column, SpreadsheetCell cell) {
    checkIndexes(row, column);
    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mColumn; ++j) {
            mCell[i][j] = cell;
        }
    }
}

SpreadsheetCell* Spreadsheet::getCell(const int row, const int column) const {
    checkIndexes(row, column);
    return &mCell[row][column];
}

void Spreadsheet::addRow(const int count) {
    int newRow = mRow + count;
    SpreadsheetCell** newCell = new SpreadsheetCell*[newRow];
    
    for (int i = 0; i < newRow; ++i) {
        newCell[i] = new SpreadsheetCell[mColumn];
    }

    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mColumn; ++j) {
            newCell[i][j] = mCell[i][j];
        }
    }

    for (int i = 0; i < mRow; ++i) {
        delete[] mCell[i];
    }
    delete[] mCell;

    mCell = newCell;
    mRow = newRow;
}

void Spreadsheet::addColumn(const int count) {
    int newColumn = mColumn + count;
    SpreadsheetCell** newCell = new SpreadsheetCell*[mRow];
    
    for (int i = 0; i < mRow; ++i) {
        newCell[i] = new SpreadsheetCell[newColumn];
    }

    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mColumn; ++j) {
            newCell[i][j] = mCell[i][j];
        }
    }

    for (int i = 0; i < mRow; ++i) {
        delete[] mCell[i];
    }
    delete[] mCell;

    mCell = newCell;
    mColumn = newColumn;
}

void Spreadsheet::removeRow(const int index) {
    if (index < 0 || index >= mRow) {
        throw std::out_of_range("Wrong index.");
    }

    SpreadsheetCell** newCell = new SpreadsheetCell*[mRow - 1];
    
    for (int i = 0, newRow = 0; i < mRow; ++i) {
        if (i != index) {
            newCell[newRow] = new SpreadsheetCell[mColumn];
            for (int j = 0; j < mColumn; ++j) {
                newCell[newRow][j] = mCell[i][j];
            }
            ++newRow;
        } else {
            delete[] mCell[i];
        }
    }

    delete[] mCell;
    mCell = newCell;
    --mRow;
}

void Spreadsheet::removeColumn(const int index) {
    if (index < 0 || index >= mColumn) {
        throw std::out_of_range("Wrong index.");
    }

    int newColumn = mColumn - 1;
    SpreadsheetCell** newCell = new SpreadsheetCell*[mRow];
    
    for (int i = 0; i < mRow; ++i) {
        newCell[i] = new SpreadsheetCell[newColumn];
        
        for (int j = 0, newCol = 0; j < mColumn; ++j) {
            if (j != index) {
                newCell[i][newCol] = mCell[i][j];
                ++newCol;
            }
        }

        delete[] mCell[i];
    }

    delete[] mCell;
    mCell = newCell;
    mColumn = newColumn;
}

void Spreadsheet::printCells() {
    const int cellWidth = 12;
    
    for (int i = 0; i < mRow; ++i) {
        std::cout << " " << std::string((cellWidth + 1) * mColumn, '-') << std::endl;

        for (int j = 0; j < mColumn; ++j) {
            std::cout << "| " << std::left << std::setw(cellWidth - 2)
                      << mCell[i][j].getStringValue() << " ";
        }
        std::cout << "|\n";
    }

    std::cout << " " << std::string((cellWidth + 1) * mColumn, '-') << std::endl;
}

//helper function
void Spreadsheet::checkIndexes(const int row, const int column) const {
    if (row < 0 || row > mRow || column < 0 || column > mColumn) {
        throw std::out_of_range("Out of range.");
    }
}
