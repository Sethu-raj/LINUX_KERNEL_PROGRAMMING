# Linux Device Driver & Kernel Module Programming

## Overview

This repository contains notes, examples, and practical exercises related to **Linux Device Driver Development** and **Linux Kernel Module (LKM) Programming**. The content covers kernel fundamentals, module creation, debugging techniques, module parameters, symbol exporting, kernel threads, process management, and memory optimization techniques used in Linux kernel development.

---

## Topics Covered

### 1. Linux Kernel and Device Drivers

* Linux Kernel Architecture
* Device Drivers and their role
* Kernel Space vs User Space
* Kernel Modules and Loadable Kernel Modules (LKM)
* Advantages of Kernel Modules

### 2. Kernel Module Basics

* Creating a simple Hello World Kernel Module
* `module_init()` and `module_exit()`
* Module loading and unloading
* Building kernel modules using Makefiles
* Understanding `.ko` files

### 3. Kernel Module Management

* `insmod`
* `rmmod`
* `modprobe`
* `depmod`
* `lsmod`
* `modinfo`

### 4. Kernel Logging and Debugging

* `printk()` function
* printk log levels
* `pr_info()`, `pr_err()`, `pr_debug()`
* Kernel Ring Buffer
* `dmesg`
* Dynamic Debug
* Stack Dump using `dump_stack()`

### 5. Module Parameters

* `module_param()`
* `module_param_array()`
* Integer Parameters
* String Parameters
* Array Parameters
* Boolean and `invbool` Parameters
* Built-in Module Parameters

### 6. Module Metadata

* `MODULE_LICENSE()`
* `MODULE_AUTHOR()`
* `MODULE_DESCRIPTION()`
* `MODULE_VERSION()`
* `MODULE_ALIAS()`
* `MODULE_INFO()`

### 7. Symbol Exporting and Module Stacking

* Symbol Tables
* `EXPORT_SYMBOL()`
* `EXPORT_SYMBOL_GPL()`
* Module Dependencies
* Module Stacking

### 8. Kernel Build System

* Kbuild System
* Build Process
* `modpost`
* `Module.symvers`
* `modules.order`
* Version Magic (vermagic)

### 9. Kernel Debugging Tools

* `objdump`
* `modinfo`
* `strace`
* `systool`
* `/proc/kallsyms`
* `System.map`

### 10. Kernel Errors

* Kernel Oops
* Kernel Panic
* `BUG()`
* `BUG_ON()`
* Tainted Kernel

### 11. Process Management in Kernel

* `task_struct`
* Process States
* Current Process using `current`
* PID Lookup
* Parent Process Information

### 12. Memory Management Concepts

* Process Memory Map
* `mm_struct`
* Virtual Memory Layout
* Text, Data, BSS, Heap, Stack Segments

### 13. Kernel Threads

* Creating Kernel Threads
* `kthread_run()`
* `kthread_stop()`
* `kthread_should_stop()`
* Multiple Kernel Threads
* Race Conditions

### 14. Kernel Version Handling

* `LINUX_VERSION_CODE`
* `KERNEL_VERSION()`
* `UTS_RELEASE`
* Multi-version Driver Support

### 15. Memory Optimization Macros

* `__init`
* `__exit`
* `__initdata`
* `__exitdata`

### 16. Module Auto Loading

* Automatic Module Loading
* `/etc/modules`
* `/etc/modules-load.d/`
* Blacklisting Modules
* Persistent Module Parameters

---

## Prerequisites

Before building kernel modules, ensure the following packages are installed:

```bash
sudo apt update
sudo apt install build-essential
sudo apt install linux-headers-$(uname -r)
```

---

## Generic Kernel Module Makefile

```Makefile
obj-m += hello.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
```

---

## Build Module

```bash
make
```

---

## Load Module

```bash
sudo insmod hello.ko
```

Verify:

```bash
lsmod | grep hello
```

Check logs:

```bash
dmesg | tail
```

---

## Remove Module

```bash
sudo rmmod hello
```

---

## Useful Commands

```bash
uname -r
lsmod
modinfo hello
dmesg
cat /proc/modules
cat /proc/kallsyms
journalctl -k
```

---

## Learning Outcomes

After completing these exercises, you will understand:

* Linux Kernel Module architecture
* Driver compilation and loading
* Kernel logging mechanisms
* Module parameters
* Symbol exporting and module dependencies
* Kernel thread creation
* Process handling inside kernel space
* Kernel debugging techniques
* Memory optimization using kernel macros

---

## References

* Linux Kernel Documentation
* Linux Device Drivers (LDD3)
* Kernel Module Programming Guide
* Linux Source Tree Documentation

---

## Author

**Sethu Raj**

Linux Kernel & Device Driver Programming Notes
