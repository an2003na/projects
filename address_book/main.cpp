#include "address_book.h"


int main()
{
	std::vector<Contact> contacts;
	const std::string file = "contacts.txt";
	load_contact_from_file (contacts, file);
	make_choise (contacts, file);
	return 0;
}
