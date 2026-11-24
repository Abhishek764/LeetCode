class LFUCache {
    int cap, minFreq;
    unordered_map<int, pair<int,int>> kv; // key -> {value, freq}
    unordered_map<int, list<int>> freqList; // freq -> keys (front = most recent)
    unordered_map<int, list<int>::iterator> pos;

    void touch(int key) {
        int f = kv[key].second;
        freqList[f].erase(pos[key]);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }
        kv[key].second = f + 1;
        freqList[f + 1].push_front(key);
        pos[key] = freqList[f + 1].begin();
    }
public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end()) return -1;
        touch(key);
        return kv[key].first;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        if (kv.count(key)) {
            kv[key].first = value;
            touch(key);
            return;
        }
        if ((int)kv.size() >= cap) {
            int evict = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            kv.erase(evict);
            pos.erase(evict);
        }
        kv[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};