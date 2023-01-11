#include <time.h>
#include <stdio.h>


#define SECS_IN_MIN			(60)
#define SECS_IN_HOUR		(60*SECS_IN_MIN)
#define SECS_IN_DAY			(24*SECS_IN_HOUR)



int main(void)
{
/*
The <time.h> header shall declare the tm structure,
 which shall include at least the following members:
	int tm_sec;		// Seconds [0,60].
	int tm_min;		// Minutes [0,59].
	int tm_hour;	// Hour [0,23].
	int tm_mday;	// Day of month [1,31].
	int tm_mon;		// Month of year [0,11].
	int tm_year;	// Years since 1900.
	int tm_wday;	// Day of week [0,6] (Sunday =0).
	int tm_yday;	// Day of year [0,365].
	int tm_isdst;	// Daylight Savings flag.
*/
	struct tm rmtm, *p_tm;	
    time_t rmtime = time(NULL);

	// localtime_r(&rmtime, &rmtm);

	// p_tm = localtime(&rmtime);
	// printf("time_t=%lu, %s\n", rmtime, asctime(p_tm));

	rmtm.tm_year = 2022 - 1900;
	rmtm.tm_mon = 11 - 1;
	rmtm.tm_mday = 2;
	rmtm.tm_hour = 28200 / SECS_IN_HOUR;
	rmtm.tm_min = (28200 % SECS_IN_HOUR) /SECS_IN_MIN;
	rmtm.tm_sec = 28200 % SECS_IN_MIN;

	rmtime = mktime(&rmtm);

    printf("rmtime:%ld\n", rmtime);
	p_tm = localtime(&rmtime);
	printf("time_t=%lu, %s\n", rmtime, asctime(p_tm));



    return 0;
}