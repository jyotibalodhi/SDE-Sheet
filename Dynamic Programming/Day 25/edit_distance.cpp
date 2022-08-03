int editDistance(string s1, string s2)
{
     int n = s1.size();
        int m = s2.size();

        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);

        for(int j=0;j<=m;j++){
            prev[j] = j;
        }

        for(int i=1;i<n+1;i++){
            cur[0]=i;
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1])
                    cur[j] = 0+prev[j-1];

                else cur[j] = 1+min(prev[j-1],min(prev[j],cur[j-1]));
            }
            prev = cur;
        }

        return prev[m];
}