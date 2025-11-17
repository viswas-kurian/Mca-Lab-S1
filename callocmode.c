#include<stdio.h>
#include<stdlib.h>


int main(){
	int i,n,j,maxCount=0,mode;
	
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);

	int *arr =(int *)calloc(n,sizeof(int));
	
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++){
		int count=0;
		for(j=0;j<n;j++){
			if(arr[j]==arr[i]){
				count++;
			}
		}
			if(count>maxCount){
				maxCount=count;
				mode = arr[i];
			}
	}
	
	printf("The mode in the array is : %d",mode);
	free(arr);
	
	return 0;
	
}
