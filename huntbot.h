#ifndef HUNTBOT_H
#define HUNTBOT_H

#include "robot.h"

class HuntBot: public Robot
{
    public:
        // Construtor
        HuntBot(Simulation *sim, string figure);
        // Comportamento
        virtual void behave();
};

#endif

