#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    std::string input;

    bool* arr = new bool[3*n];

    std::cin >> input;

    for(int i = 0; i < n; i++)
    {
        arr[i] = input.at(i) == '1';
        arr[2*n + i] = arr[i];
    }
    std::cin >> input;
    for(int i = 0; i < n; i++)
    {
        arr[n+i] = input.at(i) == '1';
    }

    int total = 0;
    //case 1: first one not change
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1] != arr[n+i-1]) 
        {
            total++;
            for(int j = -1; j < 2 && (i+j < n); j++) arr[i+j] = !arr[i+j];
        }
    }
    if(arr[n-1] == arr[2*n-1] && arr[n-2] == arr[2*n-2])
    {
        std::cout << total << std::endl;
    
        return 0;
    }

    //case 2: first one change
    total = 1;
    arr[0] = !arr[2*n];
    arr[1] = !arr[2*n+1];
    for (int i = 2; i < n; i++) arr[i] = arr[2*n + i];

    for (int i = 1; i < n; i++)
    {
        if (arr[i-1] != arr[n+i-1]) // do click
        {
            total++;
            for(int j = -1; j < 2 && (i+j < n); j++) arr[i+j] = !arr[i+j];
        }
    }
    if(arr[n-1] == arr[2*n-1] && arr[n-2] == arr[2*n-2])
    {
        std::cout << total << std::endl;
        return 0;
    }

    std::cout << -1 << std::endl;
    
    return 0;
}
