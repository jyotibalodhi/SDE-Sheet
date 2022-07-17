#include <bits/stdc++.h> 
string fourSum(vector<int> num, int target, int n) {

        if (num.empty())
            return "No";

        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
            int target_3 = target - num[i];  
            for (int j = i + 1; j < n; j++) {    
                
                int target_2 = target_3 - num[j];
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                    int two_sum = num[front] + num[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else {
                       return "Yes";             
                    }
                }           
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        }
    
        return "No";
}
