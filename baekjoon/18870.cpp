#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    
    int* list = (int*)malloc(sizeof(int) * count);
    int* zippedList = (int*)malloc(sizeof(int) * count);
    

    for (int i = 0; i < count; i++)
    {
        cin >> list[i];
        zippedList[i] = list[i];
    }

    sort(zippedList, zippedList + count);
    auto it = unique(zippedList, zippedList + count);
    
    for (int i = 0; i < count; i++)
    {
        cout << lower_bound(zippedList, it, list[i]) - zippedList << " ";
    }
    return 0;
}