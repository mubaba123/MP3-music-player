#include<stdio.h>
#include<stdlib.h>
#include"PLAYGUI.h"
#include"PLAYLIST.h"

/*歌曲的信息*/
typedef struct Song_inf
{
	char tag[3];
	char name[30];
	char singer[30];
	char Album[30];
	char year[4];
	char comment[28];
	char flag;
	char track;
	char style;
}Song_INF;

struct List_t 
{
	int num;
	char name[100];//歌单名称
	struct List_t* next;
};

/*读取指定文件中的用户信息，并把相关信息储存到链表*/
struct List_t* Pre_List()
{
	struct List_t* head, * p, * q;
	int number = 1;/*记录歌单个数*/

	FILE* fp;
	fp = fopen("mediaList.txt", "a+");
	if (fp == NULL)
	{
		face_fileFailure();/*输出文件开打失败*/
		exit(1);
	}

	head = (struct List_t*)malloc(sizeof(struct List_t));
	head->next = NULL;

	p = (struct List_t*)malloc(sizeof(struct List_t));

	fscanf(fp, "%s", p->name);

	p->num = number;
	head->next = p;

	while (!feof(fp))/*判断文件是否结束*/
	{
		number++;
		q= (struct List_t*)malloc(sizeof(struct List_t));
		fscanf(fp, "%s", q->name);
		q->num = number;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	p = head->next;
	fclose(fp);
	return head;
}

/*输入歌单编号，返回指向对应歌单信息的指针*/
struct List_t* GetChoice_List(struct List_t* head)
{
	int Choice_List;
	int Flag_List = 0;/*1表示成功输入了歌曲编号*/
	struct List_t* p = head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t                   请输入歌单编号                                         \n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	scanf("%d", &Choice_List);
	while (p != NULL)
	{
		if (p->num == Choice_List)
		{
			Flag_List = 1;
			break;
		}
		p = p->next;
	}
	while (Flag_List == 0)
	{
		p = p->next;
		printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
		printf("\t\t\t\t                  不存在歌单编号，请重新输入                                         \n");
		printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	scanf("%d", &Choice_List);
	while (p != NULL)
	{
		if (p->num == Choice_List)
		{
			Flag_List = 1;
			break;
		}
		p = p->next;
	}
	return p;
}}

/*将指定歌单中的歌曲信息存入链表中，并返回链表的头节点*/
struct Media_t* LoadMedia(struct Media_t* p0)
{
	FILE* fp;
	char path[150];
	strcpy(path, p0->name);
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		face_fileFailure();//输出文件打开失败！
		exit(1);
	}
	struct List_t* head, * p, * q;
	int number = 1;/*记录歌曲个数*/
	head = (struct Media_t*)malloc(sizeof(struct Media_t));
	head->next = NULL;
	p= (struct Media_t*)malloc(sizeof(struct Media_t));
	fscanf(fp, "%s", p->name);
	p->num = number;
	head->next = p;

	while (!feof(fp)) {

		number++;
		q = (struct List_t*)malloc(sizeof(struct List_t));
		fscanf(fp, "%s", q->name);
		q->num = number;
		q->next = NULL;
		p->next = q;
		p = q;
	}

	p = head->next;

	fclose(fp);

	return head;
}
