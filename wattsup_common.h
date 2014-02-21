#ifndef WATTSUP_COMMON_H
#define WATTSUP_COMMON_H

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define wu_strlen	256
#define wu_num_fields	18
#define wu_param_len	16

struct wu_packet {
	unsigned int	cmd;
	unsigned int	sub_cmd;
	unsigned int	count;
	char	buf[wu_strlen];
	int	len;
	char	* field[wu_num_fields];
	char	* label[wu_num_fields];
};


struct wu_data {
	unsigned int	watts;
	unsigned int	volts;
	unsigned int	amps;
	unsigned int	watt_hours;

	unsigned int	cost;
	unsigned int	mo_kWh;
	unsigned int	mo_cost;
	unsigned int	max_watts;

	unsigned int	max_volts;
	unsigned int	max_amps;
	unsigned int	min_watts;
	unsigned int	min_volts;

	unsigned int	min_amps;
	unsigned int	power_factor;
	unsigned int	duty_cycle;
	unsigned int	power_cycle;
	
	unsigned int	frequency;
	unsigned int	VA;
};

struct wu_option {
	char	* longopt;
	int	shortopt;
	int	param;
	int	flag;
	char	* value;

	char	* descr;
	char	* option;
	char	* format;

	int	(*show)(int dev_fd);
	int	(*store)(int dev_fd);
};

enum {
	wu_option_help = 0,
	wu_option_version,

	wu_option_debug,

	wu_option_count,
	wu_option_final,

	wu_option_delim,
	wu_option_newline,
	wu_option_localtime,
	wu_option_gmtime,
	wu_option_label,

	wu_option_suppress,

	wu_option_cal,
	wu_option_header,

	wu_option_interval,
	wu_option_mode,
	wu_option_user,

	wu_option_info_all,
	wu_option_no_data,
	wu_option_set_only,
};

enum {
	wu_field_watts		= 0,
	wu_field_volts,
	wu_field_amps,

	wu_field_watt_hours,
	wu_field_cost,
	wu_field_mo_kwh,
	wu_field_mo_cost,

	wu_field_max_watts,
	wu_field_max_volts,
	wu_field_max_amps,

	wu_field_min_watts,
	wu_field_min_volts,
	wu_field_min_amps,

	wu_field_power_factor,
	wu_field_duty_cycle,
	wu_field_power_cycle,

	wu_field_frequency,
	wu_field_va
};

struct wu_field {
	unsigned int	enable;
	char		* name;
	char		* descr;
};

#endif
