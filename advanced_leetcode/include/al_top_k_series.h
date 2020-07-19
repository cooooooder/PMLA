//
// Created by XieSiqi on 2020/7/18.
//

#ifndef PMLA_AL_TOP_K_SERIES_H
#define PMLA_AL_TOP_K_SERIES_H

namespace pmla {

class al_top_k_series {
public:
    /** Given a non-empty array of integers, return the k most frequent elements.*/
    /**
     * time: O(nlogk)
     * space: O(n)
     * @param nums
     * @param k
     * @return
     */
    vector<int> top_k_frequent_elements(vector<int>& nums, int k) {
        unordered_map<int, int> _map;
        for (int i = 0; i < nums.size(); i++) {
            _map[nums[i]] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> _queue;
        for (auto iter = _map.begin(); iter != _map.end(); iter++) {
            if (_queue.size() >= k) {
                if (iter->second <= _queue.top().first) {
                    continue;
                }
                _queue.pop();
            }
            _queue.push(make_pair(iter->second, iter->first));
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            auto cur = _queue.top();
            _queue.pop();
            res.push_back(cur.second);
        }
        return res;
    }

    /** Given a non-empty list of words, return the k most frequent elements.*/
    vector<string> top_k_frequent_words(vector<string>& words, int k) {
        vector<string> res;
        if (words.empty() || k <= 0) {
            return res;
        }
        unordered_map<string, int> _map;
        for (string &word: words) {
            _map[word] += 1;
        }
        vector<pair<string, int>> record(_map.begin(), _map.end());
        sort(record.begin(), record.end(),
             [](const pair<string, int> &a, const pair<string, int> &b) -> bool {
                 if (a.second == b.second) {
                     return a.first < b.first;
                 }
                 return a.second > b.second;
             });
        for (auto &cur: record) {
            if (k-- == 0) {
                break;
            }
            res.push_back(cur.first);
        }
        return res;
    }

};

}

#endif //PMLA_AL_TOP_K_SERIES_H
