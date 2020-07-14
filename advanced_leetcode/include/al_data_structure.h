//
// Created by XieSiqi on 2020/7/12.
//

#ifndef PMLA_AL_DATA_STRUCTURE_H
#define PMLA_AL_DATA_STRUCTURE_H

namespace pmla {
    // 定义二叉树数据结构
    struct al_tree_node {
        int val;
        al_tree_node* left;
        al_tree_node* right;
        al_tree_node(int x): val(x), left(NULL), right(NULL) {}
    };

    // 定义prefix tree数据结构
    struct al_trie_node {
        al_trie_node* children[26];
        bool is_end;
        al_trie_node() {
            is_end = false;
            memset(children, 0, sizeof(children));
        }
    };
}

#endif //PMLA_AL_DATA_STRUCTURE_H
