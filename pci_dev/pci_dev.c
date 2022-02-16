#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/pci.h>
#include <linux/uaccess.h>

struct pci_device_info {
	unsigned short vendor_id;
	unsigned short device_id;
};

SYSCALL_DEFINE1(pci_dev, struct pci_device_info *, info)
{
	struct pci_dev *dev = NULL;
	struct pci_device_info devices[100]; // или ошибка здесь
	int index = 0;

	while ((dev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, dev))) {
		printk(KERN_INFO "----------------------\n");
		devices[index].device_id = dev->device;
		devices[index].vendor_id = dev->vendor;
		printk(KERN_INFO "pci vendor id [%d]\n",
		       devices[index].vendor_id);
		printk(KERN_INFO "pci device id [%d]\n",
		       devices[index].device_id);
		++index;
	}

	copy_to_user(info, &devices,
		     sizeof(struct pci_device_info)); // или ошибка здесь

	return 0;
}
