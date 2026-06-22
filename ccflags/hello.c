#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Simple Kernel Module with DEBUG macro");

static int test_hello_init(void)
{
#ifdef DEBUG
    printk(KERN_INFO "DEBUG: %s - In init function\n", __func__);
#else
    printk(KERN_INFO "%s - In init function\n", __func__);
#endif
    return 0;
}

static void test_hello_exit(void)
{
#ifdef DEBUG
    printk(KERN_INFO "DEBUG: %s - In exit function\n", __func__);
#else
    printk(KERN_INFO "%s - In exit function\n", __func__);
#endif
}

module_init(test_hello_init);
module_exit(test_hello_exit);
