#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

/* Variable from another module */
extern int my_value;

static int __init user_init(void)
{
    printk(KERN_INFO "User Module Loaded\n");
    printk(KERN_INFO "Received my_value = %d\n", my_value);

    my_value = 200;

    printk(KERN_INFO "Modified my_value = %d\n", my_value);

    return 0;
}

static void __exit user_exit(void)
{
    printk(KERN_INFO "User Module Removed\n");
}

module_init(user_init);
module_exit(user_exit);
