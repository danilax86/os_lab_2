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
	struct pci_device_info dev_info;

	dev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, dev);
	dev_info.device_id = dev->device;
	dev_info.vendor_id = dev->vendor;

	printk(KERN_INFO "pci vendor id [%d]\n", dev_info.vendor_id);
	printk(KERN_INFO "pci device id [%d]\n", dev_info.device_id);

	copy_to_user(info, &dev_info, sizeof(struct pci_device_info));

	return 0;
}
