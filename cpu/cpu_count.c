#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CPU Example");
MODULE_DESCRIPTION("CPU count module");

static int __init my_cpu_init(void)
{
    printk(KERN_INFO "===========================\n");
    printk(KERN_INFO "Online CPUs  : %d\n", num_online_cpus());
    printk(KERN_INFO "Possible CPUs: %d\n", num_possible_cpus());
    printk(KERN_INFO "===========================\n");

    return 0;
}

static void __exit my_cpu_exit(void)
{
    printk(KERN_INFO "CPU module exit\n");
}

module_init(my_cpu_init);
module_exit(my_cpu_exit);
