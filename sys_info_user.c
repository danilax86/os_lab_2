#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_syscall_info 441

long syscall_info_syscall(int pid_input)
{
	return syscall(__NR_syscall_info, pid_input);
}

int main(int argc, char **argv)
{
	syscall_info_syscall(argv[1]);
	return 0;
}
