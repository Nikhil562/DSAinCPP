class Solution {
public:
    vector<int> solve(vector<int> spells, vector<int> potion,long long success)
{
    vector<int> scc;
    int mod = 1e9+7;

    for (int i = 0; i < spells.size(); i++)
    {
        int low = 0;
        int high = potion.size()-1; 
        int ans = 0;
        int temp=-1;
        while (low <= high)
        {
            int mid = (high + low) >> 1;
            if ((long long)spells[i] * (long long)potion[mid] >= success)
            {
                temp = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(temp==-1) ans = 0;
        else ans = potion.size() - temp;
        scc.push_back(ans);
    }

    return scc;
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

    sort(potions.begin(), potions.end());

    vector<int> ans = solve(spells, potions,success);
    return ans;
    }
};