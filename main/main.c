#include "../include/info.h"

int main(void)
{
	ch_movie(movie_name, CNT, &msel);
	ch_theater(theater, &tsel);
	ch_date(&year, &month, &day);
	ch_seat(&mrow, &mcol);
	payment(movie_name, msel, mcol, mrow, ticket, ccost);
	view_res();

	return 0;
}
