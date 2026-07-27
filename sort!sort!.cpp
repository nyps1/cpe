#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M;   // 設成全域變數，讓 cmp 可以使用

bool Odd(int x) {
    return x % 2 != 0;
}

bool cmp(int a, int b) {
    int ra = a % M;
    int rb = b % M;

    // 1. 餘數小的排前面
    if (ra != rb) {
        return ra < rb;
    }

    // 2. 餘數一樣時，判斷原本的數字是奇數還是偶數
    bool aOdd = Odd(a);
    bool bOdd = Odd(b);

    // 一奇一偶，奇數排前面
    if (aOdd != bOdd) {
        return aOdd;
    }

    // 3. 都是奇數，數值大的排前面
    if (aOdd && bOdd) {
        return a > b;
    }

    // 4. 都是偶數，數值小的排前面
    return a < b;
}

int main() {
    int N;

    while (cin >> N >> M) {
        cout << N << " " << M << "\n";

        if (N == 0 && M == 0) {
            break;
        }

        vector<int> num(N);

        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }

        sort(num.begin(), num.end(), cmp);

        for (int x : num) {
            cout << x << "\n";
        }
    }

    return 0;
}