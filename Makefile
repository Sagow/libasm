SRCS_ASM =			ft_strlen.s		\
					ft_strcpy.s		\
					ft_strcmp.s		\
					ft_read.s		\
					ft_write.s		\
					ft_strdup.s

SRCS_TEST =			main.c

OBJS_ASM =			${SRCS_ASM:.s=.o}

OBJS_TEST =			${SRCS_TEST:.c=.o}

CC_ASM =			nasm

CC_TEST =			gcc

FLAGS_ASM =			-f elf64

FLAGS_TEST =		-m64 -g -std=c99

NAME =				libasm.a

NAME_TEST =			test

RM =				rm -f

%.o:		%.s
			$(CC_ASM) $(FLAGS_ASM) $<

.c.o :
			${CC_TEST} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS_ASM}
			ar rc ${NAME} ${OBJS_ASM}
			ranlib ${NAME}

all :		${NAME}

clean :
			${RM} ${OBJS_ASM}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

test :		all ${OBJS_TEST}
			${CC_TEST} -o ${NAME_TEST} ${OBJS_TEST} $(NAME) -g -Wall
			./${NAME_TEST}

.PHONY :	all clean fclean re test

