#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

void my_function(void)
{
    printk(KERN_INFO "Inside my_function()\n");
}

EXPORT_SYMBOL(my_function);

static int __init symbol_init(void)
{
    printk(KERN_INFO "Symbol Module Loaded\n");
    return 0;
}

static void __exit symbol_exit(void)
{
    printk(KERN_INFO "Symbol Module Removed\n");
}

module_init(symbol_init);
module_exit(symbol_exit);
