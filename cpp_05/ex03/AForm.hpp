#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include <iostream>

class Bureaucrat;

class AForm
{
protected:
	std::string _name;
	bool _isSigned;
	int _gradeToSign;
	int _gradeToExecute;
public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	//* Getters
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//* Form methods
	void beSigned(const Bureaucrat &b);
	virtual void execute(const Bureaucrat &executor) const = 0;

	//* Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class InvalidNameException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormSignException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif