#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init test_hello_init(void)
{
    char buffer[] = "Hello World. Linux is the best OS";

    print_hex_dump(KERN_INFO,
                   "buf: ",
                   DUMP_PREFIX_OFFSET,
                   16,
                   1,
                   buffer,
                   sizeof(buffer),
                   0);

    return 0;
}

static void __exit test_hello_exit(void)
{
    printk(KERN_INFO "Module Removed\n");
}

module_init(test_hello_init);
module_exit(test_hello_exit);
