#ifndef PREYBOT_H
#define PREYBOT_H

#include "robot.h"

class PreyBot: public Robot
{
    public:
        // Construtor
        PreyBot(Simulation *sim, string figure);
        // Comportamento
        virtual void behave();
};

#endif

