#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define FNAME   "tmp.txt"
#define MAX_CHAR	256

#define MAX_LINE		17
char *data[MAX_LINE] = {
	"  1 Raw_Read_Error_Rate     0x002f   200   200   051    Pre-fail  Always       -       0",
	"  3 Spin_Up_Time            0x0027   140   131   021    Pre-fail  Always       -       3958",
	"  4 Start_Stop_Count        0x0032   100   100   000    Old_age   Always       -       184",
	"  5 Reallocated_Sector_Ct   0x0033   200   200   140    Pre-fail  Always       -       0",
	"  7 Seek_Error_Rate         0x002e   200   200   000    Old_age   Always       -       0",
	"  9 Power_On_Hours          0x0032   057   057   000    Old_age   Always       -       31754",
	" 10 Spin_Retry_Count        0x0032   100   100   000    Old_age   Always       -       0",
	" 11 Calibration_Retry_Count 0x0032   100   100   000    Old_age   Always       -       0",
	" 12 Power_Cycle_Count       0x0032   100   100   000    Old_age   Always       -       184",
	"192 Power-Off_Retract_Count 0x0032   200   200   000    Old_age   Always       -       167",
	"193 Load_Cycle_Count        0x0032   200   200   000    Old_age   Always       -       17",
	"194 Temperature_Celsius     0x0022   116   103   000    Old_age   Always       -       27",
	"196 Reallocated_Event_Count 0x0032   200   200   000    Old_age   Always       -       0",
	"197 Current_Pending_Sector  0x0032   200   200   000    Old_age   Always       -       0",
	"198 Offline_Uncorrectable   0x0030   100   253   000    Old_age   Offline      -       0",
	"199 UDMA_CRC_Error_Count    0x0032   200   200   000    Old_age   Always       -       0",
	"200 Multi_Zone_Error_Rate   0x0008   100   253   000    Old_age   Offline      -       0"
};

/*

*/
int main(int argc, char *argv[])
{
	int i = 0;

	char id[4];
	char name[32];
	char flag[16];
	char value[16];
	char worst[16];
	char threshold[16];
	char type[16];
	char updated[16];
	char when_failed[16];
	char raw_value[16];

	while (data[i]) {
		sscanf(data[i], "%s %s %s %s %s %s %s %s %s %s", id, name, flag, value, worst, threshold, type, updated, when_failed, raw_value);
		printf("id='%3s', name='%-50s', flag='0x%04lx' ", id, name, strtol(flag, NULL, 16));
		// printf("value='%s', worst='%s', threshold='%s' ", value, worst, threshold);
		// printf("type='%s', updated='%s', when_failed='%s' ", type, updated, when_failed);
		printf("raw_value=%d\n", atoi(raw_value));
		i++;
	}


	return 0;
}