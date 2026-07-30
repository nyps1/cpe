#include <iostream>
#include <vector>

using namespace std;

int countday(int day){
    switch (day)
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
            break;
        case 2:
            day = 28;
            break;
        }

    return day;
}

//2011 1 1 = 6
int main(){
    vector<vector<int>> month(13, vector<int>(32, 0));    
    month[1][0] = 5;
    int day;
    for (int i = 1; i <= 12; i++){
        int temp = 0;
        day = countday(i);
        for (int j = 1; j <= day; j++, temp++){
            if (i > 1){
                if (j == 1){
                    month[i][j] = month[i-1][countday(i-1)] + 1 % 7;
                    if(month[i][j] % 7 == 1){
                        month[i][j] -= 7;
                    }
                }else{
                    month[i][j] = month[i][j-1] + 1 % 7;
                if(month[i][j] % 7 == 1){
                    month[i][j] -= 7;
                }
                }
                
            }else{
                month[i][j] = month[i][j-1] + 1 % 7;
                if(month[i][j] % 7 == 1){
                    month[i][j] -= 7;
                }
            }
        }
    }
    /*for (int testmonth = 1; testmonth <= 12; testmonth++){
        for (int testdate = 1; testdate <= countday(testmonth); testdate++){
            cout << month[testmonth][testdate] << " ";
        }
        cout << endl;
    }*/

    int t;
    cin >> t;
    int n, m;
    while (t){

        cin >> n >> m;
        switch (month[n][m])
        {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 7:
            cout << "Sunday" << endl;
            break;
        }
        t--;
    }

}