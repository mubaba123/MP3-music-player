#pragma once
#ifndef __PLAYGUI_H__
#define __PLAYGUI_H__
//
//void Play_GUI();
void PLAY_Menu(void);
void face_fileFailure();
void listSongList(struct List_t* head);//输出链表中的全部信息
int Face_Play(struct Media_t* p0);
void listMedia(struct Media_t* head);
void Play_mode();

#endif 
