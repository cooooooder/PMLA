//
// Created by XieSiqi on 2020/7/16.
//

#ifndef PMLA_AL_CONSTRUCT_TREE_FROM_OTHER_TRAVERSAL_H
#define PMLA_AL_CONSTRUCT_TREE_FROM_OTHER_TRAVERSAL_H

namespace pmla {

class al_construct_tree_from_other_traversal {
public:
    al_tree_node *build_tree_from_preorder_and_inorder_helper(vector<int> &preorder, vector<int> &inorder, int preorder_left,
                                    int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return NULL;
        }

        al_tree_node *root = new al_tree_node(preorder[preorder_left]);
        int root_index = index[preorder[preorder_left]];
        // 左子树节点数
        int left_subtree_size = root_index - inorder_left;
        int right_subtree_size = inorder_right - root_index;
        // 递归构造左子树
        root->left = build_tree_from_preorder_and_inorder_helper(preorder, inorder, preorder_left + 1, preorder_left + left_subtree_size,
                                       inorder_left, inorder_left + left_subtree_size);
        root->right = build_tree_from_preorder_and_inorder_helper(preorder, inorder, preorder_left + left_subtree_size + 1, preorder_right,
                                        root_index + 1, inorder_right);
        return root;
    }

    /** 从前序遍历和中序遍历构建二叉树*/
    al_tree_node* build_tree_from_preorder_and_inorder(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        // 便于后续找中序遍历根节点的index
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return build_tree_from_preorder_and_inorder_helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1);
    }

    /** 从中序遍历和后序遍历构建二叉树*/

    al_tree_node *build_tree_from_inorder_and_postorder_helper(vector<int> &inorder, vector<int> &postorder,
                                                               int inorder_left, int inorder_right, int postorder_left,
                                                               int postorder_right) {
        if (inorder_left > inorder_right) {
            return NULL;
        }
        al_tree_node *root = new al_tree_node(postorder[postorder_right]);
        int root_index = index[postorder[postorder_right]];
        int left_subtree_size = root_index - inorder_left;
        int right_subtree_size = inorder_right - root_index;
        // 构造左子树
        root->left = build_tree_from_inorder_and_postorder_helper(inorder, postorder, inorder_left,
                                                                  inorder_left + left_subtree_size - 1,
                                                                  postorder_left, postorder_left + left_subtree_size - 1);
        // 构造右子树
        root->right = build_tree_from_inorder_and_postorder_helper(inorder, postorder, root_index + 1, inorder_right,
                                                                   postorder_left + left_subtree_size, postorder_right-1);
        return root;
    }

    al_tree_node* build_tree_from_inorder_and_postorder(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return NULL;
        }
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return build_tree_from_inorder_and_postorder_helper(inorder, postorder,
                                                            0, inorder.size() - 1,
                                                            0, postorder.size() - 1);
    }

private:
    unordered_map<int, int> index;
};

}

#endif //PMLA_AL_CONSTRUCT_TREE_FROM_OTHER_TRAVERSAL_H
