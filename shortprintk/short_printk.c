#include <linux/module.h>
#include <linux/kernel.h>

static int __init demo_init(void)
{
    pr_info("Module Loaded\n");
    pr_warn("Warning Message\n");
    pr_err("Error Message\n");
    return 0;
}

static void __exit demo_exit(void)
{
    pr_info("Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(demo_init);
module_exit(demo_exit);
