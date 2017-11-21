#include "robot.h"
#include <cmath>
#include <iostream>

using namespace std;

Robot::Robot(Simulation *sim, string figure)
{
    // Grava referencia ao simulador
    this->sim = sim;
    // Se adiciona ao simulador
    this->sim->add(this);
    // Le imagem 
    this->image = IMG_Load(figure.c_str());
    this->width = this->image->w;
    this->height = this->image->h;
    // Cria textura
    this->texture = SDL_CreateTextureFromSurface(this->sim->renderer, this->image);
    if (this->texture == NULL)
	{
		cout << "SDL_CreateTextureFromSurface error " << SDL_GetError() << endl;
	}
    // Inicializa posicao
    this->pos_x = 0.0;
    this->pos_y = 0.0;
    this->angle = 0.0;
    // Inicializa velocidade
    this->vel_left = 0.0;
    this->vel_right = 0.0;
}

Robot::~Robot()
{
    // Libera imagem
    SDL_DestroyTexture(this->texture);
    SDL_FreeSurface(this->image);
}

void Robot::behave()
{
}

void Robot::step()
{
    // Calcula nova posicao
    this->ajustaLimites();
    float vel_y = 0.5*(this->vel_left + this->vel_right) * cos(this->angle);
    float vel_x = 0.5*(this->vel_left + this->vel_right) * sin(this->angle);
    float vel_ang = -(1.0/50.0)*(this->vel_right - this->vel_left);
    this->pos_x += vel_x;
    this->pos_y += vel_y;
    this->angle += vel_ang;
    this->ajustaLimites();
}

void Robot::ajustaLimites()
{
    // Ajusta limites da tela
    while (this->pos_x > this->sim->width/2)
    {
        this->pos_x -= this->sim->width;
    }
    while (this->pos_y > this->sim->height/2)
    {
        this->pos_y -= this->sim->height;
    }
    while (this->pos_x < -this->sim->width/2)
    {
        this->pos_x += this->sim->width;
    }
    while (this->pos_y < -this->sim->height/2)
    {
        this->pos_y += this->sim->height;
    }
    // Ajusta angulo para ficar entre 0 e 2pi
    while(this->angle > M_PI)
    {
        this->angle -= 2*M_PI;
    }
    while(this->angle < -M_PI)
    {
        this->angle += 2*M_PI;
    }
    // Ajusta velocidades maximas
    if (this->vel_left > 10.0) this->vel_left = 10.0;
    if (this->vel_right > 10.0) this->vel_right = 10.0;
    if (this->vel_left < -10.0) this->vel_left = -10.0;
    if (this->vel_right < -10.0) this->vel_right = -10.0;    
}

void Robot::draw()
{
    SDL_Rect pos = {(int)this->pos_x - 25 + this->sim->width/2,
                    -(int)this->pos_y - 25 + this->sim->height/2,
                    50, 50};
    SDL_RenderCopyEx(this->sim->renderer, this->texture, 
            NULL, &pos, this->angle*180.0/M_PI, 0, SDL_FLIP_NONE);
}

void Robot::setVel(float vel_left, float vel_right)
{
    this->vel_left = vel_left;
    this->vel_right = vel_right;
}

void Robot::setPos(float pos_x, float pos_y, float angle)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->angle = angle;
    this->ajustaLimites();
}

void Robot::setRandPos()
{
    this->setPos((rand() % sim->width) - sim->width/2,
                 (rand() % sim->height) - sim->height/2,
                 (float)(rand() % 360)*360.0/M_PI);
}

