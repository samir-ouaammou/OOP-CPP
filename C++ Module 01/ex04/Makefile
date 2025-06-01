SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

TMPFILE = *.replace

NAME = SedIsForLosers

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

replace:
	$(RM) $(TMPFILE)
