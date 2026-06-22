#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello Kernel Module Loaded\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Hello Kernel Module Removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Simple Hello World Kernel Module");
MODULE_VERSION("1.0");

module_init(hello_init);
module_exit(hello_exit);
