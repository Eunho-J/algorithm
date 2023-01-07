#include <iostream>

using namespace std;

int dot(int* list1, int* list2, int length) {
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result += list1[i] * list2[i];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int x_A = 0, x_B = 0, y_A = 0, y_B = 0;

    cin >> y_A >> x_A;
    int **a = (int**) malloc(sizeof(int*) * y_A);
    for (int i = 0; i < y_A; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * x_A);
    }
    for (int i = 0; i < y_A; i++)
    {
        for (int j = 0; j < x_A; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cin >> y_B >> x_B;
    int **b = (int**) malloc(sizeof(int*) * x_B);
    for (int i = 0; i < x_B; i++)
    {
        b[i] = (int*)malloc(sizeof(int) * y_B);
    }
    for (int i = 0; i < y_B; i++)
    {
        for (int j = 0; j < x_B; j++)
        {
            cin >> b[j][i];
        }
    }
    for (int i = 0; i < y_A; i++)
    {
        for (int j = 0; j < x_B; j++)
        {
            cout << dot(a[i], b[j], x_A) << " ";
        }
        cout << endl;
    }
    
    return 0;
}