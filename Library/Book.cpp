#include "Library.h"

#include <iostream>

std::vector<std::string> Library::Book::m_genres {"Novel", "Mystery"};

std::vector<std::string> Library::Book::getGenres() {
    return m_genres;
}

void Library::Book::addGenre(const std::string& genre) {
    m_genres.push_back(genre);
}

Library::Book::Book(const std::string& title, const std::string& author, const unsigned int ISBN, const unsigned int genreIndex)
    : m_title {title}
    , m_author {author}
    , m_ISBN {ISBN}
    , m_genreIndex {genreIndex} 
{
}

std::string Library::Book::getTitle() const {
    return m_title;
}

std::string Library::Book::getAuthor() const {
    return m_author;
}

unsigned int Library::Book::getISBN() const {
    return m_ISBN;
}

unsigned int Library::Book::getGenreIndex() const {
    return m_genreIndex;
}