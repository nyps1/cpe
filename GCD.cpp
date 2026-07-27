#include <iostream>

using namespace std;

int GCD(int i, int j){
    if (j == 0){
        return i;
    }else{
        return GCD(j, i%j);
    }
}


int main(){
    int n;
    while(cin >> n){
        int g = 0;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                g += GCD(i,j);
                //cout << g << "\n";
            }
        }
        if (n == 0){
            break;
        }else{
            cout << g << "\n";
        }
        
    }
}