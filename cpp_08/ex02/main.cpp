#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "--------Stack test----------" << std::endl;
	std::stack<int> s;
	s.push(5);
	s.push(17);
	std::cout << "top: " << s.top() << std::endl;
	s.pop();
	std::cout << "size: " << s.size() << std::endl;
	s.push(3);
	s.push(5);
	s.push(737);
	//[...]
	s.push(0);
	while(!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "--------List Test----------" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	return 0;
}
