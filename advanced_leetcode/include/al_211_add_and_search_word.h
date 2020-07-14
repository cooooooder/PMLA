//
// Created by XieSiqi on 2020/7/13.
//

#ifndef PMLA_AL_211_ADD_AND_SEARCH_WORD_H
#define PMLA_AL_211_ADD_AND_SEARCH_WORD_H

//Design a data structure that supports the following two operations:
//
//
//void addWord(word)
//bool search(word)
//
//
// search(word) can search a literal word or a regular expression string contain
//ing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
//
//
// Note:
//You may assume that all words are consist of lowercase letters a-z.
// Related Topics Backtracking Design Trie
// 👍 1773 👎 90

namespace pmla {

class al_211_add_and_search_word {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie_node = new al_trie_node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {

    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {

    }

private:
    al_trie_node* trie_node;
};

}

#endif //PMLA_AL_211_ADD_AND_SEARCH_WORD_H
