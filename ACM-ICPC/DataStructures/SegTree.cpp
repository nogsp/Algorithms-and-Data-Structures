#include<iostream>
using namespace std;

struct Node {
    int val = 0;
    Node(int val = 0) {
        this->val = val;
    }

    Node operator + (const Node& node) {
        return Node(this->val + node.val);
    }

	int getVal() {
		return this->val;
	}
};


class SegTree{
	static const int segmax = 100020 * 4;
	/* use static inline if is needed more memory
	but keep in mind that segt will be shared
	with all instances of the class */
	/*static inline*/ Node segt[segmax];	
	int n;
	public:

	SegTree(int n, int *arr) {
		this->n = n;
		init(1, 0, n-1, arr);
	}
	void update(int l, int x) {
		update(1, 0, n-1, l, x);
	}
	Node query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}

	private:
	void init(int index, int tl, int tr, int *arr) {
		int mid = (tl + tr) >> 1;
		int next = index << 1;

		if(tl == tr) {
			segt[index] = Node(arr[tl]);
			return;
		}
		init(next, tl, mid, arr);
		init(next+1, mid+1, tr, arr);
		segt[index] = segt[next] + segt[next+1];
	}

	void update(int index, int tl, int tr, int pos, int x) {
		int mid = (tl + tr) >> 1;
		int next = index << 1;

		if(tl > pos || tr < pos) return;

		if(tl == tr) {
			segt[index] = Node(x);
			return;
		}

		update(next, tl, mid, pos, x);
		update(next+1, mid+1, tr, pos, x);
		segt[index] = segt[next] + segt[next + 1];
	}

	Node query(int index, int tl, int tr, int l, int r) {
		int mid = (tl + tr) >> 1;
		int next = index << 1;

		if(tl > r || tr < l) return Node();

		if(tl >= l && tr <= r) {
			return segt[index];
		}

		return query(next, tl, mid, l, r) + query(next+1, mid+1, tr, l, r);
	}
};

int main() {
	int arr[100020];
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	SegTree seg(n, arr);

	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 0) {
			int l, x;
			cin >> l >> x;
			seg.update(l, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << seg.query(l, r).getVal() << endl;
		}
	}
}	
