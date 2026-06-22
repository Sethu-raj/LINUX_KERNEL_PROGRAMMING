#include <linux/module.h>
#include <linux/kernel.h>

static int my_init(void)
{
    printk(KERN_INFO "Module Loaded\n");
    return 0;
}

int start_module(void) __attribute__((alias("my_init")));

static void my_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

void stop_module(void) __attribute__((alias("my_exit")));

module_init(start_module);
module_exit(stop_module);

MODULE_LICENSE("GPL");
