#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int count = 0; count < t; count++){
        char garbege1;
        char garbege2;
        int matrixsize;
        cin >> garbege1 >> garbege2;
        cin >> matrixsize;
        vector<vector<long long>> matrix(matrixsize, vector<long long>(matrixsize));
        for (int i = 0; i < matrixsize; i++){
            for (int j = 0; j < matrixsize; j++){
                cin >> matrix[i][j];
            }
        }
        int issym = 0;
        for (int i = 0; i < matrixsize; i++) {
            for (int j = 0; j < matrixsize; j++) {
                // 1. 檢查負數（題目要求的隱藏條件）
                if (matrix[i][j] < 0) {
                    issym++;
                }
                // 2. 檢查中心鏡射（這行絕對不會超出 0 到 matrixsize - 1 的範圍）
                if (matrix[i][j] != matrix[matrixsize - 1 - i][matrixsize - 1 - j]) {
                    issym++;
                }
            }
        }


        if (issym == 0){
            cout << "Test #" << count+1 << ": Symmetric.\n";
        }else{
            cout << "Test #" << count+1 << ": Non-symmetric.\n";
        }
    }
    return 0;
}