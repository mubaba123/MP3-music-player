#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>
#include<WinBase.h>
#include<stdlib.h>
#include"PLAYGUI.h"
#include"PLAYLIST.h"
#include"PLAYMUSIC.h"
#include"FILELIST.h"

#pragma comment(lib,"winmm.lib")

int main()
{
	struct Media_t* HEAD_MEDIA=NULL;/*������Ϣ��������ʽ�洢��HEAD_MEDIAΪ����ͷ*/
	struct Media_t* p_Media = NULL;/*ָ�룬ָ��ǰ���ŵĸ����Ľڵ�*/
	
	struct List_t* p_List = NULL;
	struct List_t* HEAD_LIST = Pre_List();/*�赥��Ϣ��������ʽ�洢��HEAD_LISTΪ����ͷ*/

	int Choice_Play = 0;/*����ѡ��Ĳ��Ź��ܵ�ѡ��*/
	int Flag_Play = 1;/*��¼����״̬��0��ʾ�˳�����*/
	void Play_GUI();
	//while(1)
	/*�������������Ӧ�ı�žͿ�ʼ��������*/
	HEAD_MEDIA = Pre_Media();/*��ȡD:\\ .mp3����*/
	ListMedia(HEAD_MEDIA);/*��ʾ�����б�*/
	p_Media = GetChoice_Media(HEAD_MEDIA);/*���������ţ�����ָ���Ӧ������Ϣ��ָ��*/
	Play(p_Media);
loop:
	system("cls");
	PLAY_Menu();

	Flag_Play = 1;

/*0��ֹͣ�����˳�����*/

		int choice = 0;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("CLS");
			stop(p_Media);
			p_List = HEAD_LIST->next;
			listSongList(HEAD_LIST);
			/*system("pause");*/
			p_List = GetChoice_List(HEAD_LIST);
			printf("\n\t\t\t\t %s\n", p_List->name);
			HEAD_MEDIA = LoadMedia(p_List);
			system("pause");
			goto loop;
			break;

		case 2:
			while (Flag_Play == 1)
			{
				Choice_Play = Face_Play(p_Media);
				switch (Choice_Play)
				{
				case 1://��ͣ
					pause(p_Media);
					break;
				case 2://ѡ������
					stop(p_Media);
					ListMedia(HEAD_MEDIA);
					p_Media = GetChoice_Media(HEAD_MEDIA);
					Play(p_Media);
					break;
				case 3://��һ��
					stop(p_Media);
					p_Media = getLast(p_Media, HEAD_MEDIA);
					Play(p_Media);
					break;
				case 4://��һ��
					stop(p_Media);
					p_Media = getNext(p_Media, HEAD_MEDIA);
					Play(p_Media);
					break;
				case 5:
					volumeDown(p_Media);
					break;
				case 6:
					volumeUp(p_Media);
					break;
				case 7:
					goAhead15(p_Media);
					break;
				case 8:
					drawBack15(p_Media);
					break;
				case 9:
					stop(p_Media);
					goto loop;
					break;
				case 0:/*��������*/
					continue_play(p_Media);
					break;
				}
			}
			break;

		case 3:
			system("cls");
			Play_mode();
			int choice1 = 0;
			scanf("%d", &choice1);
			switch (choice1)
			{
			case 1:
				printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t\t\t\t       ����ѭ������ģʽ\n");
				printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				system("pause");
				Play_for(p_Media);
				/*Sleep(19000);*/
				break;
			case 2:
				printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t\t\t\t       �������ģʽ\n");
				printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				system("pause");
				stop(p_Media);
				p_Media = random(p_Media, HEAD_MEDIA);
				Play(p_Media);
				//����
				break;
			case 3:
				printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t\t\t\t       ˳�򲥷�ģʽ\n");
				printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				system("pause");
				stop(p_Media);
				Play_order(p_Media);
				/*	getchar();*/
				break;
			}
			goto loop;
			break;

		case 4:
			printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t\t\t\t       �����˳�ϵͳ\n");
			printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			exit(0);/*�����˳�*/
	    }
	return 0;
}









