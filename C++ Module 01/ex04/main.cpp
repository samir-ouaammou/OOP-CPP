# include <iostream>
# include <fstream>
# include <string>

int main(int ac, char **av)
{
    std::string    filename;
    std::string    s1;
    std::string    s2;

    if (ac != 4)
    {
        std::cout << "Error: invalid number of arguments." << std::endl;
        std::cout << "Usage: ./program_name <filename> <string_to_replace> <replacement_string>" << std::endl;
        return (1);
    }
    filename = av[1];
    s1 = av[2];
    s2 = av[3];
    std::fstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Error: could not open input file." << std::endl;
        return (1);
    }
    if (s1.empty())
    {
        std::cout << "Error: string to replace (s1) cannot be empty." << std::endl;
        return (1);
    }
    return (0);
}