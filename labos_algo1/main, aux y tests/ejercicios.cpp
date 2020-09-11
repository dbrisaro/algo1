#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>

// Ejercicios

bool esSenial(vector<int> const& s, int prof, int freq) {
    bool resp = esValida(s, prof, freq);
    return resp;
}

bool seEnojo(senial const& s, int umbral, int prof, int freq) {
    bool resp = false;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i+1; j <= s.size(); j++) {
            senial subsecuencia = subsec(s, i, j);
            resp = resp || (duracion(subsecuencia, freq, 2) &&
                    superaUmbral(subsecuencia, umbral));
        }
    }
    return resp;
}

bool esReunionValida(reunion const& r, int prof, int freq) {
    bool resp = (r.size() > 0) && esMatriz(r) &&
            senialesValidas(r, prof, freq) && hablantesDeReunionesValidas(r, prof, freq);
    return resp;
}

void acelerar(reunion& r, int prof, int freq) {
    for(int i = 0; i < r.size(); i++){
        r[i].first = acelerarSenial(r[i].first);
    }
}

void ralentizar(reunion& r, int prof, int freq) {
    for(int i = 0; i < r.size(); i++) {
        r[i].first = senialInterpolada(r[i].first);
    }
}

vector<hablante> tonosDeVozElevados(reunion const& r, int freq, int prof) {
    vector<hablante> maximos;
    vector<int> maxi = tonoMaximo(r);
    for(int i = 0; i < r.size(); i++) {
        if (tono(maxi) == tono(r[i].first)) {
            maximos.push_back(r[i].second);
        }
    }
    return maximos;
}

void ordenar(reunion& r, int freq, int prof) {
    for(int i=0; i < r.size(); i++) {
        int maxPos = encontrarMaxiPosi(r, i, r.size());
        pair<senial , hablante> aux = r[i];
        r[i] = r[maxPos];
        r[maxPos] = aux;
    }
    return;
}

vector<pair<int,int> > silencios(senial const& s, int prof, int freq, int umbral) {
    vector<pair<int,int> > intervalos;
    vector<int> indices;
    pair<int, int> parIndices;
    for(int i=0; i < s.size(); i++) {
        if (abs(s[i]) < umbral) {
            indices.push_back(i);
            if (i == (s.size() - 1)) {
                parIndices = make_pair(indices[0], indices[(indices.size() - 1)]);
                intervalos.push_back(parIndices);
            }
        } else {
            if ( duraMasDe0_1(indices, freq) ) {
                parIndices = make_pair(indices[0], indices[(indices.size() - 1)]);
                intervalos.push_back(parIndices);
                indices = vector<int>();
            } else {
                indices = vector<int>();
            }
        }
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
    vector<int> v1 = s;
    for(int i = 0; b < s.size(); i++){
        int valorMediana = ordenarYmediana(i, b, s);
        v1[(b-r)] = valorMediana;
        b = b + 1;
    }
    s = v1;
    return;
}

int ordenarYmediana(int inicial, int final, vector<int> s) {
    for (int i = inicial; i <= final; i++) {
        int minPosi = findMinPosi(s, i, final);
        int auxiliar = s[i];
        s[i] = s[minPosi];
        s[minPosi] = auxiliar;
    }
    int indiceMediana = (final-inicial)/2 + inicial;
    return s[indiceMediana];
}
