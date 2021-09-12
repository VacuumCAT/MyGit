/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    int st[110];
    bool g[110][110];
    Node* bfs(Node* node){
        vector<Node*> nodes(110,nullptr) ;
        queue<Node*> que;
        Node *head=new Node(node->val);
        nodes[head->val]=head;
        que.push(node);
        while(!que.empty()){
            auto cur=que.front();
            que.pop();
            st[cur->val]=true;
            auto ptr=cur->neighbors;
            for(auto x:ptr){
                if(nodes[x->val]==nullptr){
                    Node *tmp=new Node(x->val);
                    if(!g[cur->val][x->val]){
                        nodes[cur->val]->neighbors.push_back(tmp);
                        g[cur->val][x->val]=true;
                    } 
                    nodes[x->val]=tmp;
                    if(!st[x->val]) que.push(x);
                }
                else{
                    if(!g[cur->val][x->val]){
                        nodes[cur->val]->neighbors.push_back(nodes[x->val]);
                        g[cur->val][x->val]=true;
                    } 
                    if(!st[x->val]) que.push(x);
                }
            }
        }
        return head;
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        return bfs(node);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        dfs(node);  // 复制所有点

        for (auto [s, d]: hash) {
            for (auto ver: s->neighbors)
                d->neighbors.push_back(hash[ver]);
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);

        for (auto ver: node->neighbors)
            if (hash.count(ver) == 0)
                dfs(ver);
    }
};

//y总做法：
//第一步，复制所有点
//第二部，复制所有边