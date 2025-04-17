////inficx to post fix
#include<stdio.h>
#define MAX 100
#include <ctype.h> // Required for isalnum()
#include<string.h>
typedef  struct{
	char arr[MAX];
	int tos;
}stack;



void push(stack *s,char c){
	s->arr[++s->tos]=c;
	

}
char pop(stack *s){
	
return s->arr[s->tos--];
	
}

int prior(char c){
	
if(c==')')
return 0;

if(c=='*' || c=='/' )
return 2;

if(c=='+'|| c=='-')
return 1;

if(c=='$')
return 3;

}





int main(){
	stack s,p;
	char exp[MAX];
	s.tos=-1;
	p.tos=-1;
	int i=0;
	printf("enter a expression:");
	fflush(stdin);
 fgets(exp, MAX, stdin);  // Use fgets instead of gets
for(i=strlen(exp);i>=0;i--){
	if(isalnum(exp[i])){
		push(&p,exp[i]);
	}
	else if(exp[i]==')'){
		push(&p,exp[i]);
	}
	else if(exp[i]=='('){
		while(p.arr[p.tos]!=')'){
			push(&s,pop(&p));
		}
		pop(&p);
	}
	else{
		
		int stackKoValue=	prior(p.arr[p.tos]);
		int currentValue=	prior(exp[i]);
		while (currentValue <= stackKoValue && p.tos != -1) {
    			char save = pop(&p);
   				 push(&s, save);
   					 // Update stackKoValue because after each pop, the top element might change
    					if (p.tos != -1)
       			 stackKoValue = prior(p.arr[p.tos]);
					}	
						
					push(&p,exp[i]);
					
	}
}

		
		
		
	  while(p.tos!=-1)//until opstack is not empty
   {
      push(&s,pop(&p));
   }
   
   printf("Prefix Expression is: ");
   
   for(i=s.tos;i>=0;i--)
   {
   
     printf("%c",s.arr[i]);
}
 return 0;
		
		
		
		
	}














