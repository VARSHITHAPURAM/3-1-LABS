#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 50
void push(char);
char pop(void);
int top=-1;
char stack[MAX];
int main()
{
 	int i;
 	char str[20],a,b,c;
 	printf("\n\t\t *** CODE GENERATION ***\n\n\t for single register microprocessor");
 	printf("\n\n\n\n ENTER THE POSTFIX EXPRESSION:");
 	gets(str);
 	printf("\n");
 	for(i=0;str[i]!='\0';i++){
 		if(isalpha(str[i]))
 		push(str[i]);
 		else{
 			b=pop();
 			a=pop();
 			switch(str[i]){
 				case '+': printf("\n\n\t\t LOAD %c, R",a);
					  printf("\n\n\t\t ADD %c, R",b);
					  printf("\n\n\t\t MOV temp(R), %c",a);
					  break;
 				case '-': printf("\n\n\t\t LOAD %c, R",a);
					  printf("\n\n\t\t SUB %c, R",b);
					  printf("\n\n\t\t MOV temp(R), %c",a);
					  break;
 				case '*': printf("\n\n\t\t LOAD %c, R",a);
					  printf("\n\n\t\t MUL %c, R",b);
					  printf("\n\n\t\t MOV temp(R), %c",a);
					  break;
 				case '/': printf("\n\n\t\t LOAD %c, R",a);
					  printf("\n\n\t\t DIV %c, R",b);
				 	  printf("\n\n\t\t MOV temp(R), %c",a);
					  break;
 			}
 			push(a);
 		}
 	}
  	return 0;
}

void push(char item)// push unction
{
 if(top==MAX)
 	printf("\n\n STACK OVERFLOW");
 else{
 	top=top+1;
 	stack[top]=item;
 }
}

char pop(void)// pop function
{
 char item;
 if(top==-1)
 	printf("\n STACK UNDERFLOW");
 else {
 	item=stack[top];
 	top--;
 }
 return item;
}
