//
// Created by XieSiqi on 2020/7/7.
//

#ifndef PMLA_AL_BINARY_TREE_TRAVERSAL_H
#define PMLA_AL_BINARY_TREE_TRAVERSAL_H

namespace pmla {
    class al_binary_tree_traversal {
    public:
        // 二叉树前序递归遍历
        vector<int> preorder_traversal_recursive(tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            res.push_back(root->val);
            preorder_traversal_recursive(root->left);
            preorder_traversal_recursive(root->right);
            return res;
        }
    };
}

#endif //PMLA_AL_BINARY_TREE_TRAVERSAL_H
