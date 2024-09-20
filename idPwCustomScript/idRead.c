//script to read user id
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 25
struct cus{
	int sNo;
	char acNo[8];
	char na[MAX];
	char uId[MAX];
	char uPw[MAX];
	float uBal;
};
void main()
{
	struct cus c1;
	FILE *fp;
	int i;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	char name[25];

	rewind(fp);	
	while(fscanf(fp,"%d",&c1.sNo)!=EOF)
	{
			fscanf(fp,"%s",name);
			printf("\nName Read Successful");
			getch();
			fscanf(fp,"%s%s%s%f",c1.acNo,c1.uId,c1.uPw,&c1.uBal);
			printf("%d %s %s %s %s %f\n",c1.sNo,name,c1.acNo,c1.uId,c1.uPw,c1.uBal);
	}

	fclose(fp);
}
