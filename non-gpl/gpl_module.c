#include <linux/module.h>
#include <linux/kernel.h>

void gpl_function(void)
{
    pr_info("GPL function called!\n");
}
EXPORT_SYMBOL_GPL(gpl_function);

static int __init gpl_init(void)
{
    pr_info("GPL module loaded\n");
    return 0;
}

static void __exit gpl_exit(void)
{
    pr_info("GPL module unloaded\n");
}

module_init(gpl_init);
module_exit(gpl_exit);

MODULE_LICENSE("GPL");
