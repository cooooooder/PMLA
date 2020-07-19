//
// Created by XieSiqi on 2020/7/14.
//

#ifndef PMLA_AL_72_EDIT_DISTANCE_H
#define PMLA_AL_72_EDIT_DISTANCE_H

//Given two words word1 and word2, find the minimum number of operations require
//d to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
//
// Insert a character
// Delete a character
// Replace a character
//
//
// Example 1:
//
//
//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation:
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')
//
//
// Example 2:
//
//
//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation:
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')
//
// Related Topics String Dynamic Programming
// 👍 3951 👎 56

namespace pmla {

class al_72_edit_distance {
public:
    int min_edit_distance(string word1, string word2) {
        int word1_length = word1.length();
        int word2_length = word2.length();
        if (word1_length == 0) {
            return word2_length;
        }
        if (word2_length == 0) {
            return word1_length;
        }
        vector<vector<int> > dp(word1_length + 1, vector<int>(word2_length + 1, 0));
        // 针对第一行
        for (int i = 1; i <= word1_length; i++) {
            dp[0][i] = dp[0][i-1] + 1;
        }
        // 针对第一列
        for (int i = 1; i <= word2_length; i++) {
            dp[i][0] = dp[i-1][0] + 1;
        }

        for (int i = 1; i <= word1_length; i++) {
            for (int j = 1; j <= word2_length; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    // 增加、删除、替换
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[word1_length][word2_length];
    }
};

}

#endif //PMLA_AL_72_EDIT_DISTANCE_H
