#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

static int __init version_init(void)
{
    printk(KERN_INFO "Version = %d\n",
           KERNEL_VERSION(6,8,0));

    return 0;
}

static void __exit version_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(version_init);
module_exit(version_exit);
