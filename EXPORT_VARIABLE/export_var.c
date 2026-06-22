#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

/* Variable to export */
int my_value = 100;

EXPORT_SYMBOL_GPL(my_value);

static int __init export_init(void)
{
    printk(KERN_INFO "Export Module Loaded\n");
    printk(KERN_INFO "my_value = %d\n", my_value);

    return 0;
}

static void __exit export_exit(void)
{
    printk(KERN_INFO "Export Module Removed\n");
}

module_init(export_init);
module_exit(export_exit);
