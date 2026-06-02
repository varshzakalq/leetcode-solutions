struct node{
    node* links[26];
    bool flag;
    node* ispresent(char ch,node* n){
        return links[ch -'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }

};


class Trie {
private:
    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* n  = root;
        for(int i =0;i<word.size();i++){
            int ch = word[i];
            if(n->ispresent(ch ,n) == NULL){
                node* newnode = new node();
                n->links[ch -'a'] = newnode;
            }
            n = n->links[ch -'a'];
        }
        n->setEnd();
    }
    
    bool search(string word) {
        node* n = root;
        for(auto i:word){
            int ch =i;
            if(n->ispresent(ch,n) != NULL){
                n = n->links[ch-'a'];
            }
            else{
                return false;
            }
        }
        if(n->isEnd()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        node* n = root;
         for(auto i:prefix){
            int ch =i;
            if(n->ispresent(ch,n) != NULL){
                n = n->links[ch-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
