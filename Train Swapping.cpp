#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int num;
        int count = 0;
        int train[50];
        cin >> num;
        for (int j = 0; j < num; j++){
            
            cin >> train[j];
        }
        for (int l = 0; l < num; l++){
            for (int k = 0; k < num - 1; k++){
                if (train[k] > train[k+1]){
                    int swapnum = train[k+1];
                    train[k+1] = train [k];
                    train[k] = swapnum;
                    count ++;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps.\n";
            
    }
}