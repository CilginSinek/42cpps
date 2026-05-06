#ifndef _RPN_HPP_
#define _RPN_HPP_

#include <stack>
#include <list>
#include <cstddef>

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void pushNumber(int num);
	void calculate(char myOperator);
	size_t size() const;
	int top() const;

private:
	std::stack<int, std::list<int> > data;
};

#endif