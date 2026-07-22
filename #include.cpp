#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m;
    int fieldNum = 1;

    while(cin >> n >> m){
        if (n==0 && m==0){
            break;
        }
        vector<string> field(n);

        for (int i = 1; i < n; i++){
            cin >> field[i];
        }

        if (fieldNum > 1){
            cout << "\n";
        }

        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (field[i][j] == "*"){
                    cout << "*";
                    continue;
                }

                int minecount = 0;

                for (int imine = -1; imine <= 1; i++){
                    for (int jmine = -1; jmine <= 1; j++){
                        int newi = i + imine;
                        int newj = j + jmine;
                        
                        bool ismine = newi >= 0 && newi < n && newj >= 0 && newj < m;
                        if (ismine && field[newi][newj] == "*"){
                            minecount ++;
                        }
                    }
                }
                cout << minecount;
            }
            cout << "\n";
        }
        fieldNum ++;
    }
    return 0;
}