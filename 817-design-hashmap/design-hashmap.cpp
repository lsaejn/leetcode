// Design a HashMap without using any built-in hash table libraries.
//
// To be specific, your design should include these two functions:
//
//
// 	put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
// 	get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
// 	remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
//
//
//
// Example:
//
//
// MyHashMap hashMap = new MyHashMap();
// hashMap.put(1, 1);          
// hashMap.put(2, 2);         
// hashMap.get(1);            // returns 1
// hashMap.get(3);            // returns -1 (not found)
// hashMap.put(2, 1);          // update the existing value
// hashMap.get(2);            // returns 1 
// hashMap.remove(2);          // remove the mapping for 2
// hashMap.get(2);            // returns -1 (not found) 
//
//
//
// Note:
//
//
// 	All values will be in the range of [1, 1000000].
// 	The number of operations will be in the range of [1, 10000].
// 	Please do not use the built-in HashMap library.
//


class MyHashMap {
	//构造一个效率的哈希函数本来就是比较有挑战的工作
	//我们的思路是重写一个unordered_map,以一个65535大小的数组作为桶，链表结点作为数组元素。
	//rehash比较困难，我们直接跳过。。
public:
	/** Initialize your data structure here. */
	MyHashMap() {

	}

	/** value will always be positive. */
	void put(int key, int value) {
		int index = hash_fn(key)%MAX;
		auto &ls = col[index];
		for (auto iter = ls.begin(); iter != ls.end(); ++iter)
		{
			if (iter->first == key)
			{
				iter->second = value;
				return;
			}
		}
		ls.push_back({ key,value });
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key) {
		int index = hash_fn(key) % MAX;
		auto &ls = col[index];
		for (auto iter = ls.begin(); iter != ls.end(); ++iter)
		{
			if (iter->first == key)
				return iter->second;
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	void remove(int key) {
		int index = hash_fn(key) % MAX;
		auto &ls = col[index];
		for (auto iter = ls.begin(); iter != ls.end(); )
		{
			if (iter->first == key)
			{
				iter = ls.erase(iter);
				continue;
			}
			++iter;
		}
	}
	std::hash<int> hash_fn;
	static const int MAX=6000;
	std::array<list<pair<int, int>>, MAX> col;
};
