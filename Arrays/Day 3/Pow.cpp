#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	long long res=1;
    long long xx = x;
    
    while(n>0){
        if(n%2 ==0){
            xx = (xx%m * xx%m ) % m;
            n = n/2;
        }
        else{
            res =( xx%m * res%m ) % m;
            n--;
        }
    }
    
    return (int)(res % m);
}