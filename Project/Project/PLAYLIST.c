#include<stdio.h>
#include<io.h>/*_finddata_t�ṹ���õ�*/
#include<stdlib.h>
#include"PLAYGUI.h"

/*������Ϣ�ṹ�壬��������ţ��ļ���*/
struct Media_t
{
	int num;
	char name[100];
	struct Media_t* next;
};


char CataLog[150] = "D:\\*.mp3";/*����MP3�ļ���Ŀ¼�����ڶ�ȡָ���ļ����е��ļ�*/

/*��ȡָ���ļ����е�MP3�ļ������Ѹ��������Ϣ���浽����*/
struct Media_t* Pre_Media(void)
{
	struct Media_t* head, * p,*q;
	long Handle;/*���*/
	int Number = 1;/*��¼MP3�ļ�����*/
	head = (struct Media_t*)malloc(sizeof(struct Media_t));
	head->next = NULL;
	p = (struct Media_t*)malloc(sizeof(struct Media_t));
	struct _finddata_t FileInfo;/*�洢�ļ���Ϣ�Ľṹ��*/
	char Search[150] = {0};/*��Ҫ���ҵ��ļ���ͨ�������ʹ��*/
	strcpy(Search, CataLog);
	Handle = _findfirst(Search, &FileInfo);
	if (-1 == Handle)
	{
		printf("δ�ҵ������ļ���\n");
		return head;
	}
	strcpy(p->name, FileInfo.name);
	p->num = Number;
	head->next = p;
	while (!_findnext(Handle, &FileInfo))/*ѭ�������������ϵ��ļ���ֱ���Ҳ���������Ϊֹ*/
	{
		Number++;
		q = (struct Media_t*)malloc(sizeof(struct Media_t));
		strcpy(q->name, FileInfo.name);
		q->num = Number;
		q->next = NULL;
		p->next = q;
		p = q;
	}/*����������ӵ�ǰ���ҵ���MP3�ļ�*/
	_findclose(Handle);/*�رվ��*/
	return head;
}

/*��ʾ�����б�*/
void ListMedia(struct Media_t* Head)
{
	struct Media_t* p = Head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                               �U\n");
	while (p != NULL)
	{
		printf("\t\t\t\t�U   \t*����%1d����������Ŀ%-10s\t    \t�U\n", p->num, p->name);
		p = p->next;
	}//��������е�ȫ����Ϣ
	printf("\t\t\t\t�U                                               �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}

/*���������ţ�����ָ���Ӧ������Ϣ��ָ��*/
struct Media_t* GetChoice_Media(struct Media_t* Head)
{
	int Choice_Media;
	int Flag_Media = 0;/*1��ʾ�ɹ������˸������*/
	struct Media_t* p = Head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t                   ������������                                         \n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

	scanf("%d", &Choice_Media);
	while (p != NULL)
	{
		if (p->num == Choice_Media)
		{
			Flag_Media = 1;
			break;
		}
		p = p->next;
	}
	while (Flag_Media == 0)
	{
		p = Head->next;
		printf("\t\t����������������\n");
		scanf("%d", &Choice_Media);
		while (p != NULL)
		{
			if (p->num == Choice_Media)
			{
				Flag_Media = 1;
				break;
			}
			p = p->next;
		}
	}
	return p;
}

