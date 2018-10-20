// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts.  Two accounts definitely belong to the same person if there is some email that is common to both accounts.  Note that even if two accounts have the same name, they may belong to different people as people could have the same name.  A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.  The accounts themselves can be returned in any order.
//
// Example 1:
//
// Input: 
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// Explanation: 
// The first and third John's are the same person as they have the common email "johnsmith@mail.com".
// The second John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//
//
//
// Note:
// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].
//


class Solution {
public:
    //有点晕，但我们显然应该建立一个邮箱到容器的索引的映射
    //查找的问题解决了，那么如何合并，我们要为索引打上标签，看是否被合并
	vector<vector<string>> accountsMerge(const vector<vector<string>>& accounts) {
		unordered_map<string, set<int>> index;
		vector<bool> used(accounts.size());
		for (int i = 0; i != accounts.size(); ++i)
		{
			auto &emails = accounts[i];
			for (auto& email : emails)
			{
				if (email.find('@') == string::npos)
					continue;
				index[email].insert(i);
			}
		}
		vector<vector<string>> re;
		for (int i = 0; i != accounts.size(); ++i)//遍历每个账户
		{
			if (used[i]) continue;
			re.push_back(accounts[i]);//我们把这个账户放到结果里，然后找和他电邮相同的用户
			auto &now = re.back();
			set<int> same;//相同电邮的用户索引
			for (auto& email : accounts[i])//每个地址
			{
				if (email.find('@') == string::npos)
					continue;
				if (index[email].size()>1);//这个电邮还有别的用户
				for (auto j = index[email].begin(); j != index[email].end(); ++j)
				{
					if(used[*j]==false&&i!=*j)
						same.insert(*j);
				}
			}
			for (auto j = same.begin(); j != same.end(); ++j)//现在，把这个用户的小号里的电邮地址和大号的拷贝合并
			{
				used[*j] = true;
				auto& t = accounts[*j];
				for (auto& e : t)
				{
					if (e.find('@') == string::npos||find(now.begin(),now.end(),e)!=now.end())
						continue;
					now.push_back(e);
				}					
			}
			used[i] = true;
		}
        		for (auto& elem : re)
                {
			        sort(elem.begin() + 1, elem.end());
                    elem.erase(unique(elem.begin(),elem.end()),elem.end());
                }
        if(re.size()==accounts.size()) return re;//一次合并之后大小没有变化，说明全是唯一的
		return accountsMerge(re);//否则还需要下一次合并，因为有{{a,1,2},b{1,3},c{3,4}}的情况出现，我们要不断合并
    }
};
