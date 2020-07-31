//
// Created by XieSiqi on 2020/7/31.
//

#ifndef PMLA_AL_22_GENERATE_PARENTHESES_H
#define PMLA_AL_22_GENERATE_PARENTHESES_H

namespace pmla {

class al_generate_parentheses {
public:
    vector<string> generate_parentheses(int n) {
        if (n == 0) {
            return res;
        }
        dfs("", n, n);
        return res;
    }

    /**
     *
     * @param cur_str
     * @param left:表示左括号还剩几个
     * @param right:表示右括号还剩几个
     */
    void dfs(string cur_str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(cur_str);
            return;
        }
        if (left > right) {
            return;
        }
        if (left > 0) {
            dfs(cur_str + '(', left - 1, right);
        }
        if (right > 0) {
            dfs(cur_str + ')', left, right - 1);
        }
    }

private:
    vector<string> res;
};

}

#endif //PMLA_AL_22_GENERATE_PARENTHESES_H
