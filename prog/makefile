DIRS = ch_date ch_movie ch_seat ch_theater pay_ticket view_res
INCLUDE = -I../include
OPT = -g -Wall
.PHONY: clean

libfunc.a : ch_date.o ch_movie.o ch_seat.o ch_theater.o pay_ticket.o view_res.o
	ar -rv libfuncs.a ch_date/ch_date.o ch_movie/ch_movie.o ch_seat/ch_seat.o ch_theater/ch_theater.o pay_ticket/pay_ticket.o view_res/view_res.o

ch_date.o : ch_date/ch_date.c
	gcc $(OPT) -c ch_date/ch_date.c -o ch_date/ch_date.o $(INCLUDE)

ch_movie.o : ch_movie/ch_movie.c
	gcc $(OPT) -c ch_movie/ch_movie.c -o ch_movie/ch_movie.o $(INCLUDE)

ch_seat.o : ch_seat/ch_seat.c
	gcc $(OPT) -c ch_seat/ch_seat.c -o ch_seat/ch_seat.o $(INCLUDE)

ch_theater.o : ch_theater/ch_theater.c
	gcc $(OPT) -c ch_theater/ch_theater.c -o ch_theater/ch_theater.o $(INCLUDE)

pay_ticket.o : pay_ticket/pay_ticket.c
	gcc $(OPT) -c pay_ticket/pay_ticket.c -o pay_ticket/pay_ticket.o $(INCLUDE)

view_res.o : view_res/view_res.c
	gcc $(OPT) -c view_res/view_res.c -o view_res/view_res.o $(INCLUDE)

clean :
	@for d in $(DIRS); \
	do \
		rm $$d/$$d.o; \
	done 
	rm libfuncs.a
