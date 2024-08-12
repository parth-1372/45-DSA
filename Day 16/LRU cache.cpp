class LRUCache {
public:
    set<pair<int, pair<int, int>>> s; // time, {key, value}
    unordered_map<int, pair<int, int>> map; // key, {value, time}
    int size;
    int currSize;
    int time;

    LRUCache(int capacity) {
        size = capacity;
        currSize = 0;
        time = 0;
    }

    int get(int key) {
        if (map.find(key) == map.end()) return -1;

        s.erase({map[key].second, {key, map[key].first}});
        
        time++;
        map[key] = {map[key].first, time};

        s.insert({time, {key, map[key].first}});

        return map[key].first;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            s.erase({map[key].second, {key, map[key].first}});
            currSize--;
        } else if (currSize >= size) {
            auto it = s.begin();
            map.erase(it->second.first);
            s.erase(it);
            currSize--;
        }
        time++;
        s.insert({time, {key, value}});
        map[key] = {value, time};
        currSize++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
