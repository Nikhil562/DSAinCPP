class Solution {
public:
    typedef pair<int,int> pr;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int i=0;
        int totalApples=0;
        int n=apples.size();
        priority_queue<pr,vector<pr>,greater<pr>> q;
        while(i<n || !q.empty()){
            if(i<n && apples[i]!=0) q.push({i+days[i]-1,apples[i]});
            while(!q.empty() && q.top().first<i) q.pop();
            if(!q.empty()){
                auto curr=q.top();
                q.pop();
                if(curr.second>1) q.push({curr.first,curr.second-1});
                totalApples++;
            }
             i++;
        }
           return totalApples;
    }
};