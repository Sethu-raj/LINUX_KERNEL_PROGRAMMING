#include <linux/module.h>
#include <linux/kernel.h>

static int __init cont_init(void)
{
    printk(KERN_INFO "Value = ");
    printk(KERN_CONT "%d ", 10);
    printk(KERN_CONT "%d ", 20);
    printk(KERN_CONT "%d\n", 30);

    return 0;
}

static void __exit cont_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(cont_init);
module_exit(cont_exit);
