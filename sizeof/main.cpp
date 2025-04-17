#include <stdio.h>

#define SIZE_DAL_TEXT		(256)

typedef struct {
	unsigned int	ver_dal;
	unsigned int	ver_dnp;
	char			sz_model[SIZE_DAL_TEXT];
	char			sz_model_ex[SIZE_DAL_TEXT];
	char			sz_oem[SIZE_DAL_TEXT];
	char			sz_update_model[SIZE_DAL_TEXT];

	int				num_vin;
	int				num_ain;
	int				num_vout;
	int				num_aout;
	int				num_sensor;
	int				num_alarm_relay;	// relay nums in alarm
	int				num_alarm;
	int				num_hdd;
	int				num_board_hdd;
	int				ptz;
	int				rs232;
	int				buzzer;
	int				remocon;
	int				keypad;
	int				jog_shuttle;
	int				odd;
	int				eth1;
	int				ipc1;
	int				poe1;
	int				temp;
	int				rtc;				// 1:use rtc time sync periodically 0:use system time

	int				email_jpg;

	int				onvif_server;
	int				onvif_client;
	int				num_ipc;
	int				num_extra_ipc;
	int				ipc_channel_fix;	// if 1, ipc channel is fixed.. example num_ipc=1, only 0 channel support ipc

	int				num_user;
	int				sataPortNum;
	int				numPoe;
	int				sen_cam;			// if 1, sensor camera support
	bool			enableRtspBuf;
	bool			hasSpot;
	bool			hasHDSpot;
	bool			saveAppMem;
	bool			twoHdmi;			// support two hdmi.. HD+MAIN
	int				flip_ver;			// support VIN flip vertically

	int				num_va;
	int				num_va_region;
	int				num_va_line;

	int				raid_on;
} dal_caps_t;

static dal_caps_t l_dal_caps;


#if 1

int subfunc(dal_caps_t *caps)
{
	printf("sizeof(caps->sz_model_ex)=%ld\n", sizeof(caps->sz_model_ex));
	return 0;
}

int main(void)
{
	subfunc(&l_dal_caps);
	return 0;
}

#else
int main(void)
{
	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(short)=%ld\n", sizeof(short));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(long long)=%ld\n", sizeof(long long));

	puts("--");

	printf("sizeof(unsigned char)=%ld\n", sizeof(unsigned char));
	printf("sizeof(unsigned short)=%ld\n", sizeof(unsigned short));
	printf("sizeof(unsigned int)=%ld\n", sizeof(unsigned int));
	printf("sizeof(unsigned long)=%ld\n", sizeof(unsigned long));
	printf("sizeof(unsigned long long)=%ld\n", sizeof(unsigned long long));
}

#endif