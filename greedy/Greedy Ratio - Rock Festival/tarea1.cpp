#include  <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Artista {
    int id;
    long long t;
    long long w;
};


bool comparar(const Artista& a,const Artista& b){
    //calculamos los dos lados del producto cruzado
    long long prodA=a.w*b.t;
    long long prodB=b.w*a.t;
    //Si es que son distintos los puntajes evalua que ira primero de los dos
    if(prodA!=prodB){
        return prodA>prodB;
    }
    //En caso de que sean iguales desempatamos por id
    return a.id<b.id;
}



int main(){
    int n;// cantidad de artistas
    cin>>n;

    vector<Artista> artistas; //Creo un arreglo dinamico de tipo Artista
    for(int i=1;i<=n;i++){
        long long t,w; // de tipo long long ya que puede haber  overflow
        cin>>t>>w;
        artistas.push_back({i,t,w}); // Ya que es un arreglo dinamico no accedo por incide simplemente agrego al final
    }
    sort(artistas.begin(),artistas.end(),comparar);
    for(int i=0;i<n;i++){
        cout<<artistas[i].id<<" ";
    }
    return 0;
}