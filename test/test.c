/*
 * test.c
 *
 * Main program for the libsysfs testsuite
 *
 * Copyright (C) IBM Corp. 2004
 *
 *      This program is free software; you can redistribute it and/or modify it
 *      under the terms of the GNU General Public License as published by the
 *      Free Software Foundation version 2 of the License.
 *
 *      This program is distributed in the hope that it will be useful, but
 *      WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/**
 * this doesn't do much, just loops throug to call each function.
 */

#include "test.h"
#include <errno.h>

/*************************************************/
char *function_name[] = {
	"sysfs_get_mnt_path",
	"sysfs_remove_trailing_slash",
	"sysfs_get_name_from_path",
	"sysfs_path_is_dir",
	"sysfs_path_is_link",
	"sysfs_path_is_file",
	"sysfs_get_link",
	"sysfs_open_subsystem_list",
	"sysfs_open_bus_devices_list",
	"sysfs_close_list",
	"sysfs_close_attribute",
	"sysfs_open_attribute",
	"sysfs_read_attribute",
	"sysfs_read_attribute_value",
	"sysfs_write_attribute",
	"sysfs_get_value_from_attributes",
	"sysfs_refresh_dir_attributes",
	"sysfs_refresh_dir_links",
	"sysfs_refresh_dir_subdirs",
	"sysfs_close_directory",
	"sysfs_open_directory",
	"sysfs_read_dir_attributes",
	"sysfs_read_dir_links",
	"sysfs_read_dir_subdirs",
	"sysfs_read_directory",
	"sysfs_read_all_subdirs",
	"sysfs_get_subdirectory",
	"sysfs_close_link",
	"sysfs_open_link",
	"sysfs_get_directory_link",
	"sysfs_get_subdirectory_link",
	"sysfs_get_directory_attribute",
	"sysfs_get_dir_attributes",
	"sysfs_get_dir_links",
	"sysfs_get_dir_subdirs",
	"sysfs_close_driver",
	"sysfs_open_driver",
	"sysfs_open_driver_path",
	"sysfs_get_driver_attr",
	"sysfs_get_driver_attributes",
	"sysfs_get_driver_devices",
	"sysfs_refresh_driver_devices",
	"sysfs_get_driver_links",
	"sysfs_get_driver_device",
	"sysfs_refresh_driver_attributes",
	"sysfs_open_driver_attr",
	"sysfs_close_root_device",
	"sysfs_open_root_device",
	"sysfs_get_root_devices",
	"sysfs_close_device",
	"sysfs_open_device",
	"sysfs_get_device_parent",
	"sysfs_open_device_path",
	"sysfs_get_device_attr",
	"sysfs_get_device_attributes",
	"sysfs_refresh_device_attributes",
	"sysfs_open_device_attr",
	"sysfs_close_bus",
	"sysfs_open_bus",
	"sysfs_get_bus_device",
	"sysfs_get_bus_driver",
	"sysfs_get_bus_drivers",
	"sysfs_get_bus_devices",
	"sysfs_get_bus_attributes",
	"sysfs_refresh_bus_attributes",
	"sysfs_get_bus_attribute",
	"sysfs_find_driver_bus",
	"sysfs_close_class_device",
	"sysfs_open_class_device_path",
	"sysfs_open_class_device",
	"sysfs_get_classdev_device",
	"sysfs_get_classdev_driver",
	"sysfs_get_classdev_parent",
	"sysfs_close_class",
	"sysfs_open_class",
	"sysfs_get_class_devices",
	"sysfs_get_class_device",
	"sysfs_get_classdev_attributes",
	"sysfs_refresh_classdev_attributes",
	"sysfs_get_classdev_attr",
	"sysfs_open_classdev_attr",
};

int (*func_table[81])(int) = {
	test_sysfs_get_mnt_path,
	test_sysfs_remove_trailing_slash,
	test_sysfs_get_name_from_path,
	test_sysfs_path_is_dir,
	test_sysfs_path_is_link,
	test_sysfs_path_is_file,
	test_sysfs_get_link,
	test_sysfs_open_subsystem_list,
	test_sysfs_open_bus_devices_list,
	test_sysfs_close_list,
	test_sysfs_close_attribute,
	test_sysfs_open_attribute,
	test_sysfs_read_attribute,
	test_sysfs_read_attribute_value,
	test_sysfs_write_attribute,
	test_sysfs_get_value_from_attributes,
	test_sysfs_refresh_dir_attributes,
	test_sysfs_refresh_dir_links,
	test_sysfs_refresh_dir_subdirs,
	test_sysfs_close_directory,
	test_sysfs_open_directory,
	test_sysfs_read_dir_attributes,
	test_sysfs_read_dir_links,
	test_sysfs_read_dir_subdirs,
	test_sysfs_read_directory,
	test_sysfs_read_all_subdirs,
	test_sysfs_get_subdirectory,
	test_sysfs_close_link,
	test_sysfs_open_link,
	test_sysfs_get_directory_link,
	test_sysfs_get_subdirectory_link,
	test_sysfs_get_directory_attribute,
	test_sysfs_get_dir_attributes,
	test_sysfs_get_dir_links,
	test_sysfs_get_dir_subdirs,
	test_sysfs_close_driver,
	test_sysfs_open_driver,
	test_sysfs_open_driver_path,
	test_sysfs_get_driver_attr,
	test_sysfs_get_driver_attributes,
	test_sysfs_get_driver_devices,
	test_sysfs_refresh_driver_devices,
	test_sysfs_get_driver_links,
	test_sysfs_get_driver_device,
	test_sysfs_refresh_driver_attributes,
	test_sysfs_open_driver_attr,
	test_sysfs_close_root_device,
	test_sysfs_open_root_device,
	test_sysfs_get_root_devices,
	test_sysfs_close_device,
	test_sysfs_open_device,
	test_sysfs_get_device_parent,
	test_sysfs_open_device_path,
	test_sysfs_get_device_attr,
	test_sysfs_get_device_attributes,
	test_sysfs_refresh_device_attributes,
	test_sysfs_open_device_attr,
	test_sysfs_close_bus,
	test_sysfs_open_bus,
	test_sysfs_get_bus_device,
	test_sysfs_get_bus_driver,
	test_sysfs_get_bus_drivers,
	test_sysfs_get_bus_devices,
	test_sysfs_get_bus_attributes,
	test_sysfs_refresh_bus_attributes,
	test_sysfs_get_bus_attribute,
	test_sysfs_find_driver_bus,
	test_sysfs_close_class_device,
	test_sysfs_open_class_device_path,
	test_sysfs_open_class_device,
	test_sysfs_get_classdev_device,
	test_sysfs_get_classdev_driver,
	test_sysfs_get_classdev_parent,
	test_sysfs_close_class,
	test_sysfs_open_class,
	test_sysfs_get_class_devices,
	test_sysfs_get_class_device,
	test_sysfs_get_classdev_attributes,
	test_sysfs_refresh_classdev_attributes,
	test_sysfs_get_classdev_attr,
	test_sysfs_open_classdev_attr,
};

static void usage(void)
{
	fprintf(stdout, "testlibsysfs <no-of-times> [log-file]\n");
	fprintf(stdout, "\t eg: testlibsysfs 3 /home/user/test.log\n");
}

int main(int argc, char *argv[])
{
	char std_out[] = "/dev/stdout";
	char *file_name = NULL;
	int i = 0, j = 0, k = 0, num = 1;

	if (argc == 3) {
		file_name = argv[2];
	} else {
		file_name = std_out;
	}
	my_stdout = fopen(file_name,"w");
	if (argc < 2) {
		usage();
		return 0;
	} else 
		num = strtol(argv[1], NULL, 0);

	dbg_print("\nTest running %d times\n", num);

	for (k = 0; k < num ; k++) {
		dbg_print("\nThis is the %d test run\n", k+1);
		
		for (i = 0; i < FUNC_TABLE_SIZE; i++) {
dbg_print("\n**************************************************************\n");
			dbg_print("TESTING: %s, function no: %d\n\n",
					function_name[i], i);
			for (j = 0; ; j++) {
				fflush(my_stdout);
				if (func_table[i](j) == -1)
					break;
			}
dbg_print("**************************************************************\n");
		}
	}

	fclose(my_stdout);
	return 0;
}