
 string LCP(string x,string y){
        int i=0, j=0;
        while(i<x.length() && j<y.length()){
            if(x[i]!=y[j]){
                break;
            }
            i++;
            j++;
        }
        return x.substr(0,i);
    }

string longestCommonPrefix(vector<string> &arr, int n)
{
    string prefix=arr[0];
        for(string s:arr){
            prefix=LCP(prefix,s);
        }
        return prefix;
}


