#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int test_hello_init(void)
{
    printk(KERN_INFO "%s: In init\n", __func__);

    return 0;
}


module_init(test_hello_init);

