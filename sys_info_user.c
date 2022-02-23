#include <linux/kernel.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define __NR_syscall_info 441

struct seccomp_data {
	int nr;
	__u32 arch;
	__u64 instruction_pointer;
	__u64 args[6];
};

struct syscall_info {
	__u64 sp;
	struct seccomp_data data;
};

long syscall_info_syscall(int pid_input, struct syscall_info *ptr)
{
	return syscall(__NR_syscall_info, pid_input, ptr);
}

int main(int argc, char **argv)
{
	char *a = argv[1];
	int pid_id = atoi(a);

	printf("Pid_id: %d\n", pid_id);

	struct syscall_info result;

	syscall_info_syscall(pid_id, &result);

	printf("Syscall_number: %d\n", result.data.nr);
	printf("User Stack Pointer: %lld\n", result.sp);

	return 0;
}
