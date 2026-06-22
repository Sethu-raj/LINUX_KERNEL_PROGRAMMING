#include <linux/module.h>
#include <linux/kernel.h>

static int __init debug_init(void)
{
    pr_info("Module Loaded\n");
    pr_debug("Debug Message\n");
    return 0;
}

static void __exit debug_exit(void)
{
    pr_info("Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(debug_init);
module_exit(debug_exit);
