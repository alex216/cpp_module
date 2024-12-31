#include <iostream>
#include "Contact.class.hpp"

Contact::Contact() {}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
	: first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string Contact::getFirst_name(void) const
{
	return (this->first_name);
}

std::string Contact::getLast_name(void) const
{
	return (this->last_name);
}

std::string Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string Contact::getPhone_number(void) const
{
	return (this->phone_number);
}

std::string Contact::getDarkest_secret(void) const
{
	return (this->darkest_secret);
}

void Contact::displayContact(void) const
{
	std::cout << "First name:\t" << this->getFirst_name() << std::endl;
	std::cout << "Last name:\t" << this->getLast_name() << std::endl;
	std::cout << "Nickname:\t" << this->getNickname() << std::endl;
	std::cout << "Phone number:\t" << this->getPhone_number() << std::endl;
	std::cout << "Darkest secret:\t" << this->getDarkest_secret() << std::endl;
}

bool Contact::isAnyEmpty(void) const
{
	return (this->first_name.empty() || this->last_name.empty() || this->nickname.empty() || this->phone_number.empty() || this->darkest_secret.empty());
}
