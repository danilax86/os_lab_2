#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_syscall_info 441

long syscall_info_syscall(int pid_id pid)
{
	return syscall(__NR_pci_dev, pid);
}

int main(int argc, char **argv)
{
	int pid_id = (int) strtol(argv[1], NULL, 10)

	syscall_info_syscall(argv[1]);

	return 0;
}
