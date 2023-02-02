#include <iostream>
#define X(pos,w)    (pos%w)
#define Y(pos,w)    ((int)(pos/w))

using namespace std;

int main() {
    cout << X(-1, 3) << " " <<  X(5, 3) << endl;
}