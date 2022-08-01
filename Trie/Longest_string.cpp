#include<bits/stdc++.h>

struct Node{
    Node *links[26];
    bool flag = false;  // to mark word end
    
    void put(char ch,Node * node){
        links[ch - 'a'] = node;
    }
    
    Node * get(char ch){
        return links[ch -'a'];
    }
    
    bool containsKey(char ch){
        return (links[ch -'a'] != NULL);
    }
    
    //setting flag to true at the end of the word
    void setEnd() {
        flag = true;
    }
    //checking if the word is completed or not
    bool isEnd() {
        return flag;
    }
};


class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {        
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkPrefix(string word) {
        Node *node = root;
        for (int i = 0; i < word.size(); i++) {
             if (node->containsKey(word[i])) {
                 node = node->get(word[i]);
                if(node->isEnd() == false) return false;
            }
            else 
                return false;

        }
        return true;
    }
};


string completeString(int n, vector<string> &a){
    Trie trie;
    
    for(int i=0;i<n;i++){
        trie.insert(a[i]);
    }
    
    string longest ="";
    
    for(auto &it: a){
        if(trie.checkPrefix(it)){
            //longest length string
            if(it.length()> longest.length())
                longest = it;
            //lexicographically smallest
            else if(it.length() == longest.length() && it <longest){
                longest = it;
            }
        }
    }
    
    if(longest == "") return "None";
    return longest;
    
}