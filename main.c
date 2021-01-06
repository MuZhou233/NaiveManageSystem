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



HINSTANCE hInst;   //HINSTANCE 是“句柄型”数据类型。---------


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
    static TCHAR szClassName[] = TEXT("Win32Demo");  //窗口类名

    HWND     hwnd;  //窗口句柄

    MSG      msg;  //消息

    WNDCLASS wndclass;  //窗口类



    hInst = hInstance;   //------------



    /**********第①步：注册窗口类**********/

    //为窗口类的各个字段赋值

    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格

    wndclass.lpfnWndProc  = WndProc;  //窗口过程

    wndclass.cbClsExtra   = 0;  //暂时不需要理解

    wndclass.cbWndExtra   = 0;  //暂时不需要理解

    wndclass.hInstance    = hInstance;  //当前窗口句柄

    wndclass.hIcon        = LoadIcon (NULL, IDI_APPLICATION);  //窗口图标

    wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW);  //鼠标样式

    wndclass.hbrBackground= (HBRUSH)(COLOR_BTNFACE + 1);  //窗口背景画刷（白色）

    wndclass.lpszMenuName = NULL ;  //窗口菜单

    wndclass.lpszClassName= szClassName;  //窗口类名



    //注册窗口

    RegisterClass(&wndclass);



    /*****第②步：创建窗口(并让窗口显示出来)*****/

    hwnd = CreateWindow(

            szClassName,  //窗口名字

            TEXT("电子元器件管理系统"),  //窗口标题（出现在标题栏）

            WS_OVERLAPPEDWINDOW,  //窗口风格

            CW_USEDEFAULT,  //初始化时x轴的位置

            CW_USEDEFAULT,  //初始化时y轴的位置

            700,  //窗口宽度

            500,  //窗口高度

            NULL,  //父窗口句柄

            NULL,  //窗口菜单句柄

            hInstance,  //当前窗口的句柄

            NULL  //不使用该值

    );



    //显示窗口

    ShowWindow (hwnd, iCmdShow);

    //更新（绘制）窗口

    UpdateWindow (hwnd);



    /**********第③步：消息循环**********/

    while( GetMessage(&msg, NULL, 0, 0) ){
        TranslateMessage(&msg);  //翻译消息

        DispatchMessage (&msg);  //分派消息

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


/**********第④步：消息循环**********/

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

            ;StatusPtr  read = readDataFile(meta);//读取数据
            //创建逻辑字体
            hFont = CreateFont(

                    -15/*高度*/, -7.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,

                    FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,

                    DEFAULT_CHARSET,  //使用默认字符集

                    OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管

                    DEFAULT_QUALITY,  //默认输出质量

                    FF_DONTCARE,  //不指定字体族*/

                    TEXT("微软雅黑")  //字体名

            );

            hFont2 = CreateFont(

                    -15/*高度*/, -7.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,

                    FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,

                    DEFAULT_CHARSET,  //使用默认字符集

                    OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管

                    DEFAULT_QUALITY,  //默认输出质量

                    FF_DONTCARE,  //不指定字体族*/

                    TEXT("黑体")  //字体名

            );




            //创建静态文本控件

            hStatic1 = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT("\n    账号:\n\n    密码："),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/,

                    250/*X坐标*/, 150/*Y坐标*/, 200/*宽度*/, 100/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)STATIC1,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );

            hStatic2 = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT(" "),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/| WS_BORDER /*带边框*/ ,

                    500 /*X坐标*/, -1/*Y坐标*/, 200/*宽度*/, 700/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)STATIC2,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );

            hStatic3 = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT(" "),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/| WS_BORDER /*带边框*/ ,

                    -1 /*X坐标*/, 370/*Y坐标*/, 502/*宽度*/, 120/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)STATIC3,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );

            hStatic4 = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT("\r\n\r\n\r\n         类型：                                            大小：\r\n\r\n\r\n         封装：                                            厂家：\r\n\r\n\r\n         单价：                                            库存："),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/| WS_BORDER /*带边框*/ ,

                    -1 /*X坐标*/, -10/*Y坐标*/, 502/*宽度*/, 300/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)STATIC4,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );

            hStatic5 = CreateWindow(

                    TEXT("static"),  //静态文本框的类名

                    TEXT(" 1/10"),  //控件的文本

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/| WS_BORDER /*带边框*/ ,

                    420 /*X坐标*/, 395/*Y坐标*/, 40/*宽度*/, 40/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)STATIC5,  //为控件指定一个唯一标识符

                    hInst,  //当前实例句柄

                    NULL

            );


            //创建按钮控件

            hBtn[0] = CreateWindow(//注册按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("注册"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    270 /*X坐标*/, 260 /*Y坐标*/, 60 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN1 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[1] = CreateWindow(//登录按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("登录"),

                    WS_CHILD | WS_VISIBLE  | WS_BORDER| BS_FLAT/*扁平样式*/,

                    370 /*X坐标*/, 260 /*Y坐标*/, 60 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN2 /*控件唯一标识符*/, hInst, NULL

            );


            hBtn[2] = CreateWindow(//注销按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("注销用户"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 180 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN3 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[3] = CreateWindow(//删除用户按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("删除用户"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 240 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN4 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[4] = CreateWindow(//修改密码按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("修改密码"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER| BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 300 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN5 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[5] = CreateWindow(//退出系统按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("退出系统"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 360 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN6 /*控件唯一标识符*/, hInst, NULL

            );


            hBtn[6] = CreateWindow(//确认修改密码按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("确定修改密码"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 300 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN7 /*控件唯一标识符*/, hInst, NULL

            );


            hBtn[7] = CreateWindow(//取消修改密码按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("取消修改密码"),

                    WS_CHILD | WS_VISIBLE  | WS_BORDER| BS_FLAT/*扁平样式*/,

                    540 /*X坐标*/, 360 /*Y坐标*/, 120 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN8 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[8] = CreateWindow(//增加元器件按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("增加"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER| BS_FLAT/*扁平样式*/,

                    20 /*X坐标*/, 395 /*Y坐标*/, 80 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN9 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[9] = CreateWindow(//查询元器件按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("查询"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    110 /*X坐标*/, 395 /*Y坐标*/, 80 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN10 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[10] = CreateWindow(//修改元器件按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("修改"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    200 /*X坐标*/, 395 /*Y坐标*/, 80 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN11 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[23] = CreateWindow(//删除元器件按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("删除"),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    290 /*X坐标*/, 395 /*Y坐标*/, 80 /*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN24 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[11] = CreateWindow(//元器件1

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件1"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, -1/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN12 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[12] = CreateWindow(//元器件2

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件2"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 36/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN13 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[13] = CreateWindow(//元器件3

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件3"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 72/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN14 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[14] = CreateWindow(//元器件4

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件4"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 109/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN15 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[15] = CreateWindow(//元器件5

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件5"),

                    WS_CHILD | WS_VISIBLE | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 146/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN16 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[16]= CreateWindow(//元器件6

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件6"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 183/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN17 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[17] = CreateWindow(//元器件7

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件7"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 220/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN18 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[18] = CreateWindow(//元器件8

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件8"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 257/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN19 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[19] = CreateWindow(//元器件9

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件9"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 294/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN20 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[20] = CreateWindow(//元器件10

                    TEXT("button"), //按钮控件的类名

                    TEXT("元器件10"),

                    WS_CHILD | WS_VISIBLE   | BS_FLAT/*扁平样式*/|BS_AUTORADIOBUTTON,

                    2 /*X坐标*/, 331/*Y坐标*/, 498/*宽度*/, 38/*高度*/,

                    hWnd, (HMENU)BTN21 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[21] = CreateWindow(//下一页按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("→"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/,

                    460 /*X坐标*/, 395/*Y坐标*/, 40/*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN22 /*控件唯一标识符*/, hInst, NULL

            );

            hBtn[22] = CreateWindow(//上一页按钮

                    TEXT("button"), //按钮控件的类名

                    TEXT("←"),

                    WS_CHILD | WS_VISIBLE  | BS_FLAT/*扁平样式*/,

                    380 /*X坐标*/, 395/*Y坐标*/, 40/*宽度*/, 40/*高度*/,

                    hWnd, (HMENU)BTN23 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit1 = CreateWindow(//账号输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    310 /*X坐标*/, 170/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT1 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit2 = CreateWindow(//密码输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    310 /*X坐标*/, 208/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT2 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit3 = CreateWindow(//调试用

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/|ES_MULTILINE|WS_HSCROLL |WS_VSCROLL,


                    500 /*X坐标*/, 50/*Y坐标*/, 200/*宽度*/, 200/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT3 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit4 = CreateWindow(  //修改密码输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    537 /*X坐标*/, 150/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT4 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit5 = CreateWindow(	//类型输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    80 /*X坐标*/, 35/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT5 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit6 = CreateWindow(	//大小输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    300 /*X坐标*/, 35/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT6 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit7 = CreateWindow(	//封装输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    80 /*X坐标*/, 82/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT7 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit8 = CreateWindow(	//厂家输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    300 /*X坐标*/, 82/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT8 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit9 = CreateWindow(	//价格输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    80 /*X坐标*/, 130/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT9 /*控件唯一标识符*/, hInst, NULL

            );

            hEdit10 = CreateWindow(	//库存输入框

                    TEXT("edit"), //按钮控件的类名

                    TEXT(""),

                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,

                    300 /*X坐标*/, 130/*Y坐标*/, 130/*宽度*/, 25/*高度*/, hWnd/*父窗口句柄*/,

                    (HMENU)EDIT10 /*控件唯一标识符*/, hInst, NULL

            );


            SendMessage(hStatic1,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体
            SendMessage(hStatic2,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体
            SendMessage(hEdit1,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体
            SendMessage(hEdit2,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体
            SendMessage(hEdit3,WM_SETFONT,(WPARAM)hFont,NULL);//设置文本框字体
            SendMessage(hBtn[0], WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体
            SendMessage(hBtn[1], WM_SETFONT, (WPARAM)hFont, NULL);//设置按钮字体
            SendMessage(hBtn[21], WM_SETFONT, (WPARAM)hFont2, NULL);//设置按钮字体
            SendMessage(hBtn[22], WM_SETFONT, (WPARAM)hFont2, NULL);//设置按钮字体

            show1();
            break;




        case WM_COMMAND:

            wmId    = LOWORD(wParam);

            wmEvent = HIWORD(wParam);

            if(wmId>=112&&wmId<=121)//选择了元器件的时候得知选择第几个
            {
                sprintf(xuanze,TEXT("您选择了第%d元器件"),wmId-111);
                xuanze_num=wmId-111;
            }
            StatusPtr  write = writeDataFile(meta);//写入数据

            switch (wmId){


                case BTN1:  //按下注册按钮
                    GetWindowText(hEdit1,edit1,20);
                    GetWindowText(hEdit2,edit2,20);
                    StatusPtr res =addUser(edit1,edit2);
                    if(res->stat == SUCCESS)
                    {
                        StatusPtr denlu = login(edit1,edit2);
                        if(denlu->stat == SUCCESS)
                        {
                            MessageBox(hWnd,TEXT("注册成功"),TEXT("注册"),MB_OK);
                            sprintf(zhanghao,TEXT("\r\n\r\n                    你好\r\n         %s用户\r\n                欢迎来到\r\n           元器件管理系统\r\n\r\n      您可以进行以下操作："),edit1);
                            SetWindowText(hStatic2,zhanghao);
                            ShowWindow(hStatic2,SW_SHOW);
                            show2();
                            yema=1;
                            xianshiye(yema);
                        }
                        else
                        {
                            MessageBox(hWnd,TEXT("注册失败"),TEXT("注册"),MB_OK);
                        }
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("注册失败"),TEXT("注册"),MB_OK);
                    }

                    break;

                case BTN2:  //按下登录按钮
                    GetWindowText(hEdit1,edit1,20);
                    GetWindowText(hEdit2,edit2,20);
                    StatusPtr denlu = login(edit1,edit2);
                    if(denlu->stat == SUCCESS)
                    {
                        MessageBox(hWnd,TEXT("登录成功"),TEXT("登录"),MB_OK);
                        sprintf(zhanghao,TEXT("\r\n\r\n                    你好\r\n         %s用户\r\n                欢迎来到\r\n           元器件管理系统\r\n\r\n      您可以进行以下操作："),edit1);
                        SetWindowText(hStatic2,zhanghao);
                        ShowWindow(hStatic2,SW_SHOW);
                        show2();
                        yema=1;
                        xianshiye(yema);
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("登录失败"),TEXT("登录"),MB_OK);
                    }
                    break;

                case BTN3:		//按下注销按钮
                    ;int result = MessageBox( NULL , TEXT("您是否要注销此用户？") , TEXT("注销用户") , MB_ICONINFORMATION|MB_YESNO);
                    switch(result)
                    {
                        case IDYES:
                            ;StatusPtr zhuxiao = logout();
                            if(zhuxiao->stat == SUCCESS)
                            {
                                MessageBox(hWnd,TEXT("注销成功"),TEXT("注销"),MB_OK);show1();
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("注销失败"),TEXT("注销"),MB_OK);
                            }
                            break;
                        case IDNO:break;
                    }
                    break;


                case BTN4:		//按下删除按钮
                    result = MessageBox( NULL , TEXT("您是否要删除此用户？") , TEXT("注销用户") , MB_ICONINFORMATION|MB_YESNO);
                    switch(result)/*注意！使用Unicode应用TEXT包围字串*/
                    {
                        case IDYES:
                            ;StatusPtr shanchu = removeUser();
                            if(shanchu->stat == SUCCESS)
                            {
                                StatusPtr zhuxiao = logout();
                                if(zhuxiao->stat == SUCCESS)
                                {
                                    MessageBox(hWnd,TEXT("删除成功"),TEXT("删除"),MB_OK);show1();
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("删除失败"),TEXT("删除"),MB_OK);
                                }
                            }
                            else
                            {
                                MessageBox(hWnd,TEXT("删除失败"),TEXT("删除"),MB_OK);
                            }
                            break;
                        case IDNO:break;
                    }
                    break;

                case BTN5:		//修改密码按钮
                    show3();
                    break;


                case BTN6:     //退出系统按钮
                    DestroyWindow(hWnd);
                    break;

                case BTN7:   //确认修改密码
                    result = MessageBox( NULL , TEXT("您是否确定要修改密码？") , TEXT("修改密码") , MB_ICONINFORMATION|MB_YESNO);
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
                                MessageBox(hWnd,TEXT("修改失败"),TEXT("修改"),MB_OK);
                            }
                            break;
                        case IDNO:	break;
                    }
                    break;

                case BTN8:  //取消修改密码
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

                case BTN9:    //增加元器件
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
                        result = MessageBox( NULL , TEXT("您是否要增加此元器件？") , TEXT("增加元器件") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)
                        {
                            case IDYES:
                                ;StatusPtr jiaqijain = addItem(yuanqijian);
                                if(jiaqijain->stat == SUCCESS)
                                {
                                    MessageBox(hWnd,TEXT("增加成功"),TEXT("增加"),MB_OK);
                                    yema=1;
                                    xianshiye(yema);
                                    show2();
                                    break;
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("增加失败"),TEXT("增加"),MB_OK);
                                }
                            case IDNO:show2();break;
                        }
                    }
                    break;

                case BTN10:     //查询元器件
                    if(page!=4)
                    {
                        show4();
                    }
                    else
                    {
                        result = MessageBox( NULL , TEXT("您是否要查询此元器件？") , TEXT("查询元器件") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)/*注意！使用Unicode应用TEXT包围字串*/
                        {
                            case IDYES:
                                yema=1;
                                caxun(yema);
                                MessageBox(hWnd,TEXT("查询成功"),TEXT(""),MB_OK);
                                show2();
                                break;
                            case IDNO:show2();break;
                        }
                    }
                    break;

                case BTN11:     //修改元器件
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
                                MessageBox(hWnd,TEXT("选择元器件为空"),TEXT("请重新选择"),MB_OK);
                            }


                        }
                        else
                        {
                            result = MessageBox( NULL , TEXT("您是否要修改此元器件？") , TEXT("修改元器件") , MB_ICONINFORMATION|MB_YESNO);
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
                                        MessageBox(hWnd,TEXT("修改成功"),TEXT(""),MB_OK);
                                        show2();
                                    }
                                    else
                                    {MessageBox(hWnd,TEXT("修改失败"),TEXT(""),MB_OK);}
                                    break;
                                case IDNO:show2();break;
                            }
                        }
                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("请选择一个元器件"),TEXT("请求"),MB_OK);
                    }
                    break;




                case BTN24:     //删除元器件
                    if(xuanze_num>=1&&xuanze_num<=10)
                    {
                        result = MessageBox( NULL , TEXT("您是否要删除此元器件？") , TEXT("删除元器件") , MB_ICONINFORMATION|MB_YESNO);
                        switch(result)
                        {
                            case IDYES:
                                ;ItemPtr item = searchItemById(yuanqijian_id[xuanze_num-1]);
                                if(item!=NULL)
                                {
                                    removeItem(yuanqijian_id[xuanze_num-1]);
                                    yema=1;
                                    xianshiye(yema);
                                    MessageBox(hWnd,TEXT("删除成功"),TEXT(""),MB_OK);
                                }
                                else
                                {
                                    MessageBox(hWnd,TEXT("选择元器件为空"),TEXT("删除失败"),MB_OK);
                                }
                                break;
                            case IDNO:break;
                        }

                    }
                    else
                    {
                        MessageBox(hWnd,TEXT("请选择一个元器件"),TEXT("请求"),MB_OK);
                    }
                    break;

                case BTN22:     //下一页按钮
                    if(yema<yema_max)
                        yema++;
                    if(moshi==1)
                        xianshiye(yema);
                    else
                        caxun(yema);
                    break;

                case BTN23:     //上一页按钮
                    if(yema>1)
                        yema--;
                    if(moshi==1)
                        xianshiye(yema);
                    else
                        caxun(yema);
                    break;


                default:

                    //不处理的消息一定要交给 DefWindowProc 处理。
                    return DefWindowProc(hWnd, message, wParam, lParam);

            }

            break;

        case WM_PAINT:

            hdc = BeginPaint(hWnd, &ps);

            EndPaint(hWnd, &ps);

            break;

        case WM_DESTROY:

            //请做好善后工作

            DeleteObject(hFont);

            PostQuitMessage(0);

            break;

        default:

            return DefWindowProc(hWnd, message, wParam, lParam);

    }

    return 0;

}




//隐藏所有控件
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


//显示登录注册界面控件
void show1()
{
    hide();
    ShowWindow(hStatic1,SW_SHOW);
    ShowWindow(hBtn[0],SW_SHOW);
    ShowWindow(hBtn[1],SW_SHOW);
    ShowWindow(hEdit1,SW_SHOW);
    ShowWindow(hEdit2,SW_SHOW);
}


//显示系统界面
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


//显示修改密码界面
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
    SetWindowText(hStatic2,TEXT("\r\n\r\n\r\n\r\n\r\n\r\n           请输入新的密码:"));
    ShowWindow(hEdit4,SW_SHOW);
    ShowWindow(hStatic3,SW_SHOW);
    ShowWindow(hBtn[6],SW_SHOW);
    ShowWindow(hBtn[7],SW_SHOW);
}


//显示输入元器件界面
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


//查询特殊元器件显示页面
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


//全部元器件显示页面
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