
struct Node{
    Node *links[26];
    bool fl=false;
    void insert(char ch){
        links[ch-'a']=new Node();
    }
    bool isPresent(char ch){
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        fl=true;
    }
    bool isEnd(){
        return fl;
    }
    
};
class Trie {
private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isPresent(word[i])){
                node->insert(word[i]);
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isPresent(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isPresent(word[i])){
                return false;
            }
            node=node->get(word[i]);
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