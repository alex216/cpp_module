#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	static const size_t MAX_IDEAS = 100;
	std::string _ideas[MAX_IDEAS];

public:
	Brain(void);
	Brain(const Brain &src);			// copy constructor
	Brain &operator=(const Brain &src); // copy assignment operator
	~Brain(void);

	void setIdeaInIndex(size_t index, std::string idea);
	const std::string &getIdeaInIndex(size_t index) const;
};
#endif
