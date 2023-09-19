#include "Spreadsheet.hpp"

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
    mCell = new AbstractCell*[mRow];
    for (int i = 0; i < mRow; ++i) {
        mCell[i] = new AbstractCell[mColumn];
    }
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < mRow; ++i) {
        delete[] mCell[i];
    }
    delete[] mCell;
}

void Spreadsheet::setCell(const int row, const int column, AbstractCell* src) {
    checkIndexes(row, column);
    mCell[row][column] = src;
}

AbstractCell* Spreadsheet::getCell(const int row, const int column) const {
    checkIndexes(row, column);
    return &mCell[row][column];
}

int Spreadsheet::getRow() const {
    return mRow;
}

int Spreadsheet::getColumn() const {
    return mColumn;
}

void Spreadsheet::addRow(const int count) {
    int newRow = mRow + count;
    AbstractCell** newCell = new AbstractCell*[newRow];
    
    for (int i = 0; i < newRow; ++i) {
        newCell[i] = new AbstractCell[mColumn];
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
    AbstractCell** newCell = new AbstractCell*[mRow];
    
    for (int i = 0; i < mRow; ++i) {
        newCell[i] = new AbstractCell[newColumn];
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

    AbstractCell** newCell = new AbstractCell*[mRow - 1];
    
    for (int i = 0, newRow = 0; i < mRow; ++i) {
        if (i != index) {
            newCell[newRow] = new AbstractCell[mColumn];
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
    AbstractCell** newCell = new AbstractCell*[mRow];
    
    for (int i = 0; i < mRow; ++i) {
        newCell[i] = new AbstractCell[newColumn];
        
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

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& other) {
    if (this != &other) {
        mRow = other.mRow;
        mColumn = other.mColumn;
        mCell = new AbstractCell*[mRow];
        for (int i = 0; i < mRow; ++i) {
            mCell[i] = new AbstractCell[mColumn];

            for (int j = 0; j < mColumn; ++j) {
                mCell[i][j] = other.mCell[i][j];
            }
        }
    }
    return *this;
}

AbstractCell* Spreadsheet::operator[](const int row) {
    if (row > mRow || row < 0) {
        throw std::out_of_range("Index is out of range.");
    }
    return mCell[row];
}

AbstractCell* Spreadsheet::operator[](const AbstractCell& other) {
    for (int i = 0; i < mRow; ++i) {
        for (int j = 0; j < mColumn; ++j) {
            if (mCell[i][j].getStringValue() == other.getStringValue()) {
                return mCell[i];
            }
        }
    }
    return nullptr;
}

//helper function
void Spreadsheet::checkIndexes(const int row, const int column) const {
    if (row < 0 || row > mRow || column < 0 || column > mColumn) {
        throw std::out_of_range("Out of range.");
    }
}

std::ostream& operator<<(std::ostream& out, const Spreadsheet& src) {
    const int cellWidth = 12;
    
    for (int i = 0; i < src.getRow(); ++i) {
        out << " " << std::string((cellWidth + 1) * src.getColumn(), '-') << std::endl;

        for (int j = 0; j < src.getColumn(); ++j) {
            out << "| " << std::left << std::setw(cellWidth - 2) << src.getCell(i, j)->getStringValue() << " ";
        }
        out << "|\n";
    }

    out << " " << std::string((cellWidth + 1) * src.getColumn(), '-') << std::endl;
    return out;
}

Spreadsheet operator+(const Spreadsheet& op1, const Spreadsheet& op2) {
    int newRow = op1.getRow() + op2.getRow();
    int newColumn = std::max(op1.getColumn(), op2.getColumn());
    
    Spreadsheet newSheet;
    newSheet.addRow(newRow);
    newSheet.addColumn(newColumn);

    int q = 0;

    for (int i = 0; i < op1.getRow(); ++i) {
        int p = 0;
        for (int j = 0; j < op1.getColumn(); ++j) {
            newSheet.setCell(q, p, op1.getCell(i, j)->getStringValue());
            ++p;
        }
        while (p != newColumn) {
            newSheet.setCell(q, p, "");
            ++p;
        }
        ++q;
    }

    for (int i = 0; i < op2.getRow(); ++i) {
        int p = 0;
        for (int j = 0; j < op2.getColumn(); ++j) {
            newSheet.setCell(q, p, op2.getCell(i, j)->getStringValue());
            ++p;
        }
        while (p != newColumn) {
            newSheet.setCell(q, p, "");
            ++p;
        }
        ++q;
    }

    return newSheet;
}