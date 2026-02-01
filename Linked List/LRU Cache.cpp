/* Author : Vansh Kumar
  Date : 2025-01-02
  Description: Leetcode problem-156
*/
//USE Dobuly LL and unordered map .

class LRUCache {
public:
    class Node{
    public: 
        int key , val;
        Node* next;
        Node* prev;

        Node( int k , int v){
            key = k;
            val = v;
        }
    };
    //Dummy head and tail node
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    //unordered map for key and Node* table
    unordered_map<int , Node*> m;
    int limit;

    //Helper fxn
    //to add node 
    void addNode(Node* newNode){//O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    //to delete older node
    void deleteNode(Node* oldNode){//O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;;
        tail->prev = head;
    }
    
    int get(int key) {
        //Does not exists
        if(m.find(key) == m.end()){
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;
        //Most recent ans.
        m.erase(key);
        deleteNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;
        return ans;
    }
    
    void put(int key, int val) {//O(1)
        if(m.find(key) != m.end()){//already exist in map
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        //If cache capacity reach
        if(m.size() == limit){
            //delete LRU 
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        //new node to add in DLL
        Node* newNode = new Node(key , val);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
