#include <iostream>
#include <queue>

#define MAX_UINT_16 0xFFFF;

using namespace std;

typedef pair< pair<uint16_t, uint16_t>, pair<uint8_t, uint8_t> > pair_t;


int main(int argc, char const *argv[])
{
    int n = 0;
    priority_queue<pair_t, vector<pair_t>, greater<pair_t> > dijkstra;
    vector<int> results;

    //---------get input----------------------
    cin >> n;

    while(n != 0)
    {
        pair_t** map = new pair_t*[n];
        for (size_t i = 0; i < n; i++)
        {
            map[i] = new pair_t[n];
            for (size_t j = 0; j < n; j++)
            {
                map[i][j].second.first = i;
                map[i][j].second.second = j;
                map[i][j].first.first = MAX_UINT_16;
                cin >> map[i][j].first.second;
            }
        }
        
        //--------simulate------------------------
        map[0][0].first.first = map[0][0].first.second;
        dijkstra.push(map[0][0]);

        pair_t current = dijkstra.top();
        while (current.second.first != n-1 || current.second.second != n-1)
        {
            uint8_t currX = current.second.first;
            uint8_t currY = current.second.second;
            uint16_t currTotal = current.first.first;

            dijkstra.pop();

            if (currX > 0)
            {
                if (map[currX-1][currY].first.first > currTotal + map[currX-1][currY].first.second)
                {
                    map[currX-1][currY].first.first = currTotal + map[currX-1][currY].first.second;
                    dijkstra.push(map[currX-1][currY]);
                }
            }

            if (currY > 0)
            {
                if (map[currX][currY-1].first.first > currTotal + map[currX][currY-1].first.second)
                {
                    map[currX][currY-1].first.first = currTotal + map[currX][currY-1].first.second;
                    dijkstra.push(map[currX][currY-1]);
                }
            }

            if (currX < n-1)
            {
                if (map[currX+1][currY].first.first > currTotal + map[currX+1][currY].first.second)
                {
                    map[currX+1][currY].first.first = currTotal + map[currX+1][currY].first.second;
                    dijkstra.push(map[currX+1][currY]);
                }
            }

            if (currY < n-1)
            {
                if (map[currX][currY+1].first.first > currTotal + map[currX][currY+1].first.second)
                {
                    map[currX][currY+1].first.first = currTotal + map[currX][currY+1].first.second;
                    dijkstra.push(map[currX][currY+1]);
                }
            }
            
            current = dijkstra.top();
        }

        results.push_back(current.first.first);

        for (size_t i = 0; i < n; i++)
        {
            delete[] map[i];
        }
        delete[] map;

        while(!dijkstra.empty())
            dijkstra.pop();

        cin >> n;
    }
    
    int i = 1;
    for (vector<int>::iterator it = results.begin(); it != results.end(); it++)
    {
        cout << "Problem " << i++ << ": " << *it << endl;
    }

    return 0;
}
