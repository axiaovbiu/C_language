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
void Init_Cont(contact_p cp)//初始化
{
	assert(cp);
	memset(cp->list, 0, sizeof(person_t)*MAX_SIZE);//将空间初始化为0
	cp->size = 0;
}
void Add_Person(contact_p cp)//添加联系人信息
{
	assert(cp!=NULL);
	if(cp->size == MAX_SIZE)//判断通讯录是否为满
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
void Show_Person(contact_p cp)//显示通讯录
{
	assert(cp);
	int i = 0;
	if (cp->size == 0)//判断通讯录是否为空
	{
		printf("Contact is empty!!!\n");
	}
	for (i = 0; i < (cp->size); i++)
	{
		printf("%-2s|%-5c|%-9u|%-12s|%-17s\n", cp->list[i].name, cp->list[i].sex,\
			cp->list[i].age, cp->list[i].telphone, cp->list[i].address);
	}
}
int find(contact_p cp, char *name)//按名查找联系人
{
	int i = 0;
	for (i = 0; i<cp->size; i++)
	{
		if (strcmp(cp->list[i].name, name) == 0)
			return i;
	}
	return -1;
}

void Search_Person(contact_p cp)//按姓名查找联系人
{
	int ret = 0;
	char name[NAME_SIZE];
	assert(cp);
	printf("Please enter name for search :");
	scanf("%s", name);
	ret = find(cp, name);
	if (ret == -1)//判断查找是否合法
	{
		printf("Not find this people\n");
	}
	else
	{
		printf("%-2s|%-5c|%-9u|%-12s|%-17s\n", cp->list[ret].name, cp->list[ret].sex,\
			cp->list[ret].age, cp->list[ret].telphone, cp->list[ret].address);
	}
	

}
void Dele_Person(contact_p cp)//按姓名删除联系人
{
	assert(cp);
	char name[NAME_SIZE];
	int i = 0;
	int ret = 0;
	printf("Please entr name for delete :");
	scanf("%s", name);
	ret = find(cp, name);
	if (ret == -1)//判断查找是否合法
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
	if (ret == -1)//判断查找是否合法
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
void Clear_Contact(contact_p cp)//清空通讯录
{
	cp->size = 0;
}
int person_cmp(const void *x, void *y)//姓名大小比较
{
	person_p _x = (person_p)x;
	person_p _y = (person_p)y;
	return strcmp(_x->name, _y->name);

}
void Sort_Person(contact_p cp)//按姓名排序
{
	qsort(cp->list, cp->size, sizeof(person_t), person_cmp);//利用qsort函数实现比较
	printf("Sort success !!!\n");

}