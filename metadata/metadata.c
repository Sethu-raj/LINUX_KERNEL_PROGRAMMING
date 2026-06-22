#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    printk(KERN_INFO "Metadata Module Loaded\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Metadata Module Removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Example demonstrating module metadata");
MODULE_VERSION("1.0");
MODULE_ALIAS("my_hello_module");

module_init(hello_init);
module_exit(hello_exit);
