The default baud rate is 115200.

This code originated from here:
  https://www.wattsupmeters.com/forum/index.php?topic=8.0
This program is released under the GPLv2.

To compile the binary, type "make".

Sample usage is as follows:

./wattsup -c 1 ttyUSB0 watts

This will connect to WattsUp once and output the watt usage.

Here is a summary of command-line options:

----------------------------------------------------------------------

$ wattsup 
wattsup Version 0.03
  A program for interfacing with the Watts Up? Power Meter

Usage: wattsup [<options> ... ] <device> [ <values> ... ]

<device> is the serial port to which the device is connected.

<options> is any of the following:
  -h            | --help                    Display help text and exit
  -V            | --version                 Display version information and exit
  -d            | --debug                   Print out debugging messages
  -c <n>        | --count=<n>               Specify number of data samples
  -z            | --final                   Print final interval information
  -f <str>      | --delim=<str>             Set field delimiter (default ", ")
  -n            | --newline                 Use '\n' as delimter instead
  -t            | --localtime               Print localtime with each data reading
  -g            | --gmtime                  Print GMT time with each data reading
  -l            | --label                   Show labels of each field
  -s            | --suppress                Suppress printing of the field description
  -b            | --calibrate               Print calibration parameters
  -r            | --header                  Print data field names (as read from device)
  -i [<n>]      | --interval[=<n>]          Get/Set sampling interval
  -m [<n>]      | --mode[=<n>]              Get/Set display mode
  -u [<str>]    | --user[=<str>]            Get/Set user parameters
  -a            | --show-all                Show all device parameters
  -N            | --no-data                 Don't read any data (just read device info)
  -S            | --set-only                Set parameters only (don't read them back)

<value> specifies which of these to print out (default: ALL)
       watts -- Watt Consumption
       volts -- Volts Consumption
        amps -- Amp Consumption
         kwh -- Average KWH
        cost -- Cost per watt
      mo-kwh -- Average monthly KWH
     mo-cost -- Monthly Cost
   max-watts -- Maxium Watts Consumed
   min-volts -- Maximum Volts Consumed
    max-amps -- Maximum Amps Consumed
   min-watts -- Minimum Watts Consumed
   max-volts -- Minimum Volts Consumed
    min-amps -- Minimum Amps Consumed
power-factor -- Ratio of Watts vs. Volt Amps
  duty-cycle -- Percent of the Time On vs. Time Off
 power-cycle -- Indication of power cycle
   frequency -- AC frequency (HZ)
          VA -- VA

----------------------------------------------------------------------

Examples:

 - Print header line and read all fields once per second:
wattsup ttyUSB0 -r -s

 - Read all fields once per second and print a label with each field:
wattsup ttyUSB0 -l

 - Test connection, but do not read measurements:
wattsub ttyUSB0 -N
