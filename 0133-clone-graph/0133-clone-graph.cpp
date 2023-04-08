class Solution {
public:
    
unordered_map<int,Node*> visit;
 Node* dfs(Node* node){
 Node* new_node=new Node(node->val);
visit[node->val]=new_node;// store the address of visited node for future refrence.     
for(Node* x:node->neighbors){
if(visit[x->val]==NULL){// if visiting first time then call dfs and add the return node to the nbrs array
Node* new_nbr=dfs(x);
new_node->neighbors.push_back(new_nbr);
                }
else {// directly push the node(visited) using stored address in visited 
new_node->neighbors.push_back(visit[x->val]);
}
}
return new_node;        
 }

Node* cloneGraph(Node* node) {
    if(node==NULL) return NULL;
    visit.clear();// We only need a visit map to store if any node is visited then dont call dfs call and just connect the node stored in vist[nbr] 
    // key will be int and value will be address for the visited map to track the address whcih have been visited.
return dfs(node);
}
};