class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sum =0, result =0;
        unordered_map<int, int>m;
        for(int i=0; i < hours.size(); i++){
            if(hours[i] > 8)
                sum++;
            else
                sum--;
            if(sum > 0)// if the running sum becomes positive, it's a WPI
                result = i+1;
            else if(m.find(sum-1) != m.end()) //if sum-1 exists in the map, fetch it's indx and calculate the interval
                    result = max(result, i-m[sum-1]);
             
            if(m.find(sum) == m.end()) //add the current index to the map
                   m[sum] = i;
        }
        return result;
    }
};