#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
int main()
{
	int quit = 0;
	int select = 0;
	contact_t ct;
	Init_Cont(&ct);
	while (!quit)
	{
		Menu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Add_Person(&ct);
			break;
		case 2:
			Dele_Person(&ct);
			break;
		case 3:
			Search_Person(&ct);
			break;
		case 4:
			Mod_Person(&ct);
			break;
		case 5:
			Show_Person(&ct);
			break;
		case 6:
			Clear_Contact(&ct);
			break;
		case 7:
			Sort_Person(&ct);
			break;
		case 0:
			printf("Thank you for use!!\n");
			quit = 1;
			break;
		default:
			printf("select error!!! please select again");
			break;
		}
	}
	system("pause");
	return 0;
}