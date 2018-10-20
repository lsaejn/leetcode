// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode *child[26];
	bool isWord;
	TrieNode() : isWord(false) {
		for (auto &a : child) a = NULL;
	}
};
class Trie {
private:
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (!p->child[i]) p->child[i] = new TrieNode();
			p = p->child[i];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = root;
		for (auto &a : word) {
			int i = a - 'a';
			if (!p->child[i]) return false;
			p = p->child[i];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (auto &a : prefix) {
			int i = a - 'a';
			if (!p->child[i]) return false;
			p = p->child[i];
		}
		return true;
	}
};
