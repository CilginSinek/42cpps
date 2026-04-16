#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("Recep", 1);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Sinek", 150);
		std::cout << b2 << std::endl;

		Bureaucrat b3("Junior Dev", 0); // This will throw GradeTooHighException
		std::cout << b3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b1("Sinek", 150);
		std::cout << b1 << std::endl;

		b1.setGrade(b1.getGrade() + 1); // This will throw GradeTooHighException
		std::cout << b1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
