DIRS = ch_date ch_movie ch_seat ch_theater pay_ticket view_res
.PHONY: clean

libfunc.a : ch_date.o ch_movie.o ch_seat.o ch_theater.o pay_ticket.o view_res.o
	ar -rv libfuncs.a ch_date/ch_date.o ch_movie/ch_movie.o ch_seat/ch_seat.o ch_theater/ch_theater.o pay_ticket/pay_ticket.o view_res/view_res.o

ch_date.o : ch_date/ch_date.c
	gcc -g -Wall -c ch_date/ch_date.c -o ch_date/ch_date.o

ch_movie.o : ch_movie/ch_movie.c
	gcc -g -Wall -c ch_movie/ch_movie.c -o ch_movie/ch_movie.o

ch_seat.o : ch_seat/ch_seat.c
	gcc -g -Wall -c ch_seat/ch_seat.c -o ch_seat/ch_seat.o

ch_theater.o : ch_theater/ch_theater.c
	gcc -g -Wall -c ch_theater/ch_theater.c -o ch_theater/ch_theater.o

pay_ticket.o : pay_ticket/pay_ticket.c
	gcc -g -Wall -c pay_ticket/pay_ticket.c -o pay_ticket/pay_ticket.o

view_res.o : view_res/view_res.c
	gcc -g -Wall -c view_res/view_res.c -o view_res/view_res.o

clean :
	@for d in $(DIRS); \
	do \
		rm $$d/$$d.o; \
	done 
	rm libfuncs.a
