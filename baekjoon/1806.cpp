#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{   
    uint n=0, s=0;
    
    cin >> n >> s;
    
    uint* arr = new uint[n];
    for (uint i=0; i < n; i++)
    {
        cin >> arr[i];
    }    
    
    uint sum = arr[0], count = n+1;
    uint left = 0, right = 0;
    while(right < n)
    {
        if(sum < s)
        {
            right++;
            sum += arr[right];
        }
        else if (sum >= s)
        {
            if( count > right - left + 1)
                count = right - left + 1;
            sum -= arr[left];
            left++;
        }
    }

    if (count > n) cout << 0 << endl;
    else cout << count << endl;
    
    return 0;
}
