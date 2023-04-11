class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*') st.push(s[i]);
            else st.pop();
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};