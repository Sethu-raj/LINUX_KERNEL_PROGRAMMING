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
