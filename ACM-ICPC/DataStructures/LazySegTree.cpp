#include<iostream>
#define endl "\n"
using namespace std;

//programed for somatory of range
//depends on problem

struct LazyNode{
    int val;
    LazyNode(int _val=0): val(_val){}
    LazyNode operator + (LazyNode &x) {
        return LazyNode(val + x.val);
    }
    bool isNull() { return val == 0;}
    void clear() { val = 0;}
};

struct Node{
    // Everything may change depending on the problem
    int arr[9];
    Node() {
        for(int i = 0; i < 9; i++) this->arr[i] = 0;
    }
    Node(int x) {
        for(int i = 0; i < 9; i++) this->arr[i] = 0;
        this->arr[x] = 1;
    }
    Node operator + (const Node &node) {
        Node ret;
        for(int i = 0; i < 9; i++)
            ret.arr[i] = this->arr[i] + node.arr[i];
        return ret;
    }
    void update(const LazyNode &x) {
        int maxi = 0;
        Node aux;
        for(int i = 0; i < 9; i++) aux.arr[(i+x.val)%9] = this->arr[i];
        for(int i = 0; i < 9; i++) this->arr[i] = aux.arr[i];
    }
    LazyNode getVal() {
        LazyNode ln;
        int maxi = 0;
        for(int i = 0; i < 9; i++) {
            if(this->arr[i] >= maxi) {
                maxi = this->arr[i];
                ln.val = i;
            }
        }
        return ln;
    }
};

const int _segmaxn = 100002;
Node segt[_segmaxn*4];
LazyNode lazy[_segmaxn*4];
int arr[_segmaxn*4];
/*template<class T = Node>*/ 
struct Lazytree{
    private:
    int n;

    public:
    Lazytree(int _n){
        build(_n);
    }
    void build(int _n) {
        this->n = _n;
        build(1, 0, n-1);
    }
    void update(int l, int r, LazyNode& x) {
        update(1, 0, n-1, l, r, x);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    private:
    void build(int index, int tl, int tr) {
        int mid = (tl + tr) >> 1;
        int next = index << 1;
        lazy[index] = LazyNode(0);
    
        if(tl == tr) {
            segt[index] = Node(arr[tl]);
            return;
        }

        build(next, tl, mid);
        build(next + 1, mid + 1, tr);
        segt[index] = segt[next] + segt[next + 1];
    }
    
    void propagate(int index, int tl, int tr) {
        int mid = (tl + tr) >> 1;
        int next = index << 1;
        
        if(!lazy[index].isNull()) {
            if(tl < tr) {
                segt[next].update(lazy[index]);
                segt[next + 1].update(lazy[index]);

                lazy[next] = lazy[next] + lazy[index];
                lazy[next + 1] = lazy[next + 1] + lazy[index];
            }
            lazy[index].clear();
        }
    }

    void update(int index, int tl, int tr, int l, int r, LazyNode& x) {
        int mid = (tl + tr) >> 1;
        int next = index << 1;
        
        if(tr < l || tl > r) return;
        
        if(tl >= l && tr <= r) {
            segt[index].update(x);
            lazy[index] = lazy[index] + x;
        } else {
            propagate(index, tl, tr);
            update(next, tl, mid, l, r, x);
            update(next + 1, mid + 1, tr, l, r, x);
            segt[index] = segt[next] + segt[next + 1];
        }
    }

    Node query(int index, int tl, int tr, int l, int r) {
        int mid = (tl + tr) >> 1;
        int next = index << 1;

        if(tr < l || tl > r) return Node();

        if(tl >= l && tr <= r) {
            return segt[index];
        } 

        propagate(index, tl, tr);
        Node q1 = query(next, tl, mid, l, r);
        Node q2 = query(next + 1, mid + 1, tr, l, r);
        return q1 + q2;   
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        arr[i] = 1;
    }

    Lazytree seg(n);

    while(q--) {
        int a, b;
        cin >> a >> b;
        
        LazyNode ret = seg.query(a, b).getVal();
        seg.update(a, b, ret);
    }
    for(int i = 0; i < n; i++) {
        cout << seg.query(i, i).getVal().val << endl;
    }
}