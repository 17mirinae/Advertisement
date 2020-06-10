#include "ad2.h"

void gotoxy(int, int);
void hscroll_view(char win[], int w_len, char str[], int s_len);

void hscroll_view(char win[], int w_len, char str[], int s_len){
	int i;
	int v_head=w_len-1;
	int s_head=0;
	int curr_len=0;
	int limit_len=(w_len>s_len)?s_len:w_len;

	while(1){
		if(v_head>0) 					//�� ��尡 ��â�� ó���κп� �����ϱ� ���̸�
			v_head--; 				//�� ��带 �������� �̵�
		else 						//��Ʈ�� ����� ��â�� ���� ������ �����ϸ�
			s_head++; 				//��Ʈ�� ��带 ���������� �̵���

		if(s_head+curr_len<limit_len) 			//��Ʈ�� ������ ���� ���̺��� ª����
			curr_len++;				//����� ��Ʈ�� ���̰� ������
		else if(v_head==0&&(s_head+curr_len)>s_len) 	//�� ��尡 ��â��
			curr_len--; 				//����� ��Ʈ���� ���̰� ������
		memset(win, ' ', w_len);			//��â�� �������� ����

		win[w_len]='\0';

		for(i=0;i<curr_len;i++)
			win[v_head+i]=str[s_head+i];
		system("cls");
		

		printf("%s\n", win);
		Sleep(50);

		//ó�� ���·� ����
		if(v_head==0 && curr_len==0){
			v_head=w_len-1;
			s_head=0;
			curr_len=0;
		}

		if(kbhit()){
			if(getch()=='q')
			break;}}
}
void gotoxy(int x, int y)
{
	HANDLE h;
	COORD pos;

	h=GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(h, pos);
}