#ifndef _BASE_HPP_
#define _BASE_HPP_

class Base
{
public:
	virtual ~Base();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif