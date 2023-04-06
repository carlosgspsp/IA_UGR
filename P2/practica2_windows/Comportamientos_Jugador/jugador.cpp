#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
using namespace std;


// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores) {


if(sensores.nivel == 4){
    ciclo--;

if (sensores.superficie[2] == 'a' && plan.front() == actFORWARD)
{
    return actIDLE;
}

if ((sensores.terreno[2] == 'M' || sensores.terreno[2] == 'P') && plan.front() == actFORWARD)
{
 hayPlan = false;

}

if (sensores.terreno[2] == 'A' && plan.front() == actFORWARD)
{

 hayPlan = false;

}

if (sensores.terreno[2] == 'B' && plan.front() == actFORWARD)
{
 hayPlan = false;

}



if (sensores.terreno[0] == 'X'){
if (ciclo >= 1000)
{
 if (sensores.bateria <  1300)
 {
  return actIDLE;
 }

}

}

 if (ciclo >= 1000)
 if (sensores.bateria <  450 && !hayPlan && bateria_encontrada)
 {

  sensores.destinoF=bateria.fila;
  sensores.destinoC=bateria.columna;

 }

 if(sensores.terreno[0] == 'K'){
    bikini_puesto = true;
 }


 if (!bikini_puesto && bikini_encontrado)
 {
  sensores.destinoF=bikini_estado.fila;
  sensores.destinoC=bikini_estado.columna;
  hayPlan = false;

 }

  if (sensores.terreno[0] == 'D'){
    zapatillas_puestas = true;
  }

  if (!zapatillas_puestas && zapatillas_encontradas)
 {

  sensores.destinoF=zapatillas_estado.fila;
  sensores.destinoC=zapatillas_estado.columna;
  hayPlan = false;

 }


}


  if(!hayPlan){
	actual.fila        = sensores.posF;
	actual.columna     = sensores.posC;
	actual.orientacion = sensores.sentido;
    destino.fila       = sensores.destinoF;
	destino.columna    = sensores.destinoC;
	hayPlan = pathFinding(sensores.nivel, actual, destino, plan);
	cout << "Fila: " << actual.fila << endl;
	cout << "Col : " << actual.columna << endl;
	cout << "Ori : " << actual.orientacion << endl;
    }

Action sigAccion;

if(sensores.nivel == 4)
{


if (sensores.sentido == 0)  //norte
{

mapaResultado[sensores.posF][sensores.posC] = sensores.terreno[0];
mapaResultado[sensores.posF-1][sensores.posC-1] = sensores.terreno[1];
mapaResultado[sensores.posF-1][sensores.posC] = sensores.terreno[2];
mapaResultado[sensores.posF-1][sensores.posC+1] = sensores.terreno[3];
mapaResultado[sensores.posF-2][sensores.posC-2] = sensores.terreno[4];
mapaResultado[sensores.posF-2][sensores.posC-1] = sensores.terreno[5];
mapaResultado[sensores.posF-2][sensores.posC] = sensores.terreno[6];
mapaResultado[sensores.posF-2][sensores.posC+1] = sensores.terreno[7];
mapaResultado[sensores.posF-2][sensores.posC+2] = sensores.terreno[8];
mapaResultado[sensores.posF-3][sensores.posC-3] = sensores.terreno[9];
mapaResultado[sensores.posF-3][sensores.posC-2] = sensores.terreno[10];
mapaResultado[sensores.posF-3][sensores.posC-1] = sensores.terreno[11];
mapaResultado[sensores.posF-3][sensores.posC] = sensores.terreno[12];
mapaResultado[sensores.posF-3][sensores.posC+1] = sensores.terreno[13];
mapaResultado[sensores.posF-3][sensores.posC+2] = sensores.terreno[14];
mapaResultado[sensores.posF-3][sensores.posC+3] = sensores.terreno[15];


if(!bikini_encontrado || !zapatillas_encontradas || !bateria_encontrada){
cout << "Estoy Dentro N\n";
for (int i  = 0; i<4; i++){
    for(int j = -3; j<4; j++){

        if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'X' && !bateria_encontrada){
                cout << "Estoy Dentro Bateria Norte\n";
            bateria.columna =sensores.posC+j;
            bateria.fila = sensores.posF-i;
            bateria_encontrada=true;
        }

        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'K' && !bikini_encontrado){
                cout << "Estoy Dentro Bikini Norte\n";
            bikini_estado.columna =sensores.posC+j;
            bikini_estado.fila = sensores.posF-i;
            bikini_encontrado = true;
        }
        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'D' && !zapatillas_encontradas){
            cout << "Estoy Dentro Zapatillas Norte\n";
            zapatillas_estado.columna =sensores.posC+j;
            zapatillas_estado.fila = sensores.posF-i;
            zapatillas_encontradas = true;

        }
    }
}
}

}

else if (sensores.sentido == 1) //este
{
mapaResultado[sensores.posF][sensores.posC] = sensores.terreno[0];
mapaResultado[sensores.posF-1][sensores.posC+1] = sensores.terreno[1];
mapaResultado[sensores.posF][sensores.posC+1] = sensores.terreno[2];
mapaResultado[sensores.posF+1][sensores.posC+1] = sensores.terreno[3];
mapaResultado[sensores.posF-2][sensores.posC+2] = sensores.terreno[4];
mapaResultado[sensores.posF-1][sensores.posC+2] = sensores.terreno[5];
mapaResultado[sensores.posF][sensores.posC+2] = sensores.terreno[6];
mapaResultado[sensores.posF+1][sensores.posC+2] = sensores.terreno[7];
mapaResultado[sensores.posF+2][sensores.posC+2] = sensores.terreno[8];
mapaResultado[sensores.posF-3][sensores.posC+3] = sensores.terreno[9];
mapaResultado[sensores.posF-2][sensores.posC+3] = sensores.terreno[10];
mapaResultado[sensores.posF-1][sensores.posC+3] = sensores.terreno[11];
mapaResultado[sensores.posF][sensores.posC+3] = sensores.terreno[12];
mapaResultado[sensores.posF+1][sensores.posC+3] = sensores.terreno[13];
mapaResultado[sensores.posF+2][sensores.posC+3] = sensores.terreno[14];
mapaResultado[sensores.posF+3][sensores.posC+3] = sensores.terreno[15];


if(!bikini_encontrado || !zapatillas_encontradas || !bateria_encontrada){
cout << "Estoy Dentro E\n";
for (int i  = -3; i<4; i++){
    for(int j = 0; j<4; j++){

        if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'X' && !bateria_encontrada){
                cout << "Estoy Dentro Bateria Este\n";
            bateria.columna =sensores.posC+j;
            bateria.fila = sensores.posF-i;
            bateria_encontrada=true;
        }

        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'K' && !bikini_encontrado){
                cout << "Estoy Dentro Bikini Este\n";
            bikini_estado.columna =sensores.posC+j;
            bikini_estado.fila = sensores.posF-i;
            bikini_encontrado = true;
        }
        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'D' && !zapatillas_encontradas){
                cout << "Estoy Dentro Zapatillas Este\n";
            zapatillas_estado.columna =sensores.posC+j;
            zapatillas_estado.fila = sensores.posF-i;
            zapatillas_encontradas = true;
        }
    }
}
}

}

else if (sensores.sentido == 2) //sur
{
mapaResultado[sensores.posF][sensores.posC] = sensores.terreno[0];
mapaResultado[sensores.posF+1][sensores.posC+1] = sensores.terreno[1];
mapaResultado[sensores.posF+1][sensores.posC] = sensores.terreno[2];
mapaResultado[sensores.posF+1][sensores.posC-1] = sensores.terreno[3];
mapaResultado[sensores.posF+2][sensores.posC+2] = sensores.terreno[4];
mapaResultado[sensores.posF+2][sensores.posC+1] = sensores.terreno[5];
mapaResultado[sensores.posF+2][sensores.posC] = sensores.terreno[6];
mapaResultado[sensores.posF+2][sensores.posC-1] = sensores.terreno[7];
mapaResultado[sensores.posF+2][sensores.posC-2] = sensores.terreno[8];
mapaResultado[sensores.posF+3][sensores.posC+3] = sensores.terreno[9];
mapaResultado[sensores.posF+3][sensores.posC+2] = sensores.terreno[10];
mapaResultado[sensores.posF+3][sensores.posC+1] = sensores.terreno[11];
mapaResultado[sensores.posF+3][sensores.posC] = sensores.terreno[12];
mapaResultado[sensores.posF+3][sensores.posC-1] = sensores.terreno[13];
mapaResultado[sensores.posF+3][sensores.posC-2] = sensores.terreno[14];
mapaResultado[sensores.posF+3][sensores.posC-3] = sensores.terreno[15];


if(!bikini_encontrado || !zapatillas_encontradas || !bateria_encontrada){
cout << "Estoy Dentro S\n";
for (int i  = 0; i<4; i++){
    for(int j = -3; j<4; j++){

        if(mapaResultado[sensores.posF+i][sensores.posC+j] == 'X' && !bateria_encontrada){
                cout << "Estoy Dentro Bateria Sur\n";
            bateria.columna =sensores.posC+j;
            bateria.fila = sensores.posF+i;
            bateria_encontrada=true;
        }

       else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'K' && !bikini_encontrado){
                cout << "Estoy Dentro Bikini Sur\n";
            bikini_estado.columna =sensores.posC+j;
            bikini_estado.fila = sensores.posF-i;
            bikini_encontrado = true;
        }
       else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'D' && !zapatillas_encontradas){
            cout << "Estoy Dentro Zapatillas Sur\n";
            zapatillas_estado.columna =sensores.posC+j;
            zapatillas_estado.fila = sensores.posF-i;
            zapatillas_encontradas = true;
        }
    }
}
}
}


else if (sensores.sentido == 3) //oeste
{
mapaResultado[sensores.posF][sensores.posC] = sensores.terreno[0];
mapaResultado[sensores.posF+1][sensores.posC-1] = sensores.terreno[1];
mapaResultado[sensores.posF][sensores.posC-1] = sensores.terreno[2];
mapaResultado[sensores.posF-1][sensores.posC-1] = sensores.terreno[3];
mapaResultado[sensores.posF+2][sensores.posC-2] = sensores.terreno[4];
mapaResultado[sensores.posF+1][sensores.posC-2] = sensores.terreno[5];
mapaResultado[sensores.posF][sensores.posC-2] = sensores.terreno[6];
mapaResultado[sensores.posF-1][sensores.posC-2] = sensores.terreno[7];
mapaResultado[sensores.posF-2][sensores.posC-2] = sensores.terreno[8];
mapaResultado[sensores.posF+3][sensores.posC-3] = sensores.terreno[9];
mapaResultado[sensores.posF+2][sensores.posC-3] = sensores.terreno[10];
mapaResultado[sensores.posF+1][sensores.posC-3] = sensores.terreno[11];
mapaResultado[sensores.posF][sensores.posC-3] = sensores.terreno[12];
mapaResultado[sensores.posF-1][sensores.posC-3] = sensores.terreno[13];
mapaResultado[sensores.posF-2][sensores.posC-3] = sensores.terreno[14];
mapaResultado[sensores.posF-3][sensores.posC-3] = sensores.terreno[15];


if(!bikini_encontrado || !zapatillas_encontradas || !bateria_encontrada){
cout << "Estoy Dentro O\n";
for (int i  = -3; i<4; i++){
    for(int j = 0; j<4; j++){

        if(mapaResultado[sensores.posF+i][sensores.posC-j] == 'X' && !bateria_encontrada){
            cout << "Estoy Dentro Bateria Oeste\n";
            bateria.columna =sensores.posC-j;
            bateria.fila = sensores.posF+i;
            bateria_encontrada=true;
        }

        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'K' && !bikini_encontrado){
                cout << "Estoy Dentro Bikini Oeste\n";
            bikini_estado.columna =sensores.posC+j;
            bikini_estado.fila = sensores.posF-i;
            bikini_encontrado = true;
        }
        else if(mapaResultado[sensores.posF-i][sensores.posC+j] == 'D' && !zapatillas_encontradas){
                cout << "Estoy Dentro Zapatillas Oeste\n";
            zapatillas_estado.columna =sensores.posC+j;
            zapatillas_estado.fila = sensores.posF-i;
            zapatillas_encontradas = true;
        }
    }
}
}
}



}

if (hayPlan and plan.size()>0){
    sigAccion = plan.front();
    plan.erase(plan.begin());
}
else{
    hayPlan = false;
}

return sigAccion;

}


// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding (int level, const estado &origen, const estado &destino, list<Action> &plan){
	switch (level){
		case 1: cout << "Busqueda en profundad\n";
			      return pathFinding_Profundidad(origen,destino,plan);
						break;
		case 2: cout << "Busqueda en Anchura\n";
                  return  pathFinding_anchura(origen,destino,plan);
						break;
		case 3: cout << "Busqueda Costo Uniforme\n";
                  return  pathFinding_costoUniforme(origen,destino,plan);
						break;
		case 4: cout << "Busqueda para el reto\n";
						return  pathFinding_costoUniforme(origen,destino,plan);
						break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M')
		return true;
	else
	  return false;
}

int ComportamientoJugador::CosteAccion(unsigned char casilla, bool &bikini, bool &zapatillas){

   int coste = 0;
		switch (casilla) {
		case 'A':
		    if (bikini)
		    coste = 10;
		    else
		    coste = 100;
		    break;
		case 'B':
		    if (zapatillas)
                coste = 5;
            else
                coste = 50;
                break;
		case 'T':
		    coste = 2;
		    break;
        case 'D':
            coste = 1;
            zapatillas = true;
            break;
        case 'K':
            coste = 1;
            bikini = true;
            break;
        case '?':
            coste = 2;
            break;
		default:
		    coste = 1;
		    break;
	}
	return coste;
}


// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}




struct nodo{
	estado st;
	list<Action> secuencia;
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};


// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

  while (!pila.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty()){
			current = pila.top();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}


bool ComportamientoJugador::pathFinding_anchura(const estado &origen, const estado &destino, list<Action> &plan) {

	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	queue<nodo> cola;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	cola.push(current);

  while (!cola.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		cola.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			cola.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			cola.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				cola.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la cola
		if (!cola.empty()){
			current = cola.front();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}


struct nodo_coste{
	estado st;
	list<Action> secuencia;
	bool bikini;
	bool zapatillas;
	int coste;
};

bool ComportamientoJugador::pathFinding_costoUniforme(const estado &origen, const estado &destino, list<Action> &plan) {

	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	multimap<int, nodo_coste> mapa;
                                          // Lista de Abiertos

  nodo_coste current;
	current.st = origen;
	current.secuencia.empty();
	current.coste = CosteAccion(mapaResultado[current.st.fila][current.st.columna], current.bikini, current.zapatillas);
	current.zapatillas = zapatillas_aux;
	current.bikini = bikini_aux;

	mapa.insert(pair<int, nodo_coste>(current.coste, current));

  while (!mapa.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		mapa.erase(mapa.begin());
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo_coste hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;

		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.coste += CosteAccion(mapaResultado[hijoTurnR.st.fila][hijoTurnR.st.columna], hijoTurnR.bikini, hijoTurnR.zapatillas);
			mapa.insert(pair<int, nodo_coste>(hijoTurnR.coste, hijoTurnR));

		}

		// Generar descendiente de girar a la izquierda
		nodo_coste hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.coste += CosteAccion(mapaResultado[hijoTurnL.st.fila][hijoTurnL.st.columna], hijoTurnL.bikini, hijoTurnL.zapatillas);
			mapa.insert(pair<int, nodo_coste>(hijoTurnL.coste, hijoTurnL));
		}

		// Generar descendiente de avanzar
		nodo_coste hijoForward = current;
		hijoForward.coste += CosteAccion(mapaResultado[hijoForward.st.fila][hijoForward.st.columna], hijoForward.bikini, hijoForward.zapatillas);
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				mapa.insert(pair<int, nodo_coste>(hijoForward.coste, hijoForward));
			}
		}

		// Tomo el siguiente valor del multimap
		if (!mapa.empty()){
			current = (*mapa.begin()).second;
			while (!mapa.empty() && generados.find(current.st) != generados.end())
            {
                mapa.erase(mapa.begin());
                if (!mapa.empty())
                current = (*mapa.begin()).second;
            }
		}

	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		bikini_aux = current.bikini;
		zapatillas_aux = current.zapatillas;
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}



// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}



void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
