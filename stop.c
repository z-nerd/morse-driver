#include "info.h"


static void __exit zero_exit(void) {
	pr_info("Zero module removed!\n"); 
}


module_exit(zero_exit); 