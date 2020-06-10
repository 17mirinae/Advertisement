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
		if(v_head>0) 					//뷰 헤드가 뷰창의 처음부분에 도달하기 전이면
			v_head--; 				//뷰 헤드를 왼쪽으로 이동
		else 						//스트링 출력이 뷰창의 앞쪽 끝까지 도달하면
			s_head++; 				//스트링 헤드를 오른쪽으로 이동함

		if(s_head+curr_len<limit_len) 			//스트링 꼬리가 제한 길이보다 짧으면
			curr_len++;				//출력할 스트링 길이가 증가함
		else if(v_head==0&&(s_head+curr_len)>s_len) 	//뷰 헤드가 뷰창의
			curr_len--; 				//출력할 스트링의 길이가 감소함
		memset(win, ' ', w_len);			//뷰창을 공백으로 리셋

		win[w_len]='\0';

		for(i=0;i<curr_len;i++)
			win[v_head+i]=str[s_head+i];
		system("cls");
		

		printf("%s\n", win);
		Sleep(50);

		//처음 상태로 리셋
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