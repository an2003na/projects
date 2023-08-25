#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>

class Library {
public:
    class Book {
    public:
        Book(const std::string& title, const std::string& author, const std::string& ISBN, int genreIndex);
        ~Book();

        static std::vector<std::string> genres;

        bool operator==(const Book& other) const;

    private:
        std::string title;
        std::string author;
        std::string ISBN;
        int genreIndex;
    };

    Library(int libraryID, int& administratorID, const std::string& address, const std::string& contactInfo);
    ~Library();

    static int getTotalBooks();

    void displayLibraryInfo() const;
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN, int genreIndex);
    void removeBook(const Book& book);

private:
    int libraryID;
    int& administratorID;
    std::string address;
    std::string contactInfo;
    std::vector<Book> books;

    static int totalBooks;
};

#endif

