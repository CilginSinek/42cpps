#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat b1("Recep", 1);
	Bureaucrat b2("Sinek", 150);

	Intern intern;
	AForm *form1 = intern.makeForm("shrubbery creation", "home");
	AForm *form2 = intern.makeForm("robotomy request", "pool");
	AForm *form3 = intern.makeForm("presidential pardon", "prison");
	AForm *form4 = intern.makeForm("invalid form", "target");
	if (form1)
	{
		b1.signForm(*form1);
		b1.executeForm(*form1);
	}
	if (form2)
	{
		b1.signForm(*form2);
		b1.executeForm(*form2);
	}
	if (form3)
	{
		b1.signForm(*form3);
		b1.executeForm(*form3);
	}
	if (form4)
	{
		b1.signForm(*form4);
		b1.executeForm(*form4);
	}
	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return 0;
}
