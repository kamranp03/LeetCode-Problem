class LRUCache {
public:
    class Node{
        public:
             int key,val;
             Node* prev;
             Node* next;

             Node(int k, int v)
             {
                key=k;
                val=v;
                prev=next= NULL;
             }
    };

    Node* head= new Node(-1,-1);
    Node* tail= new Node(-1,-1);

    unordered_map<int, Node*> mp;
    int limit;

    void addNode(Node* newNode) //O(1)
    {
        Node* oldNext= head->next;
        head->next= newNode;
        oldNext->prev= newNode;

        newNode->next= oldNext;
        newNode->prev= head;
    }

    void delNode(Node* old) //O(1)
    {
        Node* oldPrev= old->prev;
        Node* oldNext= old->next;

        oldPrev->next= oldNext;
        oldNext->prev= oldPrev;
    }

    LRUCache(int capacity) {
        limit= capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    int get(int key) {  //O(1)
        if(mp.find(key)==mp.end())
        {
            return -1;
        }

        Node* ansNode= mp[key];
        int ans= ansNode->val;

        mp.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        mp[key]= ansNode;

        return ans;
    }
    
    void put(int key, int val) { //O(1)
        if(mp.find(key) != mp.end())
        {
            Node* old= mp[key];
            delNode(old);
            mp.erase(key);
        }

        if(mp.size()== limit)
        {
            // delete LRU node
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        
        Node* newNode= new Node(key,val);
        addNode(newNode);
        mp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */