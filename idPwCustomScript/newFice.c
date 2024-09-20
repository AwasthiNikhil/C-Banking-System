//script to read user id
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct cus{
	int sNo;
	char uId[30],uPw[30];
	float bal;
	
};
struct cus c1;
void main()
{
	
	FILE *fp,*temp;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/new.txt","wb");
	
	while(fscanf(fp,"%s%s%f",c1.uId,c1.uPw,&c1.bal)!=EOF)
	{
		fprintf(temp,"%s%s%f\n",c1.uId,c1.uPw,c1.bal);
	}
	
	fclose(fp);
	fclose(temp);
	getch();
}
