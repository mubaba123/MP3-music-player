#include<Windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<stdlib.h>
#include"PLAYLIST.h"
#pragma comment(lib,"winmm.lib")


char FilePath[100] = "D:\\";/*储存MP3文件的目录，用于向mciSendString函数传递指令*/


/*播放*/
void Play(struct Media_t* p)
{
	char cmd[100];
	char pathname[100];
	sprintf(pathname,"%s%s", FilePath, p->name);
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t       正在播放%s歌曲\n", pathname);
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	sprintf(cmd, "open %s", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	sprintf(cmd, "play %s", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	//getchar();
	system("pause");
}

/*获取下一首歌的指针*/
struct Media_t* getNext(struct Media_t* p0, struct Media_t* head)
{
	struct Media_t* p = NULL;
	if (p0->next == NULL)
	{
		p = head->next;
	}
	else
	{
		p = p0->next;
	}
	return p;
}

//获取上一首歌的指针
struct Media_t* getLast(struct Media_t* p0, struct Media_t* head)
{
	struct Media_t* p = head->next;
	while (p != NULL) {
		if (p->next == p0) {
			return p;
		}
		p = p->next;
	}
	if (p == NULL) {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		return p;
	}
}


/*暂停播放*/
void pause(struct Media_t* p0)
{
	char cmd[100];
	char pathname[100];
	sprintf(pathname, "%s%s", FilePath, p0->name);
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t       %s歌曲播放已暂停\n", pathname);
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	sprintf(cmd, "pause %s", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t       请输入2返回界面\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	//system("pause");
}


/*继续播放*/
void continue_play(struct Media_t* p0)
{
	char cmd[100];
	char pathname[100];
	sprintf(pathname, "%s%s", FilePath, p0->name);
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t       %s歌曲继续播放\n", pathname);
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	sprintf(cmd, "resume %s", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	printf("\t\t\t\t╔═══════════════════════════════════════════════╗\n");
	printf("\t\t\t\t\t       请输入2返回界面\n");
	printf("\t\t\t\t╚═══════════════════════════════════════════════╝\n");
	//system("pause");
}


//停止播放
void stop(struct Media_t* p0)
{
	char cmd[100];
	char file[100] = "close ";
	sprintf(cmd, "%s%s", FilePath, p0->name);
	strcat(file, cmd);
	mciSendString(file, NULL, 0, NULL);
}


//调低音量
void volumeDown(struct Media_t* p0)
{
	char res[260];
	char cmd[100];
	char file1[100] = "status ";
	char file2[100] = " volume";
	char text1[100] = "setaudio ";
	char text2[100] = " volume to ";
	char vo[20];
	int a;
	sprintf(cmd, "%s%s", FilePath, p0->name);
	strcat(file1, cmd);
	strcat(file1, file2);
	mciSendString(file1, res, 260, NULL);
	int  volume = 0;
	volume = atoi(res);
	volume -= 200;
	itoa(volume, vo, 10);
	strcat(text1, cmd);
	strcat(text1, text2);
	strcat(text1, vo);
	mciSendString(text1, NULL, 0, NULL);
}

//调高音量
void volumeUp(struct Media_t* p0)
{
	char res[260];
	char cmd[100];
	char file1[100] = "status ";
	char file2[100] = " volume";
	char text1[100] = "setaudio ";
	char text2[100] = " volume to ";
	char vo[20];
	int a;
	sprintf(cmd, "%s%s", FilePath, p0->name);
	strcat(file1, cmd);
	strcat(file1, file2);
	mciSendString(file1, res, 260, NULL);
	int  volume = 0;
	volume = atoi(res);
	volume += 200;
	itoa(volume, vo, 10);
	strcat(text1, cmd);
	strcat(text1, text2);
	strcat(text1, vo);
	mciSendString(text1, NULL, 0, NULL);
}

//快进15秒
void goAhead15(struct Media_t* p0)
{
	int position;
	char cmd[100];
	char file1[100] = "seek ";
	char file2[100] = " to ";
	char file3[100];
	char text1[100] = "status ";
	char text2[100] = " position";
	char st[100];
	char word1[100] = "play ";

	sprintf(cmd, "%s%s", FilePath, p0->name);

	strcat(file1, cmd);
	strcat(file1, file2);

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st, 100, 0);

	position = atoi(st);
	position += 15000;
	itoa(position, file3, 10);
	strcat(file1, file3);
	mciSendString(file1, NULL, 0, NULL);

	strcat(word1, cmd);
	mciSendString(word1, NULL, 0, NULL);
}

//快退15秒
void drawBack15(struct Media_t* p0)
{
	int position;
	char cmd[100];
	char file1[100] = "seek ";
	char file2[100] = " to ";
	char file3[100];
	char text1[100] = "status ";
	char text2[100] = " position";
	char st[100];
	char word1[100] = "play ";

	sprintf(cmd, "%s%s", FilePath, p0->name);

	strcat(file1, cmd);
	strcat(file1, file2);

	strcat(text1, cmd);
	strcat(text1, text2);
	mciSendString(text1, st, 100, 0);

	position = atoi(st);
	position -= 15000;
	itoa(position, file3, 10);
	strcat(file1, file3);
	mciSendString(file1, NULL, 0, NULL);

	strcat(word1, cmd);
	mciSendString(word1, NULL, 0, NULL);
}

/*循环播放*/
void Play_for(struct Media_t* p)
{
	char cmd[100];
	char pathname[100];
	sprintf(pathname, "%s%s", FilePath, p->name);
	sprintf(cmd, "open %s", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	sprintf(cmd, "play %s repeat", pathname);
	mciSendString(cmd, NULL, 0, NULL);
	getchar();
	//system("pause");
}

/*随机播放*/
struct Media_t* random(struct Media_t* p0, struct Media_t* head)
{
	int a = 0;
	struct Media_t* p = NULL;
	srand((unsigned int)time(NULL));
	a = rand() % 3 + 1;
	for (int j = 1; j = a; j++)
	{
		if (p0->next == NULL)
		{
			p = head->next;
		}
		else
		{
			p = p0->next;
		}
		return p;
	}
}

/*顺序播放*/
void Play_order(struct Media_t* p)
{
	struct Media_t* head = NULL;
	char cmd[100] = { 0 };
	char pathname[100] = { 0 };
	char cmd2[100] = { 0 };
	for (int i = 0; i < 2; i++) {
		p = getNext(p, head);
		head = p;
		sprintf(pathname, "%s%s", FilePath, p->name);
		sprintf(cmd, "open %s", pathname);
		mciSendString(cmd, NULL, 0, NULL);
		sprintf(cmd, "play %s repeat", pathname);
		mciSendString(cmd, NULL, 0, NULL);
		Sleep(19000);
		sprintf(cmd2, "close %s", pathname);
		mciSendString(cmd2, NULL, 0, NULL);
		getchar();
	}

}