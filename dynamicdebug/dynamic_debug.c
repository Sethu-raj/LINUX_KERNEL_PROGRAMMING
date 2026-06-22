#include <linux/module.h>
#include <linux/kernel.h>

static int __init debug_init(void)
{
    pr_info("Module Loaded\n");

    pr_debug("Debug Message 1\n");
    pr_debug("Debug Message 2\n");

    return 0;
}

static void __exit debug_exit(void)
{
    pr_info("Module Removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Dynamic Debug Example");

module_init(debug_init);
module_exit(debug_exit);
