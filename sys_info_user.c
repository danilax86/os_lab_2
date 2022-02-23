#include <linux/kernel.h>
#include <sys/syscall.h>
#include <linux/ptrace.h>
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
	char *a = argv[1];
	int pid_id = atoi(a);

	printf("%d",pid_id);

	struct syscall_info result = { 0 };

	syscall_info_syscall(pid_id);

//	printf("Syscall_number: %d", result.data.nr)

	return 0;
}
