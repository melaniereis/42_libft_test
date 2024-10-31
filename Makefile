#==============================================================================#
#                         TESTS FOR LIBFT PROJECT                               #
#==============================================================================#

NAME = functions_test
LIBFT_ARC = ../libft.a
EXEC = libft_tester.out

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                                #
#------------------------------------------------------------------------------#

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Styles
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis
CHECK = ✓
TEST = 🧪
BUILD = 🔨
ROCKET = 🚀
CLEAN = 🧹
SPARKLES = ✨
FOLDER = 📁

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                                 #
#------------------------------------------------------------------------------#

SRC_PATH = srcs_tests
BONUS_PATH = srcs_bonus_tests
LIBFT_PATH = ..
INC_PATH = .
BUILD_PATH = .build
HEADERS = ${INC_PATH}/test.h

SRCS = ${addprefix ${SRC_PATH}/, ft_isalpha_test.c ft_isdigit_test.c ft_isalnum_test.c \
    ft_isascii_test.c ft_isprint_test.c ft_strlen_test.c ft_memset_test.c \
    ft_bzero_test.c ft_memcpy_test.c ft_memmove_test.c ft_strlcpy_test.c ft_strlcat_test.c \
    ft_toupper_test.c ft_tolower_test.c ft_strchr_test.c ft_strrchr_test.c \
	ft_strncmp_test.c ft_memchr_test.c ft_memcmp_test.c ft_strnstr_test.c ft_atoi_test.c \
    ft_calloc_test.c ft_strdup_test.c ft_substr_test.c ft_strjoin_test.c ft_strtrim_test.c \
    ft_split_test.c ft_itoa_test.c ft_strmapi_test.c ft_striteri_test.c \
    ft_putchar_fd_test.c ft_putstr_fd_test.c ft_putendl_fd_test.c ft_putnbr_fd_test.c \
	main.c}
SRCS_BONUS = ${addprefix ${BONUS_PATH}/, ft_lstnew_test.c ft_lstadd_front_test.c \
    ft_lstsize_test.c ft_lstlast_test.c ft_lstadd_back_test.c ft_lstdelone_test.c \
    ft_lstclear_test.c ft_lstiter_test.c ft_lstmap_test.c main_bonus.c}
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                               #
#------------------------------------------------------------------------------#

CC = cc
CCFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L.. -lft
INC = -I ${INC_PATH}
RM = rm -fr
MKDIR_P = mkdir -p
MAKE = make -C
MAKE_BONUS = make bonus -C

#------------------------------------------------------------------------------#
#                            	       RULES                                      #
#------------------------------------------------------------------------------#

all: ${NAME}

${BUILD_PATH}:
	@printf "\n${BLUE}${BOLD}${FOLDER} Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"

${NAME}: ${BUILD_PATH} ${OBJS} ${LIBFT_ARC}
	@printf "\n${YELLOW}${BOLD}${BUILD} Building ${WHITE}${EXEC}${YELLOW}...${RESET}\n"
	@${CC} ${CCFLAGS} ${OBJS} ${LDFLAGS} -lbsd -o ${EXEC}
	@printf "${GREEN}${BOLD}${ROCKET} Test executable created successfully!${RESET}\n"

# Rule for compiling source files
${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling test: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${BONUS_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${PURPLE}${DIM}Compiling bonus test: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

# Ensure the libft.a is built
${LIBFT_ARC}:
	@printf "\n${BLUE}${BOLD}${BUILD} Building libft...${RESET}\n"
	@${MAKE} ${LIBFT_PATH}
	@printf "${GREEN}${BOLD}${CHECK} libft.a built successfully!${RESET}\n"

${LIBFT_ARC_BONUS}:
	@printf "\n${PURPLE}${BOLD}${BUILD} Building libft with bonus...${RESET}\n"
	@${MAKE_BONUS} ${LIBFT_PATH}
	@printf "${GREEN}${BOLD}${CHECK} libft.a with bonus built successfully!${RESET}\n"

bonus: ${BUILD_PATH} ${OBJS_BONUS} ${LIBFT_ARC_BONUS}
	@printf "\n${PURPLE}${BOLD}${SPARKLES} Building bonus tests...${RESET}\n"
	@${CC} ${CCFLAGS} ${OBJS_BONUS} ${LDFLAGS} -o ${EXEC}
	@printf "${GREEN}${BOLD}${ROCKET} Bonus test executable created successfully!${RESET}\n"
##  Cleaning Rules  ##

clean:
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning test objects...${RESET}\n"
	@${RM} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Test object files cleaned!${RESET}\n"

fclean: clean
	@printf "${YELLOW}${BOLD}${CLEAN} Removing test executable and build files...${RESET}\n"
	@${RM} ${EXEC}
	@${RM} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} All test files cleaned!${RESET}\n"

re: fclean all

.PHONY: all clean fclean re bonus
