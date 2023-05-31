/*#include <stdio.h>
#include <string.h>

char input[20];
char op, op1, op2;

char temp[5]={'v','w','x','y','z'};
int temp_pointer=0;

void scan()
{
    for(int i=0;i<strlen(input); i++)
    {
        if((input[i]=='+')||(input[i]=='-')||(input[i]=='*')||(input[i]=='/'))
        {
            op=input[i];
            op1=input[i-1];
            op2=input[i+1];
            printf("\n%c = %c%c%c\n",temp[temp_pointer],op1,op,op2);
          //  cout<<"\n"<<temp[temp_pointer]<<"="<<op1<<op<<op2<<"\n";
            input[i+1]=temp[temp_pointer++];
        }
    }
}

int main()
{
   printf("\nEnter expression:");
   scanf("%s",&input);
   input[strlen(input)-1]='\0';
   scan();
   return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void pm();
void plus();
void divx();


char rev(char *str){
	int n = strlen(str);
	for(int i=0,j=n-1;i<j;i++,j--){
		char ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}

int i,ch,j,l,addr=100;
char ex[10],e[10] ,e1[10],e2[10],id1[5],op[5],id2[5];

void main(){
	while(1){
		printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the expression with assignment operator:");
				scanf("%s",e);
				l=strlen(e);
				e2[0]='\0';
				i=0;
				while(e[i]!='='){
					i++;
				}
				strncat(e2,e,i);
				rev(e);
				e1[0]='\0';
				strncat(e1,e,l-(i+1));
				rev(e1);
				printf("Three address code:\ntemp=%s\n%s=temp\n",e1,e2);
			break;
			
			case 2:
				printf("\nEnter the expression with arithmetic operator:");
				scanf("%s",ex);
				strcpy(e,ex);
				l=strlen(e);
				e1[0]='\0';
				for(i=0;i<l;i++){
					if(e[i]=='+'||e[i]=='-'){
						if(e[i+2]=='/'||e[i+2]=='*'){
							pm();
							break;
						}
						else{
							plus();
							break;
						}
					}
					else if(e[i]=='/'||e[i]=='*'){
						divx();
						break;
					}
				}
			break;
			
			case 3:
				printf("Enter the expression with relational operator");
				scanf("%s%s%s",id1,op,id2);
				if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||(strcmp(op,"==")==0)||(strcmp(op,"!=")==0))==0)
					printf("Expression is error");
				else{
					printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
					addr++;
					printf("\n%d\t T:=0",addr);
					addr++;
					printf("\n%d\t goto %d",addr,addr+2);
					addr++;
					printf("\n%d\t T:=1",addr);	
				}
			break;
			
			case 4:
				exit(0);
		}
	}
}


void pm(){
	rev(e);
	j=l-i-1;
	strncat(e1,e,j);
	rev(e1);
	printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",e1,e[j+1],e[j]);
}

void divx(){
	strncat(e1,e,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",e1,e[i+2],e[i+3]);
}

void plus(){
	strncat(e1,e,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",e1,e[i+2],e[i+3]);
}

