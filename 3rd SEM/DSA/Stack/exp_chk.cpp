#include<stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
typedef struct {
	int ex[MAX];
	int tos;
}exp;

void push(exp *s,char ch){
	s->ex[++s->tos]=ch;
}

char pop(exp *s){
	return s->ex[s->tos--];
}

int main(){
	exp s;
	s.tos=-1;
	char ch;
	char expression[MAX];
	int i=0,valid=TRUE;
	printf("enter a expressioin\n");
	gets(expression);
	while(expression[i]!='\0'){
		if(expression[i]=='('|| expression[i]=='{'|| expression[i]=='[')
		{
			push(&s,expression[i]);
		}
		else if(expression[i]==')'|| expression[i]=='}'|| expression[i]==']')
		{
			if(s.tos==-1){
			valid=FALSE;
			break;
		}
		
			ch=pop(&s);
			if(!( ch=='('&& expression[i]==')'||ch=='{'&& expression[i]=='}'||ch=='['&& expression[i]==']'))
			{
				valid=FALSE;
				break;
			}
		}
		i++;
	}
	
	if(s.tos!=-1)
	valid=FALSE;
	if(valid==TRUE){
		printf("expression is valid");
	}
	else{
		printf("expression is not valid");
	}
	return 0;
	
}
