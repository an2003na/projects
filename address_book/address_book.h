#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


struct Contact
{
	std::string f_name;
	std::string l_name;
	std::string p_number;
	std::string email;
};


void display_menu();
void display_contact(const Contact&);
void display_contacts(const std::vector<Contact>&);
bool is_valid_email(const std::string&);
bool is_valid_phone_number(const std::string&);
Contact input_contact();
void add_contact(std::vector<Contact>&);
void save_contact_to_file(const std::vector<Contact>&, const std::string&);
void load_contact_from_file(std::vector<Contact>&, const std::string&);
void search_contact(const std::vector<Contact>&, const std::string&);
void remove_contact(std::vector<Contact>&);
void update_contact(std::vector<Contact>&);
void make_choise(std::vector<Contact>&, const std::string&);


#endif
