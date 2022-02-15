#include <linux/kernel.h>
#include <linux/syscalls.h>

#include <linux/pci.h>

struct pci_dev *dev;

SYSCALL_DEFINE0(pci_dev)
{
	while ((dev = pci_get_device(PCI_ANY_ID, PCI_ANY_ID, dev))) {
		printk(KERN_INFO "pci found [%d]\n", dev->device);
	}
	return 0;
}
