class linkedListNode
{
public:
    string data;
    linkedListNode *prev;
    linkedListNode *next;
    

    linkedListNode(string url)
    {
        data = url;
        prev = NULL;
        next = NULL;
    }
        
};

class BrowserHistory
{
private:
     linkedListNode *current, *head;
    
public:
    BrowserHistory(string homepage)
    {
        head = new linkedListNode(homepage);
        current = head;
    }
    
    void visit(string url) 
    {
        linkedListNode *newNode = new linkedListNode(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) 
    {
        while(steps and current->prev)
        {
            current = current->prev;
            steps--;
        }
        return current->data;
    }
    
    string forward(int steps) 
    {
        while(steps and current->next)
        {
            current = current->next;
            steps--;
        }
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */