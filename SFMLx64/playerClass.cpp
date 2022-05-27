#include "playerClass.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "platformClass.h"
using namespace sf;
using namespace std;


    
//constructor
playerClass::playerClass() {
        FaceRight = true;
        FaceLeft = false;
        CanJump = true;
        xpos = 0;
        ypos = 525;
        xvel = 0;
        yvel = 1;
        jumpclock.restart();
        tcollision, lcollision, rcollision = false;
    }



void playerClass::collision()
{
    if (tcollision == true) {
        yvel = 0;
        jumpclock.restart();
        CanJump = true;
    }
}

void playerClass::restart(bool restart) {
        if (restart == true) {
            xpos = 0;
            ypos = 525;
            xvel = 0;
            yvel = 1;
            jumpclock.restart();
            tcollision, lcollision, rcollision = false;
        }
    }
    


    void playerClass::update(bool playerUp, bool playerDown, bool playerRight, bool playerLeft)
    {

        if (ypos <= 525) { CanJump = false; }
        else
        {
            CanJump = true;
        }

        collision();

        if ((ypos < 525) || (tcollision == false)) {
            yvel += (gravity * jumpclock.getElapsedTime().asSeconds());

        }

        if (ypos > 525) { ypos = 525; }
        if (playerUp && CanJump) {
            yvel = -12.0f;
            cout << "wowee";
        }
        ypos += yvel;
        xpos += xvel;
        if (ypos >= 525) { jumpclock.restart();}
        if (ypos >= 520) { yvel = 0; }
        if (playerRight) {
            FaceRight = true;
            FaceLeft = false;
            xvel = 5;
        }
        if (playerLeft) {
            FaceLeft = true;
            FaceRight = false;
            xvel = -5;
        }



            if (!(playerRight || playerLeft)) {
                xvel = 0;
            }
          
        }
    
    