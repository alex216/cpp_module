#include <iostream>
#include <string>
#include <iomanip>
#include "PhoneBook.class.hpp"
#include "utils.hpp"

// enum
enum COMMAND
{
	ADD,
	SEARCH,
	EXIT,
	OTHERS
};

void add_command(PhoneBook &phonebook)
{
	std::string first_name = question("Enter first name: ");
	std::string last_name = question("Enter last name: ");
	std::string nickname = question("Enter nickname: ");
	std::string phone_number = question("Enter phone number: ");
	std::string darkest_secret = question("Enter darkest secret: ");

	Contact contact_info = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	if (contact_info.isAnyEmpty())
	{
		std::cout << "All fields are required" << std::endl;
		return;
	}
	phonebook.addContact(&contact_info);
	return;
}

void search_command(PhoneBook &phoneBook)
{
	if (phoneBook.getContactLength() == 0)
	{
		std::cout << "empty phonebook" << std::endl;
		return;
	}
	phoneBook.displayPhoneBook();

	std::string index_str = question("index? ");
	if (index_str.length() != 1 || !std::isdigit(index_str[0]))
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	int index = std::stoi(index_str);
	phoneBook.displayContactOfIndex(index);
}

COMMAND decipher(const std::string &input)
{
	if (input == "EXIT" || input == "E")
		return EXIT;
	else if (input == "ADD" || input == "A")
		return ADD;
	else if (input == "SEARCH" || input == "S")
		return SEARCH;
	return OTHERS;
}

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		err("Usage: ./phonebook");
	std::cout << "Welcome to the phonebook!" << std::endl;
	std::cout << "usage:	ADD" << std::endl;
	std::cout << "	SEARCH" << std::endl;
	std::cout << "	EXIT" << std::endl
			  << std::endl;

	PhoneBook phoneBook;
	while (1)
	{
		switch (decipher(question("> ")))
		{
		case EXIT:
			std::exit(0);
		case ADD:
			add_command(phoneBook);
			break;
		case SEARCH:
			search_command(phoneBook);
			break;
		default:
			break;
		}
	}
	return 0;
}
