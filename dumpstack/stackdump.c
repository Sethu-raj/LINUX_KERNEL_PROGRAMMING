#include <linux/module.h>
#include <linux/kernel.h>

static int __init stack_init(void)
{
    printk(KERN_INFO "Dumping Kernel Stack\n");

    dump_stack();

    return 0;
}

static void __exit stack_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(stack_init);
module_exit(stack_exit);
