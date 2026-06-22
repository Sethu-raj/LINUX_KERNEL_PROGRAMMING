#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");


static void test_hello_exit(void)
{
    printk(KERN_INFO "%s: In exit\n", __func__);
}


module_exit(test_hello_exit);
