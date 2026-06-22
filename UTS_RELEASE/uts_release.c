#include <linux/module.h>
#include <linux/kernel.h>
#include <generated/utsrelease.h>

static int __init uts_init(void)
{
    printk(KERN_INFO "Kernel Release = %s\n",
           UTS_RELEASE);

    return 0;
}

static void __exit uts_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(uts_init);
module_exit(uts_exit);
