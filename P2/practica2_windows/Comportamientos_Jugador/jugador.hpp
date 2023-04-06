#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {
  int fila;
  int columna;
  int orientacion;
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      hayPlan = false;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      hayPlan = false;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    int fil, col, brujula;
    estado actual, destino;
    list<Action> plan;
    list<Action> plan_aux;

    Action ultimaAccion;
    bool hayPlan;
    bool bikini_aux = false;
    bool zapatillas_aux = false;
    bool bateria_encontrada = false;
    bool bikini_encontrado = false;
    bool zapatillas_encontradas = false;
    bool bikini_puesto = false;
    bool zapatillas_puestas = false;
    double ciclo = 3000;


    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_costoUniforme(const estado &origen, const estado &destino, list<Action> &plan);
    estado bateria;
    estado bikini_estado;
    estado zapatillas_estado;

    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);
    int CosteAccion(unsigned char casilla, bool &bikini, bool &zapatillas);
};

#endif
