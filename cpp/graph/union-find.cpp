#include <bits/stdc++.h>
#include <tuple>

//union-find implementation and kruskal algorithmn

using namespace std;

#define getT(i, t) get<i>(t)
typedef tuple<int, int, int> edge; //weight, origin, dest

void UFinit(int* id, int* sz, int size){
    for(int i = 0; i < size; i++){
        id[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int p, int* id){
    if(id[p] == p) return p;
    return (id[p] = find(id[p], id));
}

int uni(int u, int v, int* id, int* sz){
    int p = find(u, id);
    int q = find(v, id);
    if(p == q) return 0;
    if(sz[p] > sz[q])swap(p, q);
    id[p] = q;
    sz[q] += sz[p];
    return 1;
}
//using URI 1764 exercise as example
int main() {
    int nodes, edges, x, y, z;
    scanf("%d %d", &nodes, &edges);
    while(nodes + edges != 0){
        vector<edge> e;
        for(int i = 0; i < edges; i++){
            scanf("%d %d %d", &x, &y, &z);
            if(x > y)swap(x, y);
            e.push_back(make_tuple(z, x, y));
            total += z;
        }
        int id[nodes];
        int sz[nodes];
        UFinit(id, sz, nodes);

        //kruskal
        vector<edge> mst;
        int mst_total = 0;
        sort(e.begin(), e.begin() + edges);
        for(int k = 0; k < edges; k++){
            edge aux = e.at(k);
            if(uni(getT(1, aux), getT(2, aux), id, sz)){
                mst.push_back(aux);
                mst_total += getT(0, aux);
            }
        }
        //
        printf("%d\n",mst_total);
        scanf("%d %d", &nodes, &edges);
    }
    return 0;
}