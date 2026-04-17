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
	if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
	{
		std::cout << "Intern couldn't create form: " << formName << std::endl;
		return form;
	}
	std::cout << "Intern creates " << *form << std::endl;
	return form;
}