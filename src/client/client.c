/*******************************************************************************
 *	client.c
 *
 *  client main file
 *
 *
 *  This file is part of PSD-IMS
 * 
 *  Copyright (C) 2015  Daniel Pinto Rivero, Javier Bermúdez Blanco
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "psd_ims_client.h"
#include "client_graphic_v2.h"
#include "bool.h"

#ifdef DEBUG
#include "leak_detector_c.h"
#endif


int main( int argc, char **argv ) {

	if( argc < 2 ) {
		printf("Usage: %s <url>:<port>\n", argv[0]);
		return 0; 
	}

	// Initialize client
	psd_ims_client *client = psd_new_client();
	psd_bind_network(client, argv[1]);

	// TODO If posible, load info from local files


	// Run graphic client
	graphic_client_run(client);


	// free client
	psd_free_client(client);

	return 0;
}
