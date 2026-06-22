#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>

static int __init version_init(void)
{
    printk(KERN_INFO "Current Kernel Version Code = %d\n",
           LINUX_VERSION_CODE);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,8,0)

    printk(KERN_INFO "Running on Kernel >= 6.8.0\n");

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(5,15,0)

    printk(KERN_INFO "Running on Kernel >= 5.15.0 and < 6.8.0\n");

#else

    printk(KERN_INFO "Running on Older Kernel\n");

#endif

    return 0;
}

static void __exit version_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Kernel Version Compatibility Example");

module_init(version_init);
module_exit(version_exit);
