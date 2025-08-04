# Nom de la bibliothèque
NAME = libft.a

# Options de compilation
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
RM = rm -f

# Liste des fichiers source
SRCS = ft_calloc.c   ft_isascii.c  ft_itoa.c    ft_memcpy.c   ft_putchar_fd.c  ft_putstr_fd.c  ft_strdup.c    ft_strlcat.c  ft_strmapi.c  ft_strrchr.c  ft_tolower.c \
       ft_atoi.c     ft_isalnum.c  ft_isdigit.c  ft_memchr.c   ft_memmove.c  ft_putendl_fd.c  ft_split.c      ft_striteri.c  ft_strlcpy.c  ft_strncmp.c  ft_strtrim.c  ft_toupper.c \
       ft_bzero.c    ft_isalpha.c  ft_isprint.c  ft_memcmp.c   ft_memset.c   ft_putnbr_fd.c   ft_strchr.c     ft_strjoin.c   ft_strlen.c   ft_strnstr.c  ft_substr.c \
	   gnl.c         gnl_utils.c   ft_is_space.c ft_strtod.c	printf_fd.c 

# Les fichiers objets correspondants
OBJS = ft_calloc.o   ft_isascii.o  ft_itoa.o    ft_memcpy.o   ft_putchar_fd.o  ft_putstr_fd.o  ft_strdup.o    ft_strlcat.o  ft_strmapi.o  ft_strrchr.o  ft_tolower.o \
       ft_atoi.o     ft_isalnum.o  ft_isdigit.o  ft_memchr.o   ft_memmove.o  ft_putendl_fd.o  ft_split.o      ft_striteri.o  ft_strlcpy.o  ft_strncmp.o  ft_strtrim.o  ft_toupper.o \
       ft_bzero.o    ft_isalpha.o  ft_isprint.o  ft_memcmp.o   ft_memset.o   ft_putnbr_fd.o   ft_strchr.o     ft_strjoin.o   ft_strlen.o   ft_strnstr.o  ft_substr.o \
	   gnl.o         gnl_utils.o   ft_is_space.o ft_strtod.o	printf_fd.o 

# Règle par défaut, créer la bibliothèque
all: $(NAME)

# Règle pour créer la bibliothèque statique
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Règle pour compiler les fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	@$(RM) $(OBJS)

# Règle pour nettoyer les fichiers objets et la bibliothèque
fclean: clean
	@$(RM) $(NAME)

# Règle pour tout nettoyer et recompiler
re: fclean all

# Spécifie que certaines cibles ne sont pas des fichiers réels
.PHONY: all clean fclean re

