#include <stdio.h>
extern int _etext, _edata, _end;
void printsegaddress()
{
	kprintf("Address indicating End of the text segment : 0x%08x\n", &_etext);
	kprintf("Address indicating End of the data segment : 0x%08x\n", &_edata);
	kprintf("Address indicating End of the BSS segment  :   0x%08x\n", &_end);
	kprintf("Content preceding text segment: %08x\nContent after text segment: %08x\n", *(&_etext-1), *(&_etext+1));
	kprintf("Content preceding data segment: %08x\nContent after data segment: %08x\n", *(&_edata-1), *(&_edata+1));
	kprintf("Content preceding BSS segment: %08x\nContent after BSS segment: %08x\n", *(&_end-1), *(&_end+1));
	
	kprintf("\n\n");
}
