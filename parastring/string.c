#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
 
static char *message = "Default Message";
 
module_param(message, charp, 0644);
MODULE_PARM_DESC(message, "Message String");
 
static int __init hello_init(void)
{
    printk(KERN_INFO "Message = %s\n", message);
    return 0;
}
 
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}
 
module_init(hello_init);
module_exit(hello_exit);
