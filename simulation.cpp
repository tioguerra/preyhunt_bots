#include "simulation.h"
#include <iostream>

using namespace std;

Simulation::Simulation(int width, int height)
{
    // Inicializa total de robos
    this->total_robots = 0;
    // Grava largura e altura da tela
    this->width = width;
    this->height = height;
    // Inicializa biblioteca para mostrar graficos
    SDL_Init(SDL_INIT_VIDEO | IMG_INIT_PNG);
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    // Cria janela
    this->window = SDL_CreateWindow("Simulador",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            this->width, this->height, SDL_WINDOW_SHOWN );
    // Cria o desenhista
    this->renderer = SDL_CreateRenderer(this->window, -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (this->renderer == NULL)
    {
        cout << "SDL_CreateRenderer error " << SDL_GetError() << endl;
    }
    SDL_SetRenderDrawColor( this->renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

Simulation::~Simulation()
{
    // Libera o desenhista
    SDL_DestroyRenderer(this->renderer);
    // Libera janela
    SDL_DestroyWindow(this->window);
    // Encerram ambiente grafico
    IMG_Quit();
    SDL_Quit();
}

void Simulation::step()
{
	SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->renderer);
    for (int i = 0 ; i < this->total_robots ; i++)
    {
        this->robots[i]->behave();
        this->robots[i]->step();
        this->robots[i]->draw();
    }
    SDL_RenderPresent(this->renderer);
    SDL_Delay(25);
}

void Simulation::add(Robot *robot)
{
    this->robots[this->total_robots] = robot;
    this->total_robots++;
}

bool Simulation::events()
{
    // Lida com eventos do usuario
	SDL_Event e;    
	while( SDL_PollEvent( &e ) != 0 )
	{
		// Encerra programa
		if( e.type == SDL_QUIT )
		{
			return false;
		}
		else if( e.type == SDL_KEYDOWN )
		{
			switch( e.key.keysym.sym )
			{
				default:
                break;
            }
        }
    }
    return true;
}

