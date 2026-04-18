#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if(argc == 1)
		return 0;
	int i = 1;
	while(i < argc)
	{
		ScalarConverter::convert(argv[i]);
		i++;
	}
	return 0;
}
