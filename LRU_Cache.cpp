struct CacheBlock {
	int key;
	int value;
	CacheBlock(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }

    int get(int key) {
        if (cache_map.find(key) == cache_map.end())
			return -1;
		else {
			auto iter = cache_map[key];
			cache_list.splice(cache_list.begin(), cache_list, iter);
			cache_map[key] = cache_list.begin();
			return cache_list.begin()->value;
		}
    }

    void set(int key, int value) {
        if (cache_map.find(key) == cache_map.end()) {
            if (cache_list.size() >= max_size) {
                cache_map.erase(cache_list.back().key);
                cache_list.pop_back();
            }
            cache_list.push_front(CacheBlock(key, value));
			cache_map[key] = cache_list.begin();
        }
		else {
			auto iter = cache_map[key];
			cache_list.splice(cache_list.begin(), cache_list, iter);
			cache_map[key] = cache_list.begin();
			cache_list.begin()->value = value;
		}
    }
private:
	map<int, list<CacheBlock>::iterator> cache_map;
	list<CacheBlock> cache_list;
	int max_size;
};
