#define int long long
#define MAX 100010

struct Node {
	Node *ls, *rs;
	int val, sum, siz;

	Node (int val) {
		this -> val = val;
		this -> sum = val;
		siz = 1;
		ls = rs = NULL;
	}
}*rot;

int SZ(Node* now) {
	return now == NULL ? 0 : now -> siz;
}

int getSum(Node* now) {
	return now == NULL ? 0 : now -> sum;
}

void maintain(Node* now) {
	now -> siz = 1 + SZ(now -> ls) + SZ(now -> rs);
	now -> sum = now -> val + getSum(now -> ls) + getSum(now -> rs);
}

void split(Node* now, int k, Node* &lef, Node* &rig) {
	if (now == NULL) {
		lef = rig = NULL;
		return;
	}
	if (k <= SZ(now -> ls)) {
		rig = now;
		split(now -> ls, k, lef, rig -> ls);
	} else {
		lef = now;
		split(now -> rs, k - SZ(now -> ls) - 1, lef -> rs, rig);
	}
	maintain(now);
}

Node* merge(Node* lef, Node* rig) {
	if (lef == NULL) return rig;
	if (rig == NULL) return lef;

	if (rand() % (SZ(lef) + SZ(rig)) < SZ(lef)) {
		lef -> rs = merge(lef -> rs, rig);
		maintain(lef);
		return lef;
	} else {
		rig -> ls = merge(lef, rig -> ls);
		maintain(rig);
		return rig;
	}
}

int32_t main() {
	cin.tie(0), cout.sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		rot = NULL;

		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			rot = merge(rot, new Node(x));
		}

		Node *lef, *now, *rig, *tmp;
		while (m--) {
			int x, y; cin >> x >> y;

			split(rot, y, tmp, rig);
			split(tmp, x - 1, lef, now);

			int ans = getSum(now);
			cout << ans << '\n';
			
			rot = merge(merge(lef, new Node(ans)), rig);
		}
	}
	return 0;
}