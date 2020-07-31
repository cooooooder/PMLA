//
// Created by XieSiqi on 2020/7/24.
//

#ifndef PMLA_AL_PIGEONHOLE_PRINCIPLE_H
#define PMLA_AL_PIGEONHOLE_PRINCIPLE_H

namespace pmla {

class al_pigeonhole_principle {
public:
    /** Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array),
     * some elements appear twice and others appear once.
     * Find all the elements that appear twice in this array.
     * time: O(n)
     * space: O(1)
     * 抽屉原理
     * */
     vector<int> find_duplicate_element(vector<int> &nums) {
         vector<int> res;
         if (nums.empty()) {
             return res;
         }
         int size = nums.size();
         // 原地哈希：数值为i的数字映射到下标i-1的位置
         for (int i = 0; i < size; i++) {
             while (nums[nums[i] - 1] != nums[i]) {
                 swap(nums, i, nums[i] - 1);
             }
         }

         for (int i = 0; i < size; i++) {
             cout << nums[i] << " ";
             if (nums[i] - 1 != i) {
                 res.push_back(nums[i]);
             }
         }
         cout << endl;
         return res;
     }

     void swap(vector<int> &nums, int a, int b) {
         if (a == b) {
             return;
         }
         nums[a] = nums[a] ^ nums[b];
         nums[b] = nums[a] ^ nums[b];
         nums[a] = nums[a] ^ nums[b];
     }
};

}

#endif //PMLA_AL_PIGEONHOLE_PRINCIPLE_H
