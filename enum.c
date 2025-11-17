/*#include<stdio.h>
enum birds{SPARROW,PEACOCK,PARROT};
enum animals{TIGER=8,LION,RABBIT,ZEBRA};
int main(){
	enum birds m = TIGER;
	int k;
	k=m;
	printf("%d\n",k);
	return 0;
}*/

#include<stdio.h>
int main(){
	int y=1,x=0;
	int l=(y++,x++)?y:x;
	printf("%d\n",l);
}
