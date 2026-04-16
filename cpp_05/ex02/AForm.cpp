#include "AForm.hpp"
#include "Bureaucrat.hpp"

//* Constructors and Destructor
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (name.empty())
		throw InvalidNameException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_isSigned = other._isSigned;
		this->_gradeToSign = other._gradeToSign;
		this->_gradeToExecute = other._gradeToExecute;
	}
	std::cout << "Form Copy Assignment operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "Form Destructor called" << std::endl;
}

//* Getters

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

//* Sign

void AForm::beSigned(const Bureaucrat &b)
{
	if (this->_isSigned)
		throw FormSignException();
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

//* Exceptions

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *AForm::InvalidNameException::what() const throw()
{
	return "Invalid name!";
}

const char *AForm::FormSignException::what() const throw()
{
	return "Form is already signed!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

//* Overload of the insertion operator

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}