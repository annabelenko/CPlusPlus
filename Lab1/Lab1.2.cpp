#include <iostream>
using namespace std;

int main() {
    int from, to;

    cout << "from: ";
    cin >> from;

    cout << "to: ";
    cin >> to;

    cout << endl;

    for (int n = from; n <= to; ++n) {
        long long x = n;
        while (true) {
            cout << x;
            if (x == 1) break;

            cout << ", ";
            if(x % 2 == 0){
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
        }
        cout << endl;
    }
    return 0;
}
