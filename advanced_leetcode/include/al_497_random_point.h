//
// Created by XieSiqi on 2020/7/27.
//

#ifndef PMLA_AL_497_RANDOM_POINT_H
#define PMLA_AL_497_RANDOM_POINT_H

namespace pmla {

class al_497_random_point {
public:
    /**
     * 均匀随机出整数坐标
     * @param rects
     */
    al_497_random_point(vector<vector<int>> &rects) {
        this->rects = rects;
        int area = 0;
        for (int i = 0; i < rects.size(); i++) {
            area += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            rect_area.push_back(area);
        }
        total_area = area;
    }

    vector<int> pick() {
        int random_area = rand() % total_area + 1;
        int i = 0;
        for (; i < rect_area.size(); i++) {
            if (rect_area[i] >= random_area) {
                break;
            }
        }
        int dis_x = rand() % (rects[i][2] - rects[i][0] + 1);
        int dis_y = rand() % (rect_area[i][3] - rects[i][1] + 1);
        return {rects[i][0] + dis_x, rects[i][1] + dis_y};
    }

private:
    vector<vector<int>> rects;
    int total_area = 0;
    vector<int> rect_area;
};

}

#endif //PMLA_AL_497_RANDOM_POINT_H
