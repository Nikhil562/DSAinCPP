class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        priority_queue<pair<int,char>> q;
        for(auto i: mp) q.push({i.second,i.first});
        string ans="";
        while(q.size()>1){
            int firstChar=q.top().second;
            int firstFreq=q.top().first;
            q.pop();
            
            int secondChar=q.top().second;
            int secondFreq=q.top().first;
            q.pop();
            
            firstFreq--;
            if(firstFreq!=0) q.push({firstFreq,firstChar});
            secondFreq--;
            if(secondFreq!=0) q.push({secondFreq,secondChar});
            ans+=firstChar;
            ans+=secondChar;
            
        }
        if(q.size()!=0){
            if(q.top().first>1) return "";
            else ans+=q.top().second;
        }
        return ans;
    }
};