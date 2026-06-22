#include <linux/module.h>
#include <linux/kernel.h>

extern void gpl_function(void);

static int __init prop_init(void)
{
    pr_info("Proprietary module loaded\n");

    gpl_function();   // GPL-only symbol

    return 0;
}

static void __exit prop_exit(void)
{
    pr_info("Proprietary module unloaded\n");
}

module_init(prop_init);
module_exit(prop_exit);

MODULE_LICENSE("Proprietary");
