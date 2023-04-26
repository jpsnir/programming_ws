# Linux drivers:
[Linux kernel driver book](https://lwn.net/Kernel/LDD3/)
[Video link to writing device drivers](https://www.youtube.com/watch?v=QIO2pJqMxjE)

## GPIO
- gpiolib
- gpio-cdev

## PWM
## I2C
-i2c-tools
## SPI
-/dev/spidev*
## USB
-libusb
## UIO 
## Spaces
- kernel space - drivers cannot be killed, more robust
- user space - more safe, if a bug is introduced it will not stop everything - you can close the program without affecting others. 

## Software abstraction:  
1. sysfs interface for hardware.
2. posix and unix functions.
