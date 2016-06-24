
/* Example application of Columbo Simple Serial Library
 * Copyright 2003 Marcin Siennicki <m.siennicki@cloos.pl>
 * see COPYING file for details */

#include <stdio.h>
#include <unistd.h>

#include "cssl.h"


/* if it is time to finish */
static int finished=0;


/* example callback, it gets its id, buffer, and buffer length */
static void callback(int id,
		uint8_t *buf,
		int length)
{
	int i;

	for(i=0;i<length;i++) {

		switch (buf[i]) {

			case 0x04:  /* Ctrl-D */
				finished=1;
				return;

			case '\r': /* replace \r with \n */
				buf[i]='\n';

		}

		putchar(buf[i]);
	}

	fflush(stdout);
}


int main()
{
	cssl_t *serial;

	cssl_start();

	printf("=====%d=====\n", __LINE__);
	serial=cssl_open("/dev/ttymxc1",callback,0, 38400,8,0,1);
	printf("=====%d=====\n", __LINE__);

	if (!serial) {
		printf("%s\n",cssl_geterrormsg());
		return -1;
	}

	cssl_putstring(serial,"Type some data, ^D finishes.");
	printf("=====%d=====\n", __LINE__);

	while (!finished)
		pause();
	printf("=====%d=====\n", __LINE__);

	printf("\n^D - we exit\n");

	cssl_close(serial);
	cssl_stop();

	return 0;
}
