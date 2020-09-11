#include "definiciones.h"
#include "auxiliares.h"

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

// Ejercicio 1:

bool elRango(vector<int> const& s, int prof) {
    bool rango = true;
    int bajo = (pow(-2,(prof - 1 )) );
    int alto = ((pow(2,(prof - 1 )) - 1 ) );
    for (int i=0; i < s.size(); i++) {
        rango = rango && ( ( s[i] >= bajo ) && ( s[i] <= alto ) );
    }
    return rango;
}

bool duracion(vector<int> const& s, int freq, int seg) {
    return (s.size() >= (freq * seg));
}

bool esValida(vector<int> const& s, int prof, int freq) {
    bool freqValida = (freq == 10);
    bool enRango = elRango(s, prof);
    bool profValida = (prof == 8) || (prof == 16) || (prof == 32);
    bool laDuracion = duracion(s, freq, 1);
    bool valida = freqValida && enRango && profValida && laDuracion;
    return valida;
}

// Ejercicio 2:

float tono(senial const& s) {
    float m = 0.0;
    for(int i = 0; i < s.size(); i++) {
        m = m + abs(s[i]);
    }
    m = m / s.size();
    return m ;
}

bool superaUmbral(senial const& s, int umbral) {
    return (tono(s) > umbral);
}

senial subsec(senial const& s, int a, int b) {
    senial res;
    for (int i=a; (i<b) && (i<s.size()); i++) {
        res.push_back(s[i]);
    }
    return res;
}

// Ejercicio 3:

bool esMatriz(reunion const& r) {
    bool res = true;
    for(int i = 0; i < r.size(); i++) {
        res = res && ((((r[i]).first).size()) == (((r[0]).first).size()));
    }
    return res;
}

bool senialesValidas(reunion const& r, int prof, int freq) {
    bool valida = true;
    for(int i = 0; i < r.size(); i++) {
        valida = valida && esValida((r[i].first), prof, freq);
    }
    return valida;
}

bool hablantesDeReunionesValidas(reunion const& r, int prof, int freq) {
    bool res = true;
    int len = r.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if ( (((r[i]).second) >= len) || ((i != j) && (r[i].second == r[j].second))
            || ((i == j) && (r[i].second != r[j].second)) ) {
                res = false;
            }
        }
    }
    return res;
}


// Ejercicio 4:

vector<int> acelerarSenial(vector<int> s) {
    vector<int> s0;
    for(int i = 0; i < s.size(); i++){
        if (i % 2 == 1) {
            s0.push_back(s[i]);
        }
    }
    return s0;
}

// Ejercicio 5:

vector<int> senialInterpolada(vector<int> s) {
    vector<int> s0;
    for(int i = 0; i < s.size()-1; i++){
        int prom = (s[i] + s[i+1]) / 2;
        s0.push_back(s[i]);
        s0.push_back(prom);
    }
    s0.push_back(s[s.size()-1]);
    return s0;
}

// Ejercicios 6:

vector<int> tonoMaximo(reunion const& r) {
    vector<int> maxi = r[0].first;
    for(int i = 0; i < r.size(); i++) {
        if (tono(r[i].first) >= tono(maxi)) {
            maxi = r[i].first;
        }
    }
    return maxi;
}

// Ejercicio 7:

int encontrarMaxiPosi(reunion& r, int d, int h) {
    int maxi = d;
    for(int i = d+1; i < h; i++) {
        if (tono(r[i].first) > tono(r[maxi].first)) {
            maxi = i;
        }
    }
    return maxi;
}

//Ejercicio 8:

bool duraMasDe0_1(vector<int> const& s, int freq) {
    return (s.size() > (freq * 0.1));
}

// Ejercicio 9:

bool noSeSuperponen(senial uno, senial dos, int umbral){
    bool noSuperpuestos = true;
    for(int k = 0; k < uno.size(); k++){
        if (k == 0){
            noSuperpuestos = noSuperpuestos && ( ( (uno[k] >= umbral) && ( (dos[k] < umbral)
                    && (dos[(k+1)] < umbral))) || ((uno[k] < umbral) && (uno[(k+1)] < umbral)) );
        } else {
            if (k == uno.size() - 1) {
                noSuperpuestos = noSuperpuestos && ( (((uno[k-1] >= umbral) || ((uno[k-1] < umbral)
                        && (uno[k] >= umbral)))  && ((dos[k] < umbral) && (dos[k-1] < umbral)))
                        || ((uno[k-1] < umbral) && (uno[k] < umbral)));
            } else {
                noSuperpuestos = noSuperpuestos && ( ( (uno[k] >= umbral) && ( (dos[k] < umbral)
                        && ( (dos[(k+1)] < umbral) || (dos[k-1] < umbral) ))) || (uno[k] < umbral) );
            }
        }
    }
    return noSuperpuestos;
}

// Ejercicio 11:

int findMinPosi(vector<int> s, int d, int h) {
    int min = d;
    for(int i=d+1; i <= h; i++) {
        if (s[i] < s[min]) {
            min = i;
        }
    }
    return min;
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