#include "../include/stdlib.h"
 #include "../include/string.h"
#include "../include/video.h"
 #include "../include/stdio.h"
#include "../include/keyboard.h"
#include "kernel.h"

bool menurunning = true;

char* helpmen =
"\n\nBoot Shell\n"
"Boot Hard Drive\n"
"Exit\n\n";

void main_boot() {
	clear_screen(true);
	// printtext("\n\n\nBoot menu: Type boot to continue into pingukernel\n",0x0f,0,true);
	//printtext("\n",0x0f,0,false);
	// main();

	while(menurunning)
        {
                char buf[50];
                scan(buf,50);
                if(strcmp(buf,"boot shell")==0)
                {
                        main();
			clear_screen(true);

                }
		if(strcmp(buf,"boot hard drive")==0) {
			restart();
		}
		if(strcmp(buf,"help")==0) {
			printtext(helpmen,0x0f,'#',true);
			printtext("\n",0x0f,0,false);
		}
		if(strcmp(buf,"exit")==0) {
			menurunning = false;
			printtext("\n\n\n\n                   It is now safe to turn off your computer. \n\n",0x0f,0,true);
}		}
}



int restart(void) {
  __asm__( /* Assembly function body */
"  movw $0x1000,%ax     \n"
"  movw %ax,%ss \n"
"  movw $0xf000,%sp     \n"
"  movw $0x5307,%ax     \n"
"  movw $1,%bx  \n"
"  movw $3,%cx  \n"
"  int  $0x15   \n"
  );
  return 1; // never gets here, due to ret
}
