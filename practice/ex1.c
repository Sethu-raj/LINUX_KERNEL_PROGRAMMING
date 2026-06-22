#include <linux/module.h>
#include <linux/kernel.h>

static int __init ex1_init(void)
{
    printk(KERN_INFO "EX1: Module Loaded\n");
    return 0;
}

static void __exit ex1_exit(void)
{
    printk(KERN_INFO "EX1: Module Removed\n");
}

module_init(ex1_init);
module_exit(ex1_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Example of module_init and module_exit");
