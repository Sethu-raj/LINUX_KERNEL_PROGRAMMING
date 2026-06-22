#include <linux/module.h>
#include <linux/kernel.h>

static int __init float_init(void)
{

float f = 3.14;
printk(KERN_INFO "%f\n", f);
    int integer = 3;
    int fraction = 14;

    printk(KERN_INFO "Floating Point Value = %d.%02d\n",
           integer, fraction);

    return 0;
}

static void __exit float_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu Raj");
MODULE_DESCRIPTION("Floating Point Example");

module_init(float_init);
module_exit(float_exit);
