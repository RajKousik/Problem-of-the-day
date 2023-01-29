class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        int count;
        
        Node(int _key, int _value){
            key = _key;
            value = _value;
            count = 1;
        }
};
    
class List{
    public:
        Node* head;
        Node* tail;
        int size;
        List(){
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }  
    void addFrontNode(Node *newNode){
        newNode->next = head->next;
        newNode->prev = head;
        head->next = newNode;
        newNode->next->prev = newNode;
        size++;
    }
    
    void removeNode(Node *delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
    
    
};
class LFUCache {
public:
    unordered_map<int ,Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSize;
    int curSize;
    int minFreq;
    LFUCache(int capacity) {
        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    void updateFreqListMap(Node* node){
        //keyNode.erase(node->key);
        freqListMap[node->count]->removeNode(node);
        
        if(node->count == minFreq && freqListMap[node->count]->size ==0){
            minFreq++;
        }
        
        List* higherLevelFreqList = new List();
        if(freqListMap.find(node->count + 1) != freqListMap.end()){
            higherLevelFreqList = freqListMap[node->count + 1];
        }
        node->count += 1;
        higherLevelFreqList->addFrontNode(node);
        freqListMap[node->count] = higherLevelFreqList;
        //keyNode[node->key] = node;
    }
    
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end()){
            Node* node = keyNode[key];
            int val =  node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize == 0){
            return;
        }
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else{
            if(maxSize == curSize){
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List* freqList = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                freqList = freqListMap[minFreq];
            }
            Node* newNode = new Node(key, value);
            freqList->addFrontNode(newNode);
            keyNode[key] = newNode;
            freqListMap[minFreq] = freqList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */