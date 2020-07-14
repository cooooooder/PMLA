//
// Created by XieSiqi on 2020/7/7.
//

#ifndef PMLA_AL_BINARY_TREE_TRAVERSAL_H
#define PMLA_AL_BINARY_TREE_TRAVERSAL_H

namespace pmla {
    class al_binary_tree_traversal {
    public:
        /**
         * 非递归遍历总结：在访问过的结点前加上空结点
         * time: O(n)
         * space: O(l) l为二叉树的层数
         */

        // 二叉树前序递归遍历
        void preorder_dfs(al_tree_node* root, vector<int> &res) {
            if (root == NULL) {
                return;
            }
            res.push_back(root->val);
            preorder_dfs(root->left, res);
            preorder_dfs(root->right, res);
        }

        vector<int> preorder_traversal_recursive(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            preorder_dfs(root, res);
            return res;
        }

        // 二叉树前序非递归遍历
        vector<int> preorder_traversal_iteration(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            stack<al_tree_node*> _stack;
            _stack.push(root);
            while (!_stack.empty()) {
                auto cur = _stack.top();
                _stack.pop();
                if (cur != NULL) {
                    if (cur->right) {
                        _stack.push(cur->right);
                    }
                    if (cur->left) {
                        _stack.push(cur->left);
                    }
                    _stack.push(cur);
                    //在当前节点前面加一个空节点表示已经访问过了
                    _stack.push(NULL);
                }
                else {
                    res.push_back(_stack.top()->val);
                    _stack.pop();
                }
            }
            return res;
        }

        // 二叉树中序递归遍历
        void inorder_dfs(al_tree_node* root, vector<int> &res) {
            if (root == NULL) {
                return;
            }
            inorder_dfs(root->left);
            res.push_back(root->val);
            inorder_dfs(root->right);
        }

        vector<int> inorder_traversal_recursive(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            inorder_dfs(root, res);
            return res;
        }

        // 二叉树中序非递归遍历
        vector<int> inorder_traversal_iteration(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            stack<al_tree_node*> _stack;
            _stack.push(root);
            while (_stack.empty()) {
                auto cur = _stack.top();
                _stack.pop();
                if (cur != NULL) {
                    if (cur->right) {
                        _stack.push(cur->right);
                    }
                    _stack.push(cur);
                    _stack.push(nullptr);
                    if (cur->left) {
                        _stack.push(cur->left);
                    }
                }
                else {
                    res.push_back(_stack.top()->val);
                    _stack.pop();
                }
            }
            return res;
        }

        // 二叉树后序递归遍历
        void postorder_dfs(al_tree_node* root, vector<int> &res) {
            if (root == NULL) {
                return;
            }
            postorder_dfs(root->left, res);
            postorder_dfs(root->right, res);
            res.push_back(root->val);
        }

        vector<int> postorder_traversal_recursive(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            postotder_dfs(root, res);
            return res;
        }

        // 二叉树后序非递归遍历
        vector<int> postorder_traversal_iteration(al_tree_node* root) {
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            stack<al_tree_node*> _stack;
            _stack.push(root);
            while (!_stack.empty()) {
                auto cur = _stack.top();
                _stack.pop();
                if (cur != NULL) {
                    _stack.push(cur);
                    _stack.push(NULL);
                    if (cur->right) {
                        _stack.push(cur->right);
                    }
                    if (cur->left) {
                        _stack.push(cur->left);
                    }
                }
                else {
                    res.push_back(_stack.top()->val);
                    _stack.pop();
                }
            }
            return res;
        }
    };
}

#endif //PMLA_AL_BINARY_TREE_TRAVERSAL_H
