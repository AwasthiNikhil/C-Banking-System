//script to write user id
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	FILE *fp;
	char name[30],acno[8],uId[30],uPw[30],ch='y';
	int count=1;
	float bal;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","wb");
	do{
		//name acno bal
		fflush(stdin);
		printf("Enter name: ");
		gets(name);
		fflush(stdin);
		printf("Enter acno: ");
		gets(acno);
		fflush(stdin);
		printf("Enter Uid: ");
		gets(uId);
		fflush(stdin);
		printf("Enter Upw: ");
		gets(uPw);
		fflush(stdin);
		printf("Enter Balance: ");
		scanf("%f",&bal);
		fprintf(fp,"%3d%30s%30s%30s%30s%10.2f\n",count,name,acno,uId,uPw,bal);
		count++;
	fflush(stdin);
		system("Cls");
		printf("More? ");
		scanf("%c",&ch);
	}while(ch=='y');
	fclose(fp);
}
