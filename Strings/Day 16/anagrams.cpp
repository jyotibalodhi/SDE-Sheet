#include<unordered_map>

bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.length() != str2.length()) 
        return false;
    
    unordered_map<char,int> freq{0};
    
    for(int i=0;i<str1.length();i++){
        freq[str1[i]]++;
        freq[str2[i]]--;
    }
    
    for(auto &it :freq){
        if(it.second > 0) return false;
    }
    
    return true;
    
}