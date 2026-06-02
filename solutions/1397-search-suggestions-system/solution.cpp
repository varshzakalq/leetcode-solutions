struct node{
    node* links[26];
    bool flag;
    bool ispresent(char ch,node* n){
        return links[ch -'a'] != NULL;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
    node* get(char ch) {
        return links[ch - 'a'];
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
            if(!n->ispresent(ch ,n)){
                node* newnode = new node();
                n->links[ch -'a'] = newnode;
            }
            n = n->links[ch -'a'];
        }
        n->setEnd();
    }
    
   
    
    void dfs(node* curr,string& currWord,vector <string>&result){
        if(result.size() ==3)return;
        if(curr->isEnd())result.push_back(currWord);
        for(char ch = 'a';ch<='z';ch++){
            if(curr->ispresent(ch,curr)){
                currWord.push_back(ch);
                dfs(curr->get(ch),currWord,result);
                currWord.pop_back();
        }
    }
    }
    vector<string> prefixsearch(string prefix){
        node* n  = root;
        vector <string>result;
        for(auto i: prefix){
            if(!n->ispresent(i,n))return result;
            else{
                n =n->get(i);
            }
        }
        dfs(n,prefix,result);
        return result;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t1;
        for(int i =0;i<products.size();i++){
            t1.insert(products[i]);
        }
        vector<vector<string>>ans;
        string s ;
        for(int i = 0;i<searchWord.size();i++){
            s+= searchWord[i];
            ans.push_back(t1.prefixsearch(s));
        }
    return ans;
    }
};
