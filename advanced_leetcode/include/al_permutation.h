//
// Created by XieSiqi on 2020/7/17.
//

#ifndef PMLA_AL_PERMUTATION_H
#define PMLA_AL_PERMUTATION_H

namespace pmla {

class al_permutation {
public:
    /**
     * backtracking
     */

    /** Given a collection of distinct integers, return all possible permutations.*/
    void get_all_permutations_dfs(vector<int> &nums, vector<int> permutation, vector<bool> used) {
        if (permutation.size() == nums.size()) {
            permutation_res.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            permutation.push_back(nums[i]);
            used[i] = true;
            get_all_permutations_dfs(nums, permutation, used);
            used[i] = false;
            permutation.pop_back();
        }
    }

    vector<vector<int> > get_all_permutations(vector<int>& nums) {
        if (nums.empty()) {
            return permutation_res;
        }
        int size = nums.size();
        vector<bool> used(size, false);
        vector<int> permutation;
        get_all_permutations_dfs(nums, permutation, used);
        return permutation_res;
    }

    /** Given a collection of numbers that might contain duplicates, return all possible unique permutations.*/

    void get_unique_permutations_dfs(vector<int> &nums, vector<int> one_permutation, vector<bool> used) {
        if (one_permutation.size() == nums.size()) {
            permutation_res.push_back(one_permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            //当前值用过了 或
            //当前值等于前一个值： 两种情况：
            //1 nums[i-1] 没用过 说明回溯到了同一层 此时接着用num[i] 则会与 同层用num[i-1] 重复
            //2 nums[i-1] 用过了 说明此时在num[i-1]的下一层 相等不会重复
            if (used[i] || (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            one_permutation.push_back(nums[i]);
            used[i] = true;
            get_unique_permutations_dfs(nums, one_permutation, used);
            used[i] = false;
            one_permutation.pop_back();
        }
    }

    vector<vector<int> > get_unique_permutations(vector<int> &nums) {
        if (nums.empty()) {
            return permutation_res;
        }
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<bool> used(size, false);
        vector<int> one_permutation;
        get_unique_permutations_dfs(nums, one_permutation, used);
        return permutation_res;
    }

    /** next permutatiton*/
    void get_next_permutation(vector<int> &nums) {
        // nums {1,2,3,4,6,5}
        int size = nums.size();
        if (size == 1) {
            return;
        }
        int i = size - 2, j = size - 1, k = size - 1;
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        if (i >= 0) {
            while (k >= 0 && nums[i] >= nums[k]) {
                k--;
            }
        }
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
        sort(nums.begin() + j, nums.end());
    }

private:
    vector<vector<int> > permutation_res;
};

}


#endif //PMLA_AL_PERMUTATION_H
