#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string line;
    int count = 0;
    while (getline(cin, line)){
        
        
        for (char c:line){
            if(c == '"'){
                count += 1;
                if(count % 2 == 1){
                    cout << "``";
                }else{
                    cout << "''";
                }
            }else{
                cout << c;
            }
        }
        cout << "\n";
    }
    
    return 0;
    
}