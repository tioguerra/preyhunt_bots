#include "simulation.h"
#include "robot.h"
#include "preybot.h"
#include "huntbot.h"
#include <iostream>

using namespace std;

#define TOTAL_PREYBOTS 15
#define TOTAL_HUNTBOTS 4
Robot *robots[TOTAL_PREYBOTS+TOTAL_HUNTBOTS];

int main(int argc, char *argv[])
{
    // Cria simulador
    Simulation *sim = new Simulation(1024,768);

    // Cria robos que fogem
    for (int i = 0 ; i < TOTAL_PREYBOTS ; i++)
    {
        robots[i] = new PreyBot(sim, "preybot.png");
        robots[i]->setRandPos();
        robots[i]->setVel(rand() % 5, rand() % 5);
    }

    // Cria robos predadores
    for (int i = 0 ; i < TOTAL_HUNTBOTS ; i++)
    {
        robots[i] = new HuntBot(sim, "huntbot.png");
        robots[i]->setRandPos();
        robots[i]->setVel(rand() % 5, rand() % 5);
    }

    // Roda simulacao
    while (sim->events())
    {
        sim->step();
    }

    // Libera memoria
    for (int i = 0 ; i < TOTAL_PREYBOTS+TOTAL_HUNTBOTS ; i++)
    {
        delete robots[i];
    }
    delete sim;
    return 0;
}

