int findMinimumCoins(int amount) 
{
    vector<int> den = {1,2,5,10,20,50,100,500,1000};
    //Greedy method could be applied because diff between 
    //denominations is uniformly increasing
    int ans=0;
    int i=8;
    
    while(i>=0 && amount>0){
        if(amount >= den[i]){
            ans++;
            amount -= den[i];
        }
        else
            i--;
        }
    
    return ans;
}
