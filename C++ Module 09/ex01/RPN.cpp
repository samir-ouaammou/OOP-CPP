#include "RPN.hpp"

bool    isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void    checkInput(std::string &input)
{
    if (input.empty())
    {
        std::cerr << "Error: input is empty" << std::endl;
        exit(1);
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]) && !isspace(input[i]) && !isOperator(input[i]) && input[i] != '.')
        {
            std::cerr << "Error: invalid character in input: '" << input[i] << "'" << std::endl;
            exit(1);
        }
    }
}

void    calculatrice(std::string &input)
{
    std::stack<float> stack;
    std::istringstream stream(input);
    std::string token;

    while (stream >> token)
    {
        if (isdigit(token[0])) 
        {
            float value;
            std::istringstream ss(token);
            ss >> value;
            if (value < 0 || value > 9)
            {
                std::cerr << "Error: '" << token << "' is not valid. Numbers must be between 0 and 9." << std::endl;
                exit (1);
            }
            stack.push(value);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: not enough operands" << std::endl;
                exit(1);
            }

            float a;
            float b;

            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();

            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: division by zero" << std::endl;
                    exit(1);
                }
                stack.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error: invalid token" << std::endl;
            exit(1);
        }
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error: invalid expression" << std::endl;
        exit(1);
    }

    std::cout << stack.top() << std::endl;
}