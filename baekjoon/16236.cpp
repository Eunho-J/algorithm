#include <iostream>
#include <queue>
#include <map>
#include <limits>

using namespace std;

typedef pair<int,int> pair_time_pos;

#define X(pos,w)    (pos%w)
#define Y(pos,w)    ((int)(pos/w))

class Shark
{
private:
    int size = 2;
    int positon;
    int ate = 0;
public:
    void set_position(int dest) {
        this->positon = dest;
    }

    int get_position() { return this->positon; }

    void move_and_eat(int dest) {
        this->ate++;
        
        if (this->ate >= this->size)
        {
            this->ate -= this->size;
            this->size++;
        }

        this->positon = dest;
    }

    bool operator<(int size) { return this->size < size; }
    bool operator>(int size) { return this->size > size; }
    friend bool operator<(int size, Shark ref);
    friend bool operator>(int size, Shark ref);
};

bool operator<(int size, Shark ref) { return size < ref.size; }
bool operator>(int size, Shark ref) { return size > ref.size; }

int main(int argc, char const *argv[])
{
    int N;
    int total_time = 0;
    Shark baby_Shark;
    
    cin >> N;

    int* field = new int[N*N];
    int* min_times = new int[N*N];
    int directions[4] = {-N, -1, 1, N};

    priority_queue<pair_time_pos, vector<pair_time_pos>, greater<pair_time_pos> > queue;
    map<int, int> fish_counter;

    for (int i = 1; i <= 6; i++)
        fish_counter[i] = 0;

    for (int pos = 0; pos < N*N; pos ++)
    {
        min_times[pos] = numeric_limits<int>::max();
        cin >> field[pos];
        if ( field[pos] == 9 )
        {
            field[pos] = 0;
            baby_Shark.set_position(pos);
        }
        else if ( field[pos] > 0)
        {
            fish_counter[field[pos]]++;
        }
        
    }

    min_times[baby_Shark.get_position()] = 0;
    queue.push(make_pair(0,baby_Shark.get_position()));

    while (!queue.empty())
    {
        int curr_time = queue.top().first;
        int curr_pos = queue.top().second;
        queue.pop();

        for (int d = 0; d < 4; d++)
        {
            //현재 칸에 아기상어보다 작은 고기가 있을 경우
            if ( field[curr_pos] < baby_Shark && field[curr_pos] > 0)
            {
                total_time += curr_time;
                //먹은 후 queue 초기화 & 시간 추가
                fish_counter[field[curr_pos]]-=1;
                field[curr_pos] = 0;
                baby_Shark.move_and_eat(curr_pos);
                while(!queue.empty()) {
                    queue.pop();
                }
                for(int i = 0; i < N*N; i++) min_times[i] = numeric_limits<int>::max();
                min_times[baby_Shark.get_position()] = 0;

                queue.push(make_pair(0, baby_Shark.get_position()));

                //먹을 수 있는 물고기가 있는지 세어 보고 없으면 종료.
                int can_eat = 0;
                for (int size = 1; size < baby_Shark; size++)
                    can_eat += fish_counter[size];

                if (can_eat <= 0) goto finish;
                break;
            }
            int direction = directions[d];
            int dest_x = X(curr_pos,N) + X(direction,N);
            int dest_y = Y(curr_pos,N) + Y(direction,N);

            //가려는 방향이 지도를 벗어날 경우
            if(dest_x < 0 || dest_x >= N || dest_y < 0 || dest_y >= N) continue;

            int destination = curr_pos + direction;
            
            //가려는 칸의 고기가 아기상어보다 클 경우 갈 수 없다.
            if ( field[destination] > baby_Shark ) continue;

            if(min_times[destination] > curr_time + 1)
            {
                min_times[destination] = curr_time + 1;
                queue.push(make_pair(curr_time+1, destination));
            }
        }
    }

finish:
    cout << total_time << endl;

    return 0;
}
