##
## EPITECH PROJECT, 2019
## MiniLibC
## File description:
## Makefile
##

## USEFUL DEF ########################

CC			=	gcc
CCX			=	nasm
RM			=	-rm -f
BIN			=	libasm.so
TEST_BIN	=	unit_tests
EXT			=	.asm

#######################################

## Files ##############################

SRC_FILES	=	strlen	\
				strchr	\
				memset	\
				memcpy	\
				strcmp	\
				memmove	\
				strncmp	\
				strcasecmp	\
				rindex	\
				strstr	\
				strpbrk	\
				strcspn	\


#######################################

## Sources ############################

SRC			=	$(addsuffix $(EXT), $(addprefix src/, $(SRC_FILES)))	\

TEST_SRC		=	tests/tests_minilibc.c					\

#######################################

## OBJ ################################

SRC_OBJ		=	$(SRC:.asm=.o)

#######################################

## FLAGS ##############################

CFLAGS		=	-W -Wall -Wextra

CPPFLAGS    =	-nostdlib -shared -fPIC -fno-builtin

ASMFLAGS	=	-f elf64

LDFLAGS		=

#######################################

## RULES ##############################

%.o:    %.asm
	$(CCX) $(ASMFLAGS) -o $@ $<

%.o:    %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: all
all : $(BIN)
$(BIN): $(SRC_OBJ)
	$(CC) $(CPPFLAGS) $(SRC_OBJ) -o $(BIN)

.PHONY: clean
clean:
	@$(RM) $(BIN)
	@$(RM) $(SRC_OBJ)
	@$(RM) $(TESTS_OBJ)

.PHONY: fclean
fclean: clean
	@$(RM) $(TEST_BIN)
	@$(RM) **/*.gc*
	@$(RM) a.out

.PHONY: re
re: fclean clean all

.PHONY: tests_run
tests_run: 	ASMFLAGS += -DUNIT_TEST
tests_run: 	CFLAGS += --coverage -DUNIT_TEST
tests_run:	LDFLAGS += -lcriterion
tests_run:	re
	$(CC) -o $(TEST_BIN) $(TEST_SRC) $(SRC_OBJ) $(LDFLAGS)
	-./$(TEST_BIN)
	@$(RM) $(TEST_BIN)



#######################################
