#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void InitialPassword();         
void homePage();                 
void loadData();                
void saveData();

void WithdrawMoney();            
void TransferMoney();            
void Enquiry();                 
void EnquiryBalance();           
void EnquiryInformation();       


void ChangeInformation();        
void ChangeUser();              
void ChangeAccountNum();         
void Changephone();              
void ChangePassword();           




int n;




//�û���Ϣ
struct Account
{
	char name[100];
	char username[21];
	char phonenum[12];
	char password[7];
	float balance=10000.00;

	struct Account* next;
};

typedef struct Account Account;

Account* head = NULL;
Account* tail = NULL;
Account* curAccount;



int findAccount2(Account A)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, A.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}



//���ҵ�ǰ�˻�
int findAccount1(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->username, a.username) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}

//��ʼ������
void InitialPassword()
{
	strcpy(curAccount->password, "000000");
}

//��֤��ǰ�˻�����
int findAccount(Account a)
{
	Account* curP = head;
	while (curP != NULL)
	{
		if (strcmp(curP->password, a.password) == 0)
		{
			curAccount = curP;
			return 1;
		}
		curP = curP->next;
	}
	return 0;
}


//ȡ��ҵ��
void WithdrawMoney()
{
	int a,b;
	printf("��������Ҫȡ���Ľ��(Please enter the amount you want to withdraw)\t");
	printf("���Ϊ100������(The sum is an integer of 100)\n");
	scanf("%d", &a);
	if (a % 100)
	{
		printf("���Ϊ100������!����������(A round number of 100! Please re-enter)\n");
	}
	else
	{
		printf("ȡ��ɹ�(Withdrawals success)\n");
	}
	printf("1.����ȡ��(To withdraw money)\n");
	printf("2.������ҳ(Return to the home page)\n");
	printf("3.�˳�ϵͳ(Log out)\n");
	scanf("%d",&b);
	switch (b)
	{
		case 1:
		    WithdrawMoney();
		    break;
		case 2:
			homePage();
			break;
		case 3:
			exit(0);
		default:
			printf("\n\t���������밴����ʾ�ٴ�����!(Input error, please follow the prompt to enter again!)\t");
			break;
	}			
}

//ת��ҵ��
void TransferMoney()
{
	int a,b,c;
	printf("��������Ҫת�˵��˻�(Please enter the account to which you want to transfer the money)\t");
	scanf("%d", &c);
	printf("���Ϊ100������(The sum is an integer of 100)\n");
	scanf("%d", &a);
	if (a%100)
	{
		printf("���Ϊ100������!����������(A round number of 100! Please re-enter)\n");
	}
	else
	{
		printf("ת�˳ɹ�(Transfer success)\n");
	}
	printf("1.����ת��(To transfer)\n");
	printf("2.������ҳ(Return to the home page)\n");
	printf("3.�˳�ϵͳ(Log out)\n");
	scanf("%d",&b);
	switch (b)
	{
		case 1:
		    WithdrawMoney();
		    break;
		case 2:
			homePage();
			break;
		case 3:
			exit(0);
		default:
			printf("\n\t���������밴����ʾ�ٴ�����!(Input error, please follow the prompt to enter again!)\t");
			break;
	}			
}

//��ѯҵ��ҳ
void Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1����ѯ���/δ���(Query balance/not completed)\n");
		printf("\n\t2����ѯ������Ϣ(Querying Personal Information)\n");
		printf("\n\t3��������ҳ(Return to the home page)\n");
		printf("\n\t0���˳�ϵͳ(Log out)\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			EnquiryBalance();
			k == 3;
			break;
		case 2:
			EnquiryInformation();
			k == 3;
			break;
		case 3:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//��ѯ���
void EnquiryBalance()
{
	printf("\t�������Ϊ(Your balance is)��\n\t\t%lf\n",&curAccount->balance);
	printf("\n");
	int a,k = 0;
	while (k < 3)
	{
		printf("\n\t1��������һҳ(Return to previous page)\n");
		printf("\n\t2��������ҳ(Return to the home page)\n");
		printf("\n\t0���˳�ϵͳ(Log out)\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//��ѯ������Ϣ
void EnquiryInformation()
{
	printf("\t����(The name)��\n\t\t%s\n", curAccount->name);
	printf("\t�˺�(account)��\n\t\t%s\n", curAccount->username);
	printf("\t��ϵ�绰(Contact phone number)��\n\t\t%s\n", curAccount->phonenum);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1��������һҳ(Return to previous page)\n");
		printf("\n\t2��������ҳ(Return to the home page)\n");
		printf("\n\t0���˳�ϵͳ(Log out)\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			Enquiry();
			k == 3;
			break;
		case 2:
			homePage();
			k == 3;
			break;
		case 0:
			k == 3;
			saveData();
			exit(0);
		default:
			k++;
			break;
		}
	}
}

//�޸��û�
void ChangeUser()
{
	int a,k = 0;
	char Password[100];
	while (k<3)
	{
		printf("����������(Please enter your password)��\n");
		scanf("%s", Password);
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("���������û�����(Please enter a new user name):\n");
			scanf("%s", curAccount->name);
			printf("\n");
			printf("�û������޸ĳɹ���(User name changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ(Return to previous page)\n");
				printf("\n\t2��������ҳ(Return to the home page)\n");
				printf("\n\t0���˳�ϵͳ(Log out)\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k == 3;
					break;
				case 2:
					homePage();
					k == 3;
					break;
				case 0:
					k == 3;
					saveData();
					exit(0);
				default:
					k++;
					break;
				}
			}
		}
		else
		{
			k++;
			printf("�����������!(Incorrect password!) \t%d\t�밴����ʾ��������(Please enter again as prompted)��\n",3-k);
		}
	}
}

//�޸��˻�
void ChangeAccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("����������(Please enter your password)��\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("���������˻�����(Please enter a new account number):\n");
			scanf("%s", curAccount->username);
			system("cls");
			printf("\n");
			printf("�˻������޸ĳɹ���(Account number changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ(Return to previous page)\n");
				printf("\n\t2��������ҳ(Return to the home page)\n");
				printf("\n\t0���˳�ϵͳ(Log out)\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������!(Incorrect password!) \t%d\t�밴����ʾ��������(Please enter again as prompted)��\n", 3 - k);
		}
	}
}


//�޸���ϵ�绰
void Changephone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("����������(Please enter your password)��\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("����������ϵ�绰����(Please enter a new contact number):\n");
			scanf("%s", curAccount->phonenum);
			system("cls");
			printf("\n");
			printf("��ϵ�绰�޸ĳɹ���(Contact number modified successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ(Return to previous page)\n");
				printf("\n\t2��������ҳ(Return to the home page)\n");
				printf("\n\t0���˳�ϵͳ(Log out)\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������!(Incorrect password!) \t%d\t�밴����ʾ��������(Please enter again as prompted)��\n", 3 - k);
		}
	}
}


//�޸�����
void ChangePassword()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("����������(Please enter your password)��\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("������������(Please enter a new password):\n");
			scanf("%s", curAccount->password);
			system("cls");
			printf("\n");
			printf("�����޸ĳɹ���(Password changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1��������һҳ(Return to previous page)\n");
				printf("\n\t2��������ҳ(Return to the home page)\n");
				printf("\n\t0���˳�ϵͳ(Log out)\n");
				scanf("%d", &a);
				switch (a)
				{
				case 1:
					ChangeInformation();
					k2 == 3;
					break;
				case 2:
					homePage();
					k2 == 3;
					break;
				case 0:
					k2 == 3;
					saveData();
					exit(0);
				default:
					k2++;
					break;
				}
			}
		}
		else
		{
			k++;
			system("cls");
			printf("�����������!(Incorrect password!) \t%d\t�밴����ʾ��������(Please enter again as prompted)��\n", 3 - k);
		}
	}
}


//�޸���Ϣѡ��ҳ
void ChangeInformation()
{
	system("cls");
	int a, k2 =1;
	while (k2)
	{
		printf("\n\t1.�޸��û�(Modify the user)\n");
		printf("\n\t2.�޸��˺�(Modify the account)\n");
		printf("\n\t3.�޸���ϵ�绰(Modifying Contact Numbers)\n");
		printf("\n\t4.�޸�����(Change the password)\n");
		printf("\n\t9.������һҳ(Return to previous page)\n");
		printf("\n\t0.�˳�ϵͳ(Log out)\n");
		scanf("%d", &a);

		switch (a)
		{
		case 1:
			ChangeUser();
			k2 = 0;
			break;
		case 2:
			ChangeAccountNum();
			k2 = 0;
			break;
		case 3:
			Changephone();
			k2 = 0;
			break;
		case 4:
			ChangePassword();
			k2 = 0;
			break;
		case 9:
			homePage();
			k2 = 0;
			break;
		case 0:
			saveData();
			exit(0);
		default:
			system("cls");
			printf("�������(Input error!)\t�밴����ʾ��������(Please enter again as prompted)��\n");
			break;
		}
	}
}

//�˵�ҳ
void homePage()
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\t1.ȡ��(withdrawals)\n");
		printf("\n\t2.ת��(transfer)\n");
		printf("\n\t3.��ѯ(The query)\n");
		printf("\n\t4.�޸ĸ�������(Modification of Personal Data)\n");
		printf("\n\t0.�˳�ϵͳ(Log out)\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			WithdrawMoney();
			break;
		case 2:
			TransferMoney();
			break;
		case 3:
			Enquiry();
			break;
		case 4:
			ChangeInformation();
			break;
		case 0:
			saveData();
			exit(0);
			break;
		default:
			printf("�������(Input error!)\n");
			k1 = 1;
			break;
		}
	}
}


//��¼
void ChineseSignIn()
{
	system("cls");
	int m=0,n=0;
	while (m < 3)//3��������˺Ž��˳�ϵͳ
	{
		Account a;
		printf("\n\t�������˺�(Please enter your account number)��\n");
		scanf("%s", a.username);
		system("cls");
		if (findAccount1(a))
		{
			while (n<3)//3����������뽫�˳�ϵͳ
			{
				printf("\n\t����������(Please enter your password)��\n");
				scanf("%s", a.password);
				system("cls");

				if (findAccount(a))
				{
					m = 3;
					n = 3;
					printf("\n========��¼�ɹ�(Login successful)=======\n");
					homePage();
					break;
				}
				else
				{
					m++;
					n++;
					if (n==3)
					{
						printf("\n\t���˺��Ѿ������ᣬ����ϵ��̨�һء�(The account has been frozen, please contact the background to retrieve it)\n");
						InitialPassword();
						break;
					}
					else
					{
						printf("\n\t�������(Password mistake)  %d�λ�����˺Ž��ᱻ����Ϊ000000(The account will be changed to 000000 after this opportunity)\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\tû�в��ҵ����û�!(The user was not found!)  %d  ����������(Please re-enter)��\n",3-m);
			if (m==3)
			{
				printf("\n\t�������˳�ϵͳ(Error, logged out of system)\n");
				saveData();
				exit(0);
			}
		}
	}
}


//ע��
void ChineseSignUp()//����ע�ắ��
{
	int a,k = 0;
	printf("\n\t��ӭע��(Welcome to register)\n\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;//������ǵ�һ�������Ľ�㣬��ͷ βָ��ָ��������
	}
	else
	{
		tail->next = P; //������ǵ�һ�������Ľ�㣬����һ�����ĺ��ָ��ָ��ǰ���
		printf("�������������(Please enter your name)\n");
		scanf("%s", P->name);
		Account A;
		printf("�������㼴��ע����˻����롾10λ��(Please enter the account number you are going to register [10 digits])\n");
		scanf("%s", A.username);

		
		if (findAccount2(A))
		{
			printf("���˺��Ѿ���ע�᲻����(The account has been registered and unavailable)\n");
			exit(0);
		}
		else
		{
			strcpy(P->username,A.username);
		}
		printf("��������ĵ绰���롾11λ��(Please enter your telephone number [11 digits])\n");
		scanf("%s", P->phonenum);
		printf("����������˻����롾6λ��(Please set your account password [6 digits])\n");
		scanf("%s", P->password);
		saveData();
		while (k<3)
		{
			system("cls");
			printf("\n\t1�����ص�¼(Return to the login)\n");
			printf("\n\t0���˳�ϵͳ(Log out)\n");
			scanf("%d", &a);
			if (a == 1)
			{
				ChineseSignIn();
				break;
			}
			else if (a == 0)
			{
				exit(0);
			}
			else
			{
				k++;
				printf("�����������!(Incorrect password!) \t%d\t�밴����ʾ��������(Please enter again as prompted)��\n", 3 - k);
			}
		}
	}
}

//��ʼ��
void loadData()//��ʼ������
{
	FILE* fp = fopen("E:/atm.txt", "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			Account* newNodeP = (Account*)malloc(sizeof(Account));
			fscanf(fp, "%s\t%s\t%s\t%s\n", newNodeP->name, newNodeP->username, newNodeP->phonenum, newNodeP->password);
			newNodeP->next = NULL;

			if (head == NULL)
			{
				head = newNodeP;
				tail = newNodeP;
			}
			else
			{
				tail->next = newNodeP;
				tail = newNodeP;
			}
		}
		fclose(fp);
	}
}

//��ʼ����
void start()
{
	int n1,k=1;
	while (k)
	{
	    printf("\n\t1���û���¼(The user login)\n");
		printf("\n\t2���û�ע��(User registration)\n");
		printf("\n\t0���˳� Exit\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		    ChineseSignIn();
			k = 0;
			break;
		case 2:
			ChineseSignUp();//����ע�ắ��
			k = 0;
			break;
		case 0:
			saveData();
			exit(0);
		default:
			k = 1;
			printf("\n\t���������밴����ʾ�ٴ�����!(Input error, please follow the prompt to enter again!)\t");
			break;
		}
	}
}


//��������
void saveData()
{
	FILE* fp = fopen("D:/atm.txt", "w");
	if (fp != NULL)
	{
		Account* curP = head;
		while (curP != NULL)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\n", curP->name, curP->username, curP->phonenum, curP->password);
			curP = curP->next;
		}
		fclose(fp);
	}
}

int main()
{
	loadData();
	start();
	saveData();
	return 0;
}
