//
// Created by Sebastian Vita on 2020-05-25.
//

#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

bool esValida(vector<int> const& s, int prof, int freq);
bool duracion(vector<int> const& s, int freq, int seg);
int tono(senial const& s);
bool superaUmbral(senial const& s, int umbral);
senial subsec(senial const& s, int a, int b);
bool esMatriz(reunion const& r);
bool senialesValidas(reunion const& r, int prof, int freq);
bool hablantesDeReunionesValidas(reunion const& r, int prof, int freq);
vector<int> acelerarSenial(vector<int> s);
vector<int> senialInterpolada(vector<int> s);
vector<int> tonoMaximo(reunion const& r);
int encontrarMaxiPosi(reunion& r, int d, int h);
bool duraMasDe0_1(vector<int> const& s, int freq);
bool seSuperponen( senial uno, senial dos, int umbral);
int ordenarYmediana(int inicial, int final, vector<int> s);

#endif //REUNIONESREMOTAS_AUXILIARES_H
