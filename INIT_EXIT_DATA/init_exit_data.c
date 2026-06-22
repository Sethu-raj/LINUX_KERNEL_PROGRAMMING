#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("__initdata and __exitdata Example");

static int __initdata init_value = 100;
static int __exitdata exit_value = 200;

static int __init test_init(void)
{
    printk(KERN_INFO "Module Loaded\n");
    printk(KERN_INFO "Init Value = %d\n", init_value);

    return 0;
}

static void __exit test_exit(void)
{
    printk(KERN_INFO "Exit Value = %d\n", exit_value);
    printk(KERN_INFO "Module Removed\n");
}

module_init(test_init);
module_exit(test_exit);
