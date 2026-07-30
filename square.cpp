#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int issquare(int i){
    for (int j = 1; j < i + 1 ; j++){
        if (i == j*j){
            return 1;
        }
    }
    return 0;
}
int main(){
    int a, b;
    while (cin >> a >> b){
        if (a == 0 && b == 0){
            return 0;
        }
        
        int count = 0;
        for (int i = a; i <= b; i++){
            double result = sqrt(i);
            if (floor(result) == result){
                count ++;
            }
        }
        cout << count << endl;
    }
    return 0;
}