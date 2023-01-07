#include <iostream>
#include <cstring>

enum coordinate
{
    X,
    Y
};
enum direction 
{
    UP,  
    EAST,  
    WEST, 
    NORTH,
    SOUTH,
    DOWN
};

int east[2] = {1, 0};
int west[2] = {-1, 0};
int north[2] = {0, 1};
int south[2] = {0, -1};

int N, M, K;
int** map;
int** moves;
int coord[2];
int dice[6];
using namespace std;

bool check_valid_and_move(int idx_move)
{
    bool valid = true;
    int* next_coord = new int[2];
    next_coord[X] = coord[X] + moves[idx_move][X];
    next_coord[Y] = coord[Y] - moves[idx_move][Y];
    if (next_coord[X] < 0 || next_coord[X] >= M)
        valid = false;
    else if (next_coord[Y] < 0 || next_coord[Y] >= N)
        valid = false;
    

    if (valid)
    {
        //TODO: move and update
        
    }

    delete[] next_coord;    
    return valid;
}

int main()
{   
    cin >> N >> M >> coord[X] >> coord[Y] >> K;
    
    map = new int*[N];
    for (int i = 0; i < N; i++)
    {
        map[i] = new int[M];
    }
    
    moves = new int*[K];

    for (int h = N-1; h >= 0; h--)
    {
        for (int w = 0; w < M; w++)
        {
            cin >> map[h][w];
        }
    }

    for (int i = 0; i < K; i++)
    {
        int move_temp;
        cin >> move_temp;
        switch (move_temp)
        {
            case EAST:
                moves[i] = east;
            case WEST:
                moves[i] = west;
            case NORTH:
                moves[i] = north;
            case SOUTH:
                moves[i] = south;
            default:
                cout<<"ERROR: input direction not matching!\n";
                return -1;
        }
    }

    for (int idx = 0; idx < K; i++)
        check_valid_and_move(idx);

    return 0;
}