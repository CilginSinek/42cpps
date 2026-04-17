#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();

	std::string filename = this->getName() + "_shrubbery";

	std::ofstream ofs(filename.c_str());
	if (!ofs)
	{
		throw std::runtime_error("Error: Could not create file " + this->getName() + "_shrubbery");
	}

	ofs << "          ______ ___\n";
	ofs << "        _(_____  )__)_\n";
	ofs << "       (________  ____)       @@@\n";
	ofs << "         (________)        @@@@@@@@\n";
	ofs << "                        @@@@@@@@@@@@@\n";
	ofs << "         @@@@@       @@@@@@@@@@@@@@@@@@\n";
	ofs << "       @@@@@@@@        @@@@@@@@@@@@@@@\n";
	ofs << "      @@@@@@@@@@@       @@@@@@@@@@@@@@@\n";
	ofs << "     @@@@@@@@@@@        @@@@@@@@@@@@@@@\n";
	ofs << "       @@@@@@@@@          @@@@@@@@@@@\n";
	ofs << "         @@@@@              @@@@@@@\n";
	ofs << "          ||\\._            _./| |\n";
	ofs << "          || \\ `-.______.-' / | |\n";
	ofs << "          ||  \\            /  | |\n";
	ofs << "          ||   `-._    _.-'   | |\n";
	ofs << "          ||       `--'       | |\n";
	ofs << "          ||                  | |\n";
	ofs << "    /|\\\\|\\|| /|||/\\\\|/||/|\\\\\\/| |\\\\||//|\n";
}