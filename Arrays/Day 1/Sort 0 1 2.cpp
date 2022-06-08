#include <unordered_map>

void sort012(int *arr, int n)
{

    unordered_map<int, int> umap;
  for(int i=0;i<n;i++){
        umap[arr[i]]++;
    }
    int i=umap[0];
    int j=umap[1]+i;
    int k=umap[2]+i+j;
    
    for(int x=0;x<n;x++){
        if(x<i){
            arr[x]=0;
        }
        else if(x>=i && x<j){
            arr[x]=1;
        }
        else if(x>=j && x<k){
            arr[x]=2;
        }
    }
}