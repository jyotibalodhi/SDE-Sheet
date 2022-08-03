int atoi(string str) {
    long long ans =0.0;
    bool neg=false;
    
    if(str[0]=='-') neg = true;
    for(int i=0;i<str.length();i++){
        if((str[i]-'0')>=0 && (str[i]-'0')<=9) // only add if a number
        {
            ans = ans*10 + ((str[i])-'0');
        }
    }
    
    if(neg) ans = ans*-1;
    return (int)ans;
}