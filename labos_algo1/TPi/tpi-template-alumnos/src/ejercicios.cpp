#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>

bool enRango(vector<int> s, int prof) {
    bool result = false;
    int i = 0;
    while (i < s.size()) {
        if (s[i] >= pow(2, prof - 1) * (-1)) {
            if (s[i] <= pow(2, prof - 1) - 1) {
                i = i + 1;
            }
        }
    }
    if (i == s.size()) { result = true; }
    return result;
}
bool frecValida(int freq) {
    bool result = false;
    if(freq==10){result = true;}
    return result;
}
bool profValida(int prof) {
    bool result = false;
    if(prof==8 || prof==16 || prof==32){result = true;}
    return result;
}
bool duraMasDe(vector<int> s, int freq, float seg) {
    bool result = false;
    if(freq*seg<=s.size()){result = true;}
    return result;
}
bool esValida(vector<int> s, int prof, int freq){
    bool result = false;
    if(frecValida(freq) && enRango(s, prof) && profValida(prof) && duraMasDe(s, freq, 1)){result = true;}
    return result;
}
bool umbralValido(int umbral){
    bool result = false;
    if(umbral>0){result = true;}
    return result;
}
float tono(vector<int> s){
    float result = 0;
    int i = 0;
    int t = 0;
    while(i<s.size()){
        t = t + abs(s[i]);
        i = i+1;
    }
    result = t/(s.size());
    return result;
}
bool superaElUmbral(vector<int> s, int umbral){
    bool result = false;
    if(tono(s)>umbral){result = true;}
    return result;
}
senial subsenial(senial const& s, int a, int b) {
    senial result;
    for (int i=a; (i<b) && (i<s.size()); i++) {
        result.push_back(s[i]);
    }
    return result;
}

bool esMatriz(reunion const& r) {
    bool result = true;
    for(int i = 0; i < r.size(); i++) {
        result = result && ((((r[i]).first).size()) == (((r[0]).first).size()));
    }
    return result;
}

bool senialesValidas(reunion r, int prof, int freq){
    bool result = false;
    int icol = 0;
    while(icol<(r[0]).first.size()){
        if(esValida(r[icol].first, prof, freq)){icol = icol + 1;}
    }
    if(icol==r.size()){result = true;}
    return result;
}
bool hablantesDeReunionValidos(reunion r){
    bool result = true;
    for (int i=0; i<r.size();i++) {
        for (int j=i+1; j<r.size(); j++ && result) {
            result = result && (r[i].second!=r[j].second);
        }
    }
    for (int i=0; i<r.size(); i++) {
        result = result && (0<=r[i].second && r[i].second<r.size());
    }
    return result;
}

vector<int> acelerarSenial(vector<int> s){
    vector<int> s0;
    for(int i=1; i<s.size();i=i+2) {
        s0.push_back(s[i]);
    }
    return s0;
}
vector<int> senialInterpolada(vector<int> s){
    vector<int> s0;
    for(int i=0; i<s.size();i++) {

        int prom = (s[i] + s[i+1]/2);
        s0.push_back(s[i]);
        s0.push_back(prom);
    }
    return s0;
}
void swap(reunion &r, int x, int y){
    pair<senial, hablante> a = r[x];
    pair<senial, hablante> b = r[y];
    r[x] = b;
    r[y] = a;
}
void swap2(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void ordenarReunion(reunion &r, int n){
    int i, j;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-i-1; j++){
            if (tono(r[j].first) <= tono(r[j+1].first))
                continue;
            swap(r, j, j + 1);
        }
    }
}
void selectionSort(vector<int> v){
    int i, j, minInd;
    int n = v.size();
    for (i = 0; i < n-1; i++){
        minInd = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[minInd])
                minInd = j;
            swap2(&v[minInd], &v[i]);
    }
}

vector<int> bubbleSort(vector<int> v) {
    for(int i=0; i<v.size(); i++){
        for (int j=v.size()-1; j>i; j--){
            if (v[j]<v[j-1]){
                int k = v[i];
                v[i] = v[j];
                v[j] = k;
            }
        }
    }
    return v;
}

bool seSuperponen( senial uno, senial dos, int umbral){
    bool noSuperpuestos = true;
    for(int k = 0; k < uno.size(); k++){
        if (k == 0){
            noSuperpuestos = noSuperpuestos && ( ( (uno[k] >= umbral) && ( (dos[k] < umbral)
                                                                           && (dos[(k+1)] < umbral))) || (((uno[k] < umbral) && (uno[(k+1)] < umbral)))
                                                                                                         && (dos[k] >= umbral) );
        } else {
            if (k == uno.size() - 1) {
                noSuperpuestos = noSuperpuestos && ( ( (uno[k] >= umbral) && ( (dos[k] < umbral)
                                                                               && (dos[k-1] < umbral))) || ( ( (uno[k] < umbral) && (uno[k-1] < umbral) )
                                                                                                             && (dos[k] >= umbral) ) );
            } else {
                noSuperpuestos = noSuperpuestos && ( ( (uno[k] >= umbral) && ( (dos[k] < umbral)
                                                                               && ( (dos[(k+1)] < umbral) || (dos[k-1] < umbral) ))) ||  ( ( (uno[k] < umbral)
                                                                                                                                             && ( (uno[(k+1)] < umbral) || (uno[k-1] < umbral) ) ) && (dos[k] >= umbral) ) );
            }
        }
    }
    return noSuperpuestos;
}

int findMinPosi(vector<int> s, int d, int h) {
    int min = d;
    for(int i=d+1; i <= h; i++) {
        if (s[i] < s[min]) {
            min = i;
        }
    }
    return min;
}


// Ejercicios

bool esSenial(vector<int> const& s, int prof, int freq) {
    bool resp = false;
    resp = esValida(s, prof, freq);
    return resp;
}

bool seEnojo(senial const& s, int umbral, int prof, int freq) {
    bool resp = false;
    for(int i=0; i<s.size(); i++){
        for(int j=i+1; j<s.size(); j++){
            senial subsec = subsenial(s,i,j);
            resp = resp || duraMasDe(subsec,freq,2) && superaElUmbral(subsec, umbral);
        }
    }
    return resp;
}

bool esReunionValida(reunion const& r, int prof, int freq) {
    bool resp = false;
    if(esMatriz(r) && senialesValidas(r,prof,freq) && hablantesDeReunionValidos(r)){resp=true;}

    return resp;
}

void acelerar(reunion& r, int prof, int freq) {
    for(int i=0;i<r.size();i++){
        r[i].first = acelerarSenial(r[i].first);
    }
    return;
}

void ralentizar(reunion& r, int prof, int freq) {
    for(int i=0;i<r.size();i++){
        r[i].first = senialInterpolada(r[i].first);
    }
    return;
}

vector<hablante> tonosDeVozElevados(reunion const& r, int freq, int prof) {
    vector<hablante> maximos = {r[0].second};
    float tonoaux = tono(r[0].first);
    int i= 0;
    while (i < r.size()){
        float itono = tono(r[i].first);
        if (itono > tonoaux){
            maximos = {r[i].second};
            tonoaux = itono;
        } else if (tono(r[i].first) == tonoaux){
            maximos.push_back(r[i].second);
        }
        i = i+1;
    }
    return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
    for(int i=0; i<r.size(); i++){
        ordenarReunion(r,i);
    }
    return;
}

vector<pair<int,int> > silencios(senial const& s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    vector<int> indices;
    pair<int, int> parIndices;
    int i = 0;
    while(i<s.size()) {
        if (abs(s[i]) < umbral) {
            indices.push_back(i);
            if (i == (s.size()-1)) {
                parIndices = make_pair(indices[0], indices[(indices.size() - 1)]);
                intervalos.push_back(parIndices);
            }
        }
        else {
            if (duraMasDe(indices, freq, 0.1) ) {
                parIndices = make_pair(indices[0], indices[(indices.size()-1)]);
                intervalos.push_back(parIndices);
                indices = vector<int>();
            }
            else { indices = vector<int>();}
        }
        i = i+1;
    }

    return intervalos;
}

bool hablantesSuperpuestos(reunion const& r, int prof, int freq, int umbral) {
    bool resp = true;
    for(int i=0; i<r.size(); i++){
        for(int j=0; j<r.size(); j++){
            if (i != j){
                resp = resp && seSuperponen(r[i].first, r[j].first, umbral);
            }
        }
    }
}

senial reconstruir(senial const& s, int prof, int freq) {
    senial senalReconstruida;
    int i = 0;
    while(i<s.size()) {
        if ((s[i] == 0) && not( ((s[i+1]<0) && (s[i-1]>0)) || ((s[i+1]>0) && (s[i-1]<0)) )) {
            int l = i;
            while (s[i + 1] == 0) {
                i += 1;
            }
            int promedio = (s[l-1] + s[i+1])/2;
            if ( (s[l-1]<0 && s[i+1]<0) || (s[l-1]>0 && s[i+1]>0) ){
                for(int k=l; k <= i; k++){
                    senalReconstruida.push_back(promedio);
                }
                i += 1;
            } else {
                for (int k = l; k <= i; k++) {
                    senalReconstruida.push_back(s[i]);
                }
                i += 1;
            }
        } else {
            senalReconstruida.push_back(s[i]);
            i += 1;
        }
    }
    return senalReconstruida;
}

void filtradoMediana(senial& s, int r, int prof, int freq){
    int b = (2*r);
    vector<int> v = s;
    for(int i = 0; b < s.size(); i++){
        senial aux = subsenial(s,i,b);
        selectionSort(aux);
        int indiceMediana = (b-i)/2 + i;
        int valorMediana = aux[indiceMediana];
        v[(b-r)] = valorMediana;
        b = b + 1;
    }
    s = v;
}

