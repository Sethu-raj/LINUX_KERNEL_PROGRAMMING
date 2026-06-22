#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Kernel Module Parameter Example");

/* Module Parameters */
static char *name = "Embedded";
static int loop_count = 1;

/* Register Parameters */
module_param(name, charp, 0644);
MODULE_PARM_DESC(name, "Name to print");

module_param(loop_count, int, 0644);
MODULE_PARM_DESC(loop_count, "Number of times to print");

/* Init Function */
static int __init parm_init(void)
{
    int i;

    printk(KERN_INFO "%s: In Init\n", __func__);
    printk(KERN_INFO "%s: Loop Count = %d\n",
           __func__, loop_count);

    for (i = 0; i < loop_count; i++)
    {
        printk(KERN_INFO "%s: Hi %s\n",
               __func__, name);
    }

    return 0;
}

/* Exit Function */
static void __exit parm_exit(void)
{
    printk(KERN_INFO "%s: In Exit\n", __func__);
}

module_init(parm_init);
module_exit(parm_exit);
