#include <iostream>
#include <vector>
#include <queue>
#define P pair<int,int>
#define PP pair<int,P>
using namespace std;
int main() {
	int t;	cin >> t;
	
	for (int tc=1; tc<=t; tc++) {
		int recept[10], repair[10], customer[1001];
		P rec_ing[10] = {P(0, 0)}, rep_ing[10] = {P(0, 0)};	// first : time, second : customer
		int N, M, K, A, B, ans = 0, idx = 1, cnt = 0, num = 0;	cin >> N >> M >> K >> A >> B;
		for (int i=1; i<=N; i++) cin >> recept[i];
		for (int i=1; i<=M; i++) cin >> repair[i];
		for (int i=1; i<=K; i++) cin >> customer[i];
		
		priority_queue< int, vector<int>, greater<int> > recq;
		priority_queue< PP, vector<PP>, greater<PP> > repq;
		vector<int> recv[10], repv[10];
		
		int time = 0;
		
		while (cnt < K) {
			for (int i=idx; i<=K; i++) {	// set customer 
				if (customer[i] == 0) { 
					recq.push(i);
					idx += 1;
				} else customer[i] -= 1;
			}
			for (int i=1; i<=N; i++) {		// decrease reception desk
				if (rec_ing[i].first > 0) {	
					rec_ing[i].first -= 1;
					if (rec_ing[i].first == 0) {
						repq.push(make_pair(num++, P(i, rec_ing[i].second)));
					}
				}
			}
			for (int i=1; i<=M; i++) {		// decrease repair desk
				if (rep_ing[i].first > 0) {
					rep_ing[i].first -= 1;
					if (rep_ing[i].first == 0) {
						cnt += 1;
					}
				}
			}
			for (int i=1; i<=N; i++) {		// push customer into reception desk
				if (rec_ing[i].first == 0 && !recq.empty()) { 
					recv[i].push_back(recq.top());
					rec_ing[i] = P(recept[i], recq.top());
					recq.pop();
				}
			}
			for (int i=1; i<=M; i++) {		// push customer into repair desk
				if (rep_ing[i].first == 0 && !repq.empty()) {
					repv[i].push_back(repq.top().second.second);
					rep_ing[i] = P(repair[i], repq.top().second.second);
					repq.pop();
				}
			}
		}
		
		bool check[1001] = {false};
		
		for (int i=0; i<recv[A].size(); i++) check[recv[A][i]] = true;
		for (int i=0; i<repv[B].size(); i++) if (check[repv[B][i]]) ans += repv[B][i];
		
		if (ans == 0) ans = -1;
		
		cout << "#" << tc << " " << ans << '\n';
	}
	
	return 0;
}
