//
// Created by XieSiqi on 2020/7/6.
//
#include "al_test.h"
#include "al_102_binary_tree_level_order_traversal_test.h"

void al_102_binary_tree_level_order_traversal_test::test() {
    printf("haha");

    al_102_binary_tree_level_order_traversal instance;
    al_tree_node* root = new al_tree_node(1);
    al_tree_node* left = new al_tree_node(2);
    al_tree_node* right = new al_tree_node(3);
    root->left = left;
    root->right = right;

    vector<vector<int> > res = instance.level_order_traversal(root);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}