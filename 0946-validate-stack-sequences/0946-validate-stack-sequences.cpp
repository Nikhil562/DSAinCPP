class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {     
        int i=0,j=0;
        stack<int> s;
        int n=pushed.size();
        while(i<n && j<n){
            s.push(pushed[i]);
            while(!s.empty() && j<n &&  s.top()==popped[j]){
                s.pop();
                j++;
            } 
            i++;
        }
        return s.empty();
    }
};