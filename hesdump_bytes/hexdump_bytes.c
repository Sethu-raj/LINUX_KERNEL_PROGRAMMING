#include <linux/module.h>
#include <linux/kernel.h>

static int __init hexdump_init(void)
{
    char buffer[] = "Hello World";

    pr_info("Module Loaded\n");

    print_hex_dump(KERN_INFO,
                   "BUF: ",
                   DUMP_PREFIX_OFFSET,
                   16,
                   1,
                   buffer,
                   sizeof(buffer),
                   true);

    return 0;
}

static void __exit hexdump_exit(void)
{
    pr_info("Module Removed\n");
}

MODULE_LICENSE("GPL");

module_init(hexdump_init);
module_exit(hexdump_exit);
