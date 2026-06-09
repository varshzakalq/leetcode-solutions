struct node{
    int val;
    node* next;
};


class MyLinkedList {
public:
    node* root ;
    MyLinkedList() {
        root = NULL;
    }
    
    int get(int index) {
        node* r = root;
       for(int i =0;i<index;i++){
        if(r!= NULL)
            r = r->next;
        else
            return -1;
       }
       return (r!= NULL)?r->val: -1;
    }
    
    void addAtHead(int val) {
        node* newnode = new node;
        newnode->val = val;
        newnode->next = root;
        root = newnode;
    }
    
    void addAtTail(int val) {
        node* n= root;
        node* newnode = new node;
        newnode->val = val;
        newnode->next = NULL;
        if(n == NULL){
            
            root = newnode;
            return;
        }
        while(n->next!= NULL){
            n = n->next;
        }
        
        n->next = newnode;
    }
    
    void addAtIndex(int index, int val) {
        node* r = root;
        node* newnode = new node;
        newnode->val = val;

        if(r == NULL&& index ==0){
            root = newnode;
            return;
        }
        else if(r == NULL && index != 0)return;
        if(index == 0){
            newnode ->next = root;
            root = newnode;
            return;
        }
        for(int i =1;i<index;i++){
            if(r!= NULL)
            r = r->next;
            else{
                delete newnode;
                return;
            }
        
        }
        node *temp = (r != NULL)?r->next:NULL;
        newnode->next = temp;
        if(r!= NULL)
            r->next = newnode;

    }
    
    void deleteAtIndex(int index) {
        node* r = root;
        if(r == NULL)return;
        if(index == 0){
            if(root->next != NULL){
                root =root->next;
                return;
            }
                
            else{
                root = NULL;
                return;
            }
        }
        for(int i =0;i<index-1;i++){
            if(r!= NULL)
            r = r->next;
            else
            return;
        }
        if(r == NULL)return;
        if(r->next == NULL)return;
        if(r->next->next == NULL)r->next = NULL;
        else{
            node* temp = r->next;
            r->next = r->next->next;
            delete temp;

        }
        return;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
