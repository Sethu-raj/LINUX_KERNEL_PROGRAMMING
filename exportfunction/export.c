#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");

void print_jiffies(void)
{
    printk(KERN_INFO "%s: Jiffies = %lu\n",
           __func__, jiffies);
}

/* Export the function */
EXPORT_SYMBOL_GPL(print_jiffies);

static int __init export_init(void)
{
    printk(KERN_INFO "Export Module Loaded\n");
    return 0;
}

static void __exit export_exit(void)
{
    printk(KERN_INFO "Export Module Removed\n");
}

module_init(export_init);
module_exit(export_exit);
