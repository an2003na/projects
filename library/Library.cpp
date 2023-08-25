#include "Library.h"


// Constructor for the Book class
Library::Book::Book(const std::string& title, const std::string& author, const std::string& ISBN, int genreIndex)
    : title(title), author(author), ISBN(ISBN), genreIndex(genreIndex) {
    totalBooks++;
}


// Destructor for the Book class
Library::Book::~Book() {
    totalBooks--;
}


// operator== overloading for the Book class
bool Library::Book::operator==(const Book& other) const {
    return title == other.title && author == other.author && ISBN == other.ISBN && genreIndex == other.genreIndex;
}


// Initializing static member genres for the Book class
std::vector<std::string> Library::Book::genres = {"Mystery", "Science Fiction", "Fantasy", "Thriller", "Romance"};


// Initializing static members for the Library class
int Library::totalBooks = 0;


// Constructor for the Library class
Library::Library(int libraryID, int& administratorID, const std::string& address, const std::string& contactInfo)
    : libraryID(libraryID), administratorID(administratorID), address(address), contactInfo(contactInfo) {
    totalBooks = 0;
}


// Destructor for the Library class
Library::~Library() {
    totalBooks -= books.size();
}


// Static method to get the total number of books
int Library::getTotalBooks() {
    return totalBooks;
}


// Method to display library information
void Library::displayLibraryInfo() const {
    std::cout << "Library ID: " << libraryID << std::endl;
    std::cout << "Administrator ID: " << administratorID << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Contact Info: " << contactInfo << std::endl;
    std::cout << "Total Books: " << totalBooks << std::endl;
}


// Method to add a book to the library
void Library::addBook(const std::string& title, const std::string& author, const std::string& ISBN, int genreIndex) {
    books.emplace_back(title, author, ISBN, genreIndex);
}


// Method to remove a book from the library
void Library::removeBook(const Book& book) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (*it == book) {
            books.erase(it);
            break;
        }
    }
}
