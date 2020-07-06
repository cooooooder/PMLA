//
// Created by XieSiqi on 2020/7/6.
//

#ifndef PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

namespace pmla {
    class al_102_binary_tree_level_order_traversal {
    public:
        struct tree_node {
            int val;
            tree_node* left;
            tree_node* right;
            tree_node(int x): val(x), left(NULL), right(NULL) {}
        };

        vector<vector<int>> level_order_traversal(tree_node *root) {
            vector<vector<int>> res;

        }

    };
}


#endif //PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
