#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern Copy Assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	AForm *form = NULL;
	int i = 0;
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	while (i < 3)
	{
		if (formName == formNames[i])
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << *form << std::endl;
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << *form << std::endl;
		break;
	case 2:
		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << *form << std::endl;
		break;
	default:
		std::cout << "Intern cannot create " << formName << " because it is an invalid form name" << std::endl;
		break;
	}
	return form;
}