#include <iostream>
#include <string>

using namespace std;

long long piece(long long line){
    long long init = 1;
    for (long long i = 1; i <= line; i++){
        init += i;
    }
    return init;
}

int main(){
    long long line;
    cin >> line;
    while(line >= 0){
        long long max = 0;
        max = piece(line);
        cout << max << "\n"; 
        cin >> line;
    }
    return 0;
}