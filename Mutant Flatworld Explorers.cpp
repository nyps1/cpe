#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

int now_dir(char origindir) {
    if (origindir == 'N') {
        return 0;
    }
    else if (origindir == 'E') {
        return 1;
    }
    else if (origindir == 'S') {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    int maxX, maxY;
    cin >> maxX >> maxY;

    int startx, starty;
    char dir;
    string cmd;

    char dirs[4] = {'N', 'E', 'S', 'W'};

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    set<pair<int, int>> scent;

    while (cin >> startx >> starty >> dir) {
        cin >> cmd;

        int dire = now_dir(dir);
        bool lost = false;

        for (char c : cmd) {
            if (c == 'L') {
                dire = (dire + 3) % 4;
            }
            else if (c == 'R') {
                dire = (dire + 1) % 4;
            }
            else if (c == 'F') {
                int nextx = startx + dx[dire];
                int nexty = starty + dy[dire];

                if (nextx < 0 || nextx > maxX || nexty < 0 || nexty > maxY) {
                    if (scent.count({startx, starty})) {
                        continue;
                    }
                    else {
                        scent.insert({startx, starty});
                        lost = true;
                        break;
                    }
                }
                else {
                    startx = nextx;
                    starty = nexty;
                }
            }
        }

        cout << startx << " " << starty << " " << dirs[dire];

        if (lost) {
            cout << " LOST";
        }

        cout << "\n";
    }

    return 0;
}