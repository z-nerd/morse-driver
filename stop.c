#include "includes/info.h"
#include "includes/driver.h"


static void __exit zero_exit(void) {
	pr_info("Zero module removed!\n"); 

	unregister_chrdev_region(devno, module_nr_devs);
}


module_exit(zero_exit); 