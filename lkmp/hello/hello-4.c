#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Peter Jay Salzman <p@dirac.org>"
#define DRIVER_DESC "A Sample driver"
#define DRIVER_DEVICE "testdevice"


static int hello3_data __initdata = 4;

static int __init init_hello_4(void)
{
	printk(KERN_INFO, "Hello world %d\n", hello3_data);
	return 0;
}


static void __exit cleanup_hello_4(void)
{
	printk(KERN_INFO, "Goodbye world 2\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE(DRIVER_DEVICE);
