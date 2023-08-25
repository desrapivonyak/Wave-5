#pragma once

#include <string>
#include <vector>

class Library {
public:
    class Book {
    public:
        Book(const std::string&, const std::string&, const int, const int);
        ~Book() = default;
        static void addGenre(const std::string&);
        static std::vector<std::string> getGenres();
        std::string getTitle() const;
        std::string getAuthor() const;
        int getISBN() const;
        int getGenreIndex() const;
    private:
        std::string m_title;
        std::string m_author;
        int m_ISBN;
        static std::vector<std::string> m_genres;
        int m_genreIndex;
    };

public:
    Library(const int, int&, const std::string&, const std::string&);
    ~Library();
    static int getTotalBooks();
    void addBook(const Book&);
    void removeBook(const Book&);
    void dysplayBookInfo() const;
    void displayLibraryInfo() const;
private:
    static int m_totalBooks;
    const int m_libraryID;
    int& m_administratorID;
    std::string m_address;
    std::string m_contact;
    std::vector<Book> m_books;
};