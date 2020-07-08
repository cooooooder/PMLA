//
// Created by XieSiqi on 2020/7/6.
//

#ifndef PMLA_LEETCODE_H
#define PMLA_LEETCODE_H

#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
using namespace std;


namespace pmla {
// 定义二叉树的数据结构
    struct al_tree_node {
        int val;
        al_tree_node* left;
        al_tree_node* right;
        al_tree_node(int x): val(x), left(NULL), right(NULL) {}
    };
}


#include "al_102_binary_tree_level_order_traversal.h"

#endif //PMLA_LEETCODE_H