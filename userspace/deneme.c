#include <linux/getprocessinfS22.h>
#include <stdio.h>
#include <unistd.h>
main(){
	struct procdat mydata;	
	int f = 25; 
	getprocessinfS22(f,&mydata);
	if(f <= 22 && f > 0){
		printf("Counter: %ld\n",mydata.counter);
		printf("Nice: %ld\n",mydata.nice);
		printf("Pid: %d\n",mydata.pid);
		printf("Pidparent: %d\n",mydata.pidparent);
		printf("Uid: %ld\n",mydata.uid);
		printf("Priority: %d\n",mydata.priority);
		printf("State: %ld\n",mydata.state);
		printf("Policy: %lu\n",mydata.policy);
		printf("Prio: %ld\n",mydata.prio);

	}
	else if(f > 22){
		printf("State: %ld\n",mydata.state);

	}
		
		
	else
		return -1;
	return 0;
}
