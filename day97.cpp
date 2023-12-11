//find-the-difference

class Solution {

public:

    char findTheDifference(string s, string t) {

        unordered_map<char,int>map;

        for(auto x:s)

        map[x]++;          

        for(auto x:t){

            if(map.find(x)==map.end())

            return x;          

            if(map[x]>1)

            map[x]--;       
            else

            map.erase(x);     

        }

        return '1'; 

        

    }

};

        
    
