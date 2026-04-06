#include <iostream>
#include <bits/stdc++.h>

int main(int argc, char const *argv[])
{
    if(argc != 4)
    {
        std::cout << "Usage: ./program <filename> <char to replace> <char to replace with>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string to_replace = argv[2];
    std::string replace_with = argv[3];
    if(to_replace.length() != 1 || replace_with.length() != 1)
    {
        std::cout << "Error: <char to replace> and <char to replace with> must be single characters" << std::endl;
        return 1;
    }
    char to_replace_char = to_replace[0];
    char replace_with_char = replace_with[0];

    std::ifstream f(filename.c_str());

    if(!f.is_open())
    {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string output_filename = filename + ".replace";
    std::ofstream out(output_filename.c_str());
    if(!out.is_open())
    {
        std::cout << "Error: Could not create output file " << output_filename << std::endl;
        return 1;
    }

    std::string line;
    while(std::getline(f, line))
    {
        for(size_t i = 0; i < line.length(); i++)
        {
            if(line[i] == to_replace_char)
            {
                line[i] = replace_with_char;
            }
        }
        out << line << std::endl;
    }
    f.close();
    out.close();
    return 0;
}
