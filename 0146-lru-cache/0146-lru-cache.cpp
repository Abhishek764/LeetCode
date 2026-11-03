class LRUCache {
private:
    // Stores key and its iterator for O(1) lookup
    unordered_map<int, list<pair<int, int>>::iterator> cache;

    // Most recently used at front, least recently used at back
    list<pair<int, int>> dll;

    int capacity;

public:
    LRUCache(int capacity) {
        // Initialize the cache capacity
        this->capacity = capacity;
    }

    int get(int key) {
        // If key does not exist, return -1
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Get the node and move it to the front
        auto it = cache[key];
        dll.splice(dll.begin(), dll, it);

        // Return the stored value
        return it->second;
    }

    void put(int key, int value) {
        // If key already exists, update its value
        if (cache.find(key) != cache.end()) {
            auto it = cache[key];
            it->second = value;

            // Mark it as most recently used
            dll.splice(dll.begin(), dll, it);
            return;
        }

        // If cache is full, remove the least recently used item
        if (cache.size() == capacity) {
            int lruKey = dll.back().first;

            // Remove the key from the hashmap
            cache.erase(lruKey);

            // Remove the last node from the list
            dll.pop_back();
        }

        // Insert the new key-value pair at the front
        dll.push_front({key, value});

        // Store its iterator in the hashmap
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */