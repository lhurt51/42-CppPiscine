CC =	clang++

FLAG =	-Wall -Wextra -Werror

NAME =	replace

FILE =	*.replace

SRCS =	main.cpp \

FDIR =	frame/

OBJS =	$(addprefix $(FDIR), $(SRCS:.cpp=.o))

all: 	$(NAME)

frame:
		@mkdir $(FDIR)
		@echo "$(FDIR): has been created"

$(NAME): $(OBJS)
		@$(CC) $(FLAG) $(OBJS) -o $(NAME)
		@echo "$(NAME): has been created"

frame/%.o: %.cpp | frame
		@$(CC) $(FLAG) -c $< -o $@

clean:
		@rm -f $(OBJS)
		@rm -rf $(FDIR)
		@echo "$(FDIR) & $(OBJS): have been cleaned"

fclean:	clean
		@/bin/rm -f $(NAME)
		@/bin/rm -f $(FILE)
		@echo "$(NAME) & $(FILE): have been cleaned"

re: fclean all

.PHONY: all clean fclean re
