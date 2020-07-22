//
// Created by XieSiqi on 2020/7/21.
//

#ifndef PMLA_AL_994_ROTTEN_ORANGES_H
#define PMLA_AL_994_ROTTEN_ORANGES_H

namespace pmla {

class al_994_rotten_oranges {
public:
    /** 多源BFS*/
    int oranges_rotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> _queue;
        int fresh_count = 0;
        int times = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    _queue.push(make_pair(i, j));
                }
                if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }

        while (!_queue.empty()) {
            int size = _queue.size();
            for (int i = 0; i < size; i++) {
                auto cur = _queue.front();
                _queue.pop();
                for (auto &dir: directions) {
                    int nx = cur.first + dir[0], ny = cur.second + dir[1];
                    if (nx < 0 || ny < 0 || nx >= row || ny >= col || grid[nx][ny] != 1) {
                        continue;
                    }
                    fresh_count--;
                    grid[nx][ny] = 2;
                    _queue.push(make_pair(nx, ny));
                }
            }
            if (!_queue.empty()) {
                times++;
            }
        }
        if (fresh_count) {
            return -1;
        }
        return times;
    }

private:
    vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
};

}

#endif //PMLA_AL_994_ROTTEN_ORANGES_H
