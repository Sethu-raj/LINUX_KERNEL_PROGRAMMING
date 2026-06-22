#include <linux/module.h>
#include <linux/kernel.h>

int value = 0;

module_param(value, int, 0644);

static int __init ex28_init(void)
{
    printk(KERN_INFO "Value = %d\n", value);
    return 0;
}

static void __exit ex28_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

module_init(ex28_init);
module_exit(ex28_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Passing Parameters Example");
