#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

void    addToVector(const std::string &input, std::vector<int> &numbers)
{
    std::istringstream iss(input);
    std::string temp;

    while (iss >> temp)
    {
        long long   num = 0;

        for (size_t i = 0; i < temp.size(); i++)
        {
            if (temp[i] < '0' || temp[i] > '9' || num > 2147483647)
            {
                std::cerr << "Error: Invalid input: " << temp << std::endl;
                exit(1);
            }
            num = num * 10 + (temp[i] - '0');
        }

        bool isDuplicate = (std::find(numbers.begin(), numbers.end(), num) != numbers.end());
        if (isDuplicate)
        {
            std::cerr << "Error: Duplicate number found: " << num << std::endl;
            exit(1);
        }

        numbers.push_back(static_cast<int>(num));
    }
}

void    printVectorBefore(const std::vector<int> &numbers)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
}

void    printVectorAfter(const std::vector<int> &numbers)
{
    std::cout << "After: ";
    for (size_t i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;
}

void    printTiming(clock_t start, clock_t end, size_t size)
{
    std::cout << std::fixed << std::setprecision(5);
    double timeTaken = double(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << size << " elements with std::vector : " << static_cast<double>(timeTaken) << " us" << std::endl;
}

int binarySearch(const std::vector<int> &vector, int left, int right, int key)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (vector[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

void    mergeInsertionSort(std::vector<int> &vector)
{
    int n = vector.size();
    
    for (int i = 0; i < n / 2; i++)
    {
        if (vector[2 * i] > vector[2 * i + 1])
            std::swap(vector[2 * i], vector[2 * i + 1]);
    }

    for (int size = 2; size < n; size *= 2)
    {
        for (int i = 0; i < n; i += size)
        {
            int mid = std::min(i + size / 2, n);
            int end = std::min(i + size, n);
            std::vector<int> temp(end - i);
            int left = i, right = mid, k = 0;
            
            while (left < mid && right < end)
            {
                if (vector[left] <= vector[right])
                    temp[k++] = vector[left++];
                else
                    temp[k++] = vector[right++];
            }
            
            while (left < mid)
                temp[k++] = vector[left++];

            while (right < end)
                temp[k++] = vector[right++];
            
            for (int j = 0; j < k; ++j)
                vector[i + j] = temp[j];
        }
    }
    
    std::vector<int> sorted;
    for (int i = 0; i < n; i++)
    {
        int key = vector[i];
        int pos = binarySearch(sorted, 0, sorted.size(), key);
        sorted.insert(sorted.begin() + pos, key);
    }
    
    vector = sorted;
}

void    sortVector(std::vector<int> &numbers)
{
    mergeInsertionSort(numbers);
}

std::vector<int> jacobsthalSequence(int n)
{
    std::vector<int> sequence(n);
    sequence[0] = 0;
    if (n > 1)
    {
        sequence[1] = 1;
        for (int i = 2; i < n; i++)
            sequence[i] = sequence[i - 1] + 2 * sequence[i - 2];

    }
    return (sequence);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Please provide numbers as arguments." << std::endl;
        return (1);
    }

    std::string input;
    for (int i = 1; i < ac; i++)
        input += av[i] + std::string(" ");

    std::vector<int> numbers;

    addToVector(input, numbers);

    printVectorBefore(numbers);

    clock_t start = clock();

    sortVector(numbers);

    clock_t end = clock();

    printVectorAfter(numbers);

    printTiming(start, end, numbers.size());

    int n = 10;
    std::vector<int> jSeq = jacobsthalSequence(n);
    std::cout << "Jacobsthal Sequence up to " << n << " terms: ";
    for (int i = 0; i < n; i++)
        std::cout << jSeq[i] << " ";
    std::cout << std::endl;

    return (0);
}
