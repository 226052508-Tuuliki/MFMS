# Makefile for the MFMS project (ANSI C / C99, GCC)
#   make        -> builds the program "mfms"
#   make run    -> builds and runs it
#   make clean  -> removes the program
CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic
SRC    = main.c validation.c employees/employees.c budget/budget.c \
         supplier/suppliers.c assets/assets.c reports/reports.c

mfms: $(SRC)
	$(CC) $(CFLAGS) -o mfms $(SRC)

run: mfms
	./mfms

clean:
	rm -f mfms mfms.exe
