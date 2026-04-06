#include "Harl.hpp"

int main(int argc, char const *argv[])
{
    Harl harl;
    int i = 1;
    if(argc == 1)
    {
        harl.complain("asdasdasd");
        return 0;
    }
    else
    {
        while(argv[i] != NULL)
        {
            harl.complain(argv[i]);
            i++;
        }
    }
    return 0;
}
