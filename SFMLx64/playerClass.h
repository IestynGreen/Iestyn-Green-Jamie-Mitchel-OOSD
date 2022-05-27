#pragma once
#ifndef SFMLGAME_PLAYERCLASS_H
#define SFMLGAME_PLAYERCLASS_H
#include <iostream>
#include "gameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


    class playerClass:public gameObject{
    public:
        bool FaceRight, FaceLeft, CanJump, tcollision = false,lcollision = false, rcollision = false;
        sf::Clock jumpclock;
        float gravity = 2.0f;
        void restart(bool restart);
        void update(bool playerUp, bool playerDown, bool playerRight, bool playerLeft);
        playerClass();
        void collision();
    };



#endif //SFMLGAME_PLAYERCLASS_H