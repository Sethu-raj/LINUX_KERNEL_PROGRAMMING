
#include <linux/module.h>
#include <linux/kernel.h>
 
MODULE_LICENSE("GPL");
 
/* Function defined in another module */
extern void print_jiffies(void);
 
static int __init user_init(void)
{
    printk(KERN_INFO "User Module Loaded\n");
 
    print_jiffies();
 
    return 0;
}
 
static void __exit user_exit(void)
{
    printk(KERN_INFO "User Module Removed\n");
}
 
module_init(user_init);
module_exit(user_exit);
