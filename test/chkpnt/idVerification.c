/* TODO (Admin#1#): ImplementDB */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXLENGTH 25
int typeSelecter=-1;

struct users
{
	char uId[MAXLENGTH];
	char uPw[MAXLENGTH];
	float uBal;
	
};
//1 cus--->NBC
//0 bank-->NBA

//struct users user= {"NBCNick010","dummyPw0318"};
struct users user;

//int getInfo()
//{
//	struct users user;
//	FILE *fp;
//	int i;
////	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
//	fscanf(fp,"%s%s%f",user.uId,user.uPw,&user.uBal);
////	fclose(fp);
//}

//int fileId()
//{
//	FILE *fp;
//	fp=fopen("userId.txt","rb");
//	
//}

int chkId(char id[])
{
	struct users user;
	FILE *fp;
	int i;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	while(fscanf(fp,"%s%s%f",user.uId,user.uPw,&user.uBal)!=EOF)
		if(strcmp(id,user.uId)==0)
			return 1;
	return 0;
//	printf("%s %s %f \n",c1.uId,c1.uPw,c1.bal);


	fclose(fp);
}
int chkPw(char pw[])
{
	if(!strcmp(pw,user.uPw))
		return 1;
	return 0;
}

int chkType(char id[])
{
	char checker[3];
	int i;
	for(i=0;i<3;i++)
	{
		checker[i]=id[i];
	}
	if(strcmp(checker,"NBA")==0)
		 typeSelecter=0;
	else if(strcmp(checker,"NBC")==0)
		 typeSelecter=1;
}


int login()
{
	char id[MAXLENGTH],pw[MAXLENGTH],ch;
	int i=0;
	top:
	system("Cls");
	printf("\n______________________\n");
	printf("***Login Page***");
	printf("\n______________________\n");
	fflush(stdin);
	printf("\nEnter your ID: ");
	gets(id);
	if(chkId(id))
	{
		again:
		system("Cls");
		printf("\nEnter your ID: %s\n",id);
		printf("Enter password: ");
		fflush(stdin);
		while(1)
		{
			if(i<0)
				i=0;
			ch=getch();
			if(ch==13)
				break;
			if(ch==8)
			{
				putch('\b');
				putch(' ');
				putch('\b');
				i--;
				continue;
			}
			pw[i++]=ch;
			putch('*');
		}
		pw[i]='\0';
		i=0;
		if(!chkPw(pw))
		{
			printf("\nWrong Password!!!\nEnter again?(Y/N)");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
				goto again;
			else	return -7;
		}
		printf("\nPassword Entry Successful...");
		getch();
		system("Cls");
		chkType(id);
	}
	else
	{
		printf("\nWrong ID!!!\nEnter again?(Y/N)");
		fflush(stdin);
		scanf(" %c",&ch);
		if(ch=='y'||ch=='Y')
			goto top;
		else	return -7;
	}
}

void main()
{
	int menuCh,bpCh,cpCh;
	choice1:
	system("Cls");
	printf("\n__________________________\n");
	printf("\t***Menu***");
	printf("\n__________________________\n");
	printf("\n1. Login\n");
	printf("\n2. Customer Support\n");
	printf("\n3. Help\n");
	printf("\n4. Exit\n");
	scanf("%d",&menuCh);
	switch(menuCh)
	{
		case 1:
			system("Cls");
		fflush(stdin);
			login();
			if( typeSelecter==1)
			{
				//customeerFile
				//Id-Pw-Balance
				//Customer Page
				printf("\n________________________________\n");
				printf("\t***Customers Page***");
				printf("\n________________________________\n");
				printf("\n1. Check Balance\n");
				printf("\n2. Send Money\n");
				printf("\n3. Topup\n");
				printf("\n4. Exit\n");
			}
			else if( typeSelecter==0)
			{
				//Bank Page
				printf("\n__________________________\n");
				printf("\t***Bank Page***");
				printf("\n__________________________\n");
				printf("\n1. View Customers' List\n");
				printf("\n2. Add Customer\n");
				printf("\n3. Update Customers Balance\n");
				printf("\n4. Exit\n");
				
				
			}
			break;
		case 2:
			system("Cls");
			printf("Telephone:\t01435318");
			printf("\nEmail:\t\tbank@nepal.com");
			getch();
			goto choice1;
			break;
		case 3:
			system("Cls");
			printf("Help Text Here");
			getch();
			goto choice1;
			break;
		case 4:
		default:
			return;
	}	
}

