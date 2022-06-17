#ifndef __LINUX_GETPROCESSINFS22_H
#define __LINUX_GETPROCESSINFS22_H
#include <linux/linkage.h>
#include <linux/types.h>
#include <linux/unistd.h>

struct procdat
{
	long counter;
	long nice;
	pid_t pid;
	pid_t pidparent;
	long uid;
	int priority;
	long state;
	unsigned long policy;
	long prio;
};

#endif
