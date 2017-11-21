#ifndef ROBOT_H
#define ROBOT_H

#include "simulation.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

using namespace std;

class Simulation;

class Robot
{
    public:
        // Construtor
        Robot(Simulation *sim, string figure);
        // Destrutor
        ~Robot();
        // Comportamento (vazio)
        virtual void behave();
        // Simula passo do robo
        void step();
        // Desenha robo na tela
        void draw();
        // Ajusta velocidade das rodas
        void setVel(float vel_left, float vel_right);
        // Teleporta o robo para a dada posicao
        void setPos(float pos_x, float pos_y, float angle);
        // Teleporta o robo para posicao aleatoria
        void setRandPos();
        // Ajusta para que o robo apareca sempre dentro da tela
        void ajustaLimites();
        // Ponteiro para o objeto simulador
        Simulation *sim;
        // Ponteiro para a imagem
        SDL_Surface *image;
        SDL_Texture *texture;
        float pos_x, pos_y, angle;
        float vel_left, vel_right;
        int width, height;
};

#endif

