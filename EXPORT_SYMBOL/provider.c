#include <linux/module.h>
#include <linux/kernel.h>

void hello(void)
{
    printk(KERN_INFO "Hello from Provider Module\n");
}

EXPORT_SYMBOL(hello);

static int __init provider_init(void)
{
    printk(KERN_INFO "Provider Loaded\n");
    return 0;
}

static void __exit provider_exit(void)
{
    printk(KERN_INFO "Provider Removed\n");
}

module_init(provider_init);
module_exit(provider_exit);

MODULE_LICENSE("GPL");
