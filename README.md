Step 1: make device file ~# sudo mknod /dev/test_device c 242 0
Step 2: run Makefile  ~# sudo make
Step 3: install module ~# insmod driver.ko
Step 4: compile test_device.c and run with sudo
