#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/smp.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Print current CPU ID");

static int __init cpu_id_init(void)
{
    pr_info("Module Loaded\n");
    pr_info("Current CPU ID = %d\n", smp_processor_id());

    return 0;
}

static void __exit cpu_id_exit(void)
{
    pr_info("Module Unloaded\n");
}

module_init(cpu_id_init);
module_exit(cpu_id_exit);
