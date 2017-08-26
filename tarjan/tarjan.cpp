#include <bits/stdc++.h>
using namespace std;
#define GRAPH_SIZE 5000
struct Edge {
    int to;
    Edge(int to) {
        this->to = to;
    }
};
vector<Edge> graph[GRAPH_SIZE];
stack<int> Stack;
bool visited[GRAPH_SIZE];
bool stacked[GRAPH_SIZE];
int low[GRAPH_SIZE];
int dfs[GRAPH_SIZE];
int cnt;
void init(int n) {
    for(int i = 0; i < n; i++){
        graph[i].clear();
    }
    memset(stacked, 0, sizeof(stacked));
    memset(visited, 0, sizeof(visited));
    cnt = 0;
}
int tarjan(int cur) {
    visited[cur] = stacked[cur] = true;
    Stack.push(cur);
    dfs[cur] = low[cur] = cnt++;
    int size = graph[cur].size();
    for(int i = 0; i < size; i++) {
        int to = graph[cur][i].to;
        if(!visited[to]){
            low[cur] = min(low[cur], tarjan(to));
        }
        else if(stacked[to]){
            low[cur] = min(low[cur], low[to]);
        }
    }
    if(dfs[cur] == low[cur]){
        while(!Stack.empty()) {
            int top = Stack.top();
            if(low[top] == low[cur]){
                Stack.pop();
                stacked[top] = false;
                printf("%d ", top);
            }
            else
                break;
        }
        puts("");
    }
    return low[cur];
}

void solve(int n) {
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            tarjan(i);
        }
    }
}

int main() {
    int n, from, to;
    freopen("in2.txt", "r", stdin);
    scanf("%d", &n);
    init(n);
    while(scanf("%d %d", &from, &to) != EOF){
        graph[from].push_back(Edge(to));
    }
    solve(n);
    return 0;
}
