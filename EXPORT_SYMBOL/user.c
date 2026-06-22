#include <linux/module.h>
#include <linux/kernel.h>

extern void hello(void);

static int __init user_init(void)
{
    printk(KERN_INFO "User Loaded\n");

    hello();

    return 0;
}

static void __exit user_exit(void)
{
    printk(KERN_INFO "User Removed\n");
}

module_init(user_init);
module_exit(user_exit);

MODULE_LICENSE("GPL");
