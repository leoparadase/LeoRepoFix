#include "Csort.h"


void DepthFirstSearch(int v, vector<char>& cl, vector<int>& p, int& cycle_start, const vector<vector<int>>& ribs, vector<int>& result) {
    cl[v] = 1;
    for (size_t i = 0; i < ribs[v].size(); ++i) {
        int to = ribs[v][i];
        if (cl[to] == 0) {
            p[to] = v;
            DepthFirstSearch(to, cl, p, cycle_start, ribs, result);
        }
        else if (cl[to] == 1) {
            cycle_start = to;
            return;
        }
    }
    result.push_back(v);
    cl[v] = 2;
}

void Sort::TopSort(const unordered_map<int, int>& VerticesIndex) {
    int n = arc.size();
    vector<int> result;
    vector<char> cl;
    vector<int> p;
    int cycle_start;
    p.assign(n, -1);
    cl.assign(n, 0);
    cycle_start = -1;
    result.clear();
    for (int i = 0; i < n; ++i)
        if (cl[i] != 2)
            DepthFirstSearch(i, cl, p, cycle_start, arc, result);
    if (cycle_start == -1) {
        cout << "There is no cycle in the graph" << endl;
        reverse(result.begin(), result.end());
        for (auto& i : result) {
            cout << "Station " << VerticesIndex.at(i) << " --> ";
        }
        cout << endl << endl;
    }
    else
        cout << " There is a cycle in the graph, sorting is not possible " << endl;
}


Sort::Sort(const vector<vector<int>>& r)
{
    arc = r;
}