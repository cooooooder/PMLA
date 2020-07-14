//
// Created by XieSiqi on 2020/7/12.
//

#ifndef PMLA_AL_IMPLEMENT_TRIE_H
#define PMLA_AL_IMPLEMENT_TRIE_H

namespace pmla {

class al_implement_trie {
public:
    // implement prefix tree

    /** Initialize your data structure here. */
    al_implement_trie() {
        trie_node = new al_trie_node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        al_trie_node* cur = trie_node;
        for (char &c : word) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new al_trie_node();
            }
            cur = cur->children[c - 'a'];
        }
        cur->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        al_trie_node* cur = trie_node;
        for (char &c : word) {
            if (cur->children[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        al_trie_node* cur = trie_node;
        for (char &c : prefix) {
            if (cur->children[c - 'a'] == NULL) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }

private:
    al_trie_node* trie_node;
};
}

#endif //PMLA_AL_IMPLEMENT_TRIE_H
