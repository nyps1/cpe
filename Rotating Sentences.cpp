#include <iostream>
#include <string>

using namespace std;

int main(){
    string line[100];
    int i = 0;
    while (getline(cin, line[i])){
        i++;
    }
    int row = i-1;
    while (row >= 0){
        for (int col = 0; col < line[row].length(); col++){
            cout << line[col][row];
        }
        cout << "\n";
        row--;
    }
    
}