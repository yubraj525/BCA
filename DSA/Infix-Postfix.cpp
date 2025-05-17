////inficx to post fix
#include<stdio.h>
#define MAX 100
#include <ctype.h> // Required for isalnum()
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
	
if(c=='(')
return 0;

if(c=='*' || c=='/' )
return 2;

if(c=='+'|| c=='-')
return 1;

if(c=='$')
return 3;

}

int operatorChk(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}



int main(){
	stack s,p;
	char exp[MAX];
	s.tos=-1;
	p.tos=-1;
	int i=0;
	printf("enter a expression:");
 fgets(exp, MAX, stdin);  // Use fgets instead of gets
	while(exp[i]!='\0'){
					//till not expression is ended
	if (isalnum(exp[i])) {
    push(&s, exp[i]);
}

		else if(exp[i]=='('){				// if ( 
			push(&p,exp[i]);					//push to operator stack
		}		
		
	   else	if(operatorChk(exp[i])){	// if  * + / $
			if(p.tos==-1)
			push(&p,exp[i]);
			
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
		if(exp[i]==')'){
				while(p.arr[p.tos]!='('){
					char save=pop(&p);
					push(&s,save);
				}
				pop(&p);
				
		}
		i++;
		}
		
		
		
		  while(p.tos!=-1)//until opstack is not empty
   {
      push(&s,pop(&p));
   }
   printf("Postfix Expression is: ");
   for(i=0;i<=s.tos;i++)
     printf("%c",s.arr[i]);
 return 0;
		
		
		
		
	}












































//
//
//#include<stdio.h>
//#define MAX 100
//#include <ctype.h> // Required for isalnum()
//
//typedef struct {
//    char arr[MAX];
//    int tos;
//} stack;
//
//void push(stack *s, char c) {
//    s->arr[++s->tos] = c;
//}
//
//char pop(stack *s) {
//    return s->arr[s->tos--];
//}
//
//int prior(char c) {
//    if (c == '(') return 0;
//    if (c == '*' || c == '/') return 2;
//    if (c == '+' || c == '-') return 1;
//    if (c == '$') return 3;
//    return -1; // If it's not an operator, return -1 (though we shouldn't reach here)
//}
//
//int operatorChk(char c) {
//    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
//}
//
//int main() {
//    stack s, p;
//    char exp[MAX];
//    s.tos = -1;
//    p.tos = -1;
//    int i = 0;
//    
//    printf("Enter an expression: ");
//    fgets(exp, MAX, stdin);  // Use fgets instead of gets
//    
//    while (exp[i] != '\0') {
//        // Skip spaces (added this check)
//        if (exp[i] == ' ') {
//            i++;
//            continue;
//        }
//
//        // If it's an operand (alphanumeric)
//        if (isalnum(exp[i])) {
//            push(&s, exp[i]);
//        }
//        // If it's a '('
//        else if (exp[i] == '(') {
//            push(&p, exp[i]);
//        }
//        // If it's an operator
//        else if (operatorChk(exp[i])) {
//            if (p.tos == -1)
//                push(&p, exp[i]);
//            else {
//                int stackKoValue = prior(p.arr[p.tos]);
//                int currentValue = prior(exp[i]);
//
//                while (p.tos != -1 && currentValue <= stackKoValue) {
//                    char save = pop(&p);
//                    push(&s, save);
//                    if (p.tos != -1)
//                        stackKoValue = prior(p.arr[p.tos]);
//                }
//                push(&p, exp[i]);
//            }
//        }
//        // If it's a ')'
//        else if (exp[i] == ')') {
//            while (p.arr[p.tos] != '(') {
//                char save = pop(&p);
//                push(&s, save);
//            }
//            pop(&p); // Pop '('
//        }
//        i++;
//    }
//
//    // Pop all remaining operators from the stack
//    while (p.tos != -1) {
//        push(&s, pop(&p));
//    }
//
//    // Print the postfix expression
//    printf("Postfix Expression is: ");
//    for (i = 0; i <= s.tos; i++) {
//        printf("%c", s.arr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

