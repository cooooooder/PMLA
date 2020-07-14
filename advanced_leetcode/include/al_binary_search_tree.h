//
// Created by XieSiqi on 2020/7/9.
//

#ifndef PMLA_AL_BINARY_SEARCH_TREE_H
#define PMLA_AL_BINARY_SEARCH_TREE_H
namespace pmla {

class al_binary_search_tree {
public:
    // 验证一颗二叉树是否为二叉搜索树 中序遍历结果为有序数组
    bool is_valid_binary_search_tree(al_tree_node* root) {
        if (root == NULL) {
            return true;
        }
        stack<al_tree_node*> _stack;
        _stack.push(root);
        while (!_stack.empty()) {
            auto cur = _stack.top();
            _stack.pop();

        }
    }
};
}

#endif //PMLA_AL_BINARY_SEARCH_TREE_H
