class Solution {
public:
    
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        vector<int>a,b;
        map<int,int>mp;
        for(auto it : matches)
        {
            mp[it[0]]+=0;
            mp[it[1]]-=1;
        }
        for(auto it : mp)
        {
            if(it.second==0)
                a.push_back(it.first);
            else if(it.second==-1)
                b.push_back(it.first);
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};
