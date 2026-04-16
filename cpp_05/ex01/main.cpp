#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat b1("Recep", 1);
		Form f1("Form1", 20, 30);

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		b1.executeForm(f1); // Should fail because the form is not signed
		b1.signForm(f1);	// Should succeed
		b1.executeForm(f1); // Should succeed
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try
	{
		Bureaucrat b1("Sinek", 150);
		Form f1("Form1", 20, 30);

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		b1.executeForm(f1); // Should fail because the form is not signed
		b1.signForm(f1);	// Should fail because the bureaucrat's grade is too low
		b1.executeForm(f1); // Should fail because the form is not signed
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
