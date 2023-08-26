#include "address_book.h"


//The function displays the menu
void display_menu()
{
	std::cout << "Address Book Menu!\n"
		<< "1. Add contact\n"
		<< "2. Update contact\n"
		<< "3. See contacts\n"
		<< "4. Remove contact\n"
		<< "5. Search contacts\n"
		<< "6. Exit\n"
		<< "Choose one 1-6: ";
}


//The function prints one contact to the screen
void display_contact(const Contact& contact)
{
	std::cout << "Name: " << contact.f_name << " " << contact.l_name
		<< "\nPhone number: " << contact.p_number
		<< "\nEmail: " << contact.email;
}


//The function prints all contacts to the screen
void display_contacts(const std::vector<Contact>& contacts)
{
	if (contacts.empty ()) {
		std::cout << "Contacts not found!";
	} else {
		std::cout << "All contacts: \n";
		for (const auto& con : contacts) {
			display_contact (con);
			std::cout << std::endl;
		}
	}
}


//The function checks the validation of email
bool is_valid_email(const std::string& email)
{
	if  (email.find ("@") != std::string::npos) {
		return true;
	}
	return false;
}


//The function checks the validation of phone number
bool is_valid_phone_number(const std::string& number)
{
	for (char c : number) {
		if (!std::isdigit (c)) {
			return false;
		}
	}
	return number.size () == 9; 
}


//The function takes information from user
Contact input_contact()
{
	Contact con;
	std::cout << "Enter the name: ";
	std::cin >> con.f_name;
	std::cout << "Enter the last-name: ";
	std::cin >> con.l_name;
	do {
		std::cout << "Enter the phone number: ";
		std::cin >> con.p_number;
	} while (!is_valid_phone_number (con.p_number));
	do {
		std::cout << "Enter the email: ";
		std::cin >> con.email;
	} while (!is_valid_email (con.email));
	return con;
}


//The function adds contact from input to vector
void add_contact(std::vector<Contact>& contacts)
{
	Contact con = input_contact ();
	contacts.push_back (con);
}


//The function loads contacts to file
void save_contact_to_file(const std::vector<Contact>& contacts, const std::string& filename)
{
	std::ofstream file (filename);
	if (file.is_open ()) {
		for (const auto& cont : contacts) {
		file << cont.f_name << "," << cont.l_name << ","
			<<cont.p_number << "," << cont.email << "\n";
		}
		file.close ();
	}
}


//The function loads contacts from file
void load_contact_from_file(std::vector<Contact>& contacts, const std::string& filename)
{
	std::ifstream file (filename);
	if (file.is_open ()) {
		std::string line;
		contacts.clear ();
		while (std::getline (file, line)) {
			Contact cont;
			size_t len = 0;
			len = line.find (',');
			cont.f_name = line.substr (0, len);
			line.erase (0, len + 1); //len+1 for deleting ',' symbol
			len = line.find (',');
			cont.l_name = line.substr (0, len);
			line.erase (0, len + 1);
			len = line.find (',');
			cont.p_number = line.substr (0, len);
			line.erase (0, len + 1);
			cont.email = line;
			contacts.push_back (cont);
		}
		file.close ();
	}
	
}


//The function searches contact by input data
void search_contact(const std::vector<Contact>& contacts, const std::string& str)
{
	bool bl = false;
	for (const auto& con : contacts) {
		if (con.f_name.find (str) != std::string::npos ||
		    con.l_name.find (str) != std::string::npos ||
		    con.p_number.find (str) != std::string::npos ||
		    con.email.find (str) != std::string::npos) {
			display_contact (con);
			bl = true;
		}
	}
	if (!bl) {
		std::cout << "Can't found contacts by given string!\n";
	}
}


//The function removes contact by phone number
void remove_contact(std::vector<Contact>& contacts)
{
	if (contacts.empty ()) {
		std::cout << "Contacts not found.\n";
	} else {
		std::cout << "Enter the phone number of contact for deleting it: ";
		std::string number;
		std::cin >> number;
		size_t size = 0;
		for (auto& cont : contacts) {
			if (cont.p_number == number) {
				contacts.erase (contacts.begin () + size);
				std::cout << "Contact deleted!\n";
				return;
			}
			size++;
		}
		std::cout << "Invalid phone number!\n";
	}
}


//The function updates contacts by index
void update_contact(std::vector<Contact>& contacts)
{
	if (contacts.empty ()) {
		std::cout << "Contacts not found.\n";
	} else {
		std::cout << "Enter the index of contact for updateing it: ";
		int index = 0;
		std::cin >> index;
			if (index < contacts.size () && index >= 0) {
				contacts[index] = input_contact ();
				std::cout << "Contact updated!\n";
			} else {
				std::cout << "Invalid index!\n";
		}
	}
}



void make_choise(std::vector<Contact>& contacts, const std::string& filename) {
	//if choise isn't a number => infinite loop
	int choise{};
	std::string str;
	do {
		display_menu ();
		std::cin >> choise;
		switch (choise) {
			case 1://Add contact
				add_contact (contacts);
				save_contact_to_file (contacts, filename);
				break;
			case 2://Update contact
		        	update_contact (contacts);
			        save_contact_to_file (contacts, filename);
				break;
			case 3://See contacts
				display_contacts (contacts);
				break;
			case 4://Remove contact
				remove_contact (contacts);
				save_contact_to_file (contacts, filename);
				break;
			case 5://Search contacts
			       	std::cout << "Enter the string for searching: ";
				std::cin >> str;
				search_contact (contacts, str);
				break;
			case 6://Exit
				save_contact_to_file (contacts, filename);
				std::cout << "Exiting address book!!!\n";
				return;
			default:
			//	std::cout << "Invalid choise!\n";
				break;
		}
		if (choise < 1 || choise > 6) {
			std::cout << "Invalid choise! Try again.\n";
		}
	} while (choise != 6);
}

