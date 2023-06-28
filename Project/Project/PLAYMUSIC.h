#pragma once
#ifndef __PLAYMUSIC_H__
#define __PLAYMUSIC_H__

void Play(struct Media_t* p);/*播放*/
void Play_for(struct Media_t* p);/*单曲播放*/
void drawBack15(struct Media_t* p0);/*快退15秒*/
void goAhead15(struct Media_t* p0);//快进15秒
void volumeUp(struct Media_t* p0);//调高音量
void volumeDown(struct Media_t* p0);//调低音量
void stop(struct Media_t* p0);//停止播放
void continue_play(struct Media_t* p0);//继续播放
void pause(struct Media_t* p0);//暂停播放
void Play_order(struct Media_t* p);/*顺序播放*/
struct Media_t* getNext(struct Media_t* p0, struct Media_t* head);//获取下一首歌指针
struct Media_t* getLast(struct Media_t* p0, struct Media_t* head);//获取上一首歌指针
struct Media_t* random(struct Media_t* p0, struct Media_t* head);/*随机播放*/


#endif 


