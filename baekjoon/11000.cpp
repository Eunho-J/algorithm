#include <iostream>
#include <queue>

using namespace std;


int main(int argc, char const *argv[])
{
    priority_queue<pair<uint, uint>, vector<pair<uint, uint> >, greater<pair<uint, uint> > > list;
    priority_queue<uint, vector<uint>, greater<uint>> rooms;
    int N = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        uint start, end;
        cin >> start >> end;
        // list.push(make_pair(start, end));
        list.emplace(start, end);
    }

    uint count = 0;
    while (!list.empty())
    {
        uint s = list.top().first;
        uint e = list.top().second;
        list.pop();

        if(rooms.empty()) {
            count++;
            rooms.emplace(e);
            continue;
        }

        uint cur_room = rooms.top();
        if(cur_room <= s){
            rooms.pop();
            rooms.emplace(e);
        } else {
            count++;
            rooms.emplace(e);
        }
    }

    cout << count << endl;
    return 0;
}
