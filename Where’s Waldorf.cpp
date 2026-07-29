#include <iostream>
#include <vector>
#include <string>
#include <cctype>   // 使用 tolower 必須引入

using namespace std;

// 定義八個方向的位移量（上下左右、四個對角線）
int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int m, n;

// 布林函式：從 (r, c) 出發，沿著方向 dir，檢查是否能匹配單字 word
bool checkDirection(int r, int c, int dir, const string& word, const vector<vector<char>>& grid) {
    int len = word.length();
    
    for (int i = 0; i < len; i++) {
        int nr = r + dr[dir] * i;
        int nc = c + dc[dir] * i;
        
        // 邊界檢查：如果超出矩陣邊界，代表這個方向行不通
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
            return false;
        }
        
        // 字元檢查：如果字母不對，直接回傳 false
        if (grid[nr][nc] != word[i]) {
            return false;
        }
    }
    return true; // 順利比對完所有字母，成功找到！
}

void solve() {
    cin >> m >> n;
    
    // 建立 m x n 的二維字元矩陣
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            grid[i][j] = tolower(ch); // 👈 讀入時直接統一轉小寫
        }
    }
    
    int k;
    cin >> k;
    while (k--) {
        string word;
        cin >> word;
        
        // 將要搜尋的單字也轉成小寫
        for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        
        bool found = false;
        
        // 由上到下、由左到右遍歷矩陣（自動符合題目「最上最左」的優先權要求）
        for (int i = 0; i < m && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                
                // 嘗試 8 個方向
                for (int dir = 0; dir < 8; dir++) {
                    if (checkDirection(i, j, dir, word, grid)) {
                        // 題目要求從 1 開始計算索引，所以要 +1
                        cout << i + 1 << " " << j + 1 << "\n";
                        found = true; 
                        break; // 找到就跳出方向迴圈
                    }
                }
                
            }
        }
    }
}

int main() {
    // CPE 速度優化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            solve();
            
            // ⚠️ CPE 排版大陷阱：每兩個連續 Case 的輸出之間要有一個空行
            if (test_cases > 0) {
                cout << "\n";
            }
        }
    }
    return 0;
}
