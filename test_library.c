/*
 *	wattsup - Program for controlling the Watts Up? Pro Device
 *
 *
 *	Copyright (c) 2005 Patrick Mochel
 *
 *	This program is released under the GPLv2
 *
 *
 *	Compiled with:
 *
 *	gcc -O2 -Wall -o wattsup wattsup.c 
 *
 */

#define _GNU_SOURCE

#include <unistd.h>

#include "util.h"
#include "wattsup_common.h"
#include "globals.h"

int main(int argc, char ** argv)
{
	int ret;
	int fd = 0;

	ret = parse_args(argc, argv);
	if (ret)
		return 0;

	/*
	 * Try to enable debugging early
	 */
	if ((ret = wu_check_store(wu_option_debug, 0)))
		goto Close;

	ret = open_device(wu_device, &fd);
	if (ret)
		return ret;

	dbg("%s: Open for business", wu_device);

	ret = setup_serial_device(fd);
	if (ret)
		goto Close;

	wu_clear(fd);

	wu_fd = fd;

	/*
	 * Set delimeter before we print out any fields.
	 */
	if ((ret = wu_check_store(wu_option_delim, fd)))
		goto Close;

	/*
	 * Ditto for 'label' and 'newline' flags.
	 */
	if ((ret = wu_check_store(wu_option_label, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_newline, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_suppress, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_localtime, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_gmtime, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_set_only, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_no_data, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_info_all, fd)))
		goto Close;


	/*
	 * Options to set device parameters.
	 */
	if ((ret = wu_check_store(wu_option_interval, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_mode, fd)))
		goto Close;

	if ((ret = wu_check_store(wu_option_user, fd)))
		goto Close;

	/*
	 * Check for options to print device info
	 */
	if (wu_info_all) {
		wu_show(wu_option_cal, fd);
		wu_show(wu_option_header, fd);
		wu_show(wu_option_interval, fd);
		wu_show(wu_option_mode, fd);
		wu_show(wu_option_user, fd);
	} else {
		wu_check_show(wu_option_cal, fd);
		wu_check_show(wu_option_header, fd);

		if (!wu_set_only) {
			wu_check_show(wu_option_interval, fd);
			wu_check_show(wu_option_mode, fd);
			wu_check_show(wu_option_user, fd);
		}
	}

	if (!wu_no_data) {

		if ((ret = wu_check_store(wu_option_count, fd)))
			goto Close;

		if ((ret = wu_check_store(wu_option_final, fd)))
			goto Close;

		if ((ret = wu_start_log()))
			goto Close;
	    
		wu_read_data(fd);
		
		wu_stop_log();
	}
Close:
	close(fd);
	return ret;
}


