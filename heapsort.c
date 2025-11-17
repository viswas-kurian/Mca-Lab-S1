#include<stdio.h>


void heapify(int a[],int n,int i){
	int largest=i;
	int left = 2*i+1;
	int right = 2*i+2;
	int temp;
	
	if(a[largest]<a[left] && left<n){
		largest=left;
	}
	if(a[largest]<a[right] && right<n){
		largest=right;
	}
	if(largest!=i){
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapify(a,n,largest);
	}
}

void heapSort(int a[10],int n){
	int i;
	int temp;
	for(i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
	
	
}




int main(){
	int arr[100],n,i;
	
	
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	
	printf("Enter elements in the Array: ");
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	
	printf("Array is: ");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	
	heapSort(arr,n);
	printf("Array is: ");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	return 0;
}






