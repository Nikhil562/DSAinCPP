class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        q.push(a);
        q.push(b);
        q.push(c);
        int ctr=0;
        while(q.size()>=2){
            int first=q.top();
            q.pop();
            int second=q.top();
            q.pop();
            if(first-1>0){
                q.push(first-1);
                
            }
            if(second-1>0){
                q.push(second-1);
            }
            ctr++;
        }
        return ctr;
        
    }
};
