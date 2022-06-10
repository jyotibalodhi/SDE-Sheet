#include<unordered_map>

class LRUCache {
    
     class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
    
    
  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;
    
public:
    LRUCache(int capacity) {   
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    //function to add node after head
    
  void addnode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
  }

    
    //function to delete node
  void deletenode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
  }
    
    
    
    int get(int key) {
        
     if (m.find(key) != m.end()) {   // if found in map
          node * resnode = m[key];  // m[key] is address of that node in dll
          int res = resnode -> val;
          m.erase(key);
         
          deletenode(resnode);  // making it recently used 
          addnode(resnode);
         
          m[key] = head -> next;
          return res;
    }

        return -1;
    }
    
    void put(int key, int value) {
        
         if (m.find(key) != m.end()) {   //update condition if key found
              node * existingnode = m[key];
              m.erase(key);
              deletenode(existingnode);
        }
        
        if (m.size() == cap) {
              m.erase(tail -> prev -> key);
              deletenode(tail -> prev);
        }

        addnode(new node(key, value));
        m[key] = head -> next;
  }
};
