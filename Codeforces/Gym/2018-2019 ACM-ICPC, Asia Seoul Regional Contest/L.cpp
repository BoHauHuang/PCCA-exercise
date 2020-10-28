#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
 
struct sta {
	int num, rem, wts;
 
	bool operator < (const sta& rhs) const {
		return wts < rhs.wts;
	}
};
 
int ok;
int m, n, w, h;
int nds[MAX], wts[MAX];
vector<int> v[MAX];
queue<sta> rest, woks;
priority_queue<sta> pend;
 
void init() {
	ok = 1;
	while (woks.size()) woks.pop();
	while (rest.size()) rest.pop();
	while (pend.size()) pend.pop();
 
	for (int i = 0; i < MAX; i++) v[i].clear();
	memset(nds, 0, sizeof(nds));
	memset(wts, 0, sizeof(wts));
}
 
int main() {
	cin.tie(0), cout.sync_with_stdio(false);
	init();
 
	cin >> n >> m >> w >> h;
	for (int i = 1; i <= n; i++) {
		cin >> wts[i];
		pend.push((sta){i, 0, wts[i]});
	}
	for (int i = 1; i <= m; i++) cin >> nds[i];
 
	for (int i = 1; i <= m; i++) {
		int sw = (int) woks.size();
		int sp = (int) pend.size();
 
		for (int j = 0; j < sw; j++) {
			auto now = woks.front(); woks.pop();
			if (now.rem == 0) {
 
				// cout << "Finish " << i - 1 << ' ' << now.num << '\n';
 
				if (now.wts) 
					rest.push((sta){now.num, h, now.wts});
				
				continue;
			}
			woks.push((sta){ now.num, now.rem, now.wts });
		}
		if (woks.size() > nds[i]) {
			ok = 0;
 
			// cout << "Remain > needs\n";
 
			break;
		}
		if (sp < nds[i] - woks.size()) {
			ok = 0;
 
			// cout << "Ava < needs " << sp << ' ' << nds[i] << ' ' << woks.size() << "\n";
 
			break;
		}
 
		while (woks.size() < nds[i]) { 
			auto now = pend.top(); pend.pop();
			
			woks.push((sta){ now.num, w, now.wts });
			v[now.num].push_back(i);
 
			// cout << "Add " << now.num << ' ' << i << ' ' << now.wts << endl;
		}
 
		sw = (int) woks.size();
		int sr = (int) rest.size();
		while (sw--) {
			auto now = woks.front(); woks.pop();
			woks.push((sta){ now.num, now.rem - 1, now.wts - 1 });
		}
		while (sr--) {
			auto now = rest.front(); rest.pop();
 
			if (now.rem - 1 <= 0) {
				// cout << "Turn ava " << now.num << '\n';
 
				pend.push((sta){ now.num, w, now.wts });
			}
			else
				rest.push((sta){now.num, now.rem - 1, now.wts});
		}		
	}
 
	if (!ok) {
		cout << -1 << '\n';
		return 0;
	}
	cout << 1 << '\n';
	for (int i = 1; i <= n; i++) {
		for (auto j : v[i]) cout << j << ' ';
		cout << '\n';
	}
	return 0;
}
