#include "info.h"
#include <utility.h>
#include <morse.h>


static int __init zero_init(void) {
	int i = 0;
	char msg[] = "Zero is here!?", code[2024] = "";
	

	enToMorse(msg, code, " ", "/");

	pr_info("msg:%s, len:%ld\n", msg, strlen(msg));
	pr_info("code:%s, len:%ld\n", code, strlen(code));



	for (i = 0; i < count; ++i) {
		pr_info("Hello world 1.\n"); 
	}

	return 0;
}


module_init(zero_init);