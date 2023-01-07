#include <iostream>
#include <queue>
#include <cmath>

#define RX 0
#define RY 1
#define BX 2
#define BY 3
#define DEPTH 4

#define DOT '.'
#define WALL '#'
#define HOLE 'O'
#define RED 'R'
#define BLUE 'B'

#define NO_IN 1
#define RED_IN 0
#define BLUE_IN -1

using namespace std;

//tilt_left
int br_left(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[BY]][coords[BX] - 1] != WALL)
    {
        coords[BX]--;
        if(map[coords[BY]][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            return result;
        }
    }
    while (map[coords[RY]][coords[RX] - 1] != WALL)
    {
        if(map[coords[RY]][coords[RX] - 1] == HOLE)
        {
            result = RED_IN;
            break;
        }
        //br_{direction}이 호출된 경우 이미 y좌표가 동일함을 확인했으므로
        //다시 확인할 필요 없음.
        else if (coords[RX] - 1 == coords[BX])
            break;
        coords[RX]--;
    }
    return result;
}

int rb_left(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[RY]][coords[RX] - 1] != WALL)
    {
        coords[RX]--;
        if(map[coords[RY]][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
    }
    while (map[coords[BY]][coords[BX] - 1] != WALL)
    {
        if(map[coords[BY]][coords[BX] - 1] == HOLE)
        {
            result = BLUE_IN;
            break;
        }
        else if (coords[BY] == coords[RY] && coords[BX] - 1 == coords[RX])
            break;
        coords[BX]--;
    }
    return result;
}

int tilt_left(char** map, int* coords)
{   
    coords[DEPTH] += 1;
    if (coords[RY] == coords[BY] && coords[RX] > coords[BX]) 
        return br_left(map, coords);
    else 
        return rb_left(map, coords);
}

//tilt_right
int br_right(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[BY]][coords[BX] + 1] != WALL)
    {
        coords[BX]++;
        if(map[coords[BY]][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            return result;
        }
    }
    while (map[coords[RY]][coords[RX] + 1] != WALL)
    {
        if(map[coords[RY]][coords[RX] + 1] == HOLE)
        {
            result = RED_IN;
            break;
        }
        //br_{direction}이 호출된 경우 이미 y좌표가 동일함을 확인했으므로
        //다시 확인할 필요 없음.
        else if (coords[RX] + 1 == coords[BX])
            break;
        coords[RX]++;
    }
    return result;
}

int rb_right(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[RY]][coords[RX] + 1] != WALL)
    {
        coords[RX]++;
        if(map[coords[RY]][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
    }
    while (map[coords[BY]][coords[BX] + 1] != WALL)
    {
        if(map[coords[BY]][coords[BX] + 1] == HOLE)
        {
            result = BLUE_IN;
            break;
        }
        else if (coords[BY] == coords[RY] && coords[BX] + 1 == coords[RX])
            break;
        coords[BX]++;
    }
    return result;
}

int tilt_right(char** map, int* coords)
{   
    coords[DEPTH] += 1;
    if (coords[RY] == coords[BY] && coords[RX] < coords[BX]) 
        return br_right(map, coords);
    else 
        return rb_right(map, coords);
}

//tilt_top
int br_top(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[BY] - 1][coords[BX]] != WALL)
    {
        coords[BY]--;
        if(map[coords[BY]][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            return result;
        }
    }
    while (map[coords[RY] - 1][coords[RX]] != WALL)
    {
        if(map[coords[RY] - 1][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
        //br_{direction}이 호출된 경우 이미 y좌표가 동일함을 확인했으므로
        //다시 확인할 필요 없음.
        else if (coords[RY] - 1 == coords[BY])
            break;
        coords[RY]--;
    }
    return result;
}

int rb_top(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[RY] - 1][coords[RX]] != WALL)
    {
        coords[RY]--;
        if(map[coords[RY]][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
    }
    while (map[coords[BY] - 1][coords[BX]] != WALL)
    {
        if(map[coords[BY] - 1][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            break;
        }
        else if (coords[BY] - 1 == coords[RY] && coords[BX] == coords[RX])
            break;
        coords[BY]--;
    }
    return result;
}

int tilt_top(char** map, int* coords)
{   
    coords[DEPTH] += 1;
    if (coords[RX] == coords[BX] && coords[RY] > coords[BY]) 
        return br_top(map, coords);
    else 
        return rb_top(map, coords);
}

//tilt_bottom
int br_bottom(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[BY] + 1][coords[BX]] != WALL)
    {
        coords[BY]++;
        if(map[coords[BY]][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            return result;
        }
    }
    while (map[coords[RY] + 1][coords[RX]] != WALL)
    {
        if(map[coords[RY] + 1][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
        //br_{direction}이 호출된 경우 이미 y좌표가 동일함을 확인했으므로
        //다시 확인할 필요 없음.
        else if (coords[RY] + 1 == coords[BY])
            break;
        coords[RY]++;
    }
    return result;
}

int rb_bottom(char** map, int* coords)
{
    int result = NO_IN;
    while (map[coords[RY] + 1][coords[RX]] != WALL)
    {
        coords[RY]++;
        if(map[coords[RY]][coords[RX]] == HOLE)
        {
            result = RED_IN;
            break;
        }
    }
    while (map[coords[BY] + 1][coords[BX]] != WALL)
    {
        if(map[coords[BY] + 1][coords[BX]] == HOLE)
        {
            result = BLUE_IN;
            break;
        }
        else if (coords[BY] + 1 == coords[RY] && coords[BX] == coords[RX])
            break;
        coords[BY]++;
    }
    return result;
}

int tilt_bottom(char** map, int* coords)
{   
    coords[DEPTH] += 1;
    if (coords[RX] == coords[BX] && coords[RY] < coords[BY]) 
        return br_bottom(map, coords);
    else 
        return rb_bottom(map, coords);
}


//main
int main()
{
    queue<int*> simulated;
    int* coords = new int[5];
    coords[DEPTH] = 0;
    int size_x, size_y;
    char** map;
    cin >> size_y >> size_x;

    //이차원 배열 동적 할당
    map = new char*[size_y];
    for (int i = 0; i < size_y; i++)
    {
        map[i] = new char[size_x];
    }

    char input;
    for (int y = 0; y < size_y; y++)
    {
        for (int x = 0; x < size_x; x++)
        {
            cin >> input;
            if (input == RED)
            {
                coords[RX] = x;
                coords[RY] = y;
                input = DOT;
            }
            else if (input == BLUE)
            {
                coords[BX] = x;
                coords[BY] = y;
                input = DOT;
            }
            map[y][x] = input; //consists of only DOT, WALL, and HOLE
        }
    }

    simulated.push(coords);
    int* f_coords = simulated.front();
    while(f_coords[DEPTH] < 10)
    {
        int* l_coords = new int[5];
        int* r_coords = new int[5];
        int* t_coords = new int[5];
        int* b_coords = new int[5];
        copy(f_coords, f_coords + 5, l_coords);
        copy(f_coords, f_coords + 5, r_coords);
        copy(f_coords, f_coords + 5, t_coords);
        copy(f_coords, f_coords + 5, b_coords);
        //RED_IN = 0 이므로
        //4 경우 중 하나라도 RED_IN이면
        //모두 곱하면 0이 되어 해당 depth가 답이다.
        int l_result = tilt_left(map, l_coords);
        int r_result = tilt_right(map, r_coords);
        int t_result = tilt_top(map, t_coords);
        int b_result = tilt_bottom(map, b_coords);
        int result = l_result * r_result * t_result * b_result;
        if (result == RED_IN)
        {
            cout << f_coords[DEPTH] + 1 << endl;
            return 0;
        }
        if(l_result != BLUE_IN)
            simulated.push(l_coords);
        if(r_result != BLUE_IN)
            simulated.push(r_coords);
        if(t_result != BLUE_IN)
            simulated.push(t_coords);
        if(b_result != BLUE_IN)
            simulated.push(b_coords);
        simulated.pop();
        delete[] f_coords;
        if (simulated.size() > 0)
            f_coords = simulated.front();
        else break;
    }
    //not possible under depth 10
    cout << -1 << endl;
    return 0;
}