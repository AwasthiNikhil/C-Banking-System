/* TODO (Admin#1#): ImplementDB */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXLENGTH 25
int typeSelecter=-1,buf_line=0;
char name_buffer[MAXLENGTH*2];
FILE *fp;
struct users
{
	int sNo;
	char name[MAXLENGTH*2];
	char acNo[8];
	char uId[MAXLENGTH];
	char uPw[MAXLENGTH];
	float uBal;
	
};
struct users user;
//1 cus--->NBC
//0 bank-->NBA



int chkId(char id[])
{

	int i;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,user.acNo,user.uId,user.uPw,&user.uBal)!=EOF)
		if(strcmp(id,user.uId)==0)
			return 1;
	return 0;

	
}
int chkPw(char pw[])
{
	if(!strcmp(pw,user.uPw))
	{
//		fclose(fp);
		return 1;
	}
	return 0;//Wrong PW
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


/*Customer Page Functions*/
void checkBal()
{
	system("Cls");
	printf("Hi User %s,\nYour Balance is Rs. %.2f.",user.uId,user.uBal);
	getch();
	system("Cls");
}
void deductAmt(float amt)
{
	fflush(stdin);
	buf_line=user.sNo;
	printf("Buff created\n ");
	getch();
	float newBal;
	newBal=user.uBal-amt;
	printf("Bal deducted\n ");
	getch();
	if(fp!=NULL)
		fclose(fp);
	FILE *temp;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","wb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,user.acNo,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		printf("Scanning file\n ");
		getch();
		fflush(stdin);
		if(buf_line==user.sNo)
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,user.acNo,user.uId,user.uPw,newBal);
		else
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,user.acNo,user.uId,user.uPw,user.uBal);
	}
	user.uBal=newBal;
	fclose(fp);
	fclose(temp);
	printf("\nFile Closed ");
	getch();
	remove("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt");
	rename("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt");
	remove("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt");
	
	
}
	
void sendmoney()
{
	char acNo[8];
	float amt;
	char confirm;
	system("Cls");
	printf("Account Number: ");
	scanf(" %s",acNo);
	amountAgain:
	printf("Amount: ");
	scanf(" %f",&amt);
	if(amt>user.uBal)
	{
		printf("Insufficient Balance!!");
		printf("Try Again?(Y/N)");
		scanf(" %c",&confirm);
		if(confirm=='Y'||confirm=='y')
		{
			system("Cls");
			printf("Account Number: %s\n",acNo);
			goto amountAgain;
		}
		else	goto amountExit;
		
	}
	deductAmt(amt);
	printf("Amount transfer successful.\nYou have Rs. %.2f left in your account.",user.uBal);	
	amountExit:
	getch();
	system("Cls");
}

void topup()
{
	char moNo[10];
	float amt;
	char confirm;
	system("Cls");
	printf("Mobile Number: ");
	scanf(" %s",moNo);
	amountAgain:
	printf("Amount: ");
	scanf(" %f",&amt);
	if(amt>user.uBal)
	{
		printf("Insufficient Balance!!");
		printf("Try Again?(Y/N)");
		scanf(" %c",&confirm);
		if(confirm=='Y'||confirm=='y')
		{
			system("Cls");
			printf("Mobile Number: %ld\n",moNo);
			goto amountAgain;
		}
		else	goto amountExit;
		
	}
	deductAmt(amt);
	printf("Amount transfer successful.\nYou have Rs. %.2f left in your account.",user.uBal);	
	amountExit:
	getch();
	system("Cls");
}


/*BANK PAGE FUNCTIONS FROM HERE*/
void cList()
{
	int nCnt=1;
	char tempAcNo[8];
	if(fp!=NULL)
		fclose(fp);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	system("Cls");
	printf("S.No. Name           UID         A/c No.    Balance\n");
	rewind(fp);
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,tempAcNo,user.uId,user.uPw,&user.uBal)!=EOF)
	{
	
		chkType(user.uId);
		if(typeSelecter==1)
		{
			
			printf("%-6d%-15s%-12s%-10s%-.2f\n",nCnt,name_buffer,user.uId,tempAcNo,user.uBal);
		}
		fflush(stdin);
		nCnt++;
	}
	getch();
	fclose(fp);
	system("Cls");
}


/*From Here*/
addCus()
{
	char choice,ac_buffer[8];
	int newSno=0;
	system("Cls");
	printf("Enter the following details:\n");
	if(fp!=NULL)
		fclose(fp);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","a+b");
	do
	{
		rewind(fp);
		while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,user.acNo,user.uId,user.uPw,&user.uBal)!=EOF)
		{	
			newSno=user.sNo;//To find line number
		}
		
		newSno++;
		
		
		/*Automate NBC*/
//		
		
		fflush(stdin);
		printf("Name: ");
		gets(name_buffer);
		
		fflush(stdin);
		printf("Ac No.: ");
		gets(ac_buffer);
		
		fflush(stdin);
		printf("User Id: ");
		gets(user.uId);
		
		fflush(stdin);
		printf("User Password: ");
		gets(user.uPw);
		
		fflush(stdin);
		printf("User Balance: ");
		scanf("%f",&user.uBal);
		
		fflush(stdin);
		fprintf(fp,"\n%3d%30s%30s%30s%30s%10.2f",newSno,name_buffer,ac_buffer,user.uId,user.uPw,user.uBal);
		printf("\nFile Closed ");
		fflush(stdin);
		printf("\nMore?(Y/N) ");
		scanf(" %c",&choice);
	}while(choice=='Y'||choice=='y');
	fclose(fp);	
	getch();
	system("Cls");
	
}
void main()
{
	system("color 2");
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
			
			/***
			HERE***/
//			typeSelecter=0;
			if( typeSelecter==1)
			{
				int cMenu;
				cPageStart:
				
				printf("\n\t\t\t\t________________________________\n");
				printf("\t\t\t\t\t***Customers Page***");
				printf("\n\t\t\t\t________________________________\n");
				printf("\n\t\t\t\t1. Check Balance\n");
				printf("\n\t\t\t\t2. Send Money\n");
				printf("\n\t\t\t\t3. Topup\n");
				printf("\n\t\t\t\t4. Exit\n");
				scanf("%d",&cMenu);
				switch(cMenu)
				{
					case 1:
						fflush(stdin);
						checkBal();
						
						goto cPageStart;
						break;
					case 2:
						fflush(stdin);
						sendmoney();
						goto cPageStart;
						break;
					case 3:
						fflush(stdin);
						topup();
						goto cPageStart;
						break;
					case 4:
					default:
						//EXIT
						break;
				}
			}
			else if( typeSelecter==0)
			{
				//Bank Page
				int bMenu;
				aPageStart:
				printf("\n__________________________\n");
				printf("\t***Bank Page***");
				printf("\n__________________________\n");
				printf("\n1. View Customers' List\n");
				printf("\n2. Add Customer\n");
				printf("\n3. Update Customers Balance\n");
				printf("\n4. Exit\n");
				scanf("%d",&bMenu);
				switch(bMenu)
				{
					case 1:
						fflush(stdin);
						cList();
						goto aPageStart;
						break;
					case 2:
						fflush(stdin);
						addCus();
						goto aPageStart;
						break;
					case 3:
						fflush(stdin);
//						updateBal();
						goto aPageStart;
						break;
					case 4:
					default:
						break;
				}
				
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
	fclose(fp);
}

