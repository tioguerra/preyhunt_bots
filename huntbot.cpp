#include "huntbot.h"
#include <cmath>
#include <iostream>

#define SQR(x) (x)*(x)

using namespace std;

HuntBot::HuntBot(Simulation *sim, string figure) : Robot(sim, figure)
{
}

void HuntBot::behave()
{
    float d, min_d = 1000.0, min_d_angle, dx, dy;
    for (int i = 0 ; i < this->sim->total_robots ; i++)
    {
        dx = this->sim->robots[i]->pos_x - this->pos_x;
        dy = this->sim->robots[i]->pos_y - this->pos_y;
        d = sqrt(SQR(dx)+SQR(dy));
        if (this->sim->robots[i] != this && d < min_d)
        {
            min_d = d;
            min_d_angle = atan2(dx, dy);
        }
    }
    float vel = (10000.0/(1.0+SQR(min_d)));
    float ang = min_d_angle - this->angle;
    float vel_left = vel + 4*sin(ang);
    float vel_right = vel - 4*sin(ang);
    this->setVel(vel_left, vel_right);
}

