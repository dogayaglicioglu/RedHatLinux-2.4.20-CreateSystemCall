#include <linux/getprocessinfS22.h>
#include <asm/uaccess.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <asm/system.h>

asmlinkage int sys_getprocessinfS22(int f,struct procdat *data){
	cli();
	struct procdat mydata;
	
	if(f <= 22 && f > 0){
		copy_from_user(&mydata,data,sizeof(struct procdat));

		mydata.counter=current->counter;
		mydata.nice=current->nice;
		mydata.pid=current->pid;
		mydata.pidparent=current->p_pptr->pid;
		mydata.uid=current->uid;
		mydata.priority=current->rt_priority;
		mydata.state=current->state;
		mydata.policy=current->policy;
		mydata.prio=20-current->nice;

		copy_to_user(data,&mydata,sizeof(struct procdat));
		return 0;
	}
	else if(f > 22){
		copy_from_user(&mydata,data,sizeof(struct procdat));
		mydata.state=current->state;
		copy_to_user(data,&mydata,sizeof(struct procdat));	
		return -1;
	}
	else{ 
		return -1;
	}
		
	sti();
	
} 
