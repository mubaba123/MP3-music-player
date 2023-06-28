#include<stdio.h>
#include<io.h>/*_finddata_t结构体用的*/
#include<stdlib.h>
#include"PLAYGUI.h"

/*歌曲信息结构体，包括：序号，文件名*/
struct Media_t
{
	int num;
	char name[100];
	struct Media_t* next;
};


char CataLog[150] = "D:\\*.mp3";/*储存MP3文件的目录，用于读取指定文件夹中的文件*/

/*读取指定文件夹中的MP3文件，并把歌曲相关信息储存到链表*/
struct Media_t* Pre_Media(void)
{
	struct Media_t* head, * p,*q;
	long Handle;/*句柄*/
	int Number = 1;/*记录MP3文件个数*/
	head = (struct Media_t*)malloc(sizeof(struct Media_t));
	head->next = NULL;
	p = (struct Media_t*)malloc(sizeof(struct Media_t));
	struct _finddata_t FileInfo;/*存储文件信息的结构体*/
	char Search[150] = {0};/*想要查找的文件，通配符可以使用*/
	strcpy(Search, CataLog);
	Handle = _findfirst(Search, &FileInfo);
	if (-1 == Handle)
	{
		printf("未找到所需文件。\n");
		return head;
	}
	strcpy(p->name, FileInfo.name);
	p->num = Number;
	head->next = p;
	while (!_findnext(Handle, &FileInfo))/*循环查找其他符合的文件，直到找不到其他的为止*/
	{
		Number++;
		q = (struct Media_t*)malloc(sizeof(struct Media_t));
		strcpy(q->name, FileInfo.name);
		q->num = Number;
		q->next = NULL;
		p->next = q;
		p = q;
	}/*在链表中添加当前查找到的MP3文件*/
	_findclose(Handle);/*关闭句柄*/
	return head;
}

/*显示歌曲列表*/
void ListMedia(struct Media_t* Head)
{
	struct Media_t* p = Head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                               ║\n");
	while (p != NULL)
	{
		printf("\t\t\t\t║   \t*输入%1d，将播放曲目%-10s\t    \t║\n", p->num, p->name);
		p = p->next;
	}//输出链表中的全部信息
	printf("\t\t\t\t║                                               ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

}

/*输入歌曲编号，返回指向对应歌曲信息的指针*/
struct Media_t* GetChoice_Media(struct Media_t* Head)
{
	int Choice_Media;
	int Flag_Media = 0;/*1表示成功输入了歌曲编号*/
	struct Media_t* p = Head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t                   请输入歌曲编号                                         \n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

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
		printf("\t\t不存在请重新输入\n");
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

