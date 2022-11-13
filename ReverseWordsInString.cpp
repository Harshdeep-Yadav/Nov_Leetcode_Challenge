class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string tmp = "";
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch==' '){
                
                if(tmp!="")
                    st.push(tmp);
                tmp = "";
            }
            else 
                tmp += ch;
        }
        
        if(tmp!="")
            st.push(tmp);
            
        string ans="";
        while(st.size()>1)
        {
            ans +=  (st.top()+" ");
            st.pop();
        }
        ans += st.top();
        return ans;
       
    }
};