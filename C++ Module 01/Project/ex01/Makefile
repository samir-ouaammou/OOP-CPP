SRC = main.cpp  newZombie.cpp  randomChump.cpp  Zombie.cpp  zombieHorde.cpp

OBJ = $(SRC:.cpp=.o)

NAME = MoarBrainz

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
