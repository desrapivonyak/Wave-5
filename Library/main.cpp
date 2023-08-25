#include "Library.h"

int main() {
    int adminID = 22;
    Library library(1, adminID, "Yerevan", "library1@gmail.com");

    Library::Book book {"Animal Farm", "George Orwell", 123456789, 0};
    Library::Book anotherBook {"Murder on the Orient Express", "Agatha Christie", 987654321, 1};
    
    library.addBook(book);
    library.addBook(anotherBook);

    library.displayLibraryInfo();

    library.removeBook(book);

    library.displayLibraryInfo();

    return 0;
}
