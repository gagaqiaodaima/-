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




//用户信息
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



//查找当前账户
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

//初始化密码
void InitialPassword()
{
	strcpy(curAccount->password, "000000");
}

//验证当前账户密码
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


//取款业务
void WithdrawMoney()
{
	int a,b;
	printf("请输入你要取出的金额(Please enter the amount you want to withdraw)\t");
	printf("金额为100的整数(The sum is an integer of 100)\n");
	scanf("%d", &a);
	if (a % 100)
	{
		printf("金额为100的整数!请重新输入(A round number of 100! Please re-enter)\n");
	}
	else
	{
		printf("取款成功(Withdrawals success)\n");
	}
	printf("1.重新取款(To withdraw money)\n");
	printf("2.返回主页(Return to the home page)\n");
	printf("3.退出系统(Log out)\n");
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
			printf("\n\t输入有误，请按照提示再次输入!(Input error, please follow the prompt to enter again!)\t");
			break;
	}			
}

//转账业务
void TransferMoney()
{
	int a,b,c;
	printf("请输入你要转账的账户(Please enter the account to which you want to transfer the money)\t");
	scanf("%d", &c);
	printf("金额为100的整数(The sum is an integer of 100)\n");
	scanf("%d", &a);
	if (a%100)
	{
		printf("金额为100的整数!请重新输入(A round number of 100! Please re-enter)\n");
	}
	else
	{
		printf("转账成功(Transfer success)\n");
	}
	printf("1.重新转账(To transfer)\n");
	printf("2.返回主页(Return to the home page)\n");
	printf("3.退出系统(Log out)\n");
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
			printf("\n\t输入有误，请按照提示再次输入!(Input error, please follow the prompt to enter again!)\t");
			break;
	}			
}

//查询业务页
void Enquiry()
{

	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1：查询余额/未完成(Query balance/not completed)\n");
		printf("\n\t2：查询个人信息(Querying Personal Information)\n");
		printf("\n\t3：返回主页(Return to the home page)\n");
		printf("\n\t0：退出系统(Log out)\n");
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

//查询余额
void EnquiryBalance()
{
	printf("\t您的余额为(Your balance is)：\n\t\t%lf\n",&curAccount->balance);
	printf("\n");
	int a,k = 0;
	while (k < 3)
	{
		printf("\n\t1：返回上一页(Return to previous page)\n");
		printf("\n\t2：返回主页(Return to the home page)\n");
		printf("\n\t0：退出系统(Log out)\n");
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

//查询个人信息
void EnquiryInformation()
{
	printf("\t姓名(The name)：\n\t\t%s\n", curAccount->name);
	printf("\t账号(account)：\n\t\t%s\n", curAccount->username);
	printf("\t联系电话(Contact phone number)：\n\t\t%s\n", curAccount->phonenum);
	printf("\n");
	int a, k = 0;
	while (k < 3)
	{
		printf("\n\t1：返回上一页(Return to previous page)\n");
		printf("\n\t2：返回主页(Return to the home page)\n");
		printf("\n\t0：退出系统(Log out)\n");
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

//修改用户
void ChangeUser()
{
	int a,k = 0;
	char Password[100];
	while (k<3)
	{
		printf("请输入密码(Please enter your password)：\n");
		scanf("%s", Password);
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新用户名称(Please enter a new user name):\n");
			scanf("%s", curAccount->name);
			printf("\n");
			printf("用户名称修改成功！(User name changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页(Return to previous page)\n");
				printf("\n\t2：返回主页(Return to the home page)\n");
				printf("\n\t0：退出系统(Log out)\n");
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
			printf("密码输入错误!(Incorrect password!) \t%d\t请按照提示重新输入(Please enter again as prompted)：\n",3-k);
		}
	}
}

//修改账户
void ChangeAccountNum()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码(Please enter your password)：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新账户号码(Please enter a new account number):\n");
			scanf("%s", curAccount->username);
			system("cls");
			printf("\n");
			printf("账户号码修改成功！(Account number changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页(Return to previous page)\n");
				printf("\n\t2：返回主页(Return to the home page)\n");
				printf("\n\t0：退出系统(Log out)\n");
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
			printf("密码输入错误!(Incorrect password!) \t%d\t请按照提示重新输入(Please enter again as prompted)：\n", 3 - k);
		}
	}
}


//修改联系电话
void Changephone()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码(Please enter your password)：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新联系电话号码(Please enter a new contact number):\n");
			scanf("%s", curAccount->phonenum);
			system("cls");
			printf("\n");
			printf("联系电话修改成功！(Contact number modified successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页(Return to previous page)\n");
				printf("\n\t2：返回主页(Return to the home page)\n");
				printf("\n\t0：退出系统(Log out)\n");
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
			printf("密码输入错误!(Incorrect password!) \t%d\t请按照提示重新输入(Please enter again as prompted)：\n", 3 - k);
		}
	}
}


//修改密码
void ChangePassword()
{
	system("cls");
	int a, k = 0;
	char Password[100];
	while (k < 3)
	{
		printf("请输入密码(Please enter your password)：\n");
		scanf("%s", Password);
		system("cls");
		if (strcmp(Password, curAccount->password) == 0)
		{
			printf("请输入新密码(Please enter a new password):\n");
			scanf("%s", curAccount->password);
			system("cls");
			printf("\n");
			printf("密码修改成功！(Password changed successfully!)\n");
			saveData();
			k = 3;

			int k2 = 0;
			while (k2 < 3)
			{
				printf("\n\t1：返回上一页(Return to previous page)\n");
				printf("\n\t2：返回主页(Return to the home page)\n");
				printf("\n\t0：退出系统(Log out)\n");
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
			printf("密码输入错误!(Incorrect password!) \t%d\t请按照提示重新输入(Please enter again as prompted)：\n", 3 - k);
		}
	}
}


//修改信息选项页
void ChangeInformation()
{
	system("cls");
	int a, k2 =1;
	while (k2)
	{
		printf("\n\t1.修改用户(Modify the user)\n");
		printf("\n\t2.修改账号(Modify the account)\n");
		printf("\n\t3.修改联系电话(Modifying Contact Numbers)\n");
		printf("\n\t4.修改密码(Change the password)\n");
		printf("\n\t9.返回上一页(Return to previous page)\n");
		printf("\n\t0.退出系统(Log out)\n");
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
			printf("输入错误！(Input error!)\t请按照提示重新输入(Please enter again as prompted)：\n");
			break;
		}
	}
}

//菜单页
void homePage()
{
	int a, k1 = 1;
	while (k1)
	{
		k1 = 0;
		printf("\n\t1.取款(withdrawals)\n");
		printf("\n\t2.转帐(transfer)\n");
		printf("\n\t3.查询(The query)\n");
		printf("\n\t4.修改个人资料(Modification of Personal Data)\n");
		printf("\n\t0.退出系统(Log out)\n");
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
			printf("输入错误！(Input error!)\n");
			k1 = 1;
			break;
		}
	}
}


//登录
void ChineseSignIn()
{
	system("cls");
	int m=0,n=0;
	while (m < 3)//3次输入错账号将退出系统
	{
		Account a;
		printf("\n\t请输入账号(Please enter your account number)：\n");
		scanf("%s", a.username);
		system("cls");
		if (findAccount1(a))
		{
			while (n<3)//3次输入错密码将退出系统
			{
				printf("\n\t请输入密码(Please enter your password)：\n");
				scanf("%s", a.password);
				system("cls");

				if (findAccount(a))
				{
					m = 3;
					n = 3;
					printf("\n========登录成功(Login successful)=======\n");
					homePage();
					break;
				}
				else
				{
					m++;
					n++;
					if (n==3)
					{
						printf("\n\t该账号已经被冻结，请联系后台找回。(The account has been frozen, please contact the background to retrieve it)\n");
						InitialPassword();
						break;
					}
					else
					{
						printf("\n\t密码错误(Password mistake)  %d次机会后账号将会被更改为000000(The account will be changed to 000000 after this opportunity)\n", 3 - n);
					}
				}
			}
		}
		else
		{
			m++;
			printf("\n\t没有查找到该用户!(The user was not found!)  %d  请重新输入(Please re-enter)：\n",3-m);
			if (m==3)
			{
				printf("\n\t错误，已退出系统(Error, logged out of system)\n");
				saveData();
				exit(0);
			}
		}
	}
}


//注册
void ChineseSignUp()//中文注册函数
{
	int a,k = 0;
	printf("\n\t欢迎注册(Welcome to register)\n\n");

	Account* P = (Account*)malloc(sizeof(Account));
	P->next = NULL;
	if (head == NULL)
	{
		head = P;
		tail = P;//如果这是第一个创建的结点，则将头 尾指针指向这个结点
	}
	else
	{
		tail->next = P; //如果不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
		printf("请输入你的姓名(Please enter your name)\n");
		scanf("%s", P->name);
		Account A;
		printf("请输入你即将注册的账户号码【10位】(Please enter the account number you are going to register [10 digits])\n");
		scanf("%s", A.username);

		
		if (findAccount2(A))
		{
			printf("该账号已经被注册不可用(The account has been registered and unavailable)\n");
			exit(0);
		}
		else
		{
			strcpy(P->username,A.username);
		}
		printf("请输入你的电话号码【11位】(Please enter your telephone number [11 digits])\n");
		scanf("%s", P->phonenum);
		printf("请设置你的账户密码【6位】(Please set your account password [6 digits])\n");
		scanf("%s", P->password);
		saveData();
		while (k<3)
		{
			system("cls");
			printf("\n\t1：返回登录(Return to the login)\n");
			printf("\n\t0：退出系统(Log out)\n");
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
				printf("密码输入错误!(Incorrect password!) \t%d\t请按照提示重新输入(Please enter again as prompted)：\n", 3 - k);
			}
		}
	}
}

//初始化
void loadData()//初始化函数
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

//开始界面
void start()
{
	int n1,k=1;
	while (k)
	{
	    printf("\n\t1：用户登录(The user login)\n");
		printf("\n\t2：用户注册(User registration)\n");
		printf("\n\t0：退出 Exit\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
		    ChineseSignIn();
			k = 0;
			break;
		case 2:
			ChineseSignUp();//中文注册函数
			k = 0;
			break;
		case 0:
			saveData();
			exit(0);
		default:
			k = 1;
			printf("\n\t输入有误，请按照提示再次输入!(Input error, please follow the prompt to enter again!)\t");
			break;
		}
	}
}


//保存数据
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
