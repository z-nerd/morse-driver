MODULE_NAME = morseDriver
MODULE_PARAM = ""
MODULE_CONF = "$(MODULE_NAME)"

MODULE_INSTALL_PATH = /lib/modules/$(shell uname -r)/$(MODULE_NAME).ko
MODULE_CONF_PATH = /etc/modules-load.d/$(MODULE_NAME).conf

OBJS = open.o close.o write.o start.o stop.o lib/src/utility.o lib/src/morse.o
PWD = $(CURDIR)

obj-m += $(MODULE_NAME).o
$(MODULE_NAME)-objs := $(OBJS)
ccflags-y := -I$(src)/lib/includes/


all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules


clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


log-clear:
	sudo dmesg -C


log-show:
	sudo dmesg


load:
	test ! -f "$(MODULE_NAME).ko" && (make && make load) || true
	test -n "$(shell sudo lsmod | grep -e "$(MODULE_NAME)")" && \
	echo "Module already loaded!" || sudo insmod ./$(MODULE_NAME).ko


remove:
	test -n "$(shell sudo lsmod | grep -e "$(MODULE_NAME)")" && \
	sudo rmmod $(MODULE_NAME) || echo "Module didn't exist to remove!"


info:
	sudo modinfo $(MODULE_NAME).ko


test:
	make log-clear
	make install
	echo "Zero test!" > /dev/morse
	make uninstall
	make log-show
	#make clean

install:
	make
	make load
	test ! -f /dev/morse && sudo mknod /dev/morse c 137 0 || true
	sudo chmod ugo+rw /dev/morse


uninstall:
	test -f /dev/morse && sudo rm -rf /dev/morse || true
	make remove
	test -f /dev/morse && sudo rm -rf /dev/morse || true
	echo -e "\n\nUnfortunately currently need reboot to take effect!(Don't use /dev/morse otherwise your system crash and need reboot)\n\n"


# install:
# 	make
# 	sudo cp $(MODULE_NAME).ko $(MODULE_INSTALL_PATH)
# 	echo $(MODULE_CONF) | sudo tee $(MODULE_CONF_PATH) 
# 	sudo depmod -a


# uninstall:
# 	test -f $(MODULE_INSTALL_PATH) && sudo rm $(MODULE_INSTALL_PATH) || true
# 	test -f $(MODULE_CONF_PATH) && sudo rm $(MODULE_CONF_PATH) || true
# 	sudo depmod -a
