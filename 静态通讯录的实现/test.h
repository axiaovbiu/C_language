#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _TEST_H_
#define _TEST_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define NAME_SIZE 64
#define TEL_SIZE 15
#define ADDRE_SIZE 128
#define MAX_SIZE 5
typedef struct person
{
	char name[NAME_SIZE];
	char sex;
	unsigned char age;
	char telphone[TEL_SIZE];
	char address[ADDRE_SIZE];
}person_t, *person_p, **person_pp;
typedef struct contact
{
	int size;
	person_t list[MAX_SIZE];
<<<<<<< HEAD
}contact_t,*contact_p,**contact_pp;
=======
}contact_t,*contact_p,*contact_pp;
>>>>>>> 0efe8dfb1fb9a1739d71f5d3ccea26347656dced
void Menu();
void Init_Cont(contact_p cp);
void Add_Person(contact_p cp);
void Dele_Person(contact_p cp);
void Search_Person(contact_p cp);
void Mod_Person(contact_p cp);
void Show_Person(contact_p cp);
void Clear_Contact(contact_p cp);
void Sort_Person(contact_p cp);

#endif