#include "ad1.h"

int main(void)
{
	char text[100];
	int len;

	gets(text);

	len=strlen(text);

	hrolling_view(text, len);

	return 0;
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
void hrolling_view(char text[], int len)
{
	int i;

	for(i=0;i<=len;i++){
		system("cls");
		gotoxy(30, 10);
		printf("%s\n\n\n\n\n\n\n\n\n\n", text);
		rotate_left(text, len);
		Sleep(50);
	}
}
void rotate_left(char a[], int b)
{
	int i;
	char temp;

	temp=a[0];
	
	for(i=1;i<=b;i++)
		a[i-1]=a[i];

	a[i-1]=temp;
}