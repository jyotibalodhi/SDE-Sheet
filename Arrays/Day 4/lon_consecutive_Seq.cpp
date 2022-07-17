#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    unordered_set<int> s;
    
    for(int num :arr){
        s.insert(num);
    }
    int longestStreak = 0;

      for (int num: arr) {
        if (!s.count(num - 1)) {
          int currentNum = num;
          int currentStreak = 1;

          while (s.count(currentNum + 1)) {
            currentNum += 1;
            currentStreak += 1;
          }

          longestStreak = max(longestStreak, currentStreak);
        }
      }

      return longestStreak;
}