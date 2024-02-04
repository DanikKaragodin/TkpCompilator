#include "StdAfx.h"         // описания Windows
#include "resource.h"
LRESULT CALLBACK	    WndProc (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	    ABOUTLBM (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	    ABOUTRMB (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	    ABOUTKD (HWND, UINT, WPARAM, LPARAM);
char   szWindowStyle [ ] = "myWindowStyle";

//===============================
//    ГЛАВНАЯ ФУНКЦИЯ 
int  WINAPI  WinMain   (HINSTANCE hInst,  //дескриптор приложения
                                       HINSTANCE hPreInst,  //всегда NULL
                                       LPSTR          lpszCmdLine,  //командная строка
                                       int                 nCmdShow) //окно при первом выводе
{    	
	HWND                               hWnd;                  //дескриптор окна
	MSG                                  lpMsg;                  //структура хранения сообщений 
	WNDCLASS                      wcApp;                 //структура описания стиля окна
	wcApp.lpszClassName   = szWindowStyle;   //имя стиля окна
	wcApp.hInstance	       = hInst;                   //дескриптор приложения 
	wcApp.lpfnWndProc	       = WndProc;            //указатель на обработчик сооб-щений 
	wcApp.hCursor	       = LoadCursor(NULL, IDC_ARROW);   //курсор - “стрелка”
	wcApp.hIcon		       = 0;                          //без использования пиктограммы
wcApp.lpszMenuName = (LPCSTR)IDD_MAIN_MENU;
	wcApp.hbrBackground    = (HBRUSH) GetStockObject (WHITE_BRUSH); //цвет фона 
	wcApp.style		       = CS_HREDRAW | CS_VREDRAW; //перерисовывать окно 
	wcApp.cbClsExtra	       = 0;                          //число доп. байт для WNDCLASS       
	wcApp.cbWndExtra	       = 0;                          //общее число доп. байт 

	if    ( ! RegisterClass (&wcApp) )  //регистрация окна   
		return  0;

     hWnd = CreateWindow (szWindowStyle, 
                           "ТИПОВОЙ КАРКАС Windows-приложения … ",  
		           WS_OVERLAPPEDWINDOW, //окно перекрывающееся, меню, кнопки
                               CW_USEDEFAULT,        //координата х - левый верхний угол окна 
                               CW_USEDEFAULT,        //координата у - левый верхний угол окна
                               CW_USEDEFAULT,        //ширина окна в единицах устройства
                               CW_USEDEFAULT,        //высота окна в единицах устройства
                               (HWND) NULL,                //указатель на родительское окно
                               (HMENU) NULL,              //зависит от стиля окна (указатель меню) 
                                hInst,                               //дескриптор приложения 
                                NULL );       //адрес дополнительной информации об окне
        ShowWindow (hWnd, nCmdShow);       //вывод окна
        UpdateWindow (hWnd);                         //перерисовка окна
	  while (GetMessage ( &lpMsg, NULL, 0, 0) ) 
	  {
		TranslateMessage (&lpMsg);         //преобразование виртуальных клавиш
		 DispatchMessage (&lpMsg);         //передача сообщения обработчику
         }
     	  return ( lpMsg.wParam );
}

//================================
//    ФУНКЦИЯ-ОБРАБОТЧИК ГЛАВНОГО ОКНА. (имя выбирает пользователь)
LRESULT CALLBACK  WndProc (HWND  hWnd,               //дескриптор окна
                                                       UINT    messg,              //код сообщения
                                                       WPARAM  wParam,  LPARAM    lParam) 
{	
	HDC                   hdc;             //дескриптор контекста устройства 
	PAINTSTRUCT ps;                //структура для клиентской области окна
	switch (messg){                                       
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case IDD_MENU1:
					MessageBox(hWnd, "Menu 1","TKP Compilator", MB_OK);
				break;
				case IDD_MENU2:
					MessageBox(hWnd, "Menu 2","TKP Compilator", MB_OK);
				break;
				case IDD_MENU3:
					MessageBox(hWnd, "Menu 3","TKP Compilator", MB_OK);
				break;
}		break;
		case WM_LBUTTONDOWN:
			MessageBox(hWnd, "12","12", MB_OK);
		break;
		case WM_RBUTTONDOWN:
			MessageBox(hWnd, "23","23", MB_OK);
			DialogBox(NULL,(LPCTSTR)IDD_TKP_RMB,NULL,(DLGPROC)ABOUTRMB);
		break;
		case WM_KEYDOWN:
			MessageBox(hWnd, "34","34", MB_OK);
			DialogBox(NULL,(LPCTSTR)IDD_TKP_KD,NULL,(DLGPROC)ABOUTKD);
		break;
	    case WM_PAINT:                     //перерисовать окно
		      hdc = BeginPaint (hWnd, &ps);            
                        //-----Начало фрагмента пользователя
		      //-----Конец фрагмента пользователя	
		      ValidateRect (hWnd,NULL); 
		      EndPaint (hWnd, &ps); 
		break;
		case WM_DESTROY:      //послать сообщение о завершении приложения
		        PostQuitMessage (0);
		break;
		default: 
		        return ( DefWindowProc (hWnd, messg, wParam, lParam)); 
             }
return 0;
}

LRESULT CALLBACK	    ABOUTRMB (HWND hDlg, UINT messg, WPARAM wParam, LPARAM lParam){
	int wmId = LOWORD(wParam);
	switch(messg){
		case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND :
	switch(wmId) {
	case BUTTON_OK_RMB : 
	case IDCANCEL :
		 EndDialog(hDlg, LOWORD(wParam));  
		 return TRUE;
		break;
	default:
		return FALSE;}
	break;}
	return FALSE;}


LRESULT CALLBACK	    ABOUTKD  (HWND hDlg, UINT messg, WPARAM wParam, LPARAM lParam){
	int wmId = LOWORD(wParam);
	switch(messg){
		case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND :
	switch(wmId) {
	case BUTTON_OK_KD : 
	case IDCANCEL :
		 EndDialog(hDlg, LOWORD(wParam));  
		 return TRUE;
		break;
	default:
		return FALSE;}
	break;}
	return FALSE;}


