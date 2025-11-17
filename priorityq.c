#include<stdio.h>

int data[100],priority[100];
int n = 0;

void enqueue(int value,int pr){
	data[n]=value;
	priority[n]=pr;
	n++;
}

void dequeue(){
	int i=0,maxindex=0;
	
	if(n==0){
		printf("The List is Empty.\n");
	}
	
	for(i=0;i<n;i++){
		if(priority[i]>priority[maxindex]){
			maxindex=i;
		}	
	}
	printf("Dequeued Element %d with Priority %d",data[maxindex],priority[maxindex]);
	
	for(i=maxindex;i<n-1;i++){
		data[i]=data[i+1];
		priority[i]=priority[i+1];
	}
	n--;
}


void disp(){
	int i;
	if(n==0){
		printf("The list is empty\n");
		return;
	}
	
	printf("Priority Queue (Value:Priority): \n");
	for(i=0;i<n;i++){
		printf("%d:%d\n",data[i],priority[i]);
	}
}


int main(){
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    disp();
    dequeue();
    disp();
    dequeue();
    disp();

    return 0;
}
