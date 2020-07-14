//
// Created by XieSiqi on 2020/7/12.
//

#ifndef PMLA_AL_648_REPLACE_WORDS_H
#define PMLA_AL_648_REPLACE_WORDS_H

//In English, we have a concept called root, which can be followed by some other
// words to form another longer word - let's call this word successor. For example
//, the root an, followed by other, which can form another word another.
//
// Now, given a dictionary consisting of many roots and a sentence. You need to
//replace all the successor in the sentence with the root forming it. If a success
//or has many roots can form it, replace it with the root with the shortest length
//.
//
// You need to output the sentence after the replacement.
//
//
// Example 1:
//
//
//Input: dict = ["cat","bat","rat"], sentence = "the cattle was rattled by the b
//attery"
//Output: "the cat was rat by the bat"
//
//
//
// Constraints:
//
//
// The input will only have lower-case letters.
// 1 <= dict.length <= 1000
// 1 <= dict[i].length <= 100
// 1 <= sentence words number <= 1000
// 1 <= sentence words length <= 1000
//
// Related Topics Hash Table Trie
// 👍 695 👎 130
namespace pmla {

class al_648_replace_words {
public:
    /** topic: trie */

    void insert(string &word) {
        al_trie_node *cur = trie_node;
        for (char &c : word) {
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new al_trie_node();
            }
            cur = cur->children[c - 'a'];
        }
        cur->is_end = true;
    }

    bool find_prefix(string &word, string &prefix) {
        al_trie_node *cur = trie_node;
        for (char &c : word) {
            if (cur->children[c - 'a'] == NULL) {
                return false;
            }
            prefix.push_back(c);
            cur = cur->children[c - 'a'];
            if (cur->is_end) {
                break;
            }
        }
        return true;
    }

    string replaceWords(vector<string> &dict, string sentence) {
        for (string &word : dict) {
            insert(word);
        }
        string res;
        vector<string> word_list;
        al_helper::split(word_list, sentence, ' ');
        for (string &word : word_list) {
            string prefix;
            if (find_prefix(word, prefix)) {
                if (res.empty()) {
                    res = prefix;
                }
                else {
                    res += " ";
                    res += prefix;
                }
            }
            else {
                if (res.empty()) {
                    res = word;
                }
                else {
                    res += " ";
                    res += word;
                }
            }
        }
        return res;
    }

private:
    al_trie_node *trie_node = new al_trie_node();
};
}

#endif //PMLA_AL_648_REPLACE_WORDS_H
