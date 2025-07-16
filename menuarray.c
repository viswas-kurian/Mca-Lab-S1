#include<stdio.h>
int a[5],pos = -1;
void insert(int e)
{
	if(pos + 1==5)
	{
		printf("Error: Array is full");
	}
	else
	{
		a[++pos]=e;
	}
}
void delete()
{
	if (pos==-1)
	{
		printf("Error: Array is Empty");
	}
	else
	{
		printf("\n%d",a[pos--]);
	}
}
void search(int se)
{
    if (pos == -1)
    {
        printf("Error: Array is empty\n");
        return;
    }
    int i;
    for (i = 0; i <= pos; i++)
    {
        if (a[i] == se)
        {
            printf("Found value %d at position %d\n", se, i);
            return; 
        }
    }
    printf("Value %d not found\n", se);
}


void sort()
{
	int i,j,temp;
	for(i=0;i<=pos;i++)
	{	
		for(j=0;j<pos-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
		}
	}
	printf("Sorted");
}


void disp()
{
	if (pos==-1)
	{
		printf("Error:Array is full");
	}
	int i;
	for(i =0;i<=pos;i++)
	{
		printf("%d\t",a[i]);
	}
}
int menu()
{
	int ch;
	printf("\nINSERT-1\nDELETE-2\nDISP ALL-3\nSearch-4\nSort-5\nEXIT-6\nEnter your choice: ");
	scanf("%d",&ch);
	return ch;
}
void processArray()
{
	int ch;
	int se;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("Enter the value to insert: ");
				scanf("%d",&ch);
				insert(ch);
				break;
			case 2:
				delete();
				break;
			case 3:
				disp();
				break;
				case 4:
					printf("Enter the value to be searched: ");
					scanf("%d",&se);
					search(se);
					break;
				case 5:
					sort(); 	
					break;
			default:
				printf("Error: Wrong choice");
				break;
		}
	}
}

int main()
{
	processArray();
	return 0;
}
