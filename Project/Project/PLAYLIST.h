#pragma once
#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

/*歌曲信息结构体，包括：序号，文件名*/
struct Media_t
{
	int num;
	char name[100];
	struct Media_t* next;
};



struct Media_t* Pre_Media(void);/*读取指定文件夹中的MP3文件，并把歌曲相关信息储存到链表*/
void ListMedia(struct Media_t* Head);/*显示歌曲列表*/
struct Media_t* GetChoice_Media(struct Media_t* Head);/*输入歌曲编号，返回指向对应歌曲信息的指针*/

#endif 


