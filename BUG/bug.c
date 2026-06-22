#include <linux/module.h>
#include <linux/kernel.h>

static int __init bug_init(void)
{
    printk(KERN_INFO "Before BUG()\n");

    BUG();

    printk(KERN_INFO "This line will never execute\n");
    return 0;
}

static void __exit bug_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(bug_init);
module_exit(bug_exit);
