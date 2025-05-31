#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty." << std::endl;
        return (1);
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return (1);
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile)
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        inputFile.close();
        return (1);
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            result += line.substr(pos, found - pos);
            result += s2;
            pos = found + s1.length();
        }
        result += line.substr(pos);

        outputFile << result << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return (0);
}
