#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_pci_dev 440

struct pci_device_info {
	unsigned short vendor_id;
	unsigned short device_id;
};

long pci_dev_syscall(struct pci_device_info *ptr)
{
	return syscall(__NR_pci_dev, ptr);
}

int main()
{
	struct pci_device_info result = { 0 };

	pci_dev_syscall(&result);

	printf("vendor_id: %hu\n", result.vendor_id);
	printf("device_id: %d\n", result.device_id);

	return 0;
}
