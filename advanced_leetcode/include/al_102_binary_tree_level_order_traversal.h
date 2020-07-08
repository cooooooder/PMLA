//
// Created by XieSiqi on 2020/7/6.
//

#ifndef PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
#define PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H

namespace pmla {
    class al_102_binary_tree_level_order_traversal {
    public:

        vector<vector<int> > level_order_traversal(al_tree_node *root) {
            vector<vector<int> > res;
            queue<al_tree_node*> _queue;
            _queue.push(root);
            while (!_queue.empty()) {
                int size = _queue.size();
                vector<int> level_res;
                for (int i = 0; i < size; i++ ) {
                    auto cur = _queue.front();
                    _queue.pop();
                    if (cur->left) {
                        _queue.push(cur->left);
                    }
                    if (cur->right) {
                        _queue.push(cur->right);
                    }
                }
                res.push_back(level_res);
            }
            return res;
        }
    };
}


#endif //PMLA_AL_102_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H
