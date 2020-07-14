//
// Created by XieSiqi on 2020/7/8.
//

#ifndef PMLA_AL_15_3SUM_H
#define PMLA_AL_15_3SUM_H


//Given an array nums of n integers, are there elements a, b, c in nums such tha
//t a + b + c = 0? Find all unique triplets in the array which gives the sum of ze
//ro.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
//Given array nums = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
//
// Related Topics Array Two Pointers
// 👍 6957 👎 814

namespace pmla {

class al_15_3sum {
public:
    // two pointers
    vector<vector<int>> three_sum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // avoid duplicated triplets
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // avoid duplicated triplets
                    while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    while (left < right && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    if (left < right && nums[left + 1] != nums[left]) {
                        left++;
                    }
                    if (left < right && nums[right - 1] != nums[right]) {
                        right--;
                    }
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};

} // end of namespace pmla

#endif //PMLA_AL_15_3SUM_H
