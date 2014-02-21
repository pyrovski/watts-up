#include "wattsup_common.h"

const char * wu_version = "0.03";

const char * prog_name = "wattsup";

const char * sysfs_path_start = "/sys/class/tty";

struct wu_field wu_fields[wu_num_fields] = {
	[wu_field_watts]	= {
		.name	= "watts",
		.descr	= "Watt Consumption",
	},

	[wu_field_min_watts]	= {
		.name	= "min-watts",
		.descr	= "Minimum Watts Consumed",
	},

	[wu_field_max_watts]	= {
		.name	= "max-watts",
		.descr	= "Maxium Watts Consumed",
	},

	[wu_field_volts]	= {
		.name	= "volts",
		.descr	= "Volts Consumption",
	},

	[wu_field_min_volts]	= {
		.name	= "max-volts",
		.descr	= "Minimum Volts Consumed",
	},

	[wu_field_max_volts]	= {
		.name	= "min-volts",
		.descr	= "Maximum Volts Consumed",
	},

	[wu_field_amps]		= {
		.name	= "amps",
		.descr	= "Amp Consumption",
	},

	[wu_field_min_amps]	= {
		.name	= "min-amps",
		.descr	= "Minimum Amps Consumed",
	},

	[wu_field_max_amps]	= {
		.name	= "max-amps",
		.descr	= "Maximum Amps Consumed",
	},

	[wu_field_watt_hours]	= {
		.name	= "kwh",
		.descr	= "Average KWH",
	},

	[wu_field_mo_kwh]	= {
		.name	= "mo-kwh",
		.descr	= "Average monthly KWH",
	},

	[wu_field_cost]		= {
		.name	= "cost",
		.descr	= "Cost per watt",
	},

	[wu_field_mo_cost]	= {
		.name	= "mo-cost",
		.descr	= "Monthly Cost",
	},

	[wu_field_power_factor]	= {
		.name	= "power-factor",
		.descr	= "Ratio of Watts vs. Volt Amps",
	},

	[wu_field_duty_cycle]	= {
		.name	= "duty-cycle",
		.descr	= "Percent of the Time On vs. Time Off",
	},

	[wu_field_power_cycle]	= {
		.name	= "power-cycle",
		.descr	= "Indication of power cycle",
	},

	[wu_field_frequency]	= {
		.name	= "frequency",
		.descr	= "AC frequency (HZ)",
	},

	[wu_field_va]	= {
		.name	= "VA",
		.descr	= "VA",
	},
};

