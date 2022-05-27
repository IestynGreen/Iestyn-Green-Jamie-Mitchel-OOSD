#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "playerClass.h"
#include "MainMenu.h"
#include <windows.h>
#include "platformClass.h"
#include "enemyClass.h"





//defnie window size
int windowWidth = 1536;
int windowHeight = 865;


using namespace sf;
using namespace std;

//set window size
int windowHeightX = windowHeight;
int windowWidthX = windowWidth;
sf::View view2(sf::Vector2f(350.f, 300.f), sf::Vector2f(1536.f, 865.f));
int main() {

    std::cout << windowWidth << windowHeight << endl;
    //Create the main window
    
   
    
    RenderWindow app(VideoMode(windowWidthX, windowHeightX), "Platformer");
    
    
    
   

    MainMenu mainMenu(app.getSize().x, app.getSize().y);
    bool playerUp, playerDown, playerLeft, playerRight = false;
    playerClass playerObject;
    enemyClass enemyObject;
    platformClass platforms[2];
    Texture texture,back,enemyt;

    texture.loadFromFile("../assets/images/animation.png");
    back.loadFromFile("../assets/images/bckgrnd.png");
    enemyt.loadFromFile("../assets/images/jmp_2.png");

    IntRect Size(0, 432, 865, 1563);
    Sprite bckgrnd(back, Size);

    IntRect rectSourceSprite(0, 0, 50, 50);
    IntRect rectSourceSprite2(0, 50, 50, 50);
    IntRect rectSourceSprite3(0, 100, 50, 50);
    IntRect rectSourceSprite4(0, 150, 50, 50);
    Sprite sprite(texture, rectSourceSprite4);
    Sprite enemysprite(enemyt);
    enemysprite.setPosition(enemyObject.xpos, enemyObject.ypos);
    Clock clock;
    int fullscreen = 0;
    int music = 1;
    int SE = 1;
    bool MusicPlay = true;
    bool SEPlay = true;

    std::cout << fullscreen << endl;

    



    //set background
    RectangleShape background;
    background.setSize(Vector2f(1536, 865));
    Texture Maintexture;
    Maintexture.loadFromFile("../assets/images/mainMenu.png");
    background.setTexture(&Maintexture);

    //photo to the game
    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(1536, 865));
    Texture back_texture;
    back_texture.loadFromFile("../assets/images/background.png");
    Pbackground.setTexture(&back_texture);

    //set background
    RectangleShape NGbackground;
    NGbackground.setSize(Vector2f(1536, 865));
    Texture NGMaintexture;
    NGMaintexture.loadFromFile("../assets/images/main_menu(ng).png");
    NGbackground.setTexture(&NGMaintexture);

    //set background
    RectangleShape Lbackground;
    Lbackground.setSize(Vector2f(1536, 865));
    Texture LMaintexture;
    LMaintexture.loadFromFile("../assets/images/main_menu(l).png");
    Lbackground.setTexture(&LMaintexture);

    //set background
    RectangleShape Obackground;
    Obackground.setSize(Vector2f(1536, 865));
    Texture OMaintexture;
    OMaintexture.loadFromFile("../assets/images/main_menu(o).png");
    Obackground.setTexture(&OMaintexture);

    //set background
    RectangleShape Ebackground;
    Ebackground.setSize(Vector2f(1536, 865));
    Texture EMaintexture;
    EMaintexture.loadFromFile("../assets/images/main_menu(e).png");
    Ebackground.setTexture(&EMaintexture);

    //set background
    RectangleShape Options1;
    Options1.setSize(Vector2f(1536, 865));
    Texture options1;
    options1.loadFromFile("../assets/images/options(1).png");
    Options1.setTexture(&options1);

    //options fullscreen cross
    
    RectangleShape Options2;
    Options2.setSize(Vector2f(1536, 865));
    Texture options2;
    options2.loadFromFile("../assets/images/options(1click).png");
    Options2.setTexture(&options2);

    //options music cross
    RectangleShape Music2;
    Music2.setSize(Vector2f(1536, 865));
    Texture music2;
    music2.loadFromFile("../assets/images/options(music).png");
    Music2.setTexture(&music2);

    //options music cross
    RectangleShape SE2;
    SE2.setSize(Vector2f(1536, 865));
    Texture se2;
    se2.loadFromFile("../assets/images/options(SE).png");
    SE2.setTexture(&se2);

    //options back
    RectangleShape Back1;
    Back1.setSize(Vector2f(1536, 865));
    Texture back1;
    back1.loadFromFile("../assets/images/options(back).png");
    Back1.setTexture(&back1);

    //Load Screen
    RectangleShape Load;
    Load.setSize(Vector2f(1536, 865));
    Texture load;
    load.loadFromFile("../assets/images/LoadScreen.png");
    Load.setTexture(&load);

    //Load Back Screen
    RectangleShape Load1;
    Load1.setSize(Vector2f(1536, 865));
    Texture load1;
    load1.loadFromFile("../assets/images/LoadScreen(Back).png");
    Load1.setTexture(&load1);




    Music level1;
    level1.openFromFile("../assets/Audio/level1.wav");
    

    
    SoundBuffer buffer1;
    if (!buffer1.loadFromFile("../assets/Audio/jumpsound.wav")) {
        std::cout << "Error" << endl;
    }

    Sound jump;
    jump.setBuffer(buffer1);

    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("../assets/Audio/falling.wav")) {
        std::cout << "Error" << endl;
    }

    Sound fall;
    fall.setBuffer(buffer2);

    

     //Start the game loop
    while (app.isOpen()){
       
        //Process events
        Event event{};
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed)
                app.close();
        }
        

        //Clickable areas on main menu
      

        int x = mainMenu.MainMenuPressed();
        Vector2i mousePos = Mouse::getPosition(app);
      
        
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850) {
            
            
            sprite.setPosition(playerObject.xpos, playerObject.ypos);

        }
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850) {
            
            x = 1;
            

        }
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850) {
           
            x = 2;
            

        }

        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850) {
            
            x = 3;


        }

        
        
                
                //Play
                if (x == 0)
                {
                    app.close();
                    playerObject.restart(true);
                    platforms[0].xpos = 500;
                    platforms[0].ypos = 400;
                    platforms[1].xpos = 800;
                    platforms[1].ypos = 400;
                    
                    RenderWindow PLAY(VideoMode(windowWidth, windowHeight), "Tiberius Station");
                    PLAY.setFramerateLimit(60);
                    if (MusicPlay == true) {

                        level1.play();
                    }
                    
                    while (PLAY.isOpen()) {
                        Event aevent;
                        while (PLAY.pollEvent(aevent)) {
                            int diffx = (playerObject.xpos + 25) - (enemyObject.xpos + 30);
                            int diffy = (playerObject.ypos + 25) - (enemyObject.ypos + 25);
                            if (aevent.type == Event::Closed) {
                                playerObject.xpos = 0;
                                playerObject.ypos = 500;
                                playerObject.yvel = 1;
                                playerObject.xvel = 0;
                                level1.stop();
                                clock.restart();
                                PLAY.clear();
                                app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                
                                PLAY.close();
                               
                            }
                            cout << diffx << endl;
                            cout << diffy<< endl;
                            if (aevent.type == Event::KeyPressed) {
                                if ((aevent.key.code == Keyboard::Escape) || ((-25 < diffx) && (diffx<25) && (diffy<25)&&(-25 < diffy))) {
                                    playerObject.xpos = 0;
                                    playerObject.ypos = 550;
                                    playerObject.yvel = 1;
                                    playerObject.xvel = 0;
                                    level1.stop();
                                    clock.restart();
                                    PLAY.clear();
                                    app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");

                                   
                                    PLAY.close();
                                }
                            }
                        }
                        
                        sf::RectangleShape background(sf::Vector2f(5000, 5000));
                        background.setFillColor(sf::Color(50, 50, 50));
                        background.setPosition(sf::Vector2f(-2000, -1000));

                        PLAY.draw(background);
                        PLAY.draw(Pbackground);
                        
                        PLAY.draw(sprite);
                        for (int i = 0; i < 2; ++i) {
                            sf::RectangleShape platform(sf::Vector2f(platforms[i].sizex, platforms[i].sizey));
                            platform.setPosition(platforms[i].xpos, platforms[i].ypos);
                            PLAY.draw(platform);
                        }
                        enemysprite.setPosition(enemyObject.xpos, enemyObject.ypos);
                        PLAY.draw(enemysprite);
                        
                        enemyObject.update();
                        enemyObject.nearby(playerObject.xpos,playerObject.ypos);

                        view2.setCenter(sf::Vector2f((playerObject.xpos), (playerObject.ypos)));
                        PLAY.setView(view2);

                       

                        //collision
                        for (int i = 0; i < 2; ++i) {
                            if ((platforms[i].xpos + platforms[i].sizex > playerObject.xpos) && ((platforms[i].xpos) < playerObject.xpos + 50) && ((playerObject.ypos + 50) < platforms[i].ypos) && (playerObject.ypos + 50) > platforms[i].ypos - 10) {
                                playerObject.tcollision = true;
                                cout << "sus";
                                goto collides;

                            }
                            else
                            {
                                playerObject.tcollision = false;
                            }

                        }
                        collides:

                        


                        //animations
                       //move right
                        if (playerObject.xvel > 0 && playerObject.yvel == 0) {
                            if (clock.getElapsedTime().asSeconds() > 0.2f) {
                                if (rectSourceSprite.left == 200)
                                    rectSourceSprite.left = 50;
                                else
                                    rectSourceSprite.left += 50;

                                sprite.setTextureRect(rectSourceSprite);
                                clock.restart();
                            }
                        }
                        //move left
                        if (playerObject.xvel < 0 && playerObject.yvel == 0) {
                            if (clock.getElapsedTime().asSeconds() > 0.2f) {
                                if (rectSourceSprite2.left == 200)
                                    rectSourceSprite2.left = 50;
                                else
                                    rectSourceSprite2.left += 50;

                                sprite.setTextureRect(rectSourceSprite2);
                                clock.restart();
                            }
                        }

                        //stand still
                        if ((playerObject.yvel == 0.00) && (playerObject.xvel == 0.00) && (playerObject.FaceLeft)) {
                            rectSourceSprite2.left = 0;
                            sprite.setTextureRect(rectSourceSprite2);
                            clock.restart();
                        }

                        if (playerObject.yvel == 0.00 && playerObject.xvel == 0.00 && (!playerObject.FaceLeft)) {
                            rectSourceSprite.left = 0;
                            sprite.setTextureRect(rectSourceSprite);
                            clock.restart();
                        }

                        //jump
                        if (playerObject.yvel > 0 && playerObject.FaceLeft || playerObject.yvel < 0 && playerObject.FaceLeft) {
                            if (clock.getElapsedTime().asSeconds() > 0.3f) {
                                if (rectSourceSprite3.left != 100)
                                    rectSourceSprite3.left += 50;
                                sprite.setTextureRect(rectSourceSprite3);
                                clock.restart();
                            }
                        }

                        if (playerObject.yvel > 0.00 && !playerObject.FaceLeft || playerObject.yvel < 0 && !playerObject.FaceLeft) {
                            if (clock.getElapsedTime().asSeconds() > 0.3f) {
                                if (rectSourceSprite4.left != 100)
                                    rectSourceSprite4.left += 50;
                                sprite.setTextureRect(rectSourceSprite4);
                                clock.restart();
                            }
                        }

                        if (playerObject.yvel == 0) {
                            rectSourceSprite3.left = 0;
                            rectSourceSprite4.left = 0;
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Space) && playerObject.yvel == 0 && SEPlay == true) {
                            playerUp = true;
                            jump.play();
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
                        if (Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
                        if (Keyboard::isKeyPressed(Keyboard::Space) && (playerObject.CanJump = true)) playerUp = true;
                        if (Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
                        if (!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Space))) playerUp = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight = false;
                        sprite.setPosition(playerObject.xpos, playerObject.ypos);
                        PLAY.display();
                        playerObject.update(playerUp, playerDown, playerRight, playerLeft);
                    }
                }
                //Load
                if (x == 1) {
                    
                    app.close();
                    RenderWindow LOAD(VideoMode(windowWidth, windowHeight), "LOAD");
                    
                        while (LOAD.isOpen()) {
                            Event aevent;
                            while (LOAD.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                    LOAD.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                        LOAD.close();

                                    }
                                }
                            }

                            Vector2i mousePos = Mouse::getPosition(LOAD);

                            LOAD.clear();
                            LOAD.draw(Load);

                            if (mousePos.x > 1281 && mousePos.x < 1496 && mousePos.y > 737 && mousePos.y < 837) {
                                LOAD.draw(Load1);
                            }

                            //BACK
                            if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1281 && mousePos.x < 1496 && mousePos.y > 737 && mousePos.y < 837) {
                                LOAD.close();
                                app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                            }

                            
                            
                            //OPTIONS.clear();
                            
                            
                            LOAD.display();
                            
                        }
                    }
                
                
                //Options
                if (x == 2) {
                    app.close();
                    std::cout << fullscreen << endl;
                    
                    std::cout << "Options" << endl;
                    RenderWindow OPTIONS(VideoMode(windowWidth, windowHeight), "OPTIONS");
                    

                    while (OPTIONS.isOpen()) {
                        Event aevent;
                        while (OPTIONS.pollEvent(aevent)) {
                            if (aevent.type == Event::Closed) {
                                
                                app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                OPTIONS.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                    OPTIONS.close();
                                    
                                }
                            }
                        }
                        int x = mainMenu.MainMenuPressed();
                        Vector2i mousePos = Mouse::getPosition(OPTIONS);
                        std::cout << mousePos.x << "-" << mousePos.y << endl;

                        //FULLSCREEN
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1194 && mousePos.x < 1262 && mousePos.y > 186 && mousePos.y < 258) {
                            Time elapsed1 = clock.getElapsedTime();
                            if (elapsed1.asMilliseconds() > 100) {
                                std::cout << "CLICK" << endl;
                                fullscreen += 1;

                                
                                clock.restart();
                            }
                        }

                        //MUSIC
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1194 && mousePos.x < 1262 && mousePos.y > 335 && mousePos.y < 405) {
                            Time elapsed1 = clock.getElapsedTime();
                            if (elapsed1.asMilliseconds() > 100) {
                                std::cout << "CLICK" << endl;
                                music += 1;


                                clock.restart();
                            }
                        }


                        //Sound Effect
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1194 && mousePos.x < 1262 && mousePos.y > 477 && mousePos.y < 546) {
                            Time elapsed1 = clock.getElapsedTime();
                            if (elapsed1.asMilliseconds() > 100) {
                                std::cout << "CLICK" << endl;
                                SE += 1;


                                clock.restart();
                            }
                        }



                        //BACK
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1281 && mousePos.x < 1496 && mousePos.y > 737 && mousePos.y < 837) {
                            OPTIONS.close();
                            app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                        }
                      
                        //app.close();
                        OPTIONS.clear();
                        //ABOUT.close();
                        
                        OPTIONS.draw(Options1);

                        if (mousePos.x > 1281 && mousePos.x < 1496 && mousePos.y > 737 && mousePos.y < 837) {
                            OPTIONS.draw(Back1);
                        }

                        if (fullscreen % 2 != 0) {
                            OPTIONS.draw(Options2);
                            
                           windowWidthX = 0;
                           windowHeightX = 0;
                           //OPTIONS.close();
                           OPTIONS.create(VideoMode(windowWidth, windowHeight), "Platformer", Style::Fullscreen);
                           
                            
                            
                            std::cout << windowWidth << windowHeight << endl;
                           

                        }

                        if (music % 2 != 0) {
                            OPTIONS.draw(Music2);
                            MusicPlay = true;
                            
                        }
                        if (SE % 2 != 0) {
                            OPTIONS.draw(SE2);
                            SEPlay = true;
                        }
                        if (music % 2 == 0) {
                            MusicPlay = false;
                        }
                        if (SE % 2 == 0) {
                            SEPlay = false;
                        }
                        OPTIONS.display();
                        
                        
                    }
                }
                    if (x == 3){
                        app.close();
                        break;
                }
           
        
        app.clear();
        if (mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(NGbackground);
        }
        if (mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(Lbackground);
            std::cout << "YES" << endl;
        }
        if (mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(Obackground);
            std::cout << "YES" << endl;
        }
        if (mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(Ebackground);
            std::cout << "YES" << endl;
        }

        if (!((mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850) || mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850 || mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850 || mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850)) {
            app.draw(background);
        }
        
        mainMenu.draw(app);
        app.display();

       

        
       


    }
    return EXIT_SUCCESS;
};
