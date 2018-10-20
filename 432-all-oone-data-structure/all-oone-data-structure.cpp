// Implement a data structure supporting the following operations:
//
//
//
// Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
//
//
//
//
// Challenge: Perform all these in O(1) time complexity.
//


class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {        
    }
     
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(map1.find(key) == map1.end())
        {
            //new key
            map1.insert(make_pair(key, 1));
            auto p = map2.insert(make_pair(1, key));
            map3.insert(make_pair(key, p));
        }
        else
        {
            //exist key
            int old_value = map1[key];
            ++map1[key];
            //find old key in map2
            auto old_value_in_map2_it = map3[key];
            map2.erase(old_value_in_map2_it);
            auto p = map2.insert(make_pair(old_value + 1, key));
            map3.erase(key);
            map3.insert(make_pair(key, p));
        }
    }
     
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(map1.find(key) == map1.end())
        {
            //do nothing
        }
        else
        {
            //find the key
            int old_value = map1[key];
            if(old_value == 1)
            {
                //remove it from map1 map2 and map3
                map1.erase(key);
                auto old_value_in_map2_it = map3[key];
                map2.erase(old_value_in_map2_it);
                map3.erase(key);
            }
            else
            {
                //decrease the value
                //exist key
                --map1[key];
                //find old key in map2
                auto old_value_in_map2_it = map3[key];
                map2.erase(old_value_in_map2_it);
                auto p = map2.insert(make_pair(old_value - 1, key));
                map3.erase(key);
                map3.insert(make_pair(key, p));
            }
        }
    }
     
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(map2.size() != 0)
            return (*map2.rbegin()).second;    
        else
            return "";       
    }
     
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(map2.size() != 0)
            return (*map2.begin()).second;    
        else
            return "";       
    }
     
private:
    unordered_map<string, int> map1; //key to value map
    typedef multimap<int, string>::iterator map2it;  
    multimap<int, string> map2;  // value to key map
    unordered_map<string, map2it> map3;  // key to it in map2
};
