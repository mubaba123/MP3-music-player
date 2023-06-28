#include<stdio.h>
#include<stdlib.h>
#include"PLAYGUI.h"
#include"PLAYLIST.h"

/*��������Ϣ*/
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
	char name[100];//�赥����
	struct List_t* next;
};

/*��ȡָ���ļ��е��û���Ϣ�����������Ϣ���浽����*/
struct List_t* Pre_List()
{
	struct List_t* head, * p, * q;
	int number = 1;/*��¼�赥����*/

	FILE* fp;
	fp = fopen("mediaList.txt", "a+");
	if (fp == NULL)
	{
		face_fileFailure();/*����ļ�����ʧ��*/
		exit(1);
	}

	head = (struct List_t*)malloc(sizeof(struct List_t));
	head->next = NULL;

	p = (struct List_t*)malloc(sizeof(struct List_t));

	fscanf(fp, "%s", p->name);

	p->num = number;
	head->next = p;

	while (!feof(fp))/*�ж��ļ��Ƿ����*/
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

/*����赥��ţ�����ָ���Ӧ�赥��Ϣ��ָ��*/
struct List_t* GetChoice_List(struct List_t* head)
{
	int Choice_List;
	int Flag_List = 0;/*1��ʾ�ɹ������˸������*/
	struct List_t* p = head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t                   ������赥���                                         \n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
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
		printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t\t\t                  �����ڸ赥��ţ�����������                                         \n");
		printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
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

/*��ָ���赥�еĸ�����Ϣ���������У������������ͷ�ڵ�*/
struct Media_t* LoadMedia(struct Media_t* p0)
{
	FILE* fp;
	char path[150];
	strcpy(path, p0->name);
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		face_fileFailure();//����ļ���ʧ�ܣ�
		exit(1);
	}
	struct List_t* head, * p, * q;
	int number = 1;/*��¼��������*/
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
