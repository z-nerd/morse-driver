#include <linux/module.h> /* Needed by all modules */
#include <linux/fs.h>   /* file system */
#include <linux/cdev.h> /* character devices */
#include <linux/io.h>   /* Input/Output */

int module_open(struct inode *inode, struct file *filp);
int module_close(struct inode *inode, struct file *filp);
ssize_t module_write(struct file *filp, const char *buff, size_t len, loff_t *off);

static int module_major = 137;
static int module_minor = 0;
static int module_nr_devs = 1;

static dev_t devno;
static struct cdev module_cdev;

static struct file_operations module_fops = {
    open: module_open,
    write: module_write,
    release: module_close,
    owner: THIS_MODULE,
};