#include <linux/init.h> /* Needed for the macros */
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */
#include <linux/string.h> /* string-handling */
#include <linux/stddef.h> /* Unicode support */


static int count = 2;
module_param(count, int, 0);
MODULE_PARM_DESC(count, "How many time we print hello world!");


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zero"); 
MODULE_DESCRIPTION("A sample driver");