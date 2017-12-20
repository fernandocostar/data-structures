#include <bits/stdc++.h>

using namespace std;

//graph general implementation

typedef struct node{
    int info;
    struct node* next;
}Node;

typedef pair<int, Node*> Edge; //weight and edges
typedef map<int, Node*> Graph;

void insertVertex(Graph* g, int info){
    Node* n = NULL;
    (*g).insert(make_pair(info, n));
    return;
}
/*
//bi-directed graph
void insertEdgeBi(Graph* g, int from, int to){
    if(g->list.find(from) == g->list.end() || g->list.find(to) == g->list.end()) return;

    vector<Edge> v = g->list[from];
    Node* new_dest = (Node*)malloc(sizeof(Node));
    new_dest->info = to;
    v.push_back(make_pair(1, new_dest));

    v = g->list[to];
    new_dest = (Node*)malloc(sizeof(Node));
    new_dest->info = from;
    v.push_back(make_pair(1, new_dest));

    return;
}
*/
//directed graph
void insertEdge(Graph* g, int from, int to){
    if((*g).find(from) == (*g).end() || (*g).find(to) == (*g).end()) return;

    Node* aux = (*g)[from];

    Node* add = (Node*)malloc(sizeof(Node));
    add->info = to;
    add->next = NULL;
    if(!aux){
        (*g)[from] = add;
        return;
    }

    while(aux->next) aux = aux->next;

    aux->next = add;

    return;
}

void createGraph(Graph* g, int verts){
    for(int i = 0; i < verts; i++){
        insertVertex(g, i);
    }
    return;
}


void showGraph(Graph g){
    for(Graph::iterator it = g.begin(); it != g.end(); ++it){
        printf("%d->", it->first);
        Node* aux = it->second;
        while(aux){
            printf("%d,", aux->info);
            aux = aux->next;
        }
        printf("\n");
    }
    return;
}

int main(){
    Graph g;
    createGraph(&g, 5);
    showGraph(g);
    printf("\n");
    insertEdge(&g, 0, 2);
    showGraph(g);
    printf("\n");
    insertEdge(&g, 0, 3);
    showGraph(g);
    printf("\n");
    insertEdge(&g, 1, 2);
    showGraph(g);
    printf("\n");
    return 0;
}