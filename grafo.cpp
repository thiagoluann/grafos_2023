#include<stdlib.h>
#include<stdio.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices[MAX_VERTICES];
    int arestas[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    int num_arestas;
} Grafo;

void initGrafo(Grafo* G, int num_vertices){
    G->num_vertices = num_vertices;
    G->num_arestas = 0;
    for (int i = 0; i < num_vertices; i++){
        for (int j = 0; j < num_vertices; j++){
            G->arestas[i][j] = 0;
        }   
    } 
}

void adicionarArestas(Grafo* G, int origem, int destino){
    if(G->arestas[origem][destino] == 0){
        G->arestas[origem][destino] = 1;
        G->arestas[destino][origem] = 1;
        G->num_arestas++;
    }
}

void Kn(Grafo* g){
    for (int i = 0; i < g->num_vertices; i++){
        for (int j = 0; j < g->num_vertices; j++){
            if(i == j){
                g->arestas[i][j] = 0;
            }else{
                adicionarArestas(g, i, j);
            }
        }
    }
    
    
}

void printGrafo(Grafo* G){
    printf("Numero de Vértices %d\n", G->num_vertices);
    printf("Numero de Arestas %d\n", G->num_arestas);
    for (int i = 0; i < G->num_vertices; i++){
        printf("%d:", i);
        for (int j = 0; j < G->num_vertices; j++){
            printf("%d ", G->arestas[i][j]);
            //if(G->arestas[i][j] == 1){
            //    printf("%d ", j);
            //}
        }
        printf("\n");
    }
    
}

int main(){
    Grafo *G = (Grafo*)malloc(sizeof(Grafo));
    initGrafo(G, 4);
    adicionarArestas(G, 0, 1);
    adicionarArestas(G, 0, 3);
    adicionarArestas(G, 1, 2);
    adicionarArestas(G, 2, 3);
    Kn(G);
    printGrafo(G);

}













