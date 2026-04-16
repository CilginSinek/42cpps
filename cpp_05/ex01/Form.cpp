#include "Form.hpp"
#include "Bureaucrat.hpp"

//* Constructors and Destructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (name.empty())
		throw InvalidNameException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToExecute < gradeToSign)
		throw GradeTooHighException();
	std::cout << "Form Parameterized constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
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

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

//* Getters

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->_isSigned)
		throw FormSignException();
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void Form::execute(const Bureaucrat &executor) const
{
	if (!this->_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
}

//* Exceptions

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char *Form::InvalidNameException::what() const throw()
{
	return "Invalid name!";
}

const char *Form::FormSignException::what() const throw()
{
	return "Form is already signed!";
}

const char *Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

//* Overload of the insertion operator

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}