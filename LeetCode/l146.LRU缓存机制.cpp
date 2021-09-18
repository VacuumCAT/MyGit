//自己手写的，会超时
class LRUCache {
public:
    int e[200010],l[200010],r[200010],idx;//存放key
    int cap,size;
    unordered_map<int,int> hash;//存放value
    LRUCache(int capacity) {
        cap=capacity;
        r[0]=1;
        l[1]=0;
        idx=2;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            for(int i=r[0];i!=1;i=r[i]){
                if(e[i]==key){
                    //把查询到的节点插到队头
                    r[l[i]]=r[i];
                    l[r[i]]=l[i];
                    r[i]=r[0];
                    l[r[0]]=i;
                    r[0]=i;
                    l[i]=0;
                    break;
                }
            }
            return hash[key];
        } 
        else return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            hash[key]=value;
            for(int i=r[0];i!=1;i=r[i]){
                if(e[i]==key){
                    //把查询到的节点插到队头
                    r[l[i]]=r[i];
                    l[r[i]]=l[i];
                    r[i]=r[0];
                    l[r[0]]=i;
                    r[0]=i;
                    l[i]=0;
                    break;
                }
            }
            return;
        }
        if(size>=cap){
            //删除链表末尾的节点
            hash.erase(e[l[1]]);
            r[l[l[1]]]=r[l[1]];
            l[1]=l[l[1]];
            //新建一个节点 插入到队头
            e[idx]=key;
            r[idx]=r[0];
            l[r[0]]=idx;
            r[0]=idx;
            l[idx]=0;
            idx++;
            hash[key]=value;
        } 
        else{
            //新建一个节点 插入到队尾
            e[idx]=key;
            r[idx]=r[0];
            l[r[0]]=idx;
            r[0]=idx;
            l[idx]=0;
            idx++;
            size++;
            hash[key]=value;
        }
    }
};

class LRUCache {
public:
    struct Node {
        int key, val;
        Node *left, *right;
        Node(int _key, int _val): key(_key), val(_val), left(NULL), right(NULL) {}
    }*L, *R;
    unordered_map<int, Node*> hash;
    int n;

    void remove(Node* p) {
        p->right->left = p->left;
        p->left->right = p->right;
    }

    void insert(Node* p) {
        p->right = L->right;
        p->left = L;
        L->right->left = p;
        L->right = p;
    }

    LRUCache(int capacity) {
        n = capacity;
        L = new Node(-1, -1), R = new Node(-1, -1);
        L->right = R, R->left = L;
    }

    int get(int key) {
        if (hash.count(key) == 0) return -1;
        auto p = hash[key];
        remove(p);
        insert(p);
        return p->val;
    }

    void put(int key, int value) {
        if (hash.count(key)) {
            auto p = hash[key];
            p->val = value;
            remove(p);
            insert(p);
        } else {
            if (hash.size() == n) {
                auto p = R->left;
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            hash[key] = p;
            insert(p);
        }
    }
};