#pragma once
#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

/*������Ϣ�ṹ�壬��������ţ��ļ���*/
struct Media_t
{
	int num;
	char name[100];
	struct Media_t* next;
};



struct Media_t* Pre_Media(void);/*��ȡָ���ļ����е�MP3�ļ������Ѹ��������Ϣ���浽����*/
void ListMedia(struct Media_t* Head);/*��ʾ�����б�*/
struct Media_t* GetChoice_Media(struct Media_t* Head);/*���������ţ�����ָ���Ӧ������Ϣ��ָ��*/

#endif 


