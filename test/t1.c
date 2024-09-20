/* TODO (Admin#1#): ImplementDB */
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#define MAXLENGTH 25
int typeSelecter=-1,buf_line=0;
char name_buffer[MAXLENGTH*2];
FILE *fp;
int chkId(char id[]);
int chkPw(char pw[]);
int chkType(char id[]);
int login();
void checkBal();
void deductAmt(float amt);
void sendmoney();
void topup();
void cList();
void addAmt(char id[],float amt);
void subAmt(char id[],float amt);
void addCus();
void remCus();
void updateBal();
void loadingggg();

struct users
{
	int sNo;
	char name[MAXLENGTH*2];
	char acNo[8];
	char uId[MAXLENGTH];
	char uPw[MAXLENGTH];
	float uBal;
	
};


//1 cus--->NBC
//0 bank-->NBA

struct users user;

void main()
{
	system("color f1");
	int menuCh,bpCh,cpCh;
	choice1:
	system("Cls");
//	printf("\n\t\t\t\t\t__________________________\n");
	printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
	printf("\t\t\t\t\t%c\t***Menu***     \t %c",186,186);
	printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
//	printf("\n\t\t\t\t\t__________________________\n");

	printf("\n\t\t\t\t\t1. Login\n");
	printf("\n\t\t\t\t\t2. Customer Support\n");
	printf("\n\t\t\t\t\t3. Help\n");
	printf("\n\t\t\t\t\t4. Exit\n\n\n\t\t\t\t\t=> ");
	scanf("%d",&menuCh);
	loadingggg();
	switch(menuCh)
	{
		case 1:
			system("Cls");
		fflush(stdin);
			login();
			loadingggg();
			if( typeSelecter==1)
			{
				
				int cMenu;
				cPageStart:
				system("color f5");
				system("Cls");
//				printf("\n\t\t\t\t________________________________\n");
				printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
				printf("\t\t\t\t\t%c ***Customer's Page***  %c",186,186);
				printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);	
//				printf("\n\t\t\t\t________________________________\n");
				printf("\n\t\t\t\t\t1. Check Balance\n");
				printf("\n\t\t\t\t\t2. Send Money\n");
				printf("\n\t\t\t\t\t3. Topup\n");
				printf("\n\t\t\t\t\t4. Exit\n\n\n\t\t\t\t\t=> ");
				scanf("%d",&cMenu);
				loadingggg();
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
				system("color f4");
				system("Cls");
//				printf("\n__________________________\n");
				printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
				printf("\t\t\t\t\t%c   ***Bank Page***\t %c",186,186);
				printf("\n\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
//				printf("\n__________________________\n");
				printf("\n\t\t\t\t\t1. View Customers' List\n");
				printf("\n\t\t\t\t\t2. Add Customer\n");
				printf("\n\t\t\t\t\t3. Remove Customer\n");
				printf("\n\t\t\t\t\t4. Update Customers Balance\n");
				printf("\n\t\t\t\t\t5. Exit\n\n\n\t\t\t\t\t=> ");
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
						remCus();
						goto aPageStart;
						break;
					case 4:
						fflush(stdin);
						updateBal();
						goto aPageStart;
						break;
					case 5:
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
	printf("\n\t\t\t\t\t______________________\n");
	printf("\n\t\t\t\t\t  ***Login Page***");
	printf("\n\t\t\t\t\t______________________\n");
	fflush(stdin);
	printf("\n\t\t\t\tEnter your ID: ");
	gets(id);
	if(chkId(id))
	{
		again:
		system("Cls");
		printf("\n\t\t\t\t\t______________________\n");
		printf("\n\t\t\t\t\t  ***Login Page***");
		printf("\n\t\t\t\t\t______________________\n");
		printf("\n\t\t\t\tEnter your ID: %s\n",id);
		printf("\n\t\t\t\tEnter password: ");
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
			printf("\n\n\t\t\t\t\tWrong Password!!!\n\t\t\t\t\tEnter again?(Y/N)");
			fflush(stdin);
			scanf("%c",&ch);
			if(ch=='y'||ch=='Y')
				goto again;
			else	return -7;
		}
		printf("\n\n\t\t\t\t\tPassword Entry Successful...");
		getch();
		system("Cls");
		chkType(id);
	}
	else
	{
		printf("\n\n\t\t\t\t\tWrong ID!!!\n\t\t\t\t\tEnter again?(Y/N)");
		fflush(stdin);
		scanf(" %c",&ch);
		if(ch=='y'||ch=='Y')
			goto top;
		else	return -7;
	}
}

void loadingggg()
{
	int i,j;
	system("cls");
	char l[8]={"LOADING"};
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t");
	for(i=0;i<8;i++)
	{
		for(j=0;j<3;j++)
		{
			usleep(7000);
		}
		printf("%c",l[i]);
	}
	printf("\n\t\t\t\t\t");
	for(i=0;i<40;i++)
	{
		usleep(5000);
		printf("%c",254);
	}
}


/*Customer Page Functions*/
void checkBal()
{
	system("Cls");
	printf("\n\n\n\n\t\t\t\t\tHi User %s,\n\n\t\t\t\t\tYour Balance is Rs. %.2f.",user.uId,user.uBal);
	getch();
	system("Cls");
}
void deductAmt(float amt)
{
	fflush(stdin);
	char ac_buffer[8];
	buf_line=user.sNo;

	float newBal;
	newBal=user.uBal-amt;

	if(fp!=NULL)
		fclose(fp);
	FILE *temp;
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","wb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,ac_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		
		fflush(stdin);
		if(buf_line==user.sNo)
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,ac_buffer,user.uId,user.uPw,newBal);
		else
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,ac_buffer,user.uId,user.uPw,user.uBal);
	}
	user.uBal=newBal;
	fclose(fp);
	fclose(temp);
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
	printf("\n\n\n\t\t\t\t\tAccount Number: ");
	scanf(" %s",acNo);
	amountAgain:
	printf("\n\n\t\t\t\t\tAmount: ");
	scanf(" %f",&amt);
	if(amt>user.uBal)
	{
		printf("\n\t\t\t\t\tInsufficient Balance!!");
		printf("\n\t\t\t\t\tTry Again?(Y/N)");
		scanf(" %c",&confirm);
		if(confirm=='Y'||confirm=='y')
		{
			system("Cls");
			printf("\n\n\n\t\t\t\t\tAccount Number: %s\n",acNo);
			goto amountAgain;
		}
		else	goto amountExit;
	}
	deductAmt(amt);
	printf("\n\t\t\t\t\tAmount transfer successful.\n\t\t\t\t\tYou have Rs. %.2f left in your account.",user.uBal);	
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
	printf("\n\n\n\t\t\t\t\tMobile Number: ");
	scanf(" %s",moNo);
	amountAgain:
	printf("\n\t\t\t\t\tAmount: ");
	scanf(" %f",&amt);
	if(amt>user.uBal)
	{
		printf("\n\n\t\t\t\t\tInsufficient Balance!!");
		printf("\n\t\t\t\t\tTry Again?(Y/N)");
		scanf(" %c",&confirm);
		if(confirm=='Y'||confirm=='y')
		{
			system("Cls");
			printf("\n\n\n\t\t\t\t\tMobile Number: %ld\n",moNo);
			goto amountAgain;
		}
		else	goto amountExit;
	}
	deductAmt(amt);
	printf("\n\t\t\t\t\tAmount transfer successful.\n\t\t\t\t\tYou have Rs. %.2f left in your account.",user.uBal);	
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
			nCnt++;
		}
		fflush(stdin);
	}
	getch();
	fclose(fp);
	system("Cls");
}
void addAmt(char id[],float amt)
{
	FILE *temp;
	char acc_buffer[8];
	if(fp!=NULL)
		fclose(fp);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		if(!strcmp(id,user.uId))
		{
			break;
		}
	}
	rewind(fp);
	fflush(stdin);
	buf_line=user.sNo;
	printf("Buff created\n ");
	getch();
	float newBal;
	newBal=user.uBal+amt;
	printf("Bal added\n ");
	getch();
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","wb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		printf("Scanning file\n ");
		getch();
		fflush(stdin);
		if(buf_line==user.sNo)
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,newBal);
		else
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,user.uBal);
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
void subAmt(char id[],float amt)
{
	FILE *temp;
	char acc_buffer[8];
	if(fp!=NULL)
		fclose(fp);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		if(!strcmp(id,user.uId))
		{
			break;
		}
	}
	rewind(fp);
	fflush(stdin);
	buf_line=user.sNo;
	printf("Buff created\n ");
	getch();
	float newBal;
	newBal=user.uBal-amt;
	printf("Bal added\n ");
	getch();
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","wb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		printf("Scanning file\n ");
		getch();
		fflush(stdin);
		if(buf_line==user.sNo)
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,newBal);
		else
			fprintf(temp,"%3d%30s%30s%30s%30s%30.2f\n",user.sNo,name_buffer,acc_buffer,user.uId,user.uPw,user.uBal);
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
void addCus()
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
	printf("\n\n\t\t\t\t\tSuccessful")
	system("Cls");
}
void remCus()
{
	system("cls");
	char id[MAXLENGTH],ac_buffer[8];
	int newSno,iSno=1;
	FILE *temp;
	
	if(fp!=NULL)
		fclose(fp);
	printf("\n\n\n\t\t\t\t\tEnter customer UID: ");
	gets(id);
	fp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt","rb");
	temp=fopen("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","wb");
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,ac_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{	
		chkType(id);
		if(!strcmp(id,user.uId)&&typeSelecter==1)
		{
			newSno=user.sNo;
			break;
		}
		continue;
	}
	rewind(fp);
	while(fscanf(fp,"%d%s%s%s%s%f",&user.sNo,name_buffer,ac_buffer,user.uId,user.uPw,&user.uBal)!=EOF)
	{
		if(newSno==user.sNo)
		{
			continue;
		}
		else
			fprintf(temp,"\n%3d%30s%30s%30s%30s%10.2f",iSno,name_buffer,ac_buffer,user.uId,user.uPw,user.uBal);
		
		iSno++;
	}
	fclose(fp);
	fclose(temp);
	printf("\n\n\t\t\t\t\tSuccessful..");
	getch();
	remove("C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt");
	rename("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt","C:/Users/acer/Desktop/CProject/files/infoCustomer/idpw.txt");
	remove("C:/Users/acer/Desktop/CProject/files/infoCustomer/temp.txt");
	
	
	
	getch();
	system("Cls");
}



void updateBal()
{
	int ch;
	float amt;
	char id[MAXLENGTH];
	system("Cls");
	fflush(stdin);
	printf("Enter user ID: ");
	gets(id);
	printf("1. Add Balance\n2. Subtract Balance");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Amount to add: ");
			scanf("%f",&amt);
			fflush(stdin);
			system("Cls");
			addAmt(id,amt);
			break;
		case 2:
			printf("Amount to subtract: ");
			scanf("%f",&amt);
			fflush(stdin);
			system("Cls");
			subAmt(id,amt);
			break;
		default:
			break;
	}
}
