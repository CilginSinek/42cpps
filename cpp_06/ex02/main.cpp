#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base *base = new A();
	identify(base);
	identify(*base);
	delete base;

	base = new B();
	identify(base);
	identify(*base);
	delete base;

	base = new C();
	identify(base);
	identify(*base);
	delete base;

	base = new Base();
	identify(base);
	identify(*base);
	delete base;

	std::cout << "Generating random instances:" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		Base *randomBase = generate();
		identify(randomBase);
		identify(*randomBase);
		delete randomBase;
	}

	return 0;
}