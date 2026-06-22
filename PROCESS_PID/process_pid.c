#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/pid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Print process and parent information using PID");

static int pid = 1;
module_param(pid, int, 0644);
MODULE_PARM_DESC(pid, "Process ID");

static int __init process_info_init(void)
{
    struct pid *pid_struct;
    struct task_struct *task;

    pr_info("Module Loaded\n");
    pr_info("Searching for PID: %d\n", pid);

    pid_struct = find_get_pid(pid);
    if (!pid_struct) {
        pr_err("PID %d not found\n", pid);
        return -ESRCH;
    }

    task = pid_task(pid_struct, PIDTYPE_PID);
    if (!task) {
        pr_err("No task found for PID %d\n", pid);
        return -ESRCH;
    }

    pr_info("Process Name : %s\n", task->comm);
    pr_info("Process PID  : %d\n", task->pid);

    if (task->parent) {
        pr_info("Parent Name  : %s\n", task->parent->comm);
        pr_info("Parent PID   : %d\n", task->parent->pid);
    }

    return 0;
}

static void __exit process_info_exit(void)
{
    pr_info("Module Unloaded\n");
}

module_init(process_info_init);
module_exit(process_info_exit);
