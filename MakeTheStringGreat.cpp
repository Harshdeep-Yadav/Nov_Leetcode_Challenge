class Solution {
public:
    string makeGood(string s) {
        string str="";
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty() && st.top()!=s[i] && tolower(st.top())==tolower(s[i]))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        } 
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};