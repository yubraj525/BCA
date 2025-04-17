#include <stdio.h>
#include <stdlib.h> // Required for exit()
#include<conio.h>

#define SIZE 5

struct list {
    int arr[SIZE];
    int c;
};

struct list mylist;// Initialize list count to 0

// Function prototypes
void display();
void inserting();
  void insertinginfront();

int main() {
	mylist.c=0;
    int ch;

    while (1) {  // Loop to keep menu active

  
        printf("\n1: Display\n");
        printf("2: Insertingin last\n");
        printf("3: Insertinginfront\n");
		printf("4: Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &ch); 

        switch (ch) {

            case 1:
            	 	  system("cls");
                display();
                break;
            case 2:
            	  system("cls");
                inserting();
                break;
            case 3:
            	  system("cls");
                  insertinginfront();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
getch();
    return 0;
}

// Display function
void display() {

	int i;
    printf("Displaying list contents:\n");
    if (mylist.c == 0) {
        printf("List is empty.\n");
        return;
    }

    for ( i = 0; i < mylist.c; i++) {
        printf("%d ", mylist.arr[i]);
    }
    printf("\n");
}


void insertAfront() {
    int n, i;
    if (mylist.c == SIZE) {
        printf("List is full\n");
    } else {
        printf("Enter a number:\t");
        scanf("%d", &n);
        for (i = mylist.c; i > 0; i--)
            mylist.arr[i] = mylist.arr[i - 1];
        mylist.arr[0] = n;
        mylist.c++;
        printf("\nNumber added successfully\n");
    }

}

  void insertinginfront(){
    int i, a;
    
    // Check if the list is full
    if (mylist.c == SIZE) {
        printf("List is full, cannot insert more items.\n");
        return;
    }

    printf("Enter a number to insert at the front: ");
    scanf("%d", &a);

    // Shift elements to the right
    for (i = mylist.c; i > 0; i--) {
        mylist.arr[i] = mylist.arr[i - 1];
    }

    // Insert new element at the front
    mylist.arr[0] = a;
    mylist.c++;  // Increase the count

    printf("Number %d inserted at the front successfully.\n", a);
}

