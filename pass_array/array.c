#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

static int arr[5];
static int count = 0;

module_param_array(arr, int, &count, 0644);

static int __init array_init(void)
{
    int i;

    printk(KERN_INFO "Array Elements:\n");

    for (i = 0; i < count; i++)
    {
        printk(KERN_INFO "arr[%d] = %d\n", i, arr[i]);
    }

    printk(KERN_INFO "Count = %d\n", count);

    return 0;
}

static void __exit array_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

module_init(array_init);
module_exit(array_exit);
