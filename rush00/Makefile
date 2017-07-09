CC =	clang++

FLAG =	-Wall -Wextra -Werror

LNC =	-lncurses

NAME =	ft_retro

SRCS =	main.cpp \
		Game.class.cpp \
		Actor.class.cpp \
		Vector.class.cpp \

FDIR =	frame/

OBJS =	$(addprefix $(FDIR), $(SRCS:.cpp=.o))

all: 	$(NAME)

frame:
		@mkdir $(FDIR)
		@echo "$(FDIR): has been created"

$(NAME): $(OBJS)
		@$(CC) $(FLAG) $(LNC) $(OBJS) -o $(NAME)
		@echo "$(NAME): has been created"

frame/%.o: %.cpp | frame
		@$(CC) $(FLAG) -c $< -o $@

clean:
		@rm -f $(OBJS)
		@rm -rf $(FDIR)
		@echo "$(FDIR) & $(OBJS): have been cleaned"

fclean:	clean
		@/bin/rm -f $(NAME)
		@echo "$(NAME): have been cleaned"

re: fclean all

.PHONY: all clean fclean re