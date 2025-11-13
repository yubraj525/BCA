#include<stdio.h>
#define SIZE 10
struct student{
	int roll[SIZE];
	int tos;
};
int isEmpty(struct student *s){
	if(s->tos==-1)
	return true;
	return false;
}

int isFull(struct student *s){
	if(s->tos==SIZE-1)
	return true;
	return false;
}

int push(struct student *s,int data){
	if(isFull(s))
	printf("full cannot enter\n");
	s->tos++;
	s->roll[s->tos] = data;

		printf("daata inserted sucess fully\n");
		return 0;
}

int pop(struct student *s){
	if(isEmpty(s))
		printf("stackk is empty \n");
	s->tos--;
		printf("data removed sucess fully\n");
		return 0;
}
void list(struct student s){
	int i;
	if(isEmpty(&s)){
			printf("the stack is empty");
	}else{
		printf("the list contains :\n");

		
	for(i=s.tos;i>-1;i--){
		
		printf("%d\n",s.roll[i]);
	}	
	}

	}



int main() {
    struct student s;
    s.tos = -1;
    int a, b;

    while (1) {
        printf("\n1 - List\n");
        printf("2 - Push\n");
        printf("3 - Pop\n");
        printf("4 - Exit\n");
        printf("Enter choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
            	printf("%d",s.tos);
                list(s);
                break;

            case 2:
                printf("Enter a number to push: \n");
                scanf("%d", &b);
                push(&s,b);
                break;

            case 3:
                pop(&s);
                break;

            case 4:
                return 0;

            default:
                printf("Enter a valid choice.\n");
        }
    }
}


