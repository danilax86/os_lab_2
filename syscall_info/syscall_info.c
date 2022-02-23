//
// Created by danila on 23.02.2022.
//

#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/ptrace.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/sched/task_stack.h>
#include <linux/export.h>
#include <asm/syscall.h>
#include <linux/uaccess.h>
#include <linux/types.h>

SYSCALL_DEFINE1(syscall_info, int, pid_input)
{
	printk(KERN_INFO "process's pid: %d\n", pid_input);

	struct pid *pid_task = NULL;
	pid_task = find_get_pid(pid_input);

	printk(KERN_INFO "AAAA");

	struct task_struct *task_struct = NULL;
	task_struct = get_pid_task(pid_task, PIDTYPE_PID);

	printk(KERN_INFO "BBBB");

	struct syscall_info sys_info;

	// Вот здесь оно валится
	// Что-то не так с указателями?
	task_current_syscall(task_struct, &sys_info);

	printk(KERN_INFO "user_sp: %llu", sys_info.sp);

	return 0;
}