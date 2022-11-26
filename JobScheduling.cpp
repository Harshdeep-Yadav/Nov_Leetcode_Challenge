class Solution { //teeepa hai bhai
private:
    int lowerBound(vector<vector<int>>&v,int start,int lo,int hi){
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid][1]<=start){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
//         Sort the array by endTime
        sort(v.begin(),v.end(),cmp);
        vector<int>dp(n,0);
        dp[0]=v[0][2];
        
        for(int i=1;i<n;i++){
            int start=v[i][0];
            // find the end time less than equal start time using binary search
            int prev=lowerBound(v,start,0,i-1);
            if(prev==-1){
                dp[i]=max(dp[i-1],v[i][2]);
            }
            else{
                dp[i]=max(dp[i-1],v[i][2]+dp[prev]);
            }
        }
        return dp[n-1];
    }
};
