#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//#include <graphics.h>              // 引用图形库头文件
//#include <conio.h>
//#include <math.h>
#include"PLAYLIST.h"
#include"FILELIST.h"



extern char filepath2[100] = "D:\\";

void PLAY_Menu(void)
{
	printf("\n\n\n");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t          __  _______ _____                                 \n");
	printf("\t\t\t\t         /  |/  / __ \\   /                                  \n");
	printf("\t\t\t\t        / /|_/ / /_/ //_ <                                  \n");
	printf("\t\t\t\t       / /  / / ____/__/ /                                  \n");
	printf("\t\t\t\t      /_/__/_/_/    /___/ ____________                      \n");
	printf("\t\t\t\t      / __ \\/ /   /   \\ \\/ / ____/ __ \\                     \n");
	printf("\t\t\t\t     / /_/ / /   / /| |\\  / __/ / /_/ /                     \n");
	printf("\t\t\t\t    / ____/ /___/ ___ |/ / /___/ _, _/                      \n");
	printf("\t\t\t\t   /_/   /_____/_/  |_/_/_____/_/ |_|     第二组            \n");
	printf("\t\t\t\t                                                            \n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n\n");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t                   1.歌曲信息\n");
	printf("\t\t\t\t                   2.功能选项\n");
	printf("\t\t\t\t                   3.播放模式选项\n");
	printf("\t\t\t\t                   4.退出系统\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

}



/*播放歌曲界面，包含进度条*/
int Face_Play(struct Media_t* p0)
{
	system("CLS");
	struct Media_t* p = p0;
	int a;

	int LENGTH = 50;/*进度条长度*/
	int MinTens_cur = 0, MinOnes_cur = 0, SecTens_cur = 0, SecOnes_cur = 0;
	int MinTens_total = 0, MinOnes_total = 0, SecTens_total = 0, SecOnes_total = 0;

	char st1[50];
	char st2[50];
	char file1[50] = "status ";
	char file2[50] = " length";
	char text1[50] = "status ";
	char text2[50] = " position";
	char cmd[100];

	int length = 0;//存储歌曲时长
	int current = 0;//存储歌曲当前播放位置

	sprintf(cmd, "%s%s", filepath2, p->name);
	strcat(file1, cmd);
	strcat(file1, file2);
	mciSendString(file1, st1, 50, 0);

	length = atoi(st1);

	MinTens_total = length / 600000;
	MinOnes_total = (length / 60000) % 10;
	SecTens_total = ((length / 1000) % 60) / 10;
	SecOnes_total = ((length / 1000) % 60) % 10;

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st2, 50, 0);
	current = atoi(st2);

	while (!(kbhit())) {
		mciSendString(text1, st2, 50, 0);
		current = atoi(st2);
		MinTens_cur = current / 600000;
		MinOnes_cur = (current / 60000) % 10;
		SecTens_cur = ((current / 1000) % 60) / 10;
		SecOnes_cur = ((current / 1000) % 60) % 10;

		printf("\t\t\t\t╔═════════════════════════════════════════════════════════════════╗\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *1.暂停                   *2.选曲播放                       ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *3.上一曲                 *4.下一曲                         ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *5.音量-                  *6.音量+                          ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *7.快进                   *8.快退                           ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t║     *9.停止播放退出功能选项               *0.继续               ║\n");
		printf("\t\t\t\t║                                                                 ║\n");
		printf("\t\t\t\t╚═════════════════════════════════════════════════════════════════╝\n");
		printf("\n\n\t\t\t\t %d%d:%d%d/%d%d:%d%d  ",
			MinTens_cur, MinOnes_cur, SecTens_cur, SecOnes_cur,
			MinTens_total, MinOnes_total, SecTens_total, SecOnes_total);
		for (int j = 0; j <= LENGTH * current / length; j++) {
			printf("═");
		}

		Sleep(1000);
		system("CLS");
	}
	return getch() - 48;
}

void face_fileFailure() 
{
	system("CLS");
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                 文件打开失败！                ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	return;
}

//输出链表中的全部信息
void listSongList(struct List_t* head) 
{
	struct List_t* p = head->next;
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t║                                               ║\n");
	while (p != NULL)
	{
		printf("\t\t\t\t║   \t*输入%1d，将展示歌单%-10s\t    \t║\n", p->num, p->name);
		p = p->next;
	}
	printf("\t\t\t\t║                                               ║\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");

}
 
void listMedia(struct Media_t* head)
{
	struct Media_t* p = head->next;
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
void Play_mode()
{
	printf("\t\t\t\t\t╔══════════════════════════════════════╗\n");
	printf("\t\t\t\t\t║                                      ║\n");
	printf("\t\t\t\t\t║  *1.循环播放         *2.随机播放     ║\n");
	printf("\t\t\t\t\t║                                      ║\n");
	printf("\t\t\t\t\t║             *3.顺序播放              ║\n");
	printf("\t\t\t\t\t╚══════════════════════════════════════╝\n");

}


//
//void Play_GUI()
//{
//	int i;
//	short win_width, win_height;//定义窗口的宽度和高度
//	win_width = 480; win_height = 360;
//	initgraph(win_width, win_height);//初始化窗口（黑屏）
//	for (i = 0; i < 256; i += 5)
//	{
//		setbkcolor(RGB(i, i, i));//设置背景色，原来默认黑色
//		cleardevice();//清屏（取决于背景色）
//		Sleep(15);//延时15ms
//	}
//	closegraph();//关闭绘图界面
//}

