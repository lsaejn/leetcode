// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
//
// click to show corner cases.
//
// Corner Cases:
//
//  
//
//  
//
//
// 	Did you consider the case where path = "/../"?
// 	In this case, you should return "/".
// 	Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// 	In this case, you should ignore redundant slashes and return "/home/foo".
//
//


class Solution {
public:
    //我也不知道怎么做出来的，因为规则太多，散弹式随便调试了一下，居然通过了
    string simplifyPath(string path) {
        path.erase(unique(path.begin(),path.end(),[](char c,char c2){if(c==c2&&c=='/') return true; return false;}),path.end());
        //我们需要用栈，找到一个/，放进后面的字符串
        //先将字符串以/分割
        vector<string> v;
        std::string::size_type pos1, pos2;
        pos1=path.find_first_not_of("/");
        if(std::string::npos == pos1) return "/";
	    pos2 = path.find("/",pos1);
	    while (std::string::npos != pos2)
	    {
		    v.push_back(path.substr(pos1, pos2 - pos1));
		    pos1 = pos2 + 1;
		    pos2 = path.find("/", pos1);
	    }
	    if (pos1 != path.length())
		    v.push_back(path.substr(pos1));       
        vector<string> result{"/"};
        for (auto elem : v)
        {
            if(elem==".") continue;
            if(elem=="..") 
            {
                if(result.size()==1) continue;
                else result.pop_back();
            }
            else
                result.push_back(elem+"/");
        }
        string str;
        for(auto elem:result) str+=elem;
        str.pop_back();
        if(str.empty()) return"/";
        return str;
    }
};
