#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Department{
	char name[20];			//ѧԺ��
	int number;				//ѧԺ���
	int mscore=0;			//������Ŀ�ܷ�
	int wscore=0;			//Ů����Ŀ�ܷ�
	int score=0;			//�ܷ�
}Department;

typedef struct project {		//������Ŀ��ѧԺ
	char name[6][20];
}project;

int s = 6;				//����ѧԺ����
int score[6] = { 7,5,3,2,1,0 };		//ÿ����Ŀǰ�����ĵ÷�

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
	Department S[6];		//����6������ѧԺ
	project man[2];			//����������Ŀ
	project woman[2];		//����Ů����Ŀ
	adddep(S);
	welcome(S, man, woman);

	system("pause");
	return 0;
}

void welcome(Department S[],project man[],project woman[])			//��ӭ����
{
	printf("��ӭ�����˶������ͳ��ϵͳ������\n\n\n\n");

	int n;

	printf("����Ҫִ�еĹ��ܣ�\n\n");
	printf("����1�������Ŀ����\n");
	printf("����2����Ҫ�����ѧԺ��\n");
	printf("����3������Ҫ����в�ѯ\n");
	printf("�����������ּ��˳�����\n\n");

	printf("�����룺");
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

void adddep(Department S[])			//��Ӳμ��˶����ѧԺ��
{
	printf("��������ĸ�ѧԺ�ı�ż����ƣ��м��ÿո������\n");
	printf("���磺1 �����ѧԺ\n");
	for (int i = 0; i < s; i++)
		scanf("%d %s", &S[i].number, S[i].name);
	system("cls");
}

void addscore(Department S[],project man[],project woman[])			//�����Ŀ����
{
	int n;
	printf("�����ǲ���������ѧԺ��\n");
	for (int i = 0; i < s; i++)
		printf(" %s ", S[i].name);
	printf("\n\n\n");
	printf("�������Ҫ��\n");
	printf("����1�����������Ŀ����\n");
	printf("����2�����Ů����Ŀ����\n");
	printf("����3���˳�����\n");
	printf("�����������ַ�����һ��\n\n");
	printf("�����룺");
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

void addmscore(Department S[], project man[], project woman[])			//���������Ŀ�ķ���
{
	for (int i = 0; i < 2; i++)
	{
		printf("�����ǲ���������ѧԺ��\n");
		for (int i = 0; i < s; i++)
			printf(" %s ", S[i].name);
		printf("\n\n\n");

		int k;
		printf("����������Ŀ%dǰ%d����ѧԺ����\n\n",i+1,s);
		for (int j = 0; j < s; j++)
		{
			printf("��%d����", j + 1);
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
				printf("��ѧԺδ�μ��˶��ᣬ��������\n");
				j--;
			}
		}
		system("cls");
	}
	addscore(S, man, woman);
}

void addwscore(Department S[], project man[], project woman[])			//���Ů����Ŀ�ķ���
{
	for (int i = 0; i < 2; i++)
	{
		printf("�����ǲ���������ѧԺ��\n");
		for (int i = 0; i < s; i++)
			printf(" %s ", S[i].name);
		printf("\n\n\n");

		printf("����Ů����Ŀ%d��ǰ%d����ѧԺ����\n\n",i+1,s);
		for (int j = 0; j < s; j++)
		{
			int k;
			printf("��%d����", j + 1);
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
				printf("��ѧԺδ�μ��˶��ᣬ��������\n");
				j--;
			}
		}
		system("cls");
	}
	addscore(S, man, woman);
}

void print(Department S[],project man[],project woman[])						//����Ҫ�����ѧԺ
{
	int n;
	printf("�������Ҫ��\n\n");
	printf("����1������ѧԺ����������ѧԺ\n");
	printf("����2������ѧԺ�ܷ��������ѧԺ\n");
	printf("����3������������Ŀ�ܷ��������ѧԺ\n");
	printf("����4������Ů����Ŀ�ܷ��������ѧԺ\n");
	printf("����5���˳�����\n");
	printf("�����������ַ�����һ��\n\n");
	printf("�����룺");
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

void printnumber(Department S[], project man[], project woman[])					//����ѧԺ����������ѧԺ
{
	Department z;
	printf("��ѧԺ����������ѧԺ��\n\n");
	for(int i=0;i<s-1;i++)
		for (int j = 0; j < s-1-i; j++)
			if (S[j].number > S[j+1].number)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}

	for (int i = 0; i < s; i++)
		printf("��%d�ţ�%s\n",S[i].number, S[i].name);

	int a;
	printf("\n�Ƿ���������\n");
	printf("����1�������������2�˳�\n");
	printf("�����룺");
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

void printscore(Department S[], project man[], project woman[])					//����ѧԺ�ܷ��������ѧԺ
{
	Department z;
	printf("����ѧԺ�ֽܷ������ѧԺ��\n\n");
	for(int i=0;i<s-1;i++)
		for(int j=0;j<s-1-i;j++)
			if (S[j].score < S[j + 1].score)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("�ֵܷ�%d����%s�������ǣ�%d\n", i+1, S[i].name,S[i].score);

	int a;
	printf("\n�Ƿ���������\n");
	printf("����1�������������2�˳�\n");
	printf("�����룺");
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

void printmscore(Department S[], project man[], project woman[])				//����������Ŀ�ܷ��������ѧԺ
{
	Department z;
	printf("����������Ŀ�ֽܷ������ѧԺ��\n\n");
	for (int i = 0; i < s - 1; i++)
		for (int j = 0; j < s - 1 - j; j++)
			if (S[j].mscore < S[j + 1].mscore)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("������Ŀ�ֵܷ�%d����%s�������ǣ�%d\n", i+1, S[i].name,S[i].mscore);

	int a;
	printf("\n�Ƿ���������\n");
	printf("����1�������������2�˳�\n");
	printf("�����룺");
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

void printwscore(Department S[], project man[], project woman[])			//����Ů����Ŀ�ܷ��������ѧԺ
{
	Department z;
	printf("����Ů����Ŀ�ܷ��������ѧԺ��\n\n");
	for (int i = 0; i < s - 1; i++)
		for (int j = 0; j < s - 1 - j; j++)
			if (S[j].wscore < S[j + 1].wscore)
			{
				z = S[j];
				S[j] = S[j + 1];
				S[j + 1] = z;
			}
	for (int i = 0; i < s; i++)
		printf("Ů����Ŀ�ֵܷ�%d����%s�������ǣ�%d\n", i + 1, S[i].name,S[i].wscore);

	int a;
	printf("\n�Ƿ���������\n");
	printf("����1�������������2�˳�\n");
	printf("�����룺");
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

void search(Department S[], project man[], project woman[])		//��ѯ����
{
	int n;
	printf("�������Ҫ��\n\n");
	printf("����1����ѧԺ��ѯ�μ�ĳ����Ŀ�����\n");
	printf("����2������Ŀ����ǰ������ѧԺ\n");
	printf("����3���˳�����\n");
	printf("�����������ַ�����һ��\n\n");

	printf("�����룺");
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

void searchDepartment(Department S[],project man[],project woman[])		//��ѧԺ��ѯ�μ�ĳ����Ŀ�����
{
	printf("�����ǲ���������ѧԺ��\n");
	for (int i = 0; i < s; i++)
		printf(" %s ", S[i].name);
	printf("\n\n\n");

	char name[20];
	printf("����Ҫ��ѯ��ѧԺ����");
	scanf("%s", name);

	int n;
	for (n = 0; n < s; n++)
		if (!strcmp(S[n].name, name))
			break;

	if (n >= s)
		printf("��ѧԺδ�����˶���\n");
	else
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < s; j++)
			{
				if (!strcmp(man[i].name[j], name))
					printf("��ѧԺ�μ���������Ŀ%d\n", i + 1);
				if (!strcmp(woman[i].name[j], name))
					printf("��ѧԺ�μ���Ů����Ŀ%d\n", i + 1);
			}
		}
	}

	int a;
	printf("\n�Ƿ������ѯ��\n");
	printf("����1������ѯ������2�˳�\n");
	printf("�����룺");
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

void searchProject(Department S[], project man[], project woman[])			//����Ŀ����ǰ������ѧԺ
{
	char name[10];		//��Ŀ���ͣ����ӻ�Ů��
	printf("�����ѯ����Ŀ���ͣ����ӻ�Ů�ӣ�");
	scanf("%s", name);
	int number;
	printf("���������Ŀ�ı�ţ�");
	scanf("%d", &number);
	switch (strcmp(name, "����"))
	{
	case 0:			//������Ŀ
		printf("������Ŀ%d��ǰ������ѧԺ�ǣ�\n", number);
		for (int i = 0; i < 5; i++)
			printf("��%d����%s", i + 1, man[number-1].name[i]);
		break;
	case 1:		//Ů����Ŀ
		printf("Ů����Ŀ%d��ǰ������ѧԺ�ǣ�\n", number);
		for (int i = 0; i < 5; i++)
			printf("��%d����%s", i + 1, man[number-1].name[i]);
		break;
	}

	int a;
	printf("\n�Ƿ������ѯ��\n");
	printf("����1������ѯ������2�˳�\n");
	printf("�����룺");
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