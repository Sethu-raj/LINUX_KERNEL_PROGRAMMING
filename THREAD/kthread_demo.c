#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static struct task_struct *thread1;

static int thread_fn(void *data)
{
    while (!kthread_should_stop()) {
        pr_info("Kernel Thread Running...\n");
        ssleep(5);
    }

    pr_info("Kernel Thread Stopped\n");
    return 0;
}

static int __init my_kthread_init(void)
{
    pr_info("Creating Kernel Thread\n");

    thread1 = kthread_run(thread_fn, NULL, "my_kthread");

    if (IS_ERR(thread1)) {
        pr_err("Unable to create thread\n");
        return PTR_ERR(thread1);
    }

    return 0;
}

static void __exit my_kthread_exit(void)
{
    pr_info("Stopping Kernel Thread\n");

    if (thread1)
        kthread_stop(thread1);
}

module_init(my_kthread_init);
module_exit(my_kthread_exit);
