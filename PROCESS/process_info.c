#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");

static const char *get_task_state(long state)
{
    if (state == TASK_RUNNING)
        return "RUNNING";
    else if (state == TASK_INTERRUPTIBLE)
        return "INTERRUPTIBLE";
    else if (state == TASK_UNINTERRUPTIBLE)
        return "UNINTERRUPTIBLE";
    else
        return "OTHER";
}

static int __init test_tasks_init(void)
{
    struct task_struct *task_list;
    unsigned int process_count = 0;

    pr_info("%s: In init\n", __func__);

    for_each_process(task_list) {
        pr_info("Process: %s PID: %d State: %s\n",
                task_list->comm,
                task_list->pid,
                get_task_state(task_list->__state));

        process_count++;
    }

    pr_info("Number of processes: %u\n", process_count);

    return 0;
}

static void __exit test_tasks_exit(void)
{
    pr_info("%s: In exit\n", __func__);
}

module_init(test_tasks_init);
module_exit(test_tasks_exit);
