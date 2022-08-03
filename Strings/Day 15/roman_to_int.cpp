  int val(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else return 1000;
    }

int romanToInt(string s) {
     char prev=s[0];  
        int number=val(prev);   
        
        for(int i=1;i<s.length();i++){  
            if(val(prev)>=val(s[i])){ 
                number+=val(s[i]);   
            }
            else{ 
                number+=val(s[i])-(2*val(prev));
            }
            prev=s[i];  
        }
        return number;
}
