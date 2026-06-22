#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int value = 10;

module_param(value, int, 0644);

static int __init hello_init(void)
{
    printk(KERN_INFO "Value = %d\n", value);
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
