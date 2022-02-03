#include "graph.h"

void graph::addEdge(int u, int v, int w) {
    edge temp;
    temp.u = u;
    temp.v = v;
    temp.w = w;
    adj[u].push_back(temp);
}

void graph::addEdge_mst(int u, int v, int w) {
    edge temp;
    temp.u = u;
    temp.v = v;
    temp.w = w;
    adj_mst[u].push_back(temp);
}

void graph::addEdge_multi(int u, int v, int w) {
    edge temp;
    temp.u = u;
    temp.v = v;
    temp.w = w;
    adj_multi[u].push_back(temp);
}

void graph::create() {
    memset(vis, false, sizeof(vis));

/*    FILE* file = fopen("C:/Users/lenovo/Desktop/AlgoandDSPractice/Guide/edge.txt", "r");
    fscanf(file, "%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        fscanf(file, "%d %d %d", &u, &v, &w);
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
        addEdge(u, v, w);
        addEdge(v, u, w);
        f[u][v] = w;
        f[v][u] = w;
    }
    fclose(file);*/

    QSqlQuery query;
    query.exec("SELECT * FROM edge");
    int cnt = 0;
    while(query.next()) {
        QString u = query.value(0).toString();
        QString v = query.value(1).toString();
        QString w = query.value(2).toString();
        if(cnt == 0) {
            n = u.toInt();
            m = v.toInt();
        } else {
            e[cnt].u = u.toInt();
            e[cnt].v = v.toInt();
            e[cnt].w = w.toInt();
            addEdge(u.toInt(), v.toInt(), w.toInt());
            addEdge(v.toInt(), u.toInt(), w.toInt());
            f[u.toInt()][v.toInt()] = w.toInt();
            f[v.toInt()][u.toInt()] = w.toInt();
        }
        cnt++;
    }

/*    QFile f("C:/Users/lenovo/Desktop/AlgoandDSPractice/Guide/node.txt");
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!f.atEnd()) {
        QByteArray line = f.readLine();
        QString temp(line);
        QStringList list = temp.split(" ");
        name[list[0].toInt()] = list[1];
        intro[list[0].toInt()] = list[2];
    }
    f.close();
*/

    query.exec("SELECT * FROM node");
    while(query.next()) {
        QString id = query.value(0).toString();
        QString nameDat = query.value(1).toString();
        QString introDat = query.value(2).toString();
        name[id.toInt()] = nameDat;
        intro[id.toInt()] = introDat;
    }

    for(int i = 1; i <= n; i++) {
        //cout << name[i].toStdString() << " " << intro[i].toStdString();
    }
}

void graph::traversal(int u) {
    //printf("dfs %d\n", u);
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        if(!vis[adj[u][i].v]) {
            traversal(adj[u][i].v);
        }
    }
}

void graph::floyd() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            path[i][j] = 0;
            if(f[i][j] == 0) f[i][j] = 1e9 + 7;
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
     //           f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                if(f[i][j] > f[i][k] + f[k][j]) {
                    f[i][j] = f[i][k] + f[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

bool graph::cmp (const edge &a, const edge &b) {
    return a.w < b.w;
}

int graph::find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void graph::unite(int x, int y) {
    x = find(x);
    y = find(y);
    fa[y] = x;
}

void graph::kruskal() {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    sort(e + 1, e + 1 + m, cmp);
    int ans = 0, k = 0;
    for(int i = 1; i <= m; i++) {
        if(find(e[i].u) != find(e[i].v)) {
            addEdge_mst(e[i].u, e[i].v, e[i].w);
            addEdge_mst(e[i].v, e[i].u, e[i].w);

            //printf("%d %d\n", e[i].u, e[i].v);
            unite(e[i].u, e[i].v);
            k++;
            ans += e[i].w;
        }
    }
}

void graph::kruskal_multi(int cnt) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    sort(e_multi + 1, e_multi + 1 + cnt, cmp);
    int ans = 0, k = 0;
    for(int i = 1; i <= cnt; i++) {
        if(find(e_multi[i].u) != find(e_multi[i].v)) {
            addEdge_mst(e_multi[i].u, e_multi[i].v, e_multi[i].w);
            addEdge_mst(e_multi[i].v, e_multi[i].u, e_multi[i].w);
            printf("%d %d\n", e_multi[i].u, e_multi[i].v);
            unite(e_multi[i].u, e_multi[i].v);
            k++;
            ans += e_multi[i].w;
        }
    }
}

void graph::traversal_mst(int u) {
    allPath.push(u);
    vis[u] = true;
    for(int i = 0; i < adj_mst[u].size(); i++) {

        if(!vis[adj_mst[u][i].v]) {
            traversal_mst(adj_mst[u][i].v);
        }
    }
}

void graph::traversal_multi(int u) {
    vis[u] = true;
    multiPath.push(u);
    for(int i = 0; i < adj_multi[u].size(); i++) {

        if(!vis[adj_multi[u][i].v]) {
            traversal_multi(adj_multi[u][i].v);
        }
    }
}
