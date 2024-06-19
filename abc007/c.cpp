#include <atcoder/dsu>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
using namespace atcoder;

int main() {
    int64_t R, C;
    cin >> R >> C;

    int64_t sx, sy, ex, ey;
    cin >> sx >> sy;
    cin >> ex >> ey;

    // 0オリジン
    sx--;
    sy--;
    ex--;
    ey--;

    vector<string> maze(R);
    vector<vector<int64_t>> dist(R, vector<int64_t>(C, 0));
    for(int64_t r = 0; r < R; r++) {
        cin >> maze.at(r);
    }

    queue<pair<int64_t, int64_t>> que;
    que.push({sx, sy});

    while(que.empty() == false) {
        auto v = que.front();
        que.pop();

        auto nowDis = dist[v.second][v.first];

        // 上下左右
        if(v.first > 0 && maze[v.second][v.first - 1] == '.' && dist[v.second][v.first - 1] == 0) {
            dist[v.second][v.first - 1] = nowDis + 1;
            que.push({v.first - 1, v.second});
        }
        if(v.first < C - 1 && maze[v.second][v.first + 1] == '.' && dist[v.second][v.first + 1] == 0) {
            dist[v.second][v.first + 1] = nowDis + 1;
            que.push({v.first + 1, v.second});
        }
        if(v.second > 0 && maze[v.second - 1][v.first] == '.' && dist[v.second - 1][v.first] == 0) {
            dist[v.second - 1][v.first] = nowDis + 1;
            que.push({v.first, v.second - 1});
        }
        if(v.second < R - 1 && maze[v.second + 1][v.first] == '.' && dist[v.second + 1][v.first] == 0) {
            dist[v.second + 1][v.first] = nowDis + 1;
            que.push({v.first, v.second + 1});
        }
    }

    std::cout << dist[ex][ey] << endl;

    return(0);
}