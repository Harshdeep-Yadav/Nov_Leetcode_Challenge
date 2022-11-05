class Solution {
private:
    vector<vector<int>>vis;//mark the cell during dfs
    unordered_map<string,bool>found;//strings found during dfs
    unordered_map<string,bool>can;// prefixes of all the words
    int n,m;
	const int fx[4]={0,0,1,-1};
    const int fy[4]={1,-1,0,0};
public:
    void dfs(int x,int y,vector<vector<char>>& board,string &s){
        if(can.find(s)==can.end())return;// return if the string is invalid
        if(s.size()==10)return; // words length won't be greater than 10. so we can just return.
        s+=board[x][y];
        found[s] = 1;
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int dx = x+fx[i];
            int dy = y+fy[i];
            if(dx>=0 && dx<n && dy>=0 && dy<m){
                if(!vis[dx][dy]){
                    dfs(dx,dy,board,s);
                }
            }
        }
        s.pop_back();
        vis[x][y] = 0;
        return ;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        vector<pair<int,int>>pos[26];
        can[""]=true;
        for(auto&s:words){
            string ts;
            for(auto&c:s){
                ts+=c;
                can[ts] = 1;
            }
        }
        vis.resize(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                string s;
                dfs(i,j,board,s);
            }
        }
        vector<string>ans;
        for(auto&s:words){
          if(found[s])ans.push_back(s);
        }
        return ans;
    }
};