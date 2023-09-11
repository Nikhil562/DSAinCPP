class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto i: tasks) mp[i]++;
        priority_queue<int> q;
        for(auto i:mp) q.push(i.second);
        int tmp=0;
        while(!q.empty()){
            vector<int> vec;
            for(int i=0;i<n+1;i++){
                if(!q.empty()){
                vec.push_back(q.top());
                q.pop();
                }
            }
            for(int i=0;i<vec.size();i++){
                if(--vec[i]>0) q.push(vec[i]);
            }
            tmp+=q.empty()?vec.size():n+1;
        }
        return tmp;
    }
};