class Solution {
public:
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	map<string, set<string>> M1;
	map<string, double> M;
	vector<double> res;
	int n = 0;

	for (int i = 0; i<equations.size(); i++) {
		M[equations[i].first + "&&" + equations[i].second] = values[i];
		M[equations[i].second + "&&" + equations[i].first] = 1 / values[i];
		if (M1.count(equations[i].first) == 0) {
			set<string> temp;
			M1[equations[i].first] = temp;
			n++;
		}
		if (M1.count(equations[i].second) == 0) {
			set<string> temp;
			M1[equations[i].second] = temp;
			n++;
		}
		M1[equations[i].first].insert(equations[i].second);
		M1[equations[i].second].insert(equations[i].first);
	}

	map<string, int> M2;
	map<string, double> M3;
	int m = 1;
	while (n != 0) {
		string start;
		for (auto it = M1.begin(); it != M1.end(); it++) {
			if (M2.count(it->first) == 0) {
				start = it->first;
				break;
			}
		}
		M2[start] = m;
		M3[start] = 1.0;
		n -= 1;
		vector<string> temp(1, start);
		int from = 0;
		while (from != temp.size()) {
			for (auto it2 = M1[temp[from]].begin(); it2 != M1[temp[from]].end(); it2++) {
				if (M2.count(*it2) == 0) {
					M2[*it2] = m;
					M3[*it2] = M3[temp[from]] / (M[temp[from] + "&&" + *it2]);
					temp.push_back(*it2);
					n--;
				}
			}
			from++;
		}
		m++;
	}

	for (int i = 0; i<queries.size(); i++) {
		if (M2.count(queries[i].first) == 0 || M2.count(queries[i].second) == 0) {
			res.push_back(-1);
			continue;
		}
		if (M2[queries[i].first] != M2[queries[i].second]) {
			res.push_back(-1);
			continue;
		}
		double v1 = M3[queries[i].first];
		double v2 = M3[queries[i].second];
		res.push_back(v1 / v2);
	}


	return res;
}
};