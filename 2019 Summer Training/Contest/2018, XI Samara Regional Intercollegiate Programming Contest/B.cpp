#include<bits/stdc++.h>
#define INF 9223372036854775806
using namespace std;
vector<pair<long long, long long> > nodes, copy_nodes;
vector<pair<long long, long long> >::iterator it;
long long m = INF, ans = INF;

bool cmpy(pair<long long, long long> lhs, pair<long long, long long> rhs){ return (lhs.first != rhs.second)? lhs.second < rhs.second : lhs.first < rhs.first; }

long long area(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C){ return abs((A.first-C.first)*(B.second-A.second)-(A.first-B.first)*(C.second-A.second)); }

long long pick_and_test(pair<long long, long long> pick){
	set<pair<long long, long long> > test_node;
	vector<pair<long long, long long> > unique_nodes;
	test_node.insert(pick);
	
	// along x
	it = upper_bound(nodes.begin(), nodes.end(), pick);
	if(it != nodes.end()){
		test_node.insert(*it);
		it++;
		if(it != nodes.end()) test_node.insert(*it);
		it--;
	}
	it--;
	if(it != nodes.begin()){
		it--;
		test_node.insert(*it);
		if(it != nodes.begin()){
			it--;
			test_node.insert(*it);
		}
	}
	
	// along y
	it = upper_bound(copy_nodes.begin(), copy_nodes.end(), pick, cmpy);
	if(it != copy_nodes.end()){
		test_node.insert(*it);
		it++;
		if(it != copy_nodes.end()) test_node.insert(*it);
		it--;
	}
	it--;
	
	if(it != copy_nodes.begin()){
		it--;
		test_node.insert(*it);
		if(it != copy_nodes.begin()){
			it--;
			test_node.insert(*it);
		}
	}
	
	for(auto x : test_node)
		unique_nodes.push_back(x);
			
	// calculate area
	m = INF;
	for(int i = 0 ; i < unique_nodes.size() ; i++)
		for(int j = i+1 ; j < unique_nodes.size() ; j++)
			for(int k = j+1 ; k < unique_nodes.size() ; k++)
				if(m > area(unique_nodes[i], unique_nodes[j], unique_nodes[k])) m = area(unique_nodes[i], unique_nodes[j], unique_nodes[k]);
	
	return m;
}

int main(){
	long long n, x, y;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> x >> y;
		nodes.push_back(make_pair(x, y));
	}
	
	copy_nodes = nodes;
	
	sort(nodes.begin(), nodes.end());
	sort(copy_nodes.begin(), copy_nodes.end(), cmpy);
	
	for(int i = 0 ; i < n ; i++)
		if(ans > pick_and_test(nodes[i])) ans = pick_and_test(nodes[i]); 
	
	cout << ans << endl; 
	
	return 0;
}
