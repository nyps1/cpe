#include <iostream>
#include <string>

using namespace std;

int main(){
    int M, N;
    cin >> N >> M;
    int next[10000];
    int modnum[10000];
    for (int L = 0; L < N; L++){
        cin >> next[L];
        modnum[L] = next[L] % M;
        N--;
    }
    int lastM, lastN;
    cin >> lastN >> lastM;
    cout << N << M;
    cout << lastN << " " << lastM;
    return 0;
}