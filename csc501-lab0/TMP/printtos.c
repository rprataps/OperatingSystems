#include <stdio.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>

static unsigned long    *sp;
static unsigned long    *bp;

void printtos()
{
	asm("movl       %esp,sp");
	asm("movl       %ebp,bp");
	kprintf("TOS just before calling              : 0x%08x\n",bp+2);
	//kprintf("TOS holding return address         : 0x%08x\n",bp+1);	
	kprintf("TOS just after getting into printtos : 0x%08x\n",bp);
	kprintf("\n");
	kprintf("Current Stack pointer                : 0x%08x\n",sp);
	kprintf("Contents which are pushed recently in stack, i.e., below current TOS \n");
	kprintf("1. Data[0x%08x] : %08x, in decimal: %d\n",sp+1,*(sp+1),*(sp+1));
	kprintf("2. Data[0x%08x] : %08x, in decimal: %d\n",sp+2,*(sp+2),*(sp+2));
	kprintf("3. Data[0x%08x] : %08x, in decimal: %d\n",sp+3,*(sp+3),*(sp+3));
	kprintf("4. Data[0x%08x] : %08x, in decimal: %d\n",sp+4,*(sp+4),*(sp+4));
	kprintf("5. Data[0x%08x] : %08x, in decimal: %d\n",sp+5,*(sp+5),*(sp+5));
	kprintf("6. Data[0x%08x] : %08x, in decimal: %d\n",sp+6,*(sp+6),*(sp+6));

	kprintf("\n\n");
}

/*
void printtos()
{
	int i=10;
	kprintf("%d %d %d\n",&i,&i+1,&i+2);
	kprintf("%d %d %d %d\n",*(&i),*(&i+1),*(&i+2),*(&i+3));
}
*/

