#include<stdio.h>

int i = 5;//global variable 

void local_variable()
{
	int a = 10;//local variable
	printf("This is a local variable \n%d",a);
	printf("\n");
}

void static_variable()//static variable
{
	static int b = 5;
	printf("This is a static variable: \n%d",b++);
	printf("\n");
}

void register_variable()//register variable
{
	register int r = 0;
	for(r=0;r<=5;r++)
	{
		printf("Displayed using register variable: %d\n",r);
	}
}

int main()
{
	printf("This is a global variable: \n%d",i);
	printf("\n");
	
	local_variable();
	
	static_variable();
	static_variable();
	static_variable();
	
	register_variable();
	return 0;
}


