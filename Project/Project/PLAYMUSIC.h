#pragma once
#ifndef __PLAYMUSIC_H__
#define __PLAYMUSIC_H__

void Play(struct Media_t* p);/*����*/
void Play_for(struct Media_t* p);/*��������*/
void drawBack15(struct Media_t* p0);/*����15��*/
void goAhead15(struct Media_t* p0);//���15��
void volumeUp(struct Media_t* p0);//��������
void volumeDown(struct Media_t* p0);//��������
void stop(struct Media_t* p0);//ֹͣ����
void continue_play(struct Media_t* p0);//��������
void pause(struct Media_t* p0);//��ͣ����
void Play_order(struct Media_t* p);/*˳�򲥷�*/
struct Media_t* getNext(struct Media_t* p0, struct Media_t* head);//��ȡ��һ�׸�ָ��
struct Media_t* getLast(struct Media_t* p0, struct Media_t* head);//��ȡ��һ�׸�ָ��
struct Media_t* random(struct Media_t* p0, struct Media_t* head);/*�������*/


#endif 


