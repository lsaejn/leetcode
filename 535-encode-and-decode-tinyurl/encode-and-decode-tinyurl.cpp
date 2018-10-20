// Note: This is a companion problem to the System Design problem: Design TinyURL.
//
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
//
// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.


class Solution {
public:
    Solution() {
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::hash<std::string> hash_fn; 
        size_t hash = hash_fn(longUrl);
        auto passwd=to_string(hash);
        password[passwd]=longUrl;
        return "http://tinyurl.com/"+passwd;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return password[randStr];
    }
    
private:
    unordered_map<string, string> password;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
