#ifndef __INFO_H_
#define __INFO_H_

#define CNT	5

void ch_movie();
void ch_date();
void seat_sel();
void ch_theater();

void display_card();
int pay_ticket();
void payment();

void view_res();

//ch_movie
char *movie_name[CNT] = {"Suicide Squad", "Harry Potter", "Gravity", "Inception", "interstellar"};
int msel;

//ch_date
char date[13];
int year;
int month;
int day;

//ch_theater
char *theater[6] = { "Ilsan", "Hwajeong", "Guri", "Gimpo", "Bucheon", "Pangyo" };

//ch_seat
int mrow;
int mcol;

//pay_ticket
int ticket = 6000;
int ccost;


#endif
