

class Solution {
public:
    string intToRoman(int n){
	string ans;
	int times = 1;
	string R = "IVXLCDMO";
	vector<pair<char, char>> sym;
	//
	for(int i = 0; i < 7; i += 2){
		pair<char, char> p(R[i], R[i+1]);
		sym.push_back(p);
	} 
	for(auto p: sym)
		cout << p.first << " " << p.second << "\n";
	//
	times = 0;
	while( (int) n / 10 != 0 or n > 0){
		int N = n % 10;
		
		if(N > 0){
			if(N < 4){
				for(int i = 0; i < N; ++i)
					ans.push_back(sym[times].first);
			}else if(N == 4){
				ans.push_back(sym[times].second);
				ans.push_back(sym[times].first);
			}else if(N >= 5 & N < 9){
				for(int i = 0; i < (N - 5); ++i)
					ans.push_back(sym[times].first);
				  ans.push_back(sym[times].second);
			}else{
				ans.push_back(sym[times + 1].first);
				ans.push_back(sym[times].first);
			}
		}
		// 
		++times;
		n = (int) n / 10;
	}
	// 
	
	reverse(ans.begin(), ans.end());
	return ans;
}

};
