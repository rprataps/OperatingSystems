/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

void halt();

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
processA(){
	wait(1);
	sleep(2);
}
processB(){

	signal(1);
	signal(1);
	sleep(1);
}

void f4_test(){
    kprintf("---------------------->Task 4 (printprocstks)\n");
	kprintf("===>Test case1: given 10 as priority, should only print process null\n");
    printprocstks(10);

}

void f5_test(){
	int processA();
	int processB();
	kprintf("----------------------Task 5 (printsyssummary)\n");

	kprintf("===>Test case1: should print info for only process \"main\" with at least sys_sleep \n");
	syscallsummary_start();        
	sleep(1);
	sleep(1);
	sleep(1);
	resume(create(processA, 200, 20, "ProcA", 1, 1));
	getpid();
	resume(create(processB, 200, 20, "ProcB", 1, 1));
	syscallsummary_stop();
	printsyscalls();
	
}

int main()
{

	kprintf("\n\nHello World, Xinu lives\n\n");
	kprintf("---------------------->Task 1 (zfunction)\n");
	long input;
	input = 2864434397;
	kprintf("Input:  0x%lx\n",input);
	long output=zfunction(input);
	kprintf("Output: 0x%lx\n\n",output);

	kprintf("---------------------->Task 2 (printsegaddress)\n");
	printsegaddress();

	kprintf("---------------------->Task 3 (printtos)\n");
	printtos();

	f4_test();	
	f5_test();
	return 0;
}
