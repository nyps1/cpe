#include <iostream>
#include <string>
#include <cctype>

using namespace std;
const char all[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string transdown(string str){
    for(int i=0; i<str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}
void Cryptanalysis(string str, int count[]){
    str = transdown(str);
    for (int i=0; i<str.length(); i++){
        for (int j=0; j<26; j++){
            if (str[i] == all[j]){
                count[j] += 1;
            }
        }
    }
    int max = 1;
    while (max){
        for (int i=0; i<25; i++){
            if (count[i] < count[i+1]){
                max = i+1;
            }else{
                max = i;
            }
        }
        cout << all[max] << " " << count[max] << "\n";
        count[max] = 1;
    }
}
int main (){
    int n;
    string str;
    cin >> n;
    cin.ignore();
    while (n--){
        
        getline(cin, str);
        int count[26];

        Cryptanalysis(str, count);
    }
    
    return 0;
}

