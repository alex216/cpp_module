#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(Contact *contact);
	int getContactLength(void) const;
	void displayContactOfIndex(int index) const;
	void displayPhoneBook(void) const;

private:
	static int cursor;
	static int Length;
	static const int CAPACITY = 8;
	Contact contacts[CAPACITY];

	void printfLine(std::string index, std::string firstName, std::string lastName, std::string nickname) const;
	void printfContactLine(int i, const Contact *sample) const;
};

#endif
