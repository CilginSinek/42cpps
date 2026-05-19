NAME=PmergeMe
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS=main.cpp PmergeMe.cpp
OBJS=$(SRCS:.cpp=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: re
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "` > sonuc.txt

.PHONY: all clean fclean re test