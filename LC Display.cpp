#include <iostream>
#include <string>

using namespace std;

draw(string n, int s){
    char row = '-';
    char col = '|';
    char space = ' ';
    for(char c:n){
        int num = c - '0';
        cout >> 
    
}

int main(){
    int s;
    string n;
    while (cin >> s >> n){
        if (n == 0){
            break;
        }else{    
            draw(n, s);
        }
    }
    return 0;
}
