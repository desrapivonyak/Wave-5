#include "Spreadsheet.h"

#include <iostream>

int main() {
    Spreadsheet ob;
    ob.addRow(2); // ավելացնում է երկու տող

    //SpreadsheetCell* c = ob.getCell(1, 1); // nullptr, աղյուսակն ունի երկու տող, բայց չունի սյունակներ
    //cout << c->getStringValue(); // runtime error, dereferencing a nullptr

    ob.addColumn(2); // ավելացնում է երկու սյունակ

    // std::cout << ob;

    ob.getCell(1, 1)->getStringValue(); // վերադարձնում է դատարկ տող
    ob.setCell(0, 0, "hello");
    ob.setCell(0, 1, "3.14");
    ob.setCell(1, 1, "val");
    // std::cout << ob;
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |          | "val"   |
    // ---------------------

    // std::cout << ob.getCell(0, 0)->getStringValue() << std::endl; // տպում է "hello"
    // std::cout << ob.getCell(1, 0)->getStringValue() << std::endl; // տպում է ""
    SpreadsheetCell* cell = ob.getCell(1, 1);
    // std::cout << cell->getStringValue() << std::endl; // տպում է "val"
    cell->setStringValue("new");
    // std::cout << ob;
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |          | "new"   |
    // ---------------------

    // double v = cell->getDoubleValue(); // runtime error: չի կարող կոնվերտացնել "new" բառը դեպի double
    double v2 = ob.getCell(0, 1)->getDoubleValue(); 
    //std::cout << v2 << std::endl; // տպում է 3.14

    SpreadsheetCell* intCell = ob.getCell(1, 0); // վերադարձնում է ցուցիչ դատարկ տող պարունակող cell-ի վրա
    std::cout << ob;
    // intCell-ը կհղվի այս cell-ին (նկարում նշված է x նշանով)
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |    x     | "new"   |
    // ---------------------

    // intCell->setStringValue("9.9");
    // std:: cout << ob;
    // այս կետում աղյուսակն ունի այս տեսքը
    // ---------------------
    // | "hello"  | "3.14"  |
    // ---------------------
    // |   "99"   | "new"   |
    // ---------------------

    // std::cout << double(*(ob.getCell(1, 0))) << std::endl; // կտպի 99
    // std::cout << int(*intCell) << std::endl; // կտպի "99"
    //std::cout << ob.getCell(0, 0)->getIntValue() << std::endl; // runtime error, չի կոնվերտացվում "hello"-ն դեպի int

    Spreadsheet ob2;
    ob2.addRow(3);
    ob2.addColumn(4);
    ob2.setCell(0, 0, "x");
    ob2.setCell(0, 1, "y");
    ob2.setCell(1, 0, "z");
    ob2.setCell(1, 1, "5");
    ob2.setCell(0, 2, "Armenia");
    ob2.setCell(0, 3, "Tatev");
    ob2.setCell(1, 2, "London");
    ob2.setCell(1, 3, "C++");
    ob2.setCell(2, 2, "Paris");
    ob2.setCell(2, 0, "Yerevan");
    std::cout << ob2;

    Spreadsheet ob3;
    ob3 = ob + ob2;
    std::cout << ob3;
}