//script to read user id
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct cus{
	char uId[30],uPw[30];
	float bal;
	
};
void main()
{
	struct cus c1;
	FILE *fp;
	int i;
	char n[25];
	gets(n);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	while(fscanf(fp,"%s%s%f",c1.uId,c1.uPw,&c1.bal)!=EOF)
		if(strcmp(n,c1.uId)==0)
			printf("%s",n);
		
//	printf("%s %s %f \n",c1.uId,c1.uPw,c1.bal);


	fclose(fp);
}
