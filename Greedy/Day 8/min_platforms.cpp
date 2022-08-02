int calculateMinPatforms(int at[], int dt[], int n) {
    
    sort(at,at+n);
    sort(dt, dt+n);
    
    int i =1, j=0;  //i marking --> arrival and j -->departure
    
    int cnt =1;  //min 1 platform required
    int ans =1;
    
    while(i<n && j<n){
        if(at[i] <= dt[j])  //train arrives before another leaves
        {
            cnt++;         //new platform added
            i++;
        }else{
            cnt--;        //platform emptied, can be use by other train
            j++;
        }
        
        ans = max(ans, cnt);
    }
    
    return ans;
    
}