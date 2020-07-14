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

    }
};

}

#endif //PMLA_AL_72_EDIT_DISTANCE_H
