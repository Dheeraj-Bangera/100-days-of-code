// 316. Remove Duplicate Letters
class Solution {

public:

    string removeDuplicateLetters(string s) {

        vector<int> v(26,0), vis(26,0);

        for(const auto& it:s){

            v[it-'a']++;

        }

        string res="";

        for(const auto& it:s){

            v[it-'a']--;

            if(!vis[it-'a']){

                while(res.size() > 0 && res.back() > it && v[res.back()-'a'] >0){

                    vis[res.back()-'a']=0;

                    res.pop_back();

                }

                res+=it;

                vis[it-'a']=1;

            }

        }

        return res;

    }

};


        
    
