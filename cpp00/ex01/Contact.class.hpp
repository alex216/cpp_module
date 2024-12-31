#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

class Contact
{
public:
	Contact(void);
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
	~Contact(void);

	std::string getFirst_name(void) const;
	std::string getLast_name(void) const;
	std::string getNickname(void) const;
	std::string getPhone_number(void) const;
	std::string getDarkest_secret(void) const;

	void displayContact(void) const;
	bool isAnyEmpty(void) const;

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif
