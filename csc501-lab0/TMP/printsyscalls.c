#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

int getpidCount[NPROC] = {0};
int gettimeCount[NPROC] = {0};
int killCount[NPROC] = {0};
int signalCount[NPROC] = {0};
int sleepCount[NPROC] = {0};
int waitCount[NPROC] = {0};
int sleep10Count[NPROC];
int startTrace = 0;

extern int currpid;
unsigned long startTime;
unsigned long endTime;

void syscallsummary_start() {
	int i;
            for(i=0;i<NPROC;i++) {
                getpidCount[i]=0;
                gettimeCount[i]=0;
                killCount[i]=0;
                signalCount[i]=0;
                sleepCount[i]=0;
                waitCount[i]=0;
                sleep10Count[i]=0;
        }
	startTrace = 1;
	startTime = ctr1000;
}
void syscallsummary_stop(){
	endTime = ctr1000;
	startTrace=0;
}

void printsyscalls() {
	int i;
	struct pentry *proc;
	unsigned long duration;
	duration = endTime - startTime;
	for(i=0;i<NPROC;i++) {
		proc=&proctab[i];
		//if(proc->pstate != PRFREE) {
			if(getpidCount[i] > 0 || gettimeCount[i] > 0 || killCount[i] > 0 
			|| signalCount[i] > 0 || sleepCount[i] > 0 || waitCount[i] > 0)
				kprintf("\nProcess[pid:%d,name:%s]\n",i,proc->pname);
			if(getpidCount[i] > 0)
				kprintf("SYSCALL: sys_getpid, count: %d, average execution time: %lu (ms)\n",getpidCount[i],duration);
			if(gettimeCount[i] > 0)
				kprintf("SYSCALL: sys_gettime, count: %d, average execution time: %lu (ms)\n",gettimeCount[i],duration);
			if(killCount[i] > 0)
				kprintf("SYSCALL: sys_kill, count: %d, average execution time: %lu (ms)\n",killCount[i],duration);
			if(signalCount[i] > 0)
				kprintf("SYSCALL: sys_signal, count: %d, average execution time: %lu (ms)\n",signalCount[i],duration);
			if(sleepCount[i] > 0)
				kprintf("SYSCALL: sys_sleep, count: %d, average execution time: %lu (ms)\n",sleepCount[i],duration);
                        if(sleep10Count[i] > 0)
                                kprintf("SYSCALL: sys_sleep10, count: %d, average execution time: %lu (ms)\n",sleep10Count[i],duration);
			if(waitCount[i] > 0)
				kprintf("SYSCALL: sys_wait, count: %d, average execution time: %lu (ms)\n",waitCount[i],duration);
		}
	//}
}
