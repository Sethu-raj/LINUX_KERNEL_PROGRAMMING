#include <linux/module.h>
#include <linux/kernel.h>

static int __init objdump_init(void)
{
    printk(KERN_INFO "Objdump Demo Module Loaded\n");
    return 0;
}

static void __exit objdump_exit(void)
{
    printk(KERN_INFO "Objdump Demo Module Unloaded\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Kernel Module for objdump demonstration");
MODULE_VERSION("1.0");

module_init(objdump_init);
module_exit(objdump_exit);
