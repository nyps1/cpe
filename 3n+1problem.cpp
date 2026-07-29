#include <iostream>
#include <string>

using namespace std;

long long cal(long long k){
    long long count = 1;
    while (k >= 1){ 
        if (k == 1){
            //cout << count;
            return count;
        }else{
            if (k % 2 == 1){
                k = 3*k+1;
            }else{
                k = k/2;
            }
        }
        count ++;
    }
    return 0;
}

int main(){
    long long i, j;
    while(cin >> i >> j){
        long long cali = i;
        long long calj = j;
        long long temp;
        long long maxcyclelength = 0;
        long long cyclelength;
        if (cali > calj){
            temp = cali;
            cali = calj;
            calj = temp;
        }
        for (long long k = cali; k <= calj; k++){
            //cout << k;
            cyclelength = cal(k);
            
            if (maxcyclelength < cyclelength){
                maxcyclelength = cyclelength;
            }
        }
        cout << i << " " << j << " " << maxcyclelength << "\n";
    }
    return 0;

}