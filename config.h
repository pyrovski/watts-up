#ifndef CONFIG_H
#define CONFIG_H

#include "wattsup_common.h"
#include "config.h"

extern const char * wu_version,
  *prog_name,
  *sysfs_path_start;

#define wu_num_options ARRAY_SIZE(wu_options)

extern struct wu_field wu_fields[];

#endif
