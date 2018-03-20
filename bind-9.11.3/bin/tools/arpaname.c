/*
 * Copyright (C) 2009, 2015, 2016  Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/* $Id: arpaname.c,v 1.4 2009/10/27 03:05:33 marka Exp $ */

#include "config.h"

#include <isc/net.h>
#include <isc/print.h>

#include <stdio.h>

#define UNUSED(x) (void)(x)

int
main(int argc, char *argv[]) {
	unsigned char buf[16];
	int i;

	UNUSED(argc);

	while (argv[1]) {
		if (inet_pton(AF_INET6, argv[1], buf) == 1) {
			for (i = 15; i >= 0; i--)
				fprintf(stdout, "%X.%X.", buf[i] & 0xf,
					(buf[i] >> 4) & 0xf);
			fprintf(stdout, "IP6.ARPA\n");
			argv++;
			continue;
		}
		if (inet_pton(AF_INET, argv[1], buf) == 1) {
			fprintf(stdout, "%u.%u.%u.%u.IN-ADDR.ARPA\n",
				buf[3], buf[2], buf[1], buf[0]);
			argv++;
			continue;
		}
		return (1);
	}
	fflush(stdout);
	return(ferror(stdout));
}
