#include "Library.h"

int main() {
    int adminID = 123;
    Library library(1, adminID, "123 Main St", "library@example.com");

    library.addBook("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "978-1234567890", 2);
    library.addBook("The Lord of the Rings", "J.R.R. Tolkien", "978-9876543210", 3);

    library.displayLibraryInfo();

    return 0;
}
