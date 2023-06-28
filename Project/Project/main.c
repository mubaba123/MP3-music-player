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
	struct Media_t* HEAD_MEDIA=NULL;/*歌曲信息以链表形式存储，HEAD_MEDIA为链表头*/
	struct Media_t* p_Media = NULL;/*指针，指向当前播放的歌曲的节点*/
	
	struct List_t* p_List = NULL;
	struct List_t* HEAD_LIST = Pre_List();/*歌单信息以链表形式存储，HEAD_LIST为链表头*/

	int Choice_Play = 0;/*储存选择的播放功能的选项*/
	int Flag_Play = 1;/*记录播放状态，0表示退出播放*/
	void Play_GUI();
	//while(1)
	/*程序运行输入对应的编号就开始播放音乐*/
	HEAD_MEDIA = Pre_Media();/*读取D:\\ .mp3音乐*/
	ListMedia(HEAD_MEDIA);/*显示歌曲列表*/
	p_Media = GetChoice_Media(HEAD_MEDIA);/*输入歌曲编号，返回指向对应歌曲信息的指针*/
	Play(p_Media);
loop:
	system("cls");
	PLAY_Menu();

	Flag_Play = 1;

/*0是停止播放退出程序*/

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
				case 1://暂停
					pause(p_Media);
					break;
				case 2://选曲播放
					stop(p_Media);
					ListMedia(HEAD_MEDIA);
					p_Media = GetChoice_Media(HEAD_MEDIA);
					Play(p_Media);
					break;
				case 3://上一首
					stop(p_Media);
					p_Media = getLast(p_Media, HEAD_MEDIA);
					Play(p_Media);
					break;
				case 4://下一曲
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
				case 0:/*继续播放*/
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
				printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
				printf("\t\t\t\t\t       单曲循环播放模式\n");
				printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
				system("pause");
				Play_for(p_Media);
				/*Sleep(19000);*/
				break;
			case 2:
				printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
				printf("\t\t\t\t\t       随机播放模式\n");
				printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
				system("pause");
				stop(p_Media);
				p_Media = random(p_Media, HEAD_MEDIA);
				Play(p_Media);
				//函数
				break;
			case 3:
				printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
				printf("\t\t\t\t\t       顺序播放模式\n");
				printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
				system("pause");
				stop(p_Media);
				Play_order(p_Media);
				/*	getchar();*/
				break;
			}
			goto loop;
			break;

		case 4:
			printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
			printf("\t\t\t\t\t       正在退出系统\n");
			printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
			exit(0);/*正常退出*/
	    }
	return 0;
}









