#include <linux/module.h>
#include <linux/kernel.h>

static int __init once_init(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        printk_once(KERN_INFO "Printed Only Once\n");
    }

    return 0;
}

static void __exit once_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(once_init);
module_exit(once_exit);
