#include <linux/unistd.h>
#include <errno.h>
#include <sys/types.h>
extern int errno;

struct procdat	{
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

_syscall2(int, getprocessinfS22, int, f, struct procdat*, data);
