#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int* A = new int[N];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    int B, C;
    cin >> B >> C;
    long int sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(A[i] - B > 0)
            sum += (A[i] - B + C - 1) / C;
        
    }
    sum += N;
    cout << sum << endl;
    return 0;
}