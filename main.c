#include <windows.h>
#include <stdio.h>
#include "Controller/UserController.h"
#include "Controller/ItemController.h"
#include "Controller/FileController.h"
#include "Model/MetaModel.h"


#define BTN1 101
#define BTN2 102
#define BTN3 103
#define BTN4 104
#define BTN5 105
#define BTN6 106
#define BTN7 107
#define BTN8 108
#define BTN9 109
#define BTN10 110
#define BTN11 111
#define BTN12 112
#define BTN13 113
#define BTN14 114
#define BTN15 115
#define BTN16 116
#define BTN17 117
#define BTN18 118
#define BTN19 119
#define BTN20 120
#define BTN21 121
#define BTN22 122
#define BTN23 123
#define BTN24 124


#define STATIC1 201
#define STATIC2 202
#define STATIC3 203
#define STATIC4 204
#define STATIC5 205


#define EDIT1 301
#define EDIT2 302
#define EDIT3 303
#define EDIT4 304
#define EDIT5 305
#define EDIT6 306
#define EDIT7 307
#define EDIT8 308
#define EDIT9 309
#define EDIT10 310

void hide();
void show1();
void show2();
void show3();
void show4();
void caxun(int x);
void xianshiye(int x);
int page=0;
int yema=1;
int yema_max=10;
int num=0;
int moshi=1;
int xianshinum=0;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



HINSTANCE hInst;   //HINSTANCE �ǡ�����͡��������͡�---------


MetaPtr meta;


int WINAPI WinMain(

        HINSTANCE hInstance,

        HINSTANCE hPrevInstance,

        PSTR szCmdLine,

        int iCmdShow

){
    system("chcp 65001 > nul");
    initUserController();
    initItemController();
    meta = newMeta(0, 0);
    static TCHAR szClassName[] = TEXT("Win32Demo");  //��������

    HWND     hwnd;  //���ھ��

    MSG      msg;  //��Ϣ

    WNDCLASS wndclass;  //������



    hInst = hInstance;   //------------



    /**********�ڢٲ���ע�ᴰ����**********/

    //Ϊ������ĸ����ֶθ�ֵ

    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //���ڷ��

    wndclass.lpfnWndProc  = WndProc;  //���ڹ���

    wndclass.cbClsExtra   = 0;  //��ʱ����Ҫ���

    wndclass.cbWndExtra   = 0;  //��ʱ����Ҫ���

    wndclass.hInstance    = hInstance;  //��ǰ���ھ��

    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //����ͼ��

    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //�����ʽ

    wndclass.hbrBackground= (HBRUSH)(COLOR_BTNFACE + 1);  //���ڱ�����ˢ����ɫ��

    wndclass.lpszMenuName = NULL ;  //���ڲ˵�

    wndclass.lpszClassName= szClassName;  //��������



    //ע�ᴰ��

    RegisterClass(&wndclass);



    /*****�ڢڲ�����������(���ô�����ʾ����)*****/

    hwnd = CreateWindow(

            szClassName,  //��������

            TEXT("����Ԫ��������ϵͳ"),  //���ڱ��⣨�����ڱ�������

            WS_OVERLAPPEDWINDOW,  //���ڷ��

            CW_USEDEFAULT,  //��ʼ��ʱx���λ��

            CW_USEDEFAULT,  //��ʼ��ʱy���λ��

            700,  //���ڿ��

            500,  //���ڸ߶�

            NULL,  //�����ھ��

            NULL,  //���ڲ˵����

            hInstance,  //��ǰ���ڵľ��

            NULL  //��ʹ�ø�ֵ

    );



    //��ʾ����

    ShowWindow (hwnd, iCmdShow);

    //���£����ƣ�����

    UpdateWindow (hwnd);



    /**********�ڢ۲�����Ϣѭ��**********/

    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //������Ϣ

        DispatchMessage (&msg);  //������Ϣ

    }



    return msg.wParam;

}







static HFONT hFont;
static HFONT hFont2;
static HWND hBtn[50];
static HWND hEdit1;
static HWND hEdit2;
static HWND hEdit3;
static HWND hEdit4;
static HWND hEdit5;
static HWND hEdit6;
static HWND hEdit7;
static HWND hEdit8;
static HWND hEdit9;
static HWND hEdit10;
static HWND hEdit11;
static HWND hEdit12;
static HWND hStatic1;
static HWND hStatic2;
static HWND hStatic3;
static HWND hStatic4;
static HWND hStatic5;
static HWND hStatic6;
static HWND hStatic7;
static HWND hStatic8;
static HWND hStatic9;
static HWND hStatic10;
static HWND hStatic11;
static HWND hStatic12;

wchar_t edit1[20];
wchar_t edit2[20];
wchar_t edit4[20];

wchar_t yuanqijian[6][16];
wchar_t yuanqijian123[10][100];

u32 yuanqijian_id[10];
wchar_t leixing[36];
wchar_t daxiao[36];
wchar_t fengzhuang[36];
wchar_t changjia[36];
wchar_t danjia[36];
wchar_t kucun[36];
wchar_t zhanghao[100];
wchar_t xuanze[20];
int xuanze_num;
wchar_t cyema[20];


/**********�ڢܲ�����Ϣѭ��**********/

//------------

LRESULT CALLBACK WndProc(

        HWND hWnd,

        UINT message,

        WPARAM wParam,

        LPARAM lParam

){
    int wmId, wmEvent;

    PAINTSTRUCT ps;

    HDC hdc;


    switch (message){
        case  WM_CREATE:

            ;StatusPtr  read = readDataFile(meta);//��ȡ����
            //�����߼�����
            hFont = CreateFont(

                    -15/*�߶�*/, -7.5/*���*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,

                    FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,

                    DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���

                    OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�

                    DEFAULT_QUALITY,  //Ĭ���������

                    FF_DONTCARE,  //��ָ��������*/

                    TEXT("΢���ź�")  //������

            );

            hFont2 = CreateFont(

                    -15/*�߶�*/, -7.5/*���*/, 0, 0, 400 /*һ�����ֵ��Ϊ400*/,

                    FALSE/*����б��*/, FALSE/*�����»���*/, FALSE/*����ɾ����*/,

                    DEFAULT_CHARSET,  //ʹ��Ĭ���ַ���

                    OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //���в������ù�

                    DEFAULT_QUALITY,  //Ĭ���������

                    FF_DONTCARE,  //��ָ��������*/

                    TEXT("����")  //������

            );




            //������̬�ı��ؼ�

            hStatic1 = CreateWindow(

                    TEXT("static"),  //��̬�ı��������

                    TEXT("\n    �˺�:\n\n    ���룺"),  //�ؼ����ı�

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/,

                    250/*X����*/, 150/*Y����*/, 200/*���*/, 100/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)STATIC1,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��

                    hInst,  //��ǰʵ�����

                    NULL

            );

            hStatic2 = CreateWindow(

                    TEXT("static"),  //��̬�ı��������

                    TEXT(" "),  //�ؼ����ı�

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/| WS_BORDER /*���߿�*/ ,

                    500 /*X����*/, -1/*Y����*/, 200/*���*/, 700/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)STATIC2,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��

                    hInst,  //��ǰʵ�����

                    NULL

            );

            hStatic3 = CreateWindow(

                    TEXT("static"),  //��̬�ı��������

                    TEXT(" "),  //�ؼ����ı�

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/| WS_BORDER /*���߿�*/ ,

                    -1 /*X����*/, 370/*Y����*/, 502/*���*/, 120/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)STATIC3,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��

                    hInst,  //��ǰʵ�����

                    NULL

            );

            hStatic4 = CreateWindow(

                    TEXT("static"),  //��̬�ı��������

                    TEXT("\r\n\r\n\r\n         ���ͣ�                                            ��С��\r\n\r\n\r\n         ��װ��                                            ���ң�\r\n\r\n\r\n         ���ۣ�                                            ��棺"),  //�ؼ����ı�

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/| WS_BORDER /*���߿�*/ ,

                    -1 /*X����*/, -10/*Y����*/, 502/*���*/, 300/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)STATIC4,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��

                    hInst,  //��ǰʵ�����

                    NULL

            );

            hStatic5 = CreateWindow(

                    TEXT("static"),  //��̬�ı��������

                    TEXT(" 1/10"),  //�ؼ����ı�

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/| WS_BORDER /*���߿�*/ ,

                    420 /*X����*/, 395/*Y����*/, 40/*���*/, 40/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)STATIC5,  //Ϊ�ؼ�ָ��һ��Ψһ��ʶ��

                    hInst,  //��ǰʵ�����

                    NULL

            );


            //������ť�ؼ�

            hBtn[0] = CreateWindow(//ע�ᰴť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ע��"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    270 /*X����*/, 260 /*Y����*/, 60 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN1 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[1] = CreateWindow(//��¼��ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("��¼"),

                    WS_CHILD | WS_VISIBLE  | WS_BORDER| BS_FLAT/*��ƽ��ʽ*/,

                    370 /*X����*/, 260 /*Y����*/, 60 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN2 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );


            hBtn[2] = CreateWindow(//ע����ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ע���û�"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 180 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN3 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[3] = CreateWindow(//ɾ���û���ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ɾ���û�"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 240 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN4 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[4] = CreateWindow(//�޸����밴ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("�޸�����"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER| BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 300 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN5 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[5] = CreateWindow(//�˳�ϵͳ��ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("�˳�ϵͳ"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 360 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN6 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );


            hBtn[6] = CreateWindow(//ȷ���޸����밴ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ȷ���޸�����"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 300 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN7 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );


            hBtn[7] = CreateWindow(//ȡ���޸����밴ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ȡ���޸�����"),

                    WS_CHILD | WS_VISIBLE  | WS_BORDER| BS_FLAT/*��ƽ��ʽ*/,

                    540 /*X����*/, 360 /*Y����*/, 120 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN8 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[8] = CreateWindow(//����Ԫ������ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("����"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER| BS_FLAT/*��ƽ��ʽ*/,

                    20 /*X����*/, 395 /*Y����*/, 80 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN9 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[9] = CreateWindow(//��ѯԪ������ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("��ѯ"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    110 /*X����*/, 395 /*Y����*/, 80 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN10 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[10] = CreateWindow(//�޸�Ԫ������ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("�޸�"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    200 /*X����*/, 395 /*Y����*/, 80 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN11 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[23] = CreateWindow(//ɾ��Ԫ������ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("ɾ��"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    290 /*X����*/, 395 /*Y����*/, 80 /*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN24 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[11] = CreateWindow(//Ԫ����1

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����1"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, -1/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN12 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[12] = CreateWindow(//Ԫ����2

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����2"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 36/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN13 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[13] = CreateWindow(//Ԫ����3

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����3"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 72/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN14 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[14] = CreateWindow(//Ԫ����4

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����4"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 109/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN15 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[15] = CreateWindow(//Ԫ����5

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����5"),

                    WS_CHILD | WS_VISIBLE | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 146/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN16 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[16]= CreateWindow(//Ԫ����6

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����6"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 183/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN17 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[17] = CreateWindow(//Ԫ����7

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����7"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 220/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN18 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[18] = CreateWindow(//Ԫ����8

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����8"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 257/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN19 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[19] = CreateWindow(//Ԫ����9

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����9"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 294/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN20 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[20] = CreateWindow(//Ԫ����10

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("Ԫ����10"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*��ƽ��ʽ*/|BS_AUTORADIOBUTTON,

                    2 /*X����*/, 331/*Y����*/, 498/*���*/, 38/*�߶�*/,

                    hWnd, (HMENU)BTN21 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[21] = CreateWindow(//��һҳ��ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("��"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/,

                    460 /*X����*/, 395/*Y����*/, 40/*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN22 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hBtn[22] = CreateWindow(//��һҳ��ť

                    TEXT("button"), //��ť�ؼ�������

                    TEXT("��"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*��ƽ��ʽ*/,

                    380 /*X����*/, 395/*Y����*/, 40/*���*/, 40/*�߶�*/,

                    hWnd, (HMENU)BTN23 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit1 = CreateWindow(//�˺������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    310 /*X����*/, 170/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT1 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit2 = CreateWindow(//���������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    310 /*X����*/, 208/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT2 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit3 = CreateWindow(//������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/|ES_MULTILINE|WS_HSCROLL |WS_VSCROLL,


                    500 /*X����*/, 50/*Y����*/, 200/*���*/, 200/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT3 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit4 = CreateWindow(  //�޸����������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    537 /*X����*/, 150/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT4 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit5 = CreateWindow(	//���������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    80 /*X����*/, 35/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT5 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit6 = CreateWindow(	//��С�����

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    300 /*X����*/, 35/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT6 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit7 = CreateWindow(	//��װ�����

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    80 /*X����*/, 82/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT7 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit8 = CreateWindow(	//���������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    300 /*X����*/, 82/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT8 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit9 = CreateWindow(	//�۸������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    80 /*X����*/, 130/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT9 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );

            hEdit10 = CreateWindow(	//��������

                    TEXT("edit"), //��ť�ؼ�������

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*��ƽ��ʽ*/,

                    300 /*X����*/, 130/*Y����*/, 130/*���*/, 25/*�߶�*/, hWnd/*�����ھ��*/,

                    (HMENU)EDIT10 /*�ؼ�Ψһ��ʶ��*/, hInst, NULL

            );


            SendMessage(hStatic1,WM_SETFONT,(WPARAM)hFont,NULL);//�����ı�������
            SendMessage(hStatic2,WM_SETFONT,(WPARAM)hFont,NULL);//�����ı�������
            SendMessage(hEdit1,WM_SETFONT,(WPARAM)hFont,NULL);//�����ı�������
            SendMessage(hEdit2,WM_SETFONT,(WPARAM)hFont,NULL);//�����ı�������
            SendMessage(hEdit3,WM_SETFONT,(WPARAM)hFont,NULL);//�����ı�������
            SendMessage(hBtn[0], WM_SETFONT, (WPARAM)hFont, NULL);//���ð�ť����
            SendMessage(hBtn[1], WM_SETFONT, (WPARAM)hFont, NULL);//���ð�ť����
            SendMessage(hBtn[21], WM_SETFONT, (WPARAM)hFont2, NULL);//���ð�ť����
            SendMessage(hBtn[22], WM_SETFONT, (WPARAM)hFont2, NULL);//���ð�ť����

            show1();
            break;




        case WM_COMMAND:

            wmId    = LOWORD(wParam);

            wmEvent = HIWORD(wParam);

            if(wmId>=112&&wmId<=121)//ѡ����Ԫ������ʱ���֪ѡ��ڼ���
            {
                sprintf(xuanze,TEXT("��ѡ���˵�%dԪ����"),wmId-111);
                xuanze_num=wmId-111;
            }
            StatusPtr  write = writeDataFile(meta);//д������

            switch (wmId){


                case BTN1:  //����ע�ᰴť
                    GetWindowText(hEdit1,edit1,20);
                    GetWindowText(hEdit2,edit2,20);
                    StatusPtr res =addUser(edit1,edit2);
                    if(res->stat == SUCCESS)
                    {
                        StatusPtr denlu = login(edit1,edit2);
                        if(denlu->stat == SUCCESS)
                        {
                            MessageBox(hWnd,TEXT("ע��ɹ�"),TEXT("ע��"),MB_OK);
                            sprintf(zhanghao,TEXT("\r\n\r\n                    ���\r\n         %s�û�\r\n                ��ӭ����\r\n           Ԫ��������ϵͳ\r\n\r\n      �����Խ������²�����"),edit1);
                            SetWindowText(hStatic2,zhanghao);
                            ShowWindow(hStatic2,SW_SHOW);
                            show2();
                            yema=1;
                            xianshiye(yema);
                        }
                        else
                        {
                            MessageBox(hWnd,TEXT("ע��ʧ��"),TEXT("ע��"),MB_OK);
                        }
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("ע��ʧ��"),TEXT("ע��"),MB_OK);
                    }

                    break;

                case BTN2:  //���µ�¼��ť
                    GetWindowText(hEdit1,edit1,20);
                    GetWindowText(hEdit2,edit2,20);
                    StatusPtr denlu = login(edit1,edit2);
                    if(denlu->stat == SUCCESS)
                    {
                        MessageBox(hWnd,TEXT("��¼�ɹ�"),TEXT("��¼"),MB_OK);
                        sprintf(zhanghao,TEXT("\r\n\r\n                    ���\r\n         %s�û�\r\n                ��ӭ����\r\n           Ԫ��������ϵͳ\r\n\r\n      �����Խ������²�����"),edit1);
                        SetWindowText(hStatic2,zhanghao);
                        ShowWindow(hStatic2,SW_SHOW);
                        show2();
                        yema=1;
                        xianshiye(yema);
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("��¼ʧ��"),TEXT("��¼"),MB_OK);
                    }
                    break;

                case BTN3:		//����ע����ť
                    ;int result = MessageBox( NULL , TEXT("���Ƿ�Ҫע�����û���") , TEXT("ע���û�") , MB_ICONINFORMATION|MB_YESNO);
                    switch(result)
                    {
                        case IDYES:
                            ;StatusPtr zhuxiao = logout();
                            if(zhuxiao->stat == SUCCESS)
                            {
                                MessageBox(hWnd,TEXT("ע���ɹ�"),TEXT("ע��"),MB_OK);show1();
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("ע��ʧ��"),TEXT("ע��"),MB_OK);
                            }
                            break;
                        case IDNO:break;
                    }
                    break;


                case BTN4:		//����ɾ����ť
                    result = MessageBox( NULL , TEXT("���Ƿ�Ҫɾ�����û���") , TEXT("ע���û�") , MB_ICONINFORMATION|MB_YESNO);
                    switch(result)/*ע�⣡ʹ��UnicodeӦ��TEXT��Χ�ִ�*/
                    {
                        case IDYES:
                            ;StatusPtr shanchu = removeUser();
                            if(shanchu->stat == SUCCESS)
                            {
                                StatusPtr zhuxiao = logout();
                                if(zhuxiao->stat == SUCCESS)
                                {
                                    MessageBox(hWnd,TEXT("ɾ���ɹ�"),TEXT("ɾ��"),MB_OK);show1();
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("ɾ��ʧ��"),TEXT("ɾ��"),MB_OK);
                                }
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("ɾ��ʧ��"),TEXT("ɾ��"),MB_OK);
                            }
                            break;
                        case IDNO:break;
                    }
                    break;

                case BTN5:		//�޸����밴ť
                    show3();
                    break;


                case BTN6:     //�˳�ϵͳ��ť
                    DestroyWindow(hWnd);
                    break;

                case BTN7:   //ȷ���޸�����
                    result = MessageBox( NULL , TEXT("���Ƿ�ȷ��Ҫ�޸����룿") , TEXT("�޸�����") , MB_ICONINFORMATION|MB_YESNO);
                    switch(result)
                    {
                        case IDYES:
                            GetWindowText(hEdit4,edit4,20);
                            StatusPtr xiugaimima = editUser(edit1,edit4);
                            if(xiugaimima->stat == SUCCESS)
                            {
                                SetWindowText(hStatic2,zhanghao);
                                if(page==4)
                                {
                                    show2();
                                    show4();
                                }
                                else
                                {
                                    show2();
                                }
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("�޸�ʧ��"),TEXT("�޸�"),MB_OK);
                            }
                            break;
                        case IDNO:	break;
                    }
                    break;

                case BTN8:  //ȡ���޸�����
                    SetWindowText(hStatic2,zhanghao);
                    if(page==4)
                    {
                        show2();
                        show4();
                    }
                    else
                    {
                        show2();
                    }
                    break;

                case BTN9:    //����Ԫ����
                    if(page!=4)
                    {
                        show4();
                    }
                    else
                    {
                        GetWindowTextW(hEdit5,leixing,16);
                        GetWindowTextW(hEdit6,daxiao,16);
                        GetWindowTextW(hEdit7,fengzhuang,16);
                        GetWindowTextW(hEdit8,changjia,16);
                        GetWindowTextW(hEdit9,danjia,16);
                        GetWindowTextW(hEdit10,kucun,16);
                        wcscpy(yuanqijian[0],leixing);
                        wcscpy(yuanqijian[1],daxiao);
                        wcscpy(yuanqijian[2],fengzhuang);
                        wcscpy(yuanqijian[3],changjia);
                        wcscpy(yuanqijian[4],danjia);
                        wcscpy(yuanqijian[5],kucun);
                        result = MessageBox( NULL , TEXT("���Ƿ�Ҫ���Ӵ�Ԫ������") , TEXT("����Ԫ����") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)
                        {
                            case IDYES:
                                ;StatusPtr jiaqijain = addItem(yuanqijian);
                                if(jiaqijain->stat == SUCCESS)
                                {
                                    MessageBox(hWnd,TEXT("���ӳɹ�"),TEXT("����"),MB_OK);
                                    yema=1;
                                    xianshiye(yema);
                                    show2();
                                    break;
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("����ʧ��"),TEXT("����"),MB_OK);
                                }
                            case IDNO:show2();break;
                        }
                    }
                    break;

                case BTN10:     //��ѯԪ����
                    if(page!=4)
                    {
                        show4();
                    }
                    else
                    {
                        result = MessageBox( NULL , TEXT("���Ƿ�Ҫ��ѯ��Ԫ������") , TEXT("��ѯԪ����") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)/*ע�⣡ʹ��UnicodeӦ��TEXT��Χ�ִ�*/
                        {
                            case IDYES:
                                yema=1;
                                caxun(yema);
                                MessageBox(hWnd,TEXT("��ѯ�ɹ�"),TEXT(""),MB_OK);
                                show2();
                                break;
                            case IDNO:show2();break;
                        }
                    }
                    break;

                case BTN11:     //�޸�Ԫ����
                    if(xuanze_num>=1&&xuanze_num<=10)
                    {
                        if(page!=4)
                        {
                            ;ItemPtr item = searchItemById(yuanqijian_id[xuanze_num-1]);
                            if(item!=NULL)
                            {
                                show4();
                                SetWindowTextW(hEdit5,item->data[0]);
                                SetWindowTextW(hEdit6,item->data[1]);
                                SetWindowTextW(hEdit7,item->data[2]);
                                SetWindowTextW(hEdit8,item->data[3]);
                                SetWindowTextW(hEdit9,item->data[4]);
                                SetWindowTextW(hEdit10,item->data[5]);
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("ѡ��Ԫ����Ϊ��"),TEXT("������ѡ��"),MB_OK);
                            }


                        }
                        else
                        {
                            result = MessageBox( NULL , TEXT("���Ƿ�Ҫ�޸Ĵ�Ԫ������") , TEXT("�޸�Ԫ����") , MB_ICONINFORMATION|MB_YESNO);
                            switch(result)
                            {
                                case IDYES:
                                    GetWindowTextW(hEdit5,leixing,16);
                                    GetWindowTextW(hEdit6,daxiao,16);
                                    GetWindowTextW(hEdit7,fengzhuang,16);
                                    GetWindowTextW(hEdit8,changjia,16);
                                    GetWindowTextW(hEdit9,danjia,16);
                                    GetWindowTextW(hEdit10,kucun,16);
                                    wcscpy(yuanqijian[0],leixing);
                                    wcscpy(yuanqijian[1],daxiao);
                                    wcscpy(yuanqijian[2],fengzhuang);
                                    wcscpy(yuanqijian[3],changjia);
                                    wcscpy(yuanqijian[4],danjia);
                                    wcscpy(yuanqijian[5],kucun);
                                    StatusPtr xiugai = editItem(yuanqijian_id[xuanze_num-1], yuanqijian);
                                    if(xiugai->stat==SUCCESS)
                                    {
                                        yema=1;
                                        xianshiye(yema);
                                        MessageBox(hWnd,TEXT("�޸ĳɹ�"),TEXT(""),MB_OK);
                                        show2();
                                    }
                                    else
                                    {MessageBox(hWnd,TEXT("�޸�ʧ��"),TEXT(""),MB_OK);}
                                    break;
                                case IDNO:show2();break;
                            }
                        }
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("��ѡ��һ��Ԫ����"),TEXT("����"),MB_OK);
                    }
                    break;




                case BTN24:     //ɾ��Ԫ����
                    if(xuanze_num>=1&&xuanze_num<=10)
                    {
                        result = MessageBox( NULL , TEXT("���Ƿ�Ҫɾ����Ԫ������") , TEXT("ɾ��Ԫ����") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)
                        {
                            case IDYES:
                                ;ItemPtr item = searchItemById(yuanqijian_id[xuanze_num-1]);
                                if(item!=NULL)
                                {
                                    removeItem(yuanqijian_id[xuanze_num-1]);
                                    yema=1;
                                    xianshiye(yema);
                                    MessageBox(hWnd,TEXT("ɾ���ɹ�"),TEXT(""),MB_OK);
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("ѡ��Ԫ����Ϊ��"),TEXT("ɾ��ʧ��"),MB_OK);
                                }
                                break;
                            case IDNO:break;
                        }

                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("��ѡ��һ��Ԫ����"),TEXT("����"),MB_OK);
                    }
                    break;

                case BTN22:     //��һҳ��ť
                    if(yema<yema_max)
                        yema++;
                    if(moshi==1)
                        xianshiye(yema);
                    else
                        caxun(yema);
                    break;

                case BTN23:     //��һҳ��ť
                    if(yema>1)
                        yema--;
                    if(moshi==1)
                        xianshiye(yema);
                    else
                        caxun(yema);
                    break;


                default:

                    //���������Ϣһ��Ҫ���� DefWindowProc ����
                    return DefWindowProc(hWnd, message, wParam, lParam);

            }

            break;

        case WM_PAINT:

            hdc = BeginPaint(hWnd, &ps);

            EndPaint(hWnd, &ps);

            break;

        case WM_DESTROY:

            //�������ƺ���

            DeleteObject(hFont);

            PostQuitMessage(0);

            break;

        default:

            return DefWindowProc(hWnd, message, wParam, lParam);

    }

    return 0;

}




//�������пؼ�
void hide()
{
    ShowWindow(hStatic1,SW_HIDE);
    ShowWindow(hStatic2,SW_HIDE);
    ShowWindow(hStatic3,SW_HIDE);
    ShowWindow(hStatic4,SW_HIDE);
    ShowWindow(hStatic5,SW_HIDE);
    ShowWindow(hStatic6,SW_HIDE);
    ShowWindow(hStatic7,SW_HIDE);
    ShowWindow(hStatic8,SW_HIDE);
    ShowWindow(hStatic9,SW_HIDE);
    ShowWindow(hStatic10,SW_HIDE);
    ShowWindow(hStatic11,SW_HIDE);
    ShowWindow(hStatic12,SW_HIDE);
    ShowWindow(hBtn[0],SW_HIDE);
    ShowWindow(hBtn[1],SW_HIDE);
    ShowWindow(hBtn[2],SW_HIDE);
    ShowWindow(hBtn[3],SW_HIDE);
    ShowWindow(hBtn[4],SW_HIDE);
    ShowWindow(hBtn[5],SW_HIDE);
    ShowWindow(hBtn[6],SW_HIDE);
    ShowWindow(hBtn[7],SW_HIDE);
    ShowWindow(hBtn[8],SW_HIDE);
    ShowWindow(hBtn[9],SW_HIDE);
    ShowWindow(hBtn[10],SW_HIDE);
    ShowWindow(hBtn[11],SW_HIDE);
    ShowWindow(hBtn[12],SW_HIDE);
    ShowWindow(hBtn[13],SW_HIDE);
    ShowWindow(hBtn[14],SW_HIDE);
    ShowWindow(hBtn[15],SW_HIDE);
    ShowWindow(hBtn[16],SW_HIDE);
    ShowWindow(hBtn[17],SW_HIDE);
    ShowWindow(hBtn[18],SW_HIDE);
    ShowWindow(hBtn[19],SW_HIDE);
    ShowWindow(hBtn[20],SW_HIDE);
    ShowWindow(hBtn[21],SW_HIDE);
    ShowWindow(hBtn[22],SW_HIDE);
    ShowWindow(hBtn[23],SW_HIDE);
    ShowWindow(hBtn[24],SW_HIDE);
    ShowWindow(hBtn[25],SW_HIDE);
    ShowWindow(hEdit1,SW_HIDE);
    ShowWindow(hEdit2,SW_HIDE);
    ShowWindow(hEdit3,SW_HIDE);
    ShowWindow(hEdit4,SW_HIDE);
    ShowWindow(hEdit5,SW_HIDE);
    ShowWindow(hEdit6,SW_HIDE);
    ShowWindow(hEdit7,SW_HIDE);
    ShowWindow(hEdit8,SW_HIDE);
    ShowWindow(hEdit9,SW_HIDE);
    ShowWindow(hEdit10,SW_HIDE);
    ShowWindow(hEdit11,SW_HIDE);
    ShowWindow(hEdit12,SW_HIDE);
}


//��ʾ��¼ע�����ؼ�
void show1()
{
    hide();
    ShowWindow(hStatic1,SW_SHOW);
    ShowWindow(hBtn[0],SW_SHOW);
    ShowWindow(hBtn[1],SW_SHOW);
    ShowWindow(hEdit1,SW_SHOW);
    ShowWindow(hEdit2,SW_SHOW);
}


//��ʾϵͳ����
void show2()
{
    page=2;
    ShowWindow(hEdit5,SW_HIDE);
    ShowWindow(hEdit6,SW_HIDE);
    ShowWindow(hEdit7,SW_HIDE);
    ShowWindow(hEdit8,SW_HIDE);
    ShowWindow(hEdit9,SW_HIDE);
    ShowWindow(hEdit10,SW_HIDE);
    ShowWindow(hEdit4,SW_HIDE);
    ShowWindow(hStatic1,SW_HIDE);
    ShowWindow(hBtn[0],SW_HIDE);
    ShowWindow(hBtn[1],SW_HIDE);
    ShowWindow(hBtn[6],SW_HIDE);
    ShowWindow(hBtn[7],SW_HIDE);
    ShowWindow(hEdit1,SW_HIDE);
    ShowWindow(hEdit2,SW_HIDE);
    ShowWindow(hStatic2,SW_SHOW);
    ShowWindow(hStatic3,SW_SHOW);
    ShowWindow(hBtn[2],SW_SHOW);
    ShowWindow(hBtn[3],SW_SHOW);
    ShowWindow(hBtn[4],SW_SHOW);
    ShowWindow(hBtn[5],SW_SHOW);
    ShowWindow(hBtn[8],SW_SHOW);
    ShowWindow(hBtn[9],SW_SHOW);
    ShowWindow(hBtn[10],SW_SHOW);
    ShowWindow(hBtn[11],SW_SHOW);
    ShowWindow(hBtn[12],SW_SHOW);
    ShowWindow(hBtn[13],SW_SHOW);
    ShowWindow(hBtn[14],SW_SHOW);
    ShowWindow(hBtn[15],SW_SHOW);
    ShowWindow(hBtn[16],SW_SHOW);
    ShowWindow(hBtn[17],SW_SHOW);
    ShowWindow(hBtn[18],SW_SHOW);
    ShowWindow(hBtn[19],SW_SHOW);
    ShowWindow(hBtn[20],SW_SHOW);
    ShowWindow(hBtn[21],SW_SHOW);
    ShowWindow(hBtn[22],SW_SHOW);
    ShowWindow(hBtn[23],SW_SHOW);
    ShowWindow(hStatic5,SW_SHOW);

}


//��ʾ�޸��������
void show3()
{
    page=3;
    ShowWindow(hBtn[2],SW_HIDE);
    ShowWindow(hBtn[3],SW_HIDE);
    ShowWindow(hBtn[4],SW_HIDE);
    ShowWindow(hBtn[5],SW_HIDE);
    ShowWindow(hBtn[8],SW_SHOW);
    ShowWindow(hBtn[9],SW_SHOW);
    ShowWindow(hBtn[10],SW_SHOW);
    SetWindowText(hStatic2,TEXT("\r\n\r\n\r\n\r\n\r\n\r\n           �������µ�����:"));
    ShowWindow(hEdit4,SW_SHOW);
    ShowWindow(hStatic3,SW_SHOW);
    ShowWindow(hBtn[6],SW_SHOW);
    ShowWindow(hBtn[7],SW_SHOW);
}


//��ʾ����Ԫ��������
void show4()
{
    page=4;
    ShowWindow(hBtn[11],SW_HIDE);
    ShowWindow(hBtn[12],SW_HIDE);
    ShowWindow(hBtn[13],SW_HIDE);
    ShowWindow(hBtn[14],SW_HIDE);
    ShowWindow(hBtn[15],SW_HIDE);
    ShowWindow(hStatic4,SW_SHOW);
    ShowWindow(hEdit5,SW_SHOW);
    ShowWindow(hEdit6,SW_SHOW);
    ShowWindow(hEdit7,SW_SHOW);
    ShowWindow(hEdit8,SW_SHOW);
    ShowWindow(hEdit9,SW_SHOW);
    ShowWindow(hEdit10,SW_SHOW);
}


//��ѯ����Ԫ������ʾҳ��
void caxun(int x)
{
    moshi=2;
    GetWindowTextW(hEdit5,leixing,16);
    GetWindowTextW(hEdit6,daxiao,16);
    GetWindowTextW(hEdit7,fengzhuang,16);
    GetWindowTextW(hEdit8,changjia,16);
    GetWindowTextW(hEdit9,danjia,16);
    GetWindowTextW(hEdit10,kucun,16);
    wcscpy(yuanqijian[0],leixing);
    wcscpy(yuanqijian[1],daxiao);
    wcscpy(yuanqijian[2],fengzhuang);
    wcscpy(yuanqijian[3],changjia);
    wcscpy(yuanqijian[4],danjia);
    wcscpy(yuanqijian[5],kucun);
    ItemPtr item = searchItem(yuanqijian);
    while(item!=NULL)
    {
        num++;
        xianshinum=num-(x-1)*10;
        if(xianshinum>=1&&xianshinum<=10) {
            swprintf(yuanqijian123[xianshinum-1], 100,L"%ls %ls  %ls%ls  %ls%ls  %ls%ls  %ls%ls", item->data[0], item->data[1], meta->itemMeta[2],item->data[2],meta->itemMeta[3],
                     item->data[3], meta->itemMeta[4],item->data[4], meta->itemMeta[5],item->data[5]);
            SetWindowTextW(hBtn[xianshinum+10], yuanqijian123[xianshinum-1]);
            yuanqijian_id[xianshinum-1]= item->Iid;
        }

        item = searchNextItem(yuanqijian);
    }
    yema_max=num/10;
    if(num%10 !=0||yema_max==0)
    {yema_max=yema_max+1;}
    for(xianshinum=xianshinum+1;xianshinum<=10;xianshinum++)
    {
        SetWindowText(hBtn[xianshinum+10], TEXT(""));
        yuanqijian_id[xianshinum-1]= 10000;
    }
    sprintf(cyema,TEXT(" %d/%d"),yema,yema_max);
    SetWindowText(hStatic5,cyema);
    xianshinum=0;
    num=0;
}


//ȫ��Ԫ������ʾҳ��
void xianshiye(int x)
{
    moshi=1;
    wchar_t c[6*16] = L"";
    ItemPtr item = searchItem(c);
    while(item!=NULL)
    {
        num++;
        xianshinum=num-(x-1)*10;
        if(xianshinum>=1&&xianshinum<=10) {
            swprintf(yuanqijian123[xianshinum-1], 100,L"%ls %ls  %ls%ls  %ls%ls  %ls%ls  %ls%ls", item->data[0], item->data[1], meta->itemMeta[2],item->data[2],meta->itemMeta[3],
                    item->data[3], meta->itemMeta[4],item->data[4], meta->itemMeta[5],item->data[5]);
            SetWindowTextW(hBtn[xianshinum+10], yuanqijian123[xianshinum-1]);
            yuanqijian_id[xianshinum-1]= item->Iid;
        }

        item = searchNextItem(c);
    }
    yema_max=num/10;
    if(num%10 !=0||yema_max==0)
    {yema_max=yema_max+1;}
    for(xianshinum=xianshinum+1;xianshinum<=10;xianshinum++)
    {
        SetWindowText(hBtn[xianshinum+10], TEXT(""));
        yuanqijian_id[xianshinum-1]= 10000;
    }
    sprintf(cyema,TEXT(" %d/%d"),yema,yema_max);
    SetWindowText(hStatic5,cyema);
    xianshinum=0;
    num=0;

}