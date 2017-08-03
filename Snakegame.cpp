#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include "windows.h"


using namespace std;

void made_sqar();
void clear();
void gerat();
bool ran = true;
char map_[36][68];
list < pair < int , int > > memo;
int x , y;
int p,o;
int one[] = {-1, 1, 0, 0};
int two[] = {0, 0 , -1, 1};

int main()
{
    while(true)
    {
        clear();
        made_sqar();
        x = 10; y = 20;
        int cnt = 3;
        gerat();
        memo.push_back(make_pair(x ,y));
        x = x + one[cnt]; y = y + two[cnt];
        memo.push_back(make_pair(x ,y));
        x = x + one[cnt]; y = y + two[cnt];
        memo.push_back(make_pair(x ,y));
        x = x + one[cnt]; y = y + two[cnt];
        memo.push_back(make_pair(x ,y));
        while(ran)
        {
            clear();
            for(list < pair < int , int > > ::iterator it = memo.begin() ; it != memo.end() ; it++)
            map_[it->first][it->second] = 254;
            for(int i = 0 ; i < 35 ; i++) printf("%s\n",map_[i]);
            int n = 50000000; while(n--);
            if(GetAsyncKeyState(VK_UP)) cnt = 0;
            if(GetAsyncKeyState(VK_DOWN)) cnt = 1;
            if(GetAsyncKeyState(VK_LEFT)) cnt = 2;
            if(GetAsyncKeyState(VK_RIGHT)) cnt = 3;
            if(x > 3 && x < 34 && y > 3 && y < 64 ){ x = x + one[cnt]; y = y + two[cnt];}
            else break;
            if(x ==  p && y == o) { memo.push_back(make_pair(x , y)); gerat();}
            if(map_[x][y] != ' ' && map_[x][y] != 'O') break;
            memo.push_back(make_pair(x , y));
            int k = memo.front().first;
            int l = memo.front().second;
            map_[k][l] = ' ';
            memo.pop_front();
        }
        memo.clear();
    }

    return 0;
}
void gerat()
{
    while(true){ p = rand() % 35; if(p > 3 && p < 34) break;}
    while(true) {o = rand() % 65; if(o > 3 && o < 64) break;}
    map_[p][o] = 'O';
}
void made_sqar()
{
    system("color 2");
    for(int i = 0 ; i < 35 ; i++)
    {
        for(int j = 0 ; j < 65 ; j++)
        {
            if(i == 3)
            {
                if(j < 3) map_[i][j] = ' ';
                else map_[i][j] = 219;
            }
            else if(j == 3)
            {
                if(i < 3) map_[i][j] = ' ';
                else map_[i][j] = 219;
            }
            else if(i == 34)
            {
                if(j < 3) map_[i][j] = ' ';
                else map_[i][j] = 219;
            }
            else if(j == 64)
            {
                if(i < 3) map_[i][j] = ' ';
                else map_[i][j] = 219;
            }
            else map_[i][j] = ' ';
        }

    }

}



void clear()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
