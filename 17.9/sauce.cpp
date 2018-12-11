#include <iostream>

using namespace std;

int N;
int result;

int main() {
    cin >> N;
    while (N > 0) {
        if (N >= 50) {
            result += 7;
            N -= 50;
        }
        else if (N >= 30) {
            result += 4;
            N -= 30;
        }
        else {
            result += N/10;
            N = 0;
        }
    }
    cout << result << endl;
    return 0;
}