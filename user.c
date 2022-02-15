#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_pci_dev 440

long pci_dev_syscall(void)
{
        return syscall(__NR_pci_dev);
}

int main()
{
        int ans = 0;
        ans = pci_dev_syscall();

        return 0;
}
