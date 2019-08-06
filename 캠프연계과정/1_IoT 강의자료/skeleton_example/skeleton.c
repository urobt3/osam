/**
 **	SKELETON Device Driver Example for Raspberry Pi
 ** 
 **/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/errno.h>

#include <linux/fs.h>	/** ... for MAJOR(), MINOR() macro **/

#include <asm/uaccess.h>  /** ... for copy_to,from_user() **/
#include <asm/io.h>	/** ... for in/b/w/l(), out/b/w/l/() **/

#include <linux/slab.h>		/** ... for kmalloc() ... **/

int SKELETON_MAJOR = 0;

int skeleton_open (struct inode *inode, struct file *filp)
{
	printk(KERN_INFO "SKELETON: skeleton_open() is called.. \n");

	printk(KERN_INFO "SKELETON: \t Major number = %d \n", MAJOR(inode->i_rdev));
	printk(KERN_INFO "SKELETON: \t Minor number = %d \n", MINOR(inode->i_rdev));
	
	return 0; 
}

int skeleton_release (struct inode *inode, struct file *filp)
{
	printk("SKELETON: skeleton_release() is called.. \n");

	return 0;
}

ssize_t skeleton_read (struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	char *dev_data = "ABCD";
	int err;

	// dev_data = kmalloc(count, GFP_KERNEL);
	// because 'dev_data' has initial data("ABCD"), we don't have to kmalloc

	if( (err = copy_to_user(buf, dev_data, count)) < 0 )
		return err;
	/**
	 **	copy_to_user(to, from, n)
	 **/
	
	printk(KERN_INFO "SKELETON: skeleton_read() is called.. \n");

	// kfree(dev_data);

	return count;
}

ssize_t skeleton_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	char *dev_data;
	int err;

	dev_data = kmalloc(count, GFP_KERNEL);

	if( (err = copy_from_user(dev_data, buf, count)) < 0 )
		return err;
	/**
	 **	copy_from_user(to, from, n)
	 **/
	
	printk(KERN_INFO "SKELETON: skeleton_write() is called.. \n");
	printk(KERN_INFO "SKELETON: \t User write data = %s \n", dev_data);

	kfree(dev_data);

	return count;
}

int skeleton_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
{
	printk(KERN_INFO "SKELETON: skeleton_ioctl() is called.. \n");

        switch(cmd)
        {
 		case 1:  
                {
			printk("\n");
			printk("SKELETON: Keyboard = [1] \n");
                      break;
                }
                case 2:
                {
			printk("\n");
			printk("SKELETON: Keyboard = [2] \n");
                       break;
                }
                case 3:
                {
			printk("\n");
			printk("SKELETON: Keyboard = [3] \n");
                       break;
                }
                case 4:
                {
			printk("\n");
			printk("SKELETON: Keyboard = [4] \n");
 		       break;
                }
                                          
                default:
                        return 0;
        }
        return 0;
}

		
struct file_operations skeleton_fops = {
	.open		= skeleton_open,
	.release	= skeleton_release,
	.read		= skeleton_read,
	.write		= skeleton_write,
	.unlocked_ioctl		= skeleton_ioctl,	
	/** In newer kernels, use .unlocked_ioctl in the place of .ioctl. **/
};


int skeleton_init(void)
{
	int result;

	printk(KERN_INFO "SKELETON: skeleton_init() is called.. \n");

	result = register_chrdev(SKELETON_MAJOR, "SKELETON", &skeleton_fops);

	if (result < 0) {
        	printk(KERN_WARNING "SKELETON: \t Can't get major number! \n");
        	return result;
    	}

    	if(SKELETON_MAJOR == 0)
		SKELETON_MAJOR = result;

	printk("SKELETON: SKELETON_MAJOR = %d \n", SKELETON_MAJOR);

	return 0;
}

void skeleton_exit(void)
{
	unregister_chrdev(SKELETON_MAJOR, "SKELETON");
}

module_init(skeleton_init);
module_exit(skeleton_exit);

MODULE_LICENSE("Dual BSD/GPL");

