#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &src);
	Cat &operator=(const Cat &src);
	~Cat(void);

	void makeSound() const;
	void setIdea(size_t index, const std::string &idea);
	const std::string &getIdea(size_t index) const;

private:
	Brain *_brain;
};
#endif
