#include <iostream>
#include <vector>

using namespace std;

//2011 1 1 = 6
int main(){
    /*int t;
    cin >> t;
    int n, m;
    while (cin >> n >> m){}
    
    */
    vector<vector<int>> month;
    month[1][1] = 6;
    int day;
    for (int i = 1; i <= 12; i++){
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day = 30;
        case 2:
            day = 28;
        }
        for (int j = 1; j < day; j++){
            month[i][j+1] = month[i][j] % 7 + 1;
            cout << month[i][j] << endl;
        }
    }

}