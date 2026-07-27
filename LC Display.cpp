#include <iostream>
#include <string>
#include <vector>

using namespace std;
void drawing(int digit, int j, int i, int s){
    char row = '-';
    char col = '|';
    char space = ' ';
    if(i == 1){
        switch (digit)
        {
        case 0:
        case 2:
        case 3:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout << " " << string(s, row) << " ";
            break;
        case 1:
        case 4:
            cout << " " << string(s, space) << " ";
            break;
        }
    }else if(i > 1 && i < ((2*s+3)/2)+1){
        //cout << i << (2*s+3)/2;
        switch (digit){
            case 0:
            case 4:
            case 8:
            case 9:
                cout << "|" << string(s, space) << "|";
                break;
            case 1:
            case 2:
            case 3:
            case 7:
                cout << string(s+1, space) << "|";
                break;
            case 5:
            case 6:
                cout << "|" << string(s+1, space);
                break;
        }
    }else if(i == ((2*s+3)/2)+1){
        //cout << i << (2*s+3)/2;
        switch (digit){
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 9:
                cout << " " << string(s, row) << " ";
                break;
            case 0:
            case 1:
            case 7:
                cout << " " << string(s, space) << " ";
        }
    }else if(i < 2*s+3 && i > (2*s+3)/2){
        switch (digit){
            case 0:
            case 6:
            case 8:
                cout << "|" << string(s, space) << "|";
                break;
            case 1:
            case 5:
            case 4:
            case 3:
            case 7:
            case 9:
                cout << string(s+1, space) << "|";
                break;
            case 2:
                cout << "|" << string(s+1, space);
                break;
        }
    }else if(i == 2*s+3){
        switch (digit){
            case 0:
            case 2:
            case 3:
            case 5:
            case 6:
            case 8:
            case 9:
                cout << " " << string(s, row) << " ";
                break;
            case 1:
            case 7:
            case 4:
                cout << " " << string(s, space) << " ";
        }
    }
    
}

void draw(string n, int s){
    
    int total = 0;
    vector<int> num;
    for(char c:n){
        int digit = c - '0';
        num.push_back(digit);
        total++;
    }
    for(int i = 1; i <= 2*s+3; i++){
        for(int j = 0; j < total; j++){
            int digit = num[j];
            if(j == total -1){
                drawing(digit, j, i, s);
            }else{
                drawing(digit, j, i, s);
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    int s;
    string n;
    while (cin >> s >> n){
        if (s == 0){
            break;
        }else{    
            draw(n, s);
        }
    }
    return 0;
}
