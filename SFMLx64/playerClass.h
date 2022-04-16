//
// Created by iesty on 28/02/2022.
//

#ifndef SFMLGAME_PLAYERCLASS_H
#define SFMLGAME_PLAYERCLASS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class playerClass {

public:
    bool playerFaceRight, playerFaceLeft{};
    float xpos, ypos;
    float xvel, yvel;
    Clock clock;

    //constructor
    playerClass() {
        playerFaceRight = true;
        playerFaceRight = false;
        xpos = 0;
        ypos = 0;
        xvel = 0;
        yvel = 1;
        clock.restart();
    }
    void restart(bool restart) {
        if (restart == true) {
            xpos = 0;
            ypos = 0;
            xvel = 0;
            yvel = 1;
            clock.restart();
        }
    }

    void update(bool playerUp, bool playerDown, bool playerRight, bool playerLeft) {
        if (playerRight) {
            playerFaceRight = true;
            playerFaceLeft = false;
            xvel = 1;
        }
        if (playerLeft) {
            playerFaceLeft = true;
            playerFaceRight = false;
            xvel = -1;
        }
        //if(playerDown){
            //yvel = 1;
        //}
        if (playerUp) {
            Time elapsed1 = clock.getElapsedTime();
            cout << elapsed1.asMilliseconds() << endl;
            if (elapsed1.asMilliseconds() > 500) {
                //clock.restart();
                playerUp = false;

                clock.restart();

            }
            yvel -= 1;
        }


        if (!(playerRight || playerLeft)) {
            xvel = 0;
        }
        if (!(playerUp || playerDown)) {
            yvel = 0;
            
        }
        //if(xvel>= 3){
          //  xvel = 4;
        //}
       // if(xvel<= -3){
         //   xvel = -3;
        //}
        //if(yvel >= 3){
          //  yvel = 2;
        //}
        //if(yvel <= -3){
            //yvel = -3;
        //}

        if (ypos != 350 || xpos > 864) {
            yvel += 1;
           // cout << yvel << endl;
        }
        else {
            
        }

        xpos += xvel;
        ypos += yvel;


        
        //cout << xpos << endl;
    }
};



#endif //SFMLGAME_PLAYERCLASS_H

//text