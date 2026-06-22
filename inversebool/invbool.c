#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static bool param_invbool = false;

module_param(param_invbool, invbool, S_IRUGO);

static int __init my_init(void)
{
    pr_info("param_invbool : %s\n",
            param_invbool ? "true" : "false");

    return 0;
}

static void __exit my_exit(void)
{
    return;
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Sethu ");
MODULE_LICENSE("GPL");
