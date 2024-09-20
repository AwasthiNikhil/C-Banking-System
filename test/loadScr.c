#include<stdio.h>

void loadingggg()
{
	int i,j;
	char l[8]={"LOADING"};
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t");
	for(i=0;i<8;i++)
	{
		for(j=0;j<3;j++)
		{
			usleep(5000);
		}
		
			printf("%c",l[i]);
		
	}
	printf("\n");
	for(i=0;i<40;i++)
	{
		usleep(5000);
		printf("%c",254);
		
	}
	
	
}
void main()
{
	
	
	loadingggg();
	
	getch();
}
