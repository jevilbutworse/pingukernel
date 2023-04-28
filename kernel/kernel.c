#include "../include/stdlib.h"
 #include "../include/string.h"
#include "../include/video.h"
 #include "../include/stdio.h"
#include "../include/keyboard.h"

char* usrnme="\nYour current PINGUKERNEL user is: root\n";

char* version="\n\nPINGUKERNEL V0.1 \n";

bool isrunning=true;

char* help=
"\n\nKernel Commands: \n"
"calc-->start calculator \n"
"whoami--> print user info \n"
"help--> print help dialog \n"
"clear-->clears the kernel \n"
"ver--> shows the version number \n"
"shutdown--> exit pingukernel \n";

char* calc=
"+---------------------------+\n"
"| ///////////////////////// |\n"
"+---------------------------+\n"
"| [              1,264.45 ] |\n"
"+---------------------------+\n"
"|                           |\n"
"|                           |\n"
"| [sto] [rcl] [<--] [AC/ON] |\n"
"|                           |\n"
"| [ ( ] [ ) ] [sqr] [  /  ] |\n"
"|                           |\n"
"| [ 7 ] [ 8 ] [ 9 ] [  *  ] |\n"
"|                           |\n"
"| [ 4 ] [ 5 ] [ 6 ] [  -  ] |\n"
"|                           |\n"
"| [ 1 ] [ 2 ] [ 3 ] [  +  ] |\n"
"|                           |\n"
"| [ 0 ] [ . ] [+/-] [  =  ] |\n"
"|                           |\n"
"+---------------------------+\n";

void startcalc();

void main() {

	clear_screen(false);
	printtext("\nWelcome to PINGUKERNEL, type 'help' for help.\n\n",0x0f,0,true);
	printtext("\n",0x0f,0,false);
	while(isrunning)
	{
		char buf[20];
		scan(buf,10);
		if(strcmp(buf,"whoami")==0)
		{
			 printtext(usrnme,0x0f,'#',true);
			 printtext("\n",0x0f,0,false);

		}

		else if(strcmp(buf,"ver")==0) {
			printtext(version,0x0f,'#',true);
			printtext("\n",0x0f,0,false);
		}

		else if(strcmp(buf,"shutdown")==0) {
			isrunning = false;
			// printtext("\n\n\n\n                   It is now safe to turn off your computer. \n\n",0x0f,0,true);
			
		}

		else if(strcmp(buf,"calc")==0)
		{

		  	startcalc();
		  	printtext("quited from calc\n",0x04,0,false);
		}
		else if(strcmp(buf,"print")==0) {
		  	printtext("Type what ever you want to print:",0x0f,0,true);
		  	char ac[50];
                 	scan(ac,50);
		  	char res[10];
		  	itoa(ac,res);
		  	printtext(res,0x0f,0,true);
		}
		else if(strcmp(buf,"help")==0)
		{
		 printtext(help,0x0f,'#',true);
		 printtext("EXPERIMENTAL",0x04,'#',true);
		 printtext(": print--> prints to the kernel \n\n",0x0f,'#',true);
		 printtext("\n",0x0f,0,false);
		}
		else if(strcmp(buf,"clear")==0)
		{
			clear_screen();
		}
		else if (strlen(buf)>0)printtext("PINGUKERNEL cannot find the command given.\n",0x04,0,false);

	}
	 




}
void startcalc()
 {	
	printtext(calc,0x0a,'#',false);
	next_line();
	printtext("operand a,b.operation +,-,/,* q-quit from calc write ops with numpad\n",0x0a,0,false);
		  
 	int stat=1;
 	while(stat)
 	{
		 next_line();
		printtext("a:",0x0a,4,false);

		char ac[10];
		scan(ac,10);

		int a=atoi(ac);

		printtext("b:",0x0a,0,false);

		char bc[10];
		scan(bc,10);
		int b=atoi(bc);


		printtext("op:",0x0a,0,false);
		char op[2];
		scan(op,2);

		 
		switch(op[0])
		{	char res[10];
			case '-':
			
				itoa((a-b),res);

				printtext(res,0x0a,0,false);
				break;

			case '+':

				
				itoa((a+b),res);

				printtext(res,0x0a,0,false);
				break;

			case '*':
 
				
				itoa((a*b),res);

				printtext(res,0x0a,0,false);
				break;

			case '/':

				
				itoa((a/b),res);

				printtext(res,0x0a,0,false);
				break;

			case 'q':
				stat=0;
				break;

		}




	}


 }






int shutdown(void) {
  __asm__( /* Assembly function body */
"  movw $0x1000,%ax	\n"
"  movw %ax,%ss	\n"
"  movw $0xf000,%sp	\n"
"  movw $0x5307,%ax	\n"
"  movw $1,%bx	\n"
"  movw $3,%cx	\n"
"  int  $0x15	\n"
  );
  return 1; // never gets here, due to ret
}
