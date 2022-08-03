bool findPattern(string p, string s)
{
    // Write your code here.
    int n = s.length(), m = p.length();
    
     for(int i=0;i<n-m+1;i++){
         if(s[i]== p[0]){
            string ans=s.substr(i,m);
            if(ans==p){
                return true;
            }
         }
    }
    
    return false;
    
}