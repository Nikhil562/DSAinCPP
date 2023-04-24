class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            p.push(stones[i]);
            
        }
        while(p.size()>1){
            bool fl=true;
            int a;
            int b;
            while(fl){
                a=p.top();
                p.pop();
                b=p.top();
                p.pop();
                fl=false;
            }
            int c=abs(a-b);
             p.push(c);
        }
        return p.top();
    }
};