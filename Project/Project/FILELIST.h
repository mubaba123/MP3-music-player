#pragma once
#ifndef __FILELIST_H__
#define __FILELIST_H__

struct List_t
{
	int num;
	char name[100];//�赥����
	struct List_t* next;
};

///*��������Ϣ*/
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
//void Music_data();/*��������Ϣ*/
//void Music_data1();/*��������Ϣ*/
//void Music_data2();/*��������Ϣ*/
struct List_t* Pre_List();/*��ȡָ���ļ��е��û���Ϣ�����������Ϣ���浽����*/
struct List_t* GetChoice_List(struct List_t* head);/*����赥��ţ�����ָ���Ӧ�赥��Ϣ��ָ��*/
struct List_t* LoadMedia(struct Media_t* p0);/*��ָ���赥�еĸ�����Ϣ���������У������������ͷ�ڵ�*/

#endif 


