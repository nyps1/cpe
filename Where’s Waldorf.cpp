#include <iostream>
#include <vector>
#include <string>

using namespace std;
void Find_waldorf(vector<vector<char>> two_dim,vector<char> findrow, int n, int m, int length){

}

int main(){
    int situ;
    cin >> situ;
    int n, m;
    
    while (cin >> n >> m){
        string line;
        vector<vector<char>> two_dim;
        while (getline(cin, line)){
            vector<char> one_dim_row;
            stringstream ss(line);
            char str;

            while (ss >> str) {
                one_dim_row.push_back(str);
            }
            two_dim.push_back(one_dim_row);
        }

        int k;
        cin >> k;
        string findline;
        vector<char> findrow;
        while (getline(cin, findline)){
            stringstream ss(findline);
            char findstr;
            while (ss >> findstr){
                findrow.push_back(findstr);
            }
        }

        Find_waldorf(two_dim, findrow, n, m, k);
    }
    return 0;
}