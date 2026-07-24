#include <iostream>
#include <string>

using namespace std;
const int n = 49;

int count_digit(int fib[], int dec){
    for(int i = 2; i <= n; i++){
        if (dec < fib[i]){
            return i-1;
        }
    }
    return 0;
}
void fib_base(int fib[], int count, int dec){
    for (int i = count; i >= 2; i--){
        if (dec >= fib[i]){
            cout << 1;
            dec -= fib[i];
        }else{
            cout << 0;
        }
    }
}

int main(){
    int first_line;
    cin >> first_line;
    int fib[n+2];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int dec;
    for (int cycle = 0; cycle < first_line; cycle ++){
        int count;
        cin >> dec;
        count = count_digit(fib, dec);
        cout << dec << " = ";
        fib_base(fib, count, dec);
        cout << " (fib)\n";
    }
}