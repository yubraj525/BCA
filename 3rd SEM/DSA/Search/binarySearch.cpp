#include<stdio.h>
#include<stdlib.h>
int binarysearch(int arr[],int lb,int ub,int key){
	int mid;
	while(lb<=ub){
		mid=(lb+ub)/2;
		if(arr[mid]==key)
		return mid;
		else if(arr[mid]>key)
		return binarysearch(arr,lb,mid-1,key);
		else
		return binarysearch(arr,mid+1,ub,key);
	}
	return -1;//not found and we return -1
}
int main(){
	int arr[]={2,5,8,9,11,15,21,45,59,94,99,102};
	int key,i,n=sizeof(arr)/sizeof(int),pos;
	system("CLS");
	printf("list of numbers:\n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
	printf("\nEnter a number you want to search:");
	scanf("%d\t",&key);
	pos=binarysearch(arr,0,n-1,key);
	if(pos==-1)
	printf("%d does not exist in the list.",key);
	else
	printf("%d found at position %d.",key,pos+1);	
	return 0;	
}
