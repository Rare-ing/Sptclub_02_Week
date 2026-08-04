#include "Title.h"
#include "AsciiArt.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>

#pragma comment(lib,"winmm.lib")

using namespace std;

//이동
void GotoXY(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 숨기기
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;

    cursor.dwSize = 1;
    cursor.bVisible = FALSE;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//커서 다시 보이기
void ShowCursor()
{
    CONSOLE_CURSOR_INFO cursor;

    cursor.dwSize = 25;
    cursor.bVisible = TRUE;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

//색상
void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//하늘
void DrawSky()
{
    SetColor(15);

    for (int i = 0; i < Art::SkyHeight; i++)
    {
        GotoXY(0, i);

        cout << Art::Sky[i];
    }
}

//산
void DrawMountain()
{
    for (int i = 0; i < Art::MountainHeight; i++)
    {
        GotoXY(0, 10 + i);

        cout << Art::Mountain[i];
    }
}

//로고 
const int LogoRow = 1;

void DrawLogo()
{
    SetColor(14);

    for (int i = 0; i < Art::LogoHeight; i++)
    {
        GotoXY(0, LogoRow + i);

        cout << Art::Logo[i];
    }

    SetColor(15);
}

void DrawBackground()
{
    system("cls");

    DrawSky();

    DrawMountain();

    DrawLogo();
}


const int WalkerRow = 17;          // 검사 
const int WalkerMountainIndex = 7; // 자리 지우기용 
const int FogRow = 21;             // Y좌표 
const int PathLeftX = 19;          // 산길 
const int PathRightX = 89;


//잔상제거
void EraseWalker()
{
    for (int i = 0; i < Art::ManHeight; i++)
    {
        GotoXY(0, 10 + WalkerMountainIndex + i);

        cout << Art::Mountain[WalkerMountainIndex + i];
    }
}

//검사
void DrawWalker(int x, int frame)
{
    SetColor(11);

    for (int i = 0; i < Art::ManHeight; i++)
    {
        GotoXY(x, WalkerRow + i);

        cout << Art::Walk[frame][i];
    }

    SetColor(15);
}

//안개
void DrawFog(int frame)
{
    SetColor(8);

    const std::string* fog = Art::Fog1;

    if (frame == 1)
    {
        fog = Art::Fog2;
    }
    else if (frame == 2)
    {
        fog = Art::Fog3;
    }

    for (int i = 0; i < Art::FogHeight; i++)
    {
        GotoXY(0, FogRow + i);

        cout << fog[i];
    }

    SetColor(15);
}

//별 
void DrawStars(int tick)
{
    SetColor(15);

    for (int i = 0; i < Art::StarCount; i++)
    {
        int y = Art::StarY[i];

        if (y >= LogoRow && y < LogoRow + Art::LogoHeight)
        {
            continue;
        }

        GotoXY(Art::StarX[i], y);

        bool on = ((tick + i * 3) % 6) < 3;

        cout << (on ? '*' : ' ');
    }
}

// 키 깜빡임
const int PressRow = 32;
const int PressCol = 35;

void DrawPressPrompt(int tick)
{
    SetColor(10);

    GotoXY(PressCol, PressRow);

    bool on = (tick % 6) < 3;

    if (on)
    {
        cout << Art::Press;
    }
    else
    {
        cout << string(Art::Press.length(), ' ');
    }

    SetColor(15);
}

//검사
void PlayIntroAnimation()
{
    srand((unsigned)time(nullptr));

    int x = PathLeftX;
    int walkFrame = 0;
    int fogFrame = 0;
    int tick = 0;

    while (!_kbhit())
    {
        EraseWalker();

        DrawFog(fogFrame);
        DrawStars(tick);
        DrawWalker(x, walkFrame);
        DrawPressPrompt(tick);

        Sleep(180);

        x++;

        if (x > PathRightX)
        {
            x = PathLeftX;
        }

        walkFrame = (walkFrame + 1) % 4;
        fogFrame = (fogFrame + 1) % 3;
        tick++;
    }

    _getch();
}

// 이름 입력 전에 보여줄 스토리 나레이션
const std::string StoryLines[] =
{
    "1790년대 후반.",
    "조선에는 오랜 가뭄과 홍수가 반복되었다.",
    "논밭은 말라붙었고,",
    "곡식은 자라지 않았다.",
    "굶주림을 견디지 못한 백성들이 하나둘 쓰러졌으며,",
    "괴질마저 온 나라를 휩쓸었다.",
    "그리고...",
    "사람들이 죽어갈수록",
    "이상한 것들이 나타나기 시작했다.",
    "밤거리를 떠도는 요괴.",
    "산속에서 들려오는 괴이한 울음소리.",
    "그리고 죽은 자들의 혼령.",
    "사람들은 수군거렸다.",
    "\"조선에 큰 변고가 닥쳤다.\"",
    "\"왕조가 무너질 것이다.\"",
    "\"새로운 왕이 나타날 것이다.\"",
    "흉흉한 예언과 주술이 조선 전역에 퍼져나가던 때.",
    "한양의 어느 밤.",
    "한 사람이 길거리를 가로막고 있던 취객과 도적들을 상대하고 있었다.",
    "그리고 그날 밤.",
    "주인공의 운명을 바꿀 한 사람과 만나게 된다."
};

const int StoryLineCount = sizeof(StoryLines) / sizeof(StoryLines[0]);
const std::string StoryPrompt = "아무키나 입력";

const int StoryStartRow = 2;
const int StoryPromptRow = StoryStartRow + StoryLineCount + 1;

void PlayStoryIntro()
{
    system("cls");

    SetColor(15);

    for (int i = 0; i < StoryLineCount; i++)
    {
        GotoXY(20, StoryStartRow + i);
        cout << StoryLines[i];
    }

    SetColor(8);

    GotoXY(20, StoryPromptRow);
    cout << StoryPrompt;

    SetColor(15);

    while (!_kbhit())
    {
        Sleep(50);
    }

    _getch();

    system("cls");
}

void ShowTitle()
{
    // 콘솔
    system("mode con cols=120 lines=40");

    SetConsoleTitle(TEXT("환요전"));

    HideCursor();

    // BGM 재생
    PlaySound(TEXT("Title.wav"),
        NULL,
        SND_FILENAME | SND_ASYNC);

    // 배경 출력
    DrawBackground();

    // 애니메이션 (아무 키 입력 전까지 반복)
    PlayIntroAnimation();

    PlayStoryIntro();

    // 이름 입력 화면으로 넘어갈 준비
    GotoXY(0, 0);

    ShowCursor();
}
