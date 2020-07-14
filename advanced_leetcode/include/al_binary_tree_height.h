//
// Created by XieSiqi on 2020/7/8.
//

#ifndef PMLA_AL_BINARY_TREE_HEIGHT_H
#define PMLA_AL_BINARY_TREE_HEIGHT_H

namespace pmla {

class al_binary_tree_height {
public:

    // 返回二叉树的最大深度
    int binary_tree_max_depth(al_tree_node* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(binary_tree_max_depth(root->left), binary_tree_max_depth(root->right));
    }

    // 判断二叉树是否为平衡二叉树
    int balanced_tree_helper(al_tree_node* root) {
        if (root == NULL) {
            return 0;
        }
        int left = balanced_tree_helper(root->left);
        if (left == -1) {
            return -1;
        }
        int right = balanced_tree_helper(root->right);
        if (right == -1) {
            return -1;
        }
        return abs(left - right) < 2 ? 1 + max(left, right) : -1;
    }

    bool is_balanced_binary_tree(al_tree_node* root) {
        if (root == NULL) {
            return true;
        }
        return balanced_tree_helper(root) != -1;
    }

    // 返回二叉树的最小深度
    int binary_tree_min_depth(al_tree_node* root) {
        if (root == NULL) {
            return 0;
        }
        int left = binary_tree_min_depth(root->left);
        int right = binary_tree_min_depth(root->right);
        // Note:左右结点可能存在左或右为空
        if (left == 0) {
            return 1 + right;
        }
        else if (right == 0) {
            return 1 + left;
        }
        else {
            return 1 + min(left, right);
        }
    }

    // 返回二叉树的最大宽度
    int max_width_of_binary_tree(al_tree_node* root) {
        int res = 0;
        if (root == NULL) {
            return res;
        }
        queue<al_tree_node*> _queue;
        _queue.push(root);
        while (!_queue.empty()) {
            int size = _queue.size();
            if (size > res) {
                res = size;
            }
            bool exist_right_node = false;
            for (int i = 0; i < size; i++) {
                auto cur = _queue.front();
                _queue.pop();
                if (i == 0 && cur->right) {
                    exist_right_node = true;
                }
                if (cur->right || exist_right_node) {
                    _queue.push(cur->right);
                }
                if (cur->left || exist_right_node) {
                    _queue.push(cur->left);
                }
            }
        }
        return res;
    }
};

} // end of namespace pmla

#endif //PMLA_AL_BINARY_TREE_HEIGHT_H
