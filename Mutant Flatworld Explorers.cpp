#include <iostream>
#include <string>

using namespace std;
int now_dir(char origindir){
    if (origindir == 'N'){
        return 0;   
    }else if(origindir == 'E'){
        return 1;
    }else if(origindir == 'S'){
        return 2;
    }else{
        return 3;
    }
}
int main(){
    int x, y;
    int startx, starty;
    int dire;
    char dirs[4] = {'N', 'E', 'S', 'W'};
    string cmd;
    cin >> x >> y;
    int i = 0;
    char dir;
    while(cin >> startx >> starty >> dir){
        cin >> cmd;
        dire = now_dir(dir);
        for (char c:cmd){
            
            if ((startx > x || startx < 0) || (starty > y || starty < 0)){
                    cout << startx << " " << starty << " " << dirs[dire] << " " << "LOST\n";
                    break;
            }else{
                if (c == 'F'){
                    switch (dire){
                        case 0:
                            starty += 1;
                            break;
                        case 1:
                            startx += 1;
                            break;
                        case 2:
                            starty -= 1;
                            break;
                        case 3:
                            startx -= 1;
                            break;
                    } 
                }else if(c == 'L'){
                    dire = (dire + 3) % 4;
                }else if(c == 'R'){
                    dire = (dire + 1) % 4;
                }
            }
        }
        cout << startx << " " << starty << " " << dirs[dire] << "\n";
    }
    return 0;
}