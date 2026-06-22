#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
 
MODULE_LICENSE("abc");
MODULE_AUTHOR("sethu");
 
static int __init hello_init(void)
{
    printk(KERN_INFO "Taint Demo Module Loaded\n");
    return 0;
}
 
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Taint Demo Module Removed\n");
}
 
module_init(hello_init);
module_exit(hello_exit);
