#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include "sys/types.h"
#include "regex.h"


int read_reg(int phyid, int regid, int *phydata)
{
	int ret = phyid << 5 | regid;
	*phydata = ret;

	printf("phyid:%#x, regid:%#x : ret = %#x\n", phyid, regid, ret);
	return 0;
}

int get_addr(int reg)
{
	int phyid = (reg >> 5) & 0x07;
	int regid = reg & 0x1f;

	printf("reg=%#x: phyid = %#x, regid = %#x(%d)\n", reg, phyid, regid, regid);
	return 0;
}

int main(int argc, char *argv[])
{
	int phydata = 0;

	read_reg(0x07, 0x08, &phydata);
	read_reg(0x08, 0x02, &phydata);
	read_reg(0x02, 0x1f, &phydata);

	puts("====================================");

	get_addr(0x40);
	get_addr(0xd9);
	get_addr(0xdb);

	puts("====================================");

	read_reg(0x02, 0x00, &phydata);
	read_reg(0x06, 0x19, &phydata);



	return 0;
}
