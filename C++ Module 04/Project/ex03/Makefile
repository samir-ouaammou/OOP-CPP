SRC = main.cpp AMateria.cpp Cure.cpp  Ice.cpp Character.cpp MateriaSource.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Interface

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
