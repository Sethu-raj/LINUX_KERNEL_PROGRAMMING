#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Demonstrate current macro");

static int __init current_demo_init(void)
{
    pr_info("Module Loaded\n");

    pr_info("Current Process Name : %s\n", current->comm);
    pr_info("Current PID          : %d\n", current->pid);
    pr_info("Parent PID           : %d\n", current->parent->pid);
    pr_info("Parent Name          : %s\n", current->parent->comm);

    return 0;
}

static void __exit current_demo_exit(void)
{
    pr_info("Module Unloaded\n");
}

module_init(current_demo_init);
module_exit(current_demo_exit);
