#ifndef SHORTESTPATH_GRAPH_H
#define SHORTESTPATH_GRAPH_H

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
using namespace std;

struct edge {
    int u, v, w;
};

class graph {
public:
    QString name[100], intro[100];
    int n, m, fa[100];
    vector<edge> adj[100];
    vector<edge> adj_mst[100];
    vector<edge> adj_multi[100];
    queue<int> allPath;
    queue<int> multiPath;
    edge e[100];
    edge e_multi[100];
    bool vis[100];
    int f[100][100];
    int path[100][100];
    void addEdge(int u, int v, int w);
    void addEdge_mst(int u, int v, int w);
    void addEdge_multi(int u, int v, int w);
    void create();
    void traversal(int u);
    void traversal_mst(int u);
    void traversal_multi(int u);
    void floyd();
    void kruskal();
    void kruskal_multi(int cnt);
    static bool cmp(const edge &a, const edge &b);
    int find(int x);
    void unite(int x, int y);
};

#endif //SHORTESTPATH_GRAPH_H
