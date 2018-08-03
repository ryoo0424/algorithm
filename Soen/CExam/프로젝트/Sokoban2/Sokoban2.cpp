#include <windows.h>
#include "resource.h"

#define MAXSTAGE 3
#define BW 32
#define BH 32

void DrawScreen(HDC hdc);
BOOL TestEnd();
void Move(int dir);
void InitStage();
void DrawBitmap(HDC hdc,int x,int y,HBITMAP hBit);

char ns[18][21];
int nStage;
int nx,ny;
int nMove;
HBITMAP hBit[5];

char arStage[MAXSTAGE][18][21]={
	{
	"####################",
	"####################",
	"####################",
	"#####   ############",
	"#####O  ############",
	"#####  O############",
	"###  O O ###########",
	"### # ## ###########",
	"#   # ## #####  ..##",
	"# O  O   @      ..##",
	"##### ### # ##  ..##",
	"#####     ##########",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################"
	},
	{
	"####################",
	"####################",
	"####################",
	"####################",
	"####..  #     ######",
	"####..  # O  O  ####",
	"####..  #O####  ####",
	"####..    @ ##  ####",
	"####..  # #  O #####",
	"######### ##O O ####",
	"###### O  O O O ####",
	"######    #     ####",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################"
	},
	{
	"####################",
	"####################",
	"####################",
	"####################",
	"##########     @####",
	"########## O#O #####",
	"########## O  O#####",
	"###########O O #####",
	"########## O # #####",
	"##....  ## O  O  ###",
	"###...    O  O   ###",
	"##....  ############",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################"
	},
};

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass=TEXT("Sokoban2");

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=(WNDPROC)WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass, WS_BORDER | WS_CAPTION | 
		WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT,CW_USEDEFAULT,0,0,NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);
	
	while(GetMessage(&Message,0,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT crt;
	int i;
	TCHAR Message[256];
				
	switch(iMessage) {
	case WM_CREATE:
		hWndMain=hWnd;
		SetRect(&crt,0,0,900,BH*18);
		AdjustWindowRect(&crt,WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,TRUE);
		SetWindowPos(hWnd,NULL,0,0,crt.right-crt.left,crt.bottom-crt.top,
			SWP_NOMOVE | SWP_NOZORDER);
		for (i=0;i<5;i++) {
			hBit[i]=LoadBitmap(g_hInst,MAKEINTRESOURCE(IDB_WALL+i));
		}
		nStage=0;
		InitStage();
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd, &ps);
		DrawScreen(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_KEYDOWN:
		switch(wParam) {
		case VK_LEFT:
		case VK_RIGHT:
		case VK_UP:
		case VK_DOWN:
			Move(wParam);
			if (TestEnd()) {
				wsprintf(Message,"%d ���������� Ǯ�����ϴ�. "
					"���� ���������� �̵��մϴ�",nStage+1);
				MessageBox(hWnd,Message,"�˸�",MB_OK);
				if (nStage < MAXSTAGE-1) {
					nStage++;
				}
				InitStage();
			}
			break;
		case 'Q':
			DestroyWindow(hWnd);
			break;
		case 'R':
			InitStage();
			break;
		case 'N':
			if (nStage < MAXSTAGE-1) {
				nStage++;
				InitStage();
			}
			break;
		case 'P':
			if (nStage > 0) {
				nStage--;
				InitStage();
			}
			break;
		}
		return 0;
	case WM_DESTROY:
		for (i=0;i<5;i++) {
			DeleteObject(hBit[i]);
		}
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void DrawScreen(HDC hdc)
{
	int x,y;
	int iBit;
	char Message[256];

	for (y=0;y<18;y++) {
		for (x=0;x<20;x++) {
			switch(ns[y][x]) {
			case '#':
				iBit=0;
				break;
			case 'O':
				iBit=1;
				break;
			case '.':
				iBit=2;
				break;
			case ' ':
				iBit=3;
				break;
			}
			DrawBitmap(hdc,x*BW,y*BH,hBit[iBit]);
		}
	}
	DrawBitmap(hdc,nx*BW,ny*BH,hBit[4]);

	wsprintf(Message,"SOKOBAN");
	TextOut(hdc,700,10,Message,strlen(Message));
	wsprintf(Message,"Q:����, R:�ٽ� ����");
	TextOut(hdc,700,30,Message,strlen(Message));
	wsprintf(Message,"N:����, P:����");
	TextOut(hdc,700,50,Message,strlen(Message));
	wsprintf(Message,"�������� : %d",nStage+1);
	TextOut(hdc,700,70,Message,strlen(Message));
	wsprintf(Message,"�̵� ȸ�� : %d",nMove);
	TextOut(hdc,700,90,Message,strlen(Message));
}

BOOL TestEnd()
{
	int x,y;

	for (y=0;y<18;y++) {
		for (x=0;x<20;x++) {
			if (arStage[nStage][y][x]=='.' && ns[y][x]!='O') {
				return FALSE;
			}
		}
	}
	return TRUE;
}

void Move(int dir)
{
	int dx=0,dy=0;

	switch (dir) {
	case VK_LEFT:
		dx=-1;
		break;
	case VK_RIGHT:
		dx=1;
		break;
	case VK_UP:
		dy=-1;
		break;
	case VK_DOWN:
		dy=1;
		break;
	}

	if (ns[ny+dy][nx+dx]!='#') {
		if (ns[ny+dy][nx+dx]=='O') {
			if (ns[ny+dy*2][nx+dx*2] == ' ' || ns[ny+dy*2][nx+dx*2] == '.') {
				if (arStage[nStage][ny+dy][nx+dx]=='.') {
					ns[ny+dy][nx+dx]='.';
				} else {
					ns[ny+dy][nx+dx]=' ';
				}
				ns[ny+dy*2][nx+dx*2]='O';
			} else {
				return;
			}
		}
		nx+=dx;
		ny+=dy;
		nMove++;
		InvalidateRect(hWndMain,NULL,FALSE);
	}
}

void InitStage()
{
	int x,y;

	memcpy(ns,arStage[nStage],sizeof(ns));
	for (y=0;y<18;y++) {
		for (x=0;x<20;x++) {
			if (ns[y][x]=='@') {
				nx=x;
				ny=y;
				ns[y][x]=' ';
			}
		}
	}
	nMove=0;
	InvalidateRect(hWndMain,NULL,TRUE);
}

void DrawBitmap(HDC hdc,int x,int y,HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx,by;
	BITMAP bit;

	MemDC=CreateCompatibleDC(hdc);
	OldBitmap=(HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit,sizeof(BITMAP),&bit);
	bx=bit.bmWidth;
	by=bit.bmHeight;

	BitBlt(hdc,x,y,bx,by,MemDC,0,0,SRCCOPY);

	SelectObject(MemDC,OldBitmap);
	DeleteDC(MemDC);
}
