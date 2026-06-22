# Linux Kernel Module Parameters using modprobe

## Overview

This project demonstrates how to pass parameters to a Linux Kernel Module using the `modprobe` command. Module parameters allow users to configure module behavior at load time without modifying the source code.

## Features

* Define module parameters using `module_param()`
* Pass values during module loading
* View parameter values through sysfs
* Configure permanent parameter values using modprobe configuration files

## Source Code

### param.c

```c
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int value = 10;

module_param(value, int, 0644);

static int __init param_init(void)
{
    printk(KERN_INFO "Value = %d\n", value);
    return 0;
}

static void __exit param_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

module_init(param_init);
module_exit(param_exit);
```

## Makefile

```makefile
obj-m := param.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

## Build Module

```bash
make
```

## Install Module

Copy the module into the kernel modules directory and update dependencies:

```bash
sudo cp param.ko /lib/modules/$(uname -r)/extra/
sudo depmod -a
```

## Load Module with Default Parameter

```bash
sudo modprobe param
```

Expected Output:

```text
Value = 10
```

## Load Module with Custom Parameter

```bash
sudo modprobe -r param
sudo modprobe param value=100
```

Expected Output:

```text
Value = 100
```

## Verify Parameter Value

```bash
cat /sys/module/param/parameters/value
```

Output:

```text
100
```

## Configure Permanent Parameter

Create a modprobe configuration file:

```bash
sudo nano /etc/modprobe.d/param.conf
```

Add:

```text
options param value=200
```

Now every time the module is loaded:

```bash
sudo modprobe param
```

the parameter value will automatically be set to:

```text
200
```

## View Module Information

```bash
modinfo param.ko
```

Example Output:

```text
parm: value:int
```

## Important Concepts

* `module_param()` defines module parameters.
* Parameters can be passed during module loading.
* Parameters are visible through `/sys/module/<module_name>/parameters/`.
* `modprobe` automatically handles module dependencies.
* Permanent parameter values can be configured in `/etc/modprobe.d/`.

## Commands Summary

```bash
make
sudo cp param.ko /lib/modules/$(uname -r)/extra/
sudo depmod -a
sudo modprobe param
sudo modprobe -r param
sudo modprobe param value=100
cat /sys/module/param/parameters/value
modinfo param.ko
```

## Author

Sethu Raj

## License

GPL
