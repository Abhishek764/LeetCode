// class LRUCache {
// private:
//     // Stores key and its iterator for O(1) lookup
//     unordered_map<int, list<pair<int, int>>::iterator> cache;

//     // Most recently used at front, least recently used at back
//     list<pair<int, int>> dll;

//     int capacity;

// public:
//     LRUCache(int capacity) {
//         // Initialize the cache capacity
//         this->capacity = capacity;
//     }

//     int get(int key) {
//         // If key does not exist, return -1
//         if (cache.find(key) == cache.end()) {
//             return -1;
//         }

//         // Get the node and move it to the front
//         auto it = cache[key];
//         dll.splice(dll.begin(), dll, it);

//         // Return the stored value
//         return it->second;
//     }

//     void put(int key, int value) {
//         // If key already exists, update its value
//         if (cache.find(key) != cache.end()) {
//             auto it = cache[key];
//             it->second = value;

//             // Mark it as most recently used
//             dll.splice(dll.begin(), dll, it);
//             return;
//         }

//         // If cache is full, remove the least recently used item
//         if (cache.size() == capacity) {
//             int lruKey = dll.back().first;

//             // Remove the key from the hashmap
//             cache.erase(lruKey);

//             // Remove the last node from the list
//             dll.pop_back();
//         }

//         // Insert the new key-value pair at the front
//         dll.push_front({key, value});

//         // Store its iterator in the hashmap
//         cache[key] = dll.begin();
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

class LRUCache {
private:
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;

public:
    LRUCache(int capacity) : capacity(capacity) {
        // Reserve space to reduce hashmap rehashing
        cache.reserve(capacity);
    }

    int get(int key) {
        // Find the key in O(1) average time
        auto it = cache.find(key);

        // Return -1 if key does not exist
        if (it == cache.end()) return -1;

        // Move the accessed node to the front
        dll.splice(dll.begin(), dll, it->second);

        // Return its value
        return it->second->second;
    }

    void put(int key, int value) {
        // Check whether the key already exists
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Update the existing value
            it->second->second = value;

            // Move it to the most recently used position
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        // Evict the least recently used item if cache is full
        if (cache.size() == capacity) {
            int lruKey = dll.back().first;

            // Remove it from both data structures
            cache.erase(lruKey);
            dll.pop_back();
        }

        // Insert the new item at the front
        dll.emplace_front(key, value);

        // Store its iterator in the hashmap
        cache.emplace(key, dll.begin());
    }
};