#include "includes/info.h"
#include "includes/driver.h"
#include <utility.h>
#include <morse.h>


static int __init zero_init(void) {
	int errno;

	devno = MKDEV(module_major, module_minor); //cat /proc/devices
	register_chrdev_region(devno, module_nr_devs, "morse");

	cdev_init(&module_cdev, &module_fops);

	module_cdev.owner = THIS_MODULE;
    module_cdev.ops = &module_fops;

    errno = cdev_add(&module_cdev, devno, 1);

    /* Fail gracefully if need be. */
    if(errno < 0) {
    	pr_info("Error %d adding module", errno);

    	return -1;
    }

	pr_info("Zero module loaded!\n"); 


	// int i = 0;
	// char msg[] = "Zero is here!?", code[2024] = "";
	

	// enToMorse(msg, code, " ", "/");

	// pr_info("msg:%s, len:%ld\n", msg, strlen(msg));
	// pr_info("code:%s, len:%ld\n", code, strlen(code));



	// for (i = 0; i < count; ++i) {
	// 	pr_info("Hello world 1.\n"); 
	// }
	

	return 0;
}


module_init(zero_init);