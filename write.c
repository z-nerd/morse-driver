#include <linux/fs.h>	/* file system */
#include <linux/cdev.h>	/* character devices */
#include <linux/io.h>	/* Input/Output */
#include <morse.h>


ssize_t module_write(struct file *filp, const char *buff, size_t len, loff_t *off) {
	unsigned long count;
	unsigned char local_buff[100];
	unsigned char code[1024] = "";

	count = copy_from_user(local_buff, buff, ((len < 128) ? len : 128));

	count = ((len < 128) ? len : 128) - count; 

	local_buff[count] = '\0';


	pr_info("Input: %s\n", local_buff);
	enToMorse(local_buff, code, " ", "/ ");
	pr_info("code:%s, len:%ld\n", code, strlen(code));


	return len;
}