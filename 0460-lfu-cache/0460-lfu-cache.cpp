class LFUCache {
    private:
    int capacity;
    int minfreq;
    int size;
unordered_map<int,pair<int,int>>keymap;
unordered_map<int,list<int>>freqmap;
unordered_map<int,list<int>::iterator>itermap;
void updateFreq(int key) {
        int freq = keymap[key].second;
        freqmap[freq].erase(itermap[key]);
        if (freqmap[freq].empty()) {
            freqmap.erase(freq);
            if (minfreq == freq) {
                minfreq++;
            }
        }
        freq++;
        keymap[key].second = freq;
        freqmap[freq].push_front(key);
        itermap[key] = freqmap[freq].begin();
    }
    public:

    LFUCache(int capacity) {
        this->capacity=capacity;
        this->minfreq=0;
        this->size=0;   
    }
    
    int get(int key) {
        if(keymap.find(key)==keymap.end()){
            return -1;
        }
        updateFreq(key);
        return keymap[key].first;
    }
    
    void put(int key, int value) {
         if (capacity <= 0) return;
        if (keymap.find(key) != keymap.end()) {
            keymap[key].first = value;
            updateFreq(key);
            return;
        }
        if (size >= capacity) {

            int evictKey = freqmap[minfreq].back();
            freqmap[minfreq].pop_back();
            if (freqmap[minfreq].empty()) {
                freqmap.erase(minfreq);
            }
            itermap.erase(evictKey);
            keymap.erase(evictKey);
            size--;
        }
        keymap[key]={value,1};
        freqmap[1].push_front(key);
        itermap[key] = freqmap[1].begin();
        minfreq = 1;
        size++;
    }
};
//understood the concept and algorithem but copied code

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */