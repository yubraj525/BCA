#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 20
#define UP 72
#define DOWN 80
#define ENTER 13
struct list {
    int items[SIZE];
    int c;
};
struct list mylist;
void show(int select) {
    system("cls");
    printf("Select an option\n");
    if (select == 1)
        printf("[x]Insert at front\n");
    else
        printf("[1]Insert at front\n");
    if (select == 2)
        printf("[x]Insert at end\n");
    else
        printf("[2]Insert at end\n");
    if (select == 3)
        printf("[x]Insert before an item\n");
    else
        printf("[3]Insert before an item\n");
    if (select == 4)
        printf("[x]Insert after an item\n");
    else
        printf("[4]Insert after an item\n");
    if (select == 5)
        printf("[x]Remove from front\n");
    else
        printf("[5]Remove from front\n");
    if (select == 6)
        printf("[x]Remove from end\n");
    else
        printf("[6]Remove from end\n");
    if (select == 7)
        printf("[x]Remove an item\n");
    else
        printf("[7]Remove an item\n");
    if (select == 8)
        printf("[x]List from front to end\n");
    else
        printf("[8]List from front to end\n");
    if (select == 9)
        printf("[x]List from end to front\n");
    else
        printf("[9]List from end to front\n");
    if (select == 10)
        printf("[x]Search specific item\n");
    else
        printf("[10]Search specific item\n");
    if (select == 11)
        printf("[x]Modify specific item\n");
    else
        printf("[11]Modify specific item\n");
    if (select == 12)
        printf("[x]Exit\n");
    else
        printf("[12]Exit\n");
}

void insertAfront() {
    int n, i;
    if (mylist.c == SIZE) {
        printf("List is full\n");
    } else {
        printf("Enter a number:\t");
        scanf("%d", &n);
        for (i = 0; i < mylist.c; i++)
            mylist.items[i+1] = mylist.items[i];
        mylist.items[0] = n;
        mylist.c++;
        printf("\nNumber added successfully\n");
    }
    getch();
}

void insertAend() {
    int n;
    if (mylist.c == SIZE) {
        printf("New item cannot be added as the list is full\n");
    } else {
        printf("Enter a number:\t");
        scanf("%d", &n);
        mylist.items[mylist.c] = n;
        mylist.c++;
        printf("Number successfully added at end\n");
    }
    getch();
}
void display() {
    int i;
    printf("List contains:\t");
    for (i = 0; i < mylist.c; i++) {
        printf("%d ", mylist.items[i]);
    }
    printf("\n");
    getch();
}
void insertbefore(){
	int n,n1,j,i;
	if(mylist.c==SIZE){
		printf("New item cant be added!!!");
	}else{
		printf("Enter number to insert:\t");
		scanf("%d",&n);
		printf("Enter number to add before:\t");
		scanf("%d",&n1);
		for(i=0;i<mylist.c;i++){
			if(mylist.items[i]==n1){
				for(j=mylist.c;j>i;j--){
				mylist.items[j]=mylist.items[j-1];
			}
				mylist.items[i+1]=n;
				mylist.c++;
			printf("%d number added successfully",n1);
			getch();
			return;
			}
			printf("\n%d number dont exist in the list");
		}
				
	}
}
void insertafter(){
	int n,n1,i,j;
	if(mylist.c==SIZE){
		printf("New item cannt be added in the list.");
	}else{
		printf("Enter a number to insert:\t");
		scanf("%d",&n);
		printf("\nEnter the number to add after:\t");
		scanf("%d",&n1);
		for(i=0;i<mylist.c;i++){
			if(mylist.items[i]==n1){	
				for(j=mylist.c;j>i+1;j--){
					mylist.items[j]=mylist.items[j-1];
				}
				mylist.items[i+1]=n;
				mylist.c++;
				printf("%d successfully added in the list",n);
				getch();
				return;	
			}
		}
			printf("%d donnt exist in the list");
	}
	getch();
}
void Removefront(){
	int i;
	int removed_item=mylist.items[0];
	for(i=1;i<mylist.c;i++){
		mylist.items[i]=mylist.items[i+1];
		mylist.c--;
	}
	printf("%d Item removed successfully",removed_item);
}
void RemoveEnd(){
		int i;
		if(mylist.c==0){
			printf("Nothing to removed");
		}else{
			mylist.c--;
			printf("Item removed successfully");
		}
}
void Remove(){
	int i,j,n;
	int remove;
	if(mylist.c==0){
		printf("Nothing to removed");
	}else{
		printf("Enter the number you want to remove:\t");
		scanf("%d",&n);
		for(i=0;i<mylist.c;i++){
		if(mylist.items[i]==n){
			for(j=i;j<mylist.c-1;j++){
			mylist.items[j]=mylist.items[j+1];
			}
			mylist.c--;
			remove=1;
			}	
		}
		if(remove==1){
			printf("Item removed successfully");
		} else{
			printf("item didnot removed");
		}
	}
}
void search(){
	int i,n;
	int found=0;
	if(mylist.c==0){
		printf("Nothing list is empty");
	}else{
		printf("Enter the number to search:\t");
		scanf("%d",&n);
	for(i=0;i<mylist.c;i++){
		if(mylist.items[i]==n){
			found=1;
		}
	}
	if(found==1){
		printf("%d item found in the list",n);
	}else{
		printf("%d item doesnot exist in the list",n);
	}	
}	
}
void modify(){
	int n,i,n1;
	int modify=0;
	if(mylist.c==0){
		printf("Given list is empty");
	}else{
			printf("Enter the number to modify:\t");
			scanf("%d",&n);
			printf("Insert number:\t ");
			scanf("%d",&n1);
			for(i=0;i<mylist.c;i++){
			if(mylist.items[i]==n){
				mylist.items[i]=n1;
				modify=1;
			}
		}
	} if(modify==1){
		printf("\n%d itam modified with %d",n,n1);
	}else{
		printf("Item didnt modified");
	}
	
}
void displayrev(){
	int i,n;
	if(mylist.c==0)
	{
		printf("Nothing To Display");
	}
	else
	{
		printf("Displaying reverse:\n");
		for(i=mylist.c-1;i>=0;i--)
		{
		printf("%d\t",mylist.items[i]);	
		}
	}
}
void savelist(){
	FILE *fp;
	int i;
	fp=fopen("mylist.txt","w");
	for(i=0;i<mylist.c;i++){
		fprintf(fp,"%d\t",mylist.items[i]);
	}
	fclose(fp);
	
}
void selectoperation(int select) {
    if (select==12){
    		savelist();
       	 exit(0);
     	}
    else if(select==1)
        	insertAfront();
    else if(select==2)
        	insertAend();
     else if(select==3)
     	insertbefore();
	else if(select==4)
		insertafter();
    	else if(select==8)
        	display();
     else if(select==5)
		Removefront();
    	else if(select==6)
        	RemoveEnd();
     else if(select==7)
        	Remove();
    else if(select==9)
          displayrev();
     else if(select==10)
          search();
     else if(select==11)
          modify();
}
void loadlist(){
	FILE *fp;
	int i,n;
	fp=fopen("mylist.txt","r");
	if(fp!=NULL){
		while(feof(fp)==0){
			if(fscanf(fp,"%d\t",&n)==1)
			mylist.items[mylist.c]=n;
			mylist.c++;
		}
	}
}

int main() {
    int choice = 1;
    char ch;
    mylist.c = 0;
    loadlist();
    do {
    	   system("CLS");
        show(choice);
        ch = getch();
        switch (ch) {
            case UP:
                if (choice == 1)
                    choice = 12;
                else
                    choice--;
                break;
            case DOWN:
                if (choice == 12)
                    choice = 1;
                else
                    choice++;
                break;
            case ENTER:
            	system("CLS");
                selectoperation(choice);
                getch();
        }
    } while (1);
    return 0;
}
