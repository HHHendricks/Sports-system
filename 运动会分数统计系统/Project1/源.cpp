#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Department{
	char name[20];			//学院名
	int number;				//学院编号
	int mscore=0;			//男子项目总分
	int wscore=0;			//女子项目总分
	int score=0;			//总分
}Department;

typedef struct project {		//参与项目的学院
	char name[6][20];
}project;

int s = 6;				//参赛学院数量
int score[6] = { 7,5,3,2,1,0 };		//每个项目前五名的得分

void adddep(Department S[]);
void addmscore(Department S[], project man[], project woman[]);
void addwscore(Department S[], project man[], project woman[]);
void printnumber(Department S[], project man[], project woman[]);
void printscore(Department S[], project man[], project woman[]);
void printmscore(Department S[], project man[], project woman[]);
void printwscore(Department S[], project man[], project woman[]);
void searchDepartment(Department S[],project man[],project woman[]);
void searchProject(Department S[], project man[], project woman[]);
void welcome(Department S[], project man[], project woman[]);
void print(Department S[], project man[], project woman[]);
void addscore(Department S[], project man[], project woman[]);
void search(Department S[], project man[], project woman[]);

int main()
{
	Department S[6];		//定义6个参赛学院
	project man[2];			//两个男子项目
	project woman[2];		//两个女子项目
	adddep(S);
	welcome(S, man, woman);

	system("pause");
	return 0;
}

void welcome(Department S[],project man[],project woman[])			//欢迎界面
{
	printf("欢迎进入运动会分数统计系统！！！\n\n\n\n");

	int n;

	printf("输入要执行的功能：\n\n");
	printf("输入1：添加项目分数\n");
	printf("输入2：按要求输出学院名\n");
	printf("输入3：根据要求进行查询\n");
	printf("输入其他数字键退出程序\n\n");

	printf("请输入：");
	scanf("%d", &n);
	switch (n)
	{
	case 1:
		system("cls");
		addscore(S,man,woman);
		break;
	case 2:
		system("cls");
		print(S,man,woman);
		break;
	case 3:
		system("cls");
		search(S, man, woman);
		break;
	default:
		return;
	}
}

void adddep(Department S[])			//添加参加运动会的学院名
{
	printf("输入参赛的各学院的编号及名称（中间用空格隔开）\n");
	printf("例如：1 计算机学院\n");
	for (int i = 0; i < s; i++)
		scanf("%d %s", &S[i].number, S[i].name);
	system("cls");
}

void addscore(Department S[],project man[],project woman[])			//添加项目分数
{
	int n;
	printf("以下是参赛的所有学院：\n");
	for (int i = 0; i < s; i++)
		printf(" %s ", S[i].name);
	printf("\n\n\n");
	printf("输入你的要求：\n");
	printf("输入1：添加男子项目分数\n");
	printf("输入2：添加女子项目分数\n");
	printf("输入3：退出程序\n");
	printf("输入其他数字返回上一级\n\n");
	printf("请输入：");
	scanf("%d", &n);

	switch (n) {
	case 1:
		system("cls");
		addmscore(S, man,woman);
		break;
	case 2:
		system("cls");
		addwscore(S, man,woman);
		break;
	case 3:
		return;
	default:
		system("cls");
		welcome(S, man, woman);
	}
}

void addmscore(Department S[], project man[], project woman[])			//添加男子项目的分数
{
	for (int i = 0; i < 2; i++)
	{
		printf("以下是参赛的所有学院：\n");
		for (int i = 0; i < s; i++)
			printf(" %s ", S[i].name);
		printf("\n\n\n");

		int k;
		printf("输入男子项目%d前%d名的学院名：\n\n",i+1,s);
		for (int j = 0; j < s; j++)
		{
			printf("第%d名：", j + 1);
			scanf("%s", man[i].name[j]);
			for (k = 0; k < s; k++)
			{
				if (!strcmp(S[k].name, man[i].name[j]))
				{
					S[k].mscore += score[j];
					S[k].score += score[j];
					break;
				}
				
			}
			if (k >= s)
			{
				printf("该学院未参加运动会，重新输入\n");
				j--;
			}
		}
		system("cls");
	}
	addscore(S, man, woman);
}

void addwscore(Department S[], project man[], project woman[])			//添加女子项目的分数
{
	for (int i = 0; i < 2; i++)
	{
		printf("以下是参赛的所有学院：\n");
		for (int i = 0; i < s; i++)
			printf(" %s ", S[i].name);
		printf("\n\n\n");

		printf("输入女子项目%d的前%d名的学院名：\n\n",i+1,s);
		for (int j = 0; j < s; j++)
		{
			int k;
			printf("第%d名：", j + 1);
			scanf("%s", woman[i].name[j]);
			printf("\n");
			for (k = 0; k < s; k++)
			{
				if (!strcmp(S[k].name, woman[i].name[j]))
				{
					S[k].wscore += score[j];
					S[k].score += score[j];
					break;
				}
			}
			if (k >= s)
			{
				printf("该学院未参加运动会，重新输入\n");
				j--;
			}
		}
		system("cls");
	}
	addscore(S, man, woman);
}

void print(Department S[],project man[],project woman[])						//按照要求输出学院
{
	int n;
	printf("输入你的要求：\n\n");
	printf("输入1：按照学院编号升序输出学院\n");
	printf("输入2：按照学院总分升序输出学院\n");
	printf("输入3：按照男子项目总分升序输出学院\n");
	printf("输入4：按照女子项目总分升序输出学院\n");
	printf("输入5：退出程序\n");
	printf("输入其他数字返回上一级\n\n");
	printf("请输入：");
	scanf("%d", &n);
	
	switch (n)
	{
	case 1:
		system("cls");
		printnumber(S,man,woman);
		break;
	case 2:
		system("cls");
		printscore(S,man,woman);
		break;
	case 3:
		system("cls");
		printmscore(S,man,woman);
		break;
	case 4:
		system("cls");
		printwscore(S,man,woman);
		break;
	case 5:
		return;
	default:
		system("cls");
		welcome(S, man, woman);
	}
}

void printnumber(Department S[], project man[], project woman[])					//按照学院编号升序输出学院
{
	Department z;
	printf("按学院编号升序输出学院：\n\n");
	for(int i=0;i<s-1;i++)
		for (int j = 0; j < s-1-i; j++)
			if (S[j].number > S[j+1].number)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}

	for (int i = 0; i < s; i++)
		printf("第%d号：%s\n",S[i].number, S[i].name);

	int a;
	printf("\n是否继续输出？\n");
	printf("输入1继续输出，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		print(S, man, woman);
		break;
	case 2:
		return;
	}
}

void printscore(Department S[], project man[], project woman[])					//按照学院总分升序输出学院
{
	Department z;
	printf("按照学院总分降序输出学院：\n\n");
	for(int i=0;i<s-1;i++)
		for(int j=0;j<s-1-i;j++)
			if (S[j].score < S[j + 1].score)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("总分第%d名：%s，分数是：%d\n", i+1, S[i].name,S[i].score);

	int a;
	printf("\n是否继续输出？\n");
	printf("输入1继续输出，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		print(S, man, woman);
		break;
	case 2:
		return;
	}
}

void printmscore(Department S[], project man[], project woman[])				//按照男子项目总分升序输出学院
{
	Department z;
	printf("按照男子项目总分降序输出学院：\n\n");
	for (int i = 0; i < s - 1; i++)
		for (int j = 0; j < s - 1 - j; j++)
			if (S[j].mscore < S[j + 1].mscore)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("男子项目总分第%d名：%s，分数是：%d\n", i+1, S[i].name,S[i].mscore);

	int a;
	printf("\n是否继续输出？\n");
	printf("输入1继续输出，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		print(S, man, woman);
		break;
	case 2:
		return;
	}
}

void printwscore(Department S[], project man[], project woman[])			//按照女子项目总分升序输出学院
{
	Department z;
	printf("按照女子项目总分升序输出学院：\n\n");
	for (int i = 0; i < s - 1; i++)
		for (int j = 0; j < s - 1 - j; j++)
			if (S[j].wscore < S[j + 1].wscore)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("女子项目总分第%d名：%s，分数是：%d\n", i + 1, S[i].name,S[i].wscore);

	int a;
	printf("\n是否继续输出？\n");
	printf("输入1继续输出，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		print(S, man, woman);
		break;
	case 2:
		return;
	}
}

void search(Department S[], project man[], project woman[])		//查询功能
{
	int n;
	printf("输入你的要求：\n\n");
	printf("输入1：按学院查询参加某个项目的情况\n");
	printf("输入2：按项目查找前五名的学院\n");
	printf("输入3：退出程序\n");
	printf("输入其他数字返回上一级\n\n");

	printf("请输入：");
	scanf("%d", &n);
	
	switch (n)
	{
	case 1:
		system("cls");
		searchDepartment(S,man, woman);
		break;
	case 2:
		system("cls");
		searchProject(S,man, woman);
		break;
	case 3:
		return;
	default:
		system("cls");
		welcome(S, man, woman);
	}
}

void searchDepartment(Department S[],project man[],project woman[])		//按学院查询参加某个项目的情况
{
	printf("以下是参赛的所有学院：\n");
	for (int i = 0; i < s; i++)
		printf(" %s ", S[i].name);
	printf("\n\n\n");

	char name[20];
	printf("输入要查询的学院名：");
	scanf("%s", name);

	int n;
	for (n = 0; n < s; n++)
		if (!strcmp(S[n].name, name))
			break;

	if (n >= s)
		printf("该学院未参与运动会\n");
	else
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < s; j++)
			{
				if (!strcmp(man[i].name[j], name))
					printf("该学院参加了男子项目%d\n", i + 1);
				if (!strcmp(woman[i].name[j], name))
					printf("该学院参加了女子项目%d\n", i + 1);
			}
		}
	}

	int a;
	printf("\n是否继续查询？\n");
	printf("输入1继续查询，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		search(S, man, woman);
		break;
	case 2:
		return;
	}
}

void searchProject(Department S[], project man[], project woman[])			//按项目查找前五名的学院
{
	char name[10];		//项目类型：男子或女子
	printf("输入查询的项目类型（男子或女子）");
	scanf("%s", name);
	int number;
	printf("输入查找项目的编号：");
	scanf("%d", &number);
	switch (strcmp(name, "男子"))
	{
	case 0:			//男子项目
		printf("男子项目%d的前五名的学院是：\n", number);
		for (int i = 0; i < 5; i++)
			printf("第%d名：%s", i + 1, man[number-1].name[i]);
		break;
	case 1:		//女子项目
		printf("女子项目%d的前五名的学院是：\n", number);
		for (int i = 0; i < 5; i++)
			printf("第%d名：%s", i + 1, man[number-1].name[i]);
		break;
	}

	int a;
	printf("\n是否继续查询？\n");
	printf("输入1继续查询，输入2退出\n");
	printf("请输入：");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		system("cls");
		search(S, man, woman);
		break;
	case 2:
		return;
	}
}