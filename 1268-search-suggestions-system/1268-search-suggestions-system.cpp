class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<string> str;
        str=products;
        sort(str.begin(),str.end());
            for(auto i: str) cout<<i<<" ";
        vector < vector < string > > ans;
        string curr = "";
        for (int i = 0; i<searchWord.size(); i++){
            curr+=searchWord[i];
            vector <string> too;
            int cnt = 0;
            for (int j = 0 ; j<str.size(); j++){
                string sub = str[j].substr(0, curr.size());
                if (cnt < 3 && curr == sub){
                    cnt++;
                    too.push_back(str[j]);
                }
            }
            ans.push_back(too);
        }
        return ans;
    }
};


// prioirty_queue<string,vector<string>,gretaer<string>> pq;
// for(auto i: products) pq.push(i);

// vector<string>tr;
// while(!pq.empty()){
//     str.push_back(pq.top());
//     pq.pop();
// }
