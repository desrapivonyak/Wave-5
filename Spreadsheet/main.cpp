#include "Spreadsheet.h"

#include <iostream>

int main() {
    Spreadsheet ob;
    ob.addRow(2); // ավելացնում է երկու տող

    //SpreadsheetCell* c = ob.getCell(1, 1); // nullptr, աղյուսակն ունի երկու տող, բայց չունի սյունակներ
    //cout << c->getStringValue(); // runtime error, dereferencing a nullptr

    ob.addColumn(2); // ավելացնում է երկու սյունակ

    ob.printCells();

    ob.getCell(1, 1)->getStringValue(); // վերադարձնում է դատարկ տող
    ob.setCell(0, 0, "hello");
    ob.setCell(0, 1, "3.14");
    ob.setCell(1, 1, "val");
    ob.printCells();
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |          | "val"   |
    // ---------------------

    std::cout << ob.getCell(0, 0)->getStringValue() << std::endl; // տպում է "hello"
    std::cout << ob.getCell(1, 0)->getStringValue() << std::endl; // տպում է ""
    SpreadsheetCell* cell = ob.getCell(1, 1);
    std::cout << cell->getStringValue() << std::endl; // տպում է "val"
    cell->setStringValue("new");
    ob.printCells();
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |          | "new"   |
    // ---------------------

    // double v = cell->getDoubleValue(); // runtime error: չի կարող կոնվերտացնել "new" բառը դեպի double
    double v2 = ob.getCell(0, 1)->getDoubleValue(); 
    std::cout << v2 << std::endl; // տպում է 3.14

    SpreadsheetCell* intCell = ob.getCell(1, 0); // վերադարձնում է ցուցիչ դատարկ տող պարունակող cell-ի վրա
    ob.printCells();
    // intCell-ը կհղվի այս cell-ին (նկարում նշված է x նշանով)
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |    x     | "new"   |
    // ---------------------

    intCell->setStringValue("99");
    ob.printCells();
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |   "99"   | "new"   |
    // ---------------------

    std::cout << ob.getCell(1, 0)->getIntValue() << std::endl; // կտպի 99
    std::cout << intCell->getStringValue() << std::endl; // կտպի "99"
    std::cout << ob.getCell(0, 0)->getIntValue() << std::endl; // runtime error, չի կոնվերտացվում "hello"-ն դեպի int
}