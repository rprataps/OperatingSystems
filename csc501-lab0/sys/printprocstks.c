#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
static unsigned long *sp;
void printprocstks(int priority)
{
	int i;
	struct pentry *proc;
//	kprintf("Number of active processes is %d, Max processes is %d\n\n",numproc,NPROC);
	for(i=0;i<NPROC;i++) {
		proc=&proctab[i];
		if(proc->pprio < priority && proc->pstate != PRFREE) {
			kprintf("Process [%s]\n", proc->pname);
                        kprintf("	 pid: %d\n", i);
                        kprintf("	 priority: %d\n", proc->pprio);
			kprintf("	 base: 0x%08x\n", proc->pbase);
			kprintf("	 limit: 0x%08x\n", proc->plimit);
			kprintf("	 size: %d\n", proc->pstklen);
			if(i==currpid){
				asm("movl %esp, sp");
				kprintf("	 pointer: 0x%08x\n", sp);
			} else {
				kprintf("	 pointer: 0x%08x\n", proc->pesp);
			}
			kprintf("\n");
		}
	}
	kprintf("\n");
}
