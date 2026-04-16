#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat b1("Recep", 1);
	Bureaucrat b2("Sinek", 150);

	PresidentialPardonForm f1("Zehra");
	RobotomyRequestForm f2("Rumeysa");
	ShrubberyCreationForm f3("Ada");
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	b1.signForm(f1);
	b1.signForm(f2);
	b1.signForm(f3);
	b2.signForm(f1);
	b2.signForm(f2);
	b2.signForm(f3);
	b1.executeForm(f1);
	b1.executeForm(f2);
	b1.executeForm(f3);
	b2.executeForm(f1);
	b2.executeForm(f2);
	b2.executeForm(f3);
	return 0;
}
