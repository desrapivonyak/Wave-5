#include "Library.h"

#include <iostream>

int Library::m_totalBooks = 0;

Library::Library(const int libraryID, int& administratorID, const std::string& address, const std::string& contact)
        : m_libraryID {libraryID}
        , m_administratorID {administratorID}
        , m_address {address}
        , m_contact {contact}
        {}

Library::~Library() {
    m_totalBooks = 0;
}

int Library::getTotalBooks() {
    return m_totalBooks;
}

void Library::addBook(const Book& book) {
    m_books.push_back(book);
    m_totalBooks++;
}

void Library::removeBook(const Book& book) {
    int index {};
    for(int i = 0; i < m_books.size(); ++i) 
    {
        if(m_books[i].getISBN() == book.getISBN()) {
            index = i;
            break;
        }
    }
    m_books.erase(m_books.begin() + index);
    m_totalBooks--;   
}

void Library::dysplayBookInfo() const {
    for (auto book : m_books) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "ISBN: " << book.getISBN() << std::endl;
        std::cout << "Genre: " << Library::Book::getGenres()[book.getGenreIndex()] << std::endl;
    }
}

void Library::displayLibraryInfo() const {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Library ID: " << m_libraryID << std::endl;
    std::cout << "Administrator ID: " << m_administratorID << std::endl;
    std::cout << "Address: " << m_address << std::endl;
    std::cout << "Contact Info: " << m_contact << std::endl;
    std::cout << "Total Books: " << m_totalBooks << std::endl;
    std::cout << "Books info: " << std::endl;
    dysplayBookInfo();
}