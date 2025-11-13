#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
typedef struct node{
	int data;
	struct node* next;
}node;

	node* header=NULL;

node* getnode(int data) {
    node* ptr = (node*)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void front(){
	int data;
	node* ptrnew;
	printf("enter data to enter at front");
	scanf("%d",&data);
	ptrnew=getnode(data);
	if (header==NULL){
		header=ptrnew;
	}
	else{
		ptrnew->next=header;
		header=ptrnew;
	}
}
void display() {
    node* ptr = header;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(){
 int choice, data;
    while (1) {
  
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               
                front();
                break;
            case 2:
                printf("Enter data: ");
//                scanf("%d", &data);
//                insertAtEnd();
                break;
            case 3:
                printf("Enter data to delete: ");
//                scanf("%d", &data);
//                deleteNode(data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
