#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack()
        {
        }
        
        MutantStack(const MutantStack &copy) : std::stack<T>(copy)
        {
        }

        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            
            return (*this);
        }

        ~MutantStack()
        {
        }

        typedef typename std::stack<T>::container_type::iterator    iterator;

        iterator    begin()
        {
            return (this->c.begin());
        }

        iterator    end()
        {
            return (this->c.end());
        }
};

#endif
