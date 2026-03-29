#include <iostream>

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    i = 1;
	while (i < argc) {
		int j = 0;
		while(argv[i][j] != 0)
		{
			char tmp = std::toupper(argv[i][j]);
			std::cout << tmp;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}