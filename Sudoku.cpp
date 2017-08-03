#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf(a)           scanf("%d", &a)
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             50010
#define MAXR            10010
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;
const double PI = 2.0 * acos(0.0);
const double eps = 1e-11;
const int _mod = 1000000;
const int save[10][4] = {{0},{0},{6,2,4,8},{1,3,9,7},{6,4},{0},{0},{1,7,9,3},{6,8,4,2},{1,9}};
int todigit(char c) { return ( isdigit(c) ) ?( c - 48 ) : c ; }
int toint(string s) { int r = 0; istringstream sin(s); sin >> r; return r; }
ll tolong(string s) {  ll r = 0; istringstream sin(s); sin >> r; return r; }
double todouble(string s) { double r = 0.0 ; istringstream sin(s); sin >> r; return r; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > T Abs(T x) { return x > 0 ? x : -x;}
template < class T > T power(T N , T P) { return (P == 0) ?  1 : N * power(N , P - 1); }
template < class T > void max(T &a, T b) { if(a < b) a = b; }
template < class T > void min(T &a, T b) { if(b < a) a = b; }
template < class T > inline T gcd(T a,T b) {if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b);}
template < class T > inline T lcm(T a,T b) {if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b));}

//ll big_mod(ll n , ll  p , ll m)
//{
//	ll sum;
//	if(!p) return 1;
//	if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
//	else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
//}

// bool siv[MAX];
// int prime[MAX];
//void is_prime()
//{
//    int k = 0;
//    int n = sqrt(MAX);
//    prime[k++] = 2;
//    for(int i = 3 ; i < n ; i += 2) if(!siv[i]) for(int j = i * i ; j < MAX ; j += (2 * i)) siv[j] = true;
//    for(int i = 3 ; i < MAX ; i += 2) if(!siv[i]) prime[k++] = i;
//}

//int one[]={1,0,-1,0}; //4 Direction
//int two[]={0,1,0,-1}; //4 Direction
//int two[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int one[]={2,1,-1,-2,-2,-1,1,2}; //Knight Direction
//int two[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

///***************************************  END  **********************************************///

int grid[10][10];
bool sudoku();
bool usebox(int row , int col , int num);
bool have_nothing(int &row , int &col);
bool can(int num , int row , int col);
bool user(int row , int num);
bool usec(int col , int num);
void print();

int main()
{
    F_TO_R;
    freopen("output.txt", "w", stdout);
    int t, cc = 0;
    char ch;
    sf(t);
    while(t--)
    {
        for(int i = 0 ; i < 9 ; ++i) for(int j = 0 ; j < 9 ; ++j)
        {
            scanf(" %c", &ch);
            if(isdigit(ch)) grid[i][j] = todigit(ch);
            else grid[i][j] = 0;
        }
        printf("Case %d:\n", ++cc);
        if(sudoku()) print();
    }
    return 0;
}

bool sudoku()
{
    int row = 0, col = 0;
    if(!have_nothing(row , col)) return true;
    for(int i = 1 ; i <= 9 ; ++i)
    {
        if(can(i , row , col))
        {
            grid[row][col] = i;
            if(sudoku()) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

bool can(int num , int row , int col)
{
    return user(row , num) && usec(col , num) && usebox(row - row % 3 , col - col % 3 , num);
}

bool user(int row , int num)
{
    for(int k = 0 ; k < 9 ; ++k) if(grid[row][k] == num) return false;
    return true;
}

bool usec(int col , int num)
{
    for(int k = 0 ; k < 9 ; ++k) if(grid[k][col] == num) return false;
    return true;
}


bool usebox(int row , int col , int num)
{
    for(int k = 0 ; k < 3 ; ++k) for(int l = 0 ; l < 3 ; ++l) if(grid[row + k][col + l] == num) return false;
    return true;
}

bool have_nothing(int &row , int &col)
{
    for(row = 0 ; row < 9 ; ++row)  for(col = 0 ; col < 9 ; ++col) if(!grid[row][col]) return true;
    return false;
}

void print()
{
    for(int i = 0 ; i < 9 ; ++i) { for(int j = 0 ; j < 9 ; ++j) printf("%d", grid[i][j]); printf("\n");}
}
