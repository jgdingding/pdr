// Justin Gou
// jyg2qhc
// 04/17/20
// topological.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <queue>
	
using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1], ifstream::binary);
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

	map<string, vector<string>> graph;
	map<string, int> indegrees;

	while ( true ){
		string s1,s2;
		file >> s1;
		file >> s2;
		if ( s1=="0" && s2=="0" ){
			break;
		}

		//cout << s1 << " " << s2 << endl;
	
		if ( graph.count(s1) > 0 ){
			graph[s1].push_back(s2);
		}else{
			vector<string> edges;
			edges.push_back(s2);
			graph[s1] = edges;
		}

		if ( indegrees.count(s1) == 0 ){
			indegrees[s1] = 0;
		}
		if ( indegrees.count(s2) > 0 ){
			indegrees[s2]++;
		}else{
			indegrees[s2] = 1;
		}
	}
	
	queue<string> q;
	int counter = 0;
	string v, w;
	vector<string> topoNum(indegrees.size(),"");

	for (map<string, vector<string>>::iterator it = graph.begin(); it != graph.end(); it++ ){
		if ( indegrees[it->first] == 0 ){
			q.push(it->first);
		}
	}
	while ( !q.empty() ){
		v = q.front();
		q.pop();
		topoNum[counter++] = v;
		for (int i=0; i<graph[v].size(); i++) {
			if(--indegrees[graph[v][i]] == 0){
				q.push(graph[v][i]);
			}
		}
	}

	for (int i=0; i<topoNum.size(); i++) {
		cout << topoNum[i] << " ";
	}
	cout << endl;

    file.close();
	return 0;
}

