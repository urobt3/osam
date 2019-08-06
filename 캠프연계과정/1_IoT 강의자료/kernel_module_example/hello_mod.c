/** KERNEL MODULE example **/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int hello_init(void)
{
	printk(KERN_INFO "HELLO MODULE loaded... \n");

	return 0;
}

void hello_exit(void)
{
	printk(KERN_INFO "HELLO MODULE unloaded... \n");
}

module_init(hello_init);
module_exit(hello_exit);

