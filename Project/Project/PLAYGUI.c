#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
//#include <graphics.h>              // ����ͼ�ο�ͷ�ļ�
//#include <conio.h>
//#include <math.h>
#include"PLAYLIST.h"
#include"FILELIST.h"



extern char filepath2[100] = "D:\\";

void PLAY_Menu(void)
{
	printf("\n\n\n");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t          __  _______ _____                                 \n");
	printf("\t\t\t\t         /  |/  / __ \\   /                                  \n");
	printf("\t\t\t\t        / /|_/ / /_/ //_ <                                  \n");
	printf("\t\t\t\t       / /  / / ____/__/ /                                  \n");
	printf("\t\t\t\t      /_/__/_/_/    /___/ ____________                      \n");
	printf("\t\t\t\t      / __ \\/ /   /   \\ \\/ / ____/ __ \\                     \n");
	printf("\t\t\t\t     / /_/ / /   / /| |\\  / __/ / /_/ /                     \n");
	printf("\t\t\t\t    / ____/ /___/ ___ |/ / /___/ _, _/                      \n");
	printf("\t\t\t\t   /_/   /_____/_/  |_/_/_____/_/ |_|     �ڶ���            \n");
	printf("\t\t\t\t                                                            \n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t                   1.������Ϣ\n");
	printf("\t\t\t\t                   2.����ѡ��\n");
	printf("\t\t\t\t                   3.����ģʽѡ��\n");
	printf("\t\t\t\t                   4.�˳�ϵͳ\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}



/*���Ÿ������棬����������*/
int Face_Play(struct Media_t* p0)
{
	system("CLS");
	struct Media_t* p = p0;
	int a;

	int LENGTH = 50;/*����������*/
	int MinTens_cur = 0, MinOnes_cur = 0, SecTens_cur = 0, SecOnes_cur = 0;
	int MinTens_total = 0, MinOnes_total = 0, SecTens_total = 0, SecOnes_total = 0;

	char st1[50];
	char st2[50];
	char file1[50] = "status ";
	char file2[50] = " length";
	char text1[50] = "status ";
	char text2[50] = " position";
	char cmd[100];

	int length = 0;//�洢����ʱ��
	int current = 0;//�洢������ǰ����λ��

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

		printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *1.��ͣ                   *2.ѡ������                       �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *3.��һ��                 *4.��һ��                         �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *5.����-                  *6.����+                          �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *7.���                   *8.����                           �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�U     *9.ֹͣ�����˳�����ѡ��               *0.����               �U\n");
		printf("\t\t\t\t�U                                                                 �U\n");
		printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\n\n\t\t\t\t %d%d:%d%d/%d%d:%d%d  ",
			MinTens_cur, MinOnes_cur, SecTens_cur, SecOnes_cur,
			MinTens_total, MinOnes_total, SecTens_total, SecOnes_total);
		for (int j = 0; j <= LENGTH * current / length; j++) {
			printf("�T");
		}

		Sleep(1000);
		system("CLS");
	}
	return getch() - 48;
}

void face_fileFailure() 
{
	system("CLS");
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                 �ļ���ʧ�ܣ�                �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	return;
}

//��������е�ȫ����Ϣ
void listSongList(struct List_t* head) 
{
	struct List_t* p = head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                               �U\n");
	while (p != NULL)
	{
		printf("\t\t\t\t�U   \t*����%1d����չʾ�赥%-10s\t    \t�U\n", p->num, p->name);
		p = p->next;
	}
	printf("\t\t\t\t�U                                               �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}
 
void listMedia(struct Media_t* head)
{
	struct Media_t* p = head->next;
	printf("\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t�U                                               �U\n");
	while (p != NULL)
	{
		printf("\t\t\t\t�U   \t*����%1d����������Ŀ%-10s\t    \t�U\n", p->num, p->name);
		p = p->next;
	}//��������е�ȫ����Ϣ
	printf("\t\t\t\t�U                                               �U\n");
	printf("\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}
void Play_mode()
{
	printf("\t\t\t\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t\t\t\t�U                                      �U\n");
	printf("\t\t\t\t\t�U  *1.ѭ������         *2.�������     �U\n");
	printf("\t\t\t\t\t�U                                      �U\n");
	printf("\t\t\t\t\t�U             *3.˳�򲥷�              �U\n");
	printf("\t\t\t\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");

}


//
//void Play_GUI()
//{
//	int i;
//	short win_width, win_height;//���崰�ڵĿ�Ⱥ͸߶�
//	win_width = 480; win_height = 360;
//	initgraph(win_width, win_height);//��ʼ�����ڣ�������
//	for (i = 0; i < 256; i += 5)
//	{
//		setbkcolor(RGB(i, i, i));//���ñ���ɫ��ԭ��Ĭ�Ϻ�ɫ
//		cleardevice();//������ȡ���ڱ���ɫ��
//		Sleep(15);//��ʱ15ms
//	}
//	closegraph();//�رջ�ͼ����
//}

