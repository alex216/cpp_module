#include <stdint.h>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base *generate(void)
{
	Base *basePtr = NULL;

	std::srand(static_cast<unsigned int>(time(0)));
	int randomValue = std::rand() % 3;

	switch (randomValue)
	{
	case 0:
		basePtr = new A();
		break;
	case 1:
		basePtr = new B();
		break;
	case 2:
		basePtr = new C();
		break;
	default:
		basePtr = NULL;
	}
	return basePtr;
};

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

// using a pointer inside this function is forbidden
static void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Type A" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Type B" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Type C" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
	}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	Base *basePtr = generate();

	std::cout << "[pointer]\t";
	identify(basePtr);

	std::cout << "[reference]\t";
	identify(*basePtr);

	delete basePtr;
}
