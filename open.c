#include <linux/fs.h>	/* file system */
#include <linux/cdev.h>	/* character devices */
#include <linux/io.h>	/* Input/Output */


int module_open(struct inode *inode, struct file *filp) {
	return 0;
}