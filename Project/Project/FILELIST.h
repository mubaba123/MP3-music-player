#pragma once
#ifndef __FILELIST_H__
#define __FILELIST_H__

struct List_t
{
	int num;
	char name[100];//歌单名称
	struct List_t* next;
};

///*歌曲的信息*/
//typedef struct Song_inf
//{
//	char tag[3];
//	char name[30];
//	char singer[30];
//	char Album[30];
//	char year[4];
//	char comment[28];
//	char flag;
//	char track;
//	char style;
//}Song_INF;
//
//void Music_data();/*歌曲的信息*/
//void Music_data1();/*歌曲的信息*/
//void Music_data2();/*歌曲的信息*/
struct List_t* Pre_List();/*读取指定文件中的用户信息，并把相关信息储存到链表*/
struct List_t* GetChoice_List(struct List_t* head);/*输入歌单编号，返回指向对应歌单信息的指针*/
struct List_t* LoadMedia(struct Media_t* p0);/*将指定歌单中的歌曲信息存入链表中，并返回链表的头节点*/

#endif 


