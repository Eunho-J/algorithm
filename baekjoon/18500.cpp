#include <iostream>
#include <set>
#include <queue>

using namespace std;

int dw[4] = {-1, 1, 0, 0};
int dh[4] = {0, 0, -1, 1};

typedef pair<int, int> Mineral;
uint cluster_id = 0;

class Cluster
{
private:
    uint id;
    set<Mineral> minerals;
public:
    Cluster(uint id);
    ~Cluster();
    bool insert_mineral(Mineral mineral);
};

Cluster::Cluster(uint id)
{
    this->id = id;
}

Cluster::~Cluster()
{
}

bool Cluster::insert_mineral(Mineral mineral)
{
    return this->minerals.insert(mineral).second;
}


int main(int argc, char const *argv[])
{
    int height, width;
    cin >> height >> width;

    char tmp;
    bool** cave = new bool*[height];
    for (int i = 0; i < height; i++)
    {
        cave[i] = new bool[width];
        for (int j = 0; j < width; j++)
        {
            cin >> tmp;
            cave[i][j] = (tmp == '.') ? false : true;
        }
    }
    
    int n, col, row;
    cin >> n;
    bool is_from_left = true;
    bool went_through = true;
    for (int i = 0; i < n; i++)
    {
        cin >> row;
        row = height - row;
        for (int j = 0; j < width; j++)
        {
            if (is_from_left)
            {
                if (cave[row][j]) 
                {
                    went_through = false;
                    col = j;
                    break;
                }
            }
            else
            {
                if (cave[row][width-j])
                {
                    went_through = false;
                    col = width - j;
                    break;
                }
            }
        }
        
        if (!went_through) {
            //TODO
        }

        is_from_left = !is_from_left;
        went_through = true;
    }
    



    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << (cave[i][j] ? 'x' : '.');
        }
        cout << endl;
    }
    return 0;
}
