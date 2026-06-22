#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static struct task_struct *thread1;
static struct task_struct *thread2;

int counter = 0;

static int thread_fn1(void *data)
{
    int i;

    for (i = 0; i < 100000; i++)
        counter++;

    printk(KERN_INFO "Thread1 Done\n");
    return 0;
}

static int thread_fn2(void *data)
{
    int i;

    for (i = 0; i < 100000; i++)
        counter++;

    printk(KERN_INFO "Thread2 Done\n");
    return 0;
}

static int __init race_init(void)
{
    printk(KERN_INFO "Module Loaded\n");

    thread1 = kthread_run(thread_fn1, NULL, "thread1");
    thread2 = kthread_run(thread_fn2, NULL, "thread2");

    msleep(1000);

    printk(KERN_INFO "Counter Value = %d\n", counter);

    return 0;
}

static void __exit race_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

module_init(race_init);
module_exit(race_exit);
