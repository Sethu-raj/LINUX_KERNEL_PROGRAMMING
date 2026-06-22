#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Two Kernel Threads Example");

static struct task_struct *thread1;
static struct task_struct *thread2;

static int thread_fn1(void *data)
{
    while (!kthread_should_stop()) {
        pr_info("Thread 1 Running\n");
        ssleep(2);
    }

    pr_info("Thread 1 Stopped\n");
    return 0;
}

static int thread_fn2(void *data)
{
    while (!kthread_should_stop()) {
        pr_info("Thread 2 Running\n");
        ssleep(3);
    }

    pr_info("Thread 2 Stopped\n");
    return 0;
}

static int __init two_kthreads_init(void)
{
    pr_info("Creating Two Kernel Threads\n");

    thread1 = kthread_run(thread_fn1, NULL, "my_thread1");
    if (IS_ERR(thread1))
        return PTR_ERR(thread1);

    thread2 = kthread_run(thread_fn2, NULL, "my_thread2");
    if (IS_ERR(thread2)) {
        kthread_stop(thread1);
        return PTR_ERR(thread2);
    }

    return 0;
}

static void __exit two_kthreads_exit(void)
{
    pr_info("Stopping Threads\n");

    if (thread1)
        kthread_stop(thread1);

    if (thread2)
        kthread_stop(thread2);
}

module_init(two_kthreads_init);
module_exit(two_kthreads_exit);
