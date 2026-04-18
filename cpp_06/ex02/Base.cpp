#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>

Base::~Base()
{
}

static unsigned long djb2(const char* str) {
    unsigned long hash = 5381;
    while (*str)
        hash = hash * 33 ^ (unsigned char)*str++;
    return hash;
}

static unsigned int getSeed()
{
	char buf[1024] = {0};
	unsigned int seed;
	FILE* f = popen("curl -sf --max-time 5 -H \"Accept: text/plain\"  https://icanhazdadjoke.com/", "r");
	if (f)
	{
		fread(buf, 1, sizeof(buf) - 1, f);
		pclose(f);
	}
	
	if(std::strlen(buf) > 0)
	{
		seed = djb2(buf);
	}
	else
	{
		seed = static_cast<unsigned int>(std::time(NULL));
	}
	return seed;
}

Base *generate(void)
{
	srand(getSeed());
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if(dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}