#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "PhoneBook.class.hpp"
#include "utils.hpp"

int PhoneBook::cursor = 0;
int PhoneBook::Length = 0;

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int PhoneBook::getContactLength(void) const
{
	return (PhoneBook::Length);
}

void PhoneBook::addContact(Contact *contact)
{
	if (this->cursor >= PhoneBook::CAPACITY)
		this->cursor = 0;
	if (this->Length < PhoneBook::CAPACITY)
		this->Length++;
	this->contacts[this->cursor++] = *contact;
}

void PhoneBook::printfLine(std::string index, std::string firstName, std::string lastName, std::string nickname) const
{
	std::cout << "│"
			  << std::setw(10) << std::right << std::setfill(' ') << index << "║"
			  << std::setw(10) << std::right << std::setfill(' ') << firstName << "│"
			  << std::setw(10) << std::right << std::setfill(' ') << lastName << "│"
			  << std::setw(10) << std::right << std::setfill(' ') << nickname << "│"
			  << std::endl;
}

void PhoneBook::printfContactLine(int i, const Contact *sample) const
{
	if (!sample)
		return;

	std::stringstream ss;
	ss << i;
	std::string str = ss.str();
	printfLine(str, truncate(sample->getFirst_name()), truncate(sample->getLast_name()), truncate(sample->getNickname()));
}

void PhoneBook::displayContactOfIndex(int index) const
{
	if (index < 0 || index >= this->cursor)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	this->contacts[index].displayContact();
}

void PhoneBook::displayPhoneBook(void) const
{
	std::wcout.imbue(std::locale(""));
	std::cout << "╭──────────╥──────────┬──────────┬──────────╮" << std::endl;
	printfLine("index", "first name", "last name", "nickname");
	std::cout << "╞══════════╬══════════╪══════════╪══════════╡" << std::endl;
	for (int i = 0; i < PhoneBook::Length; i++)
	{
		printfContactLine(i, &(this->contacts[i]));
	}
	std::cout << "╰──────────╨──────────┴──────────┴──────────╯" << std::endl;
}
