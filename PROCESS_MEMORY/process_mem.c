#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mm.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static int __init process_mem_init(void)
{
    struct mm_struct *mm = current->mm;

    pr_info("Process : %s\n", current->comm);
    pr_info("PID     : %d\n", current->pid);

    pr_info("Code Start  : 0x%lx\n", mm->start_code);
    pr_info("Code End    : 0x%lx\n", mm->end_code);

    pr_info("Data Start  : 0x%lx\n", mm->start_data);
    pr_info("Data End    : 0x%lx\n", mm->end_data);

    pr_info("Heap Start  : 0x%lx\n", mm->start_brk);
    pr_info("Heap End    : 0x%lx\n", mm->brk);

    pr_info("Stack Start : 0x%lx\n", mm->start_stack);

    return 0;
}

static void __exit process_mem_exit(void)
{
    pr_info("Process Memory module removed\n");
}

module_init(process_mem_init);
module_exit(process_mem_exit);
