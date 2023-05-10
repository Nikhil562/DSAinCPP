class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int r = n;
        int c = n;
        int v[n][n];
        vector<vector<int>> v1;
        int t = r * c;
        int sr = 0;
        int sc = 0;
        int er = r - 1;
        int ec = c - 1;
        int value = 1;
        int count = 0;
        while (count < t)
        {
            for (int i = sc; i <= ec; i++)
            {
                if (count < t)
                {
                    v[sr][i] = value;
                    value++;
                    count++;
                }
            }
            sr++;
            for (int i = sr; i <= er; i++)
            {
                if (count < t)
                {
                    v[i][ec] = value;
                    value++;
                    count++;
                }
            }
            ec--;
            for (int i = ec; i >= sc; i--)
            {
                if (count < t)
                {
                    v[er][i] = value;
                    value++;
                    count++;
                }
            }
            er--;
            for (int i = er; i >= sr; i--)
            {
                if (count < t)
                {
                    v[i][sc] = value;
                    value++;
                    count++;
                }
            }
            sc++;
        }
        for (int i = 0; i < n; i++)
        {

            vector<int> v2;

            for (int j = 0; j < n; j++)
            {
                v2.push_back(v[i][j]);
            }

            v1.push_back(v2);
        }
        return v1;
    }
};