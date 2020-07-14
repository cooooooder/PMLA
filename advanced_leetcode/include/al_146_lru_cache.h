//
// Created by XieSiqi on 2020/7/14.
//

#ifndef PMLA_AL_146_LRU_CACHE_H
#define PMLA_AL_146_LRU_CACHE_H

//Design and implement a data structure for Least Recently Used (LRU) cache. It
//should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exis
//ts in the cache, otherwise return -1.
//put(key, value) - Set or insert the value if the key is not already present. W
//hen the cache reached its capacity, it should invalidate the least recently used
// item before inserting a new item.
//
// The cache is initialized with a positive capacity.
//
// Follow up:
//Could you do both operations in O(1) time complexity?
//
// Example:
//
//
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4
//
//
//
// Related Topics Design
// 👍 5903 👎 260

namespace pmla {

class al_146_lru_cache {
public:
    /** 使用哈希链表的数据结构来实现
     * 哈希表查找O(1) 但没有顺序
     * 链表删除增加O(1) 查找较慢（双向链表）
     * 结合两者 实现增加、删除、查找都O(1)复杂度
     * */
    al_146_lru_cache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        if (_map.find(key) == _map.end()) {
            return -1;
        }
        int val = _map[key]->second;
        // 利用 put 方法把该数据提前
        put(key, val);
        return val;
    }

    void put(int key, int val) {
        pair<int, int> new_value_pair;
        new_value_pair = make_pair(key, val);
        // 删除旧结点
        if (_map.find(key) != _map.end()) {
            cache.erase(_map[key]);
            cache.push_front(new_value_pair);
            _map[key] = cache.begin();
            return;
        }
        // 删除双向链表的最后一个结点
        if (cache.size() == _capacity) {
            pair<int, int> last_node = cache.back();
            cache.pop_back();
            _map.erase(last_node.first);
        }
        cache.push_front(new_value_pair);
        _map[key] = cache.begin();
    }

private:
    list<pair<int, int> > cache; // list跟双向链表实现相似
    unordered_map<int, list<pair<int, int> >::iterator> _map;
    int _capacity;
};

}

#endif //PMLA_AL_146_LRU_CACHE_H
