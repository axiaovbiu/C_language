#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
void Menu()
{
	printf("**************************************\n");
	printf("*****  1.Add          2.Dele    *****\n");
	printf("*****  3.Sear         4.Mod     *****\n");
	printf("*****  5.Show         6.Cle     *****\n");
	printf("*****  7.Sort         0.Exit    *****\n");
	printf("**************************************\n");
	printf("Please Select :");

}
void Init_Cont(contact_p cp)//��ʼ��
{
	assert(cp);
	memset(cp->list, 0, sizeof(person_t)*MAX_SIZE);//���ռ��ʼ��Ϊ0
	cp->size = 0;
}
void Add_Person(contact_p cp)//�����ϵ����Ϣ
{
	assert(cp!=NULL);
	if(cp->size == MAX_SIZE)//�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("Contact is full!!!\n");
	}
	printf("Please enter name:");
 	scanf("%s",cp->list[cp->size].name);
	printf("Please enter sex:");
	scanf(" %c",&(cp->list[cp->size].sex));
	printf("Please enter age:");
	scanf(" %u",&(cp->list[cp->size].age));
	printf("Please enter telphone number:");
	scanf(" %s",cp->list[cp->size].telphone);
	printf("Please enter adderss:");
	scanf("  %s",cp->list[cp->size].address);
	(cp->size)++;
	

}
void Show_Person(contact_p cp)//��ʾͨѶ¼
{
	assert(cp);
	int i = 0;
	if (cp->size == 0)//�ж�ͨѶ¼�Ƿ�Ϊ��
	{
		printf("Contact is empty!!!\n");
	}
	for (i = 0; i < (cp->size); i++)
	{
		printf("%-2s|%-5c|%-9u|%-12s|%-17s\n", cp->list[i].name, cp->list[i].sex,\
			cp->list[i].age, cp->list[i].telphone, cp->list[i].address);
	}
}
int find(contact_p cp, char *name)//����������ϵ��
{
	int i = 0;
	for (i = 0; i<cp->size; i++)
	{
		if (strcmp(cp->list[i].name, name) == 0)
			return i;
	}
	return -1;
}

void Search_Person(contact_p cp)//������������ϵ��
{
	int ret = 0;
	char name[NAME_SIZE];
	assert(cp);
	printf("Please enter name for search :");
	scanf("%s", name);
	ret = find(cp, name);
	if (ret == -1)//�жϲ����Ƿ�Ϸ�
	{
		printf("Not find this people\n");
	}
	else
	{
		printf("%-2s|%-5c|%-9u|%-12s|%-17s\n", cp->list[ret].name, cp->list[ret].sex,\
			cp->list[ret].age, cp->list[ret].telphone, cp->list[ret].address);
	}
	

}
void Dele_Person(contact_p cp)//������ɾ����ϵ��
{
	assert(cp);
	char name[NAME_SIZE];
	int i = 0;
	int ret = 0;
	printf("Please entr name for delete :");
	scanf("%s", name);
	ret = find(cp, name);
	if (ret == -1)//�жϲ����Ƿ�Ϸ�
		printf("Not find this people !!\n");
	else
	{
		for (i = ret; i < cp->size; i++)
		{
			cp->list[i] = cp->list[i + 1];
		}
		cp->size--;
		printf("delete success !!\n");
	}
}
void Mod_Person(contact_p cp)
{
	char name[MAX_SIZE];
	int ret = 0;
	printf("Please enter name for modify :");
	scanf("%s", name);
	ret = find(cp, name);
	if (ret == -1)//�жϲ����Ƿ�Ϸ�
	{
		printf("Not find this people");
	}
	else
	{
		printf("Please enter name:");
		scanf("%s", cp->list[ret].name);
		printf("Please enter sex:");
		scanf(" %c", &(cp->list[ret].sex));
		printf("Please enter age:");
		scanf(" %u", &(cp->list[ret].age));
		printf("Please enter telphone number:");
		scanf(" %s", cp->list[ret].telphone);
		printf("Please enter adderss:");
		scanf("  %s", cp->list[ret].address);
	}
}
void Clear_Contact(contact_p cp)//���ͨѶ¼
{
	cp->size = 0;
}
int person_cmp(const void *x, void *y)//������С�Ƚ�
{
	person_p _x = (person_p)x;
	person_p _y = (person_p)y;
	return strcmp(_x->name, _y->name);

}
void Sort_Person(contact_p cp)//����������
{
	qsort(cp->list, cp->size, sizeof(person_t), person_cmp);//����qsort����ʵ�ֱȽ�
	printf("Sort success !!!\n");

}