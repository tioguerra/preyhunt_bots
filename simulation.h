#ifndef SIMULATION_H
#define SIMULATION_H

#include "robot.h"

extern "C"
{
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
}

#define MAX_ROBOTS 100

class Robot;

class Simulation
{
    public:
        // Construtor
        Simulation(int width, int height);
        // Destrutor
        ~Simulation();
        // Passo da simulacao
        void step();
        // Lida com eventos do usuario
        bool events();
        // Inclui novo robo
        void add(Robot *robot);
        // Propriedades da janela grafica
        int width, height;
        SDL_Window *window;
        SDL_Renderer* renderer;
        // Array com os ponteiros para os robos da simulacao
        Robot *robots[MAX_ROBOTS];
        int total_robots;
};

#endif

