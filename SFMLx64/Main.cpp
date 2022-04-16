#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "playerClass.h"
#include "MainMenu.h"
#include <windows.h>


int windowWidth = 1536;
int windowHeight = 865;


using namespace sf;
using namespace std;

int windowHeightX = windowHeight;
int windowWidthX = windowWidth;

int main() {
    
   

    cout << windowWidth << windowHeight << endl;
    cout << "fart" << endl;
    //Create the main window
    
   
    
    RenderWindow app(VideoMode(windowWidthX, windowHeightX), "Platformer");
    

    
       
    

    MainMenu mainMenu(app.getSize().x, app.getSize().y);
    bool playerUp, playerDown, playerLeft, playerRight = false;
    playerClass playerObject;
    Texture texture, back;

    texture.loadFromFile("../assets/images/animation.png");

    back.loadFromFile("../assets/images/bckgrnd.png");

    IntRect Size(0, 432, 865, 1563);
    Sprite bckgrnd(back, Size);

    IntRect rectSourceSprite(0, 0, 50, 50);
    IntRect rectSourceSprite2(0, 50, 50, 50);
    IntRect rectSourceSprite3(0, 100, 50, 50);
    IntRect rectSourceSprite4(0, 150, 50, 50);
    Sprite sprite(texture, rectSourceSprite4);
    Clock clock;
    int fullscreen = 0;
    int music = 1;
    bool MusicPlay = true;

    cout << fullscreen << endl;



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

    //options back
    RectangleShape Back1;
    Back1.setSize(Vector2f(1536, 865));
    Texture back1;
    back1.loadFromFile("../assets/images/options(back).png");
    Back1.setTexture(&back1);



    Music level1;
    level1.openFromFile("../assets/Audio/level1.wav");
    

    
    SoundBuffer buffer1;
    if (!buffer1.loadFromFile("../assets/Audio/jumpsound.wav")) {
        cout << "Error" << endl;
    }

    Sound jump;
    jump.setBuffer(buffer1);

    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("../assets/Audio/falling.wav")) {
        cout << "Error" << endl;
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
        

        //direction
       // if (playerObject.yvel > 1) {
         //   fall.play();
        //}

        int x = mainMenu.MainMenuPressed();
        Vector2i mousePos = Mouse::getPosition(app);
       // cout << mousePos.x << "-" << mousePos.y << endl;
        
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850) {
            cout << "YESY" << endl;
            x = 0;

        }
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850) {
            cout << "YESY" << endl;
            x = 1;
            

        }
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850) {
            cout << "YESY" << endl;
            x = 2;
            

        }

        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850) {
            cout << "YESY" << endl;
            x = 3;


        }

        
        
                //cout << x << endl;
                //Play
                if (x == 0)
                {
                    app.close();
                    RenderWindow PLAY(VideoMode(windowWidth, windowHeight), "SPACE MAN GAME THINGY");
                    if (MusicPlay == true) {
                        level1.play();
                    }
                    
                    while (PLAY.isOpen()) {
                        Event aevent;
                        while (PLAY.pollEvent(aevent)) {
                            if (aevent.type == Event::Closed) {
                                playerObject.xpos = 0;
                                playerObject.ypos = 0;
                                playerObject.yvel = 1;
                                playerObject.xvel = 0;
                                level1.stop();
                                clock.restart();
                                PLAY.clear();
                                app.create(VideoMode(windowWidthX, windowHeightX), "Platformer");
                                
                                PLAY.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    playerObject.xpos = 0;
                                    playerObject.ypos = 0;
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
                        //OPTIONS.close();
                        //ABOUT.close();
                        //Play.clear();
                        //Play.display();
                        PLAY.draw(Pbackground);
                        PLAY.draw(sprite);
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
                        if ((playerObject.yvel == 0.00) && (playerObject.xvel == 0.00) && (playerObject.playerFaceLeft)) {
                            rectSourceSprite2.left = 0;
                            sprite.setTextureRect(rectSourceSprite2);
                            clock.restart();
                        }

                        if (playerObject.yvel == 0.00 && playerObject.xvel == 0.00 && (!playerObject.playerFaceLeft)) {
                            rectSourceSprite.left = 0;
                            sprite.setTextureRect(rectSourceSprite);
                            clock.restart();
                        }

                        //jump
                        if (playerObject.yvel > 0 && playerObject.playerFaceLeft || playerObject.yvel < 0 && playerObject.playerFaceLeft) {
                            if (clock.getElapsedTime().asSeconds() > 0.3f) {
                                if (rectSourceSprite3.left != 100)
                                    rectSourceSprite3.left += 50;
                                sprite.setTextureRect(rectSourceSprite3);
                                clock.restart();
                            }
                        }

                        if (playerObject.yvel > 0.00 && !playerObject.playerFaceLeft || playerObject.yvel < 0 && !playerObject.playerFaceLeft) {
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
                        if (Keyboard::isKeyPressed(Keyboard::Space) && playerObject.yvel == 0) {
                            jump.play();
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Right)) playerRight = true;
                        if (Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
                        if (Keyboard::isKeyPressed(Keyboard::Space) && playerObject.yvel < 0.5) playerUp = true;
                        if (Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true;
                        if (!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Space))) playerUp = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;
                        if (!(Keyboard::isKeyPressed(Keyboard::Right))) playerRight = false;
                        sprite.move(Vector2f(playerObject.xvel, playerObject.yvel));
                        PLAY.display();
                        playerObject.update(playerUp, playerDown, playerRight, playerLeft);
                    }
                }
                //About
                if (x == 1) {
                    app.close();
                    RenderWindow LOAD(VideoMode(windowWidth, windowHeight), "LOAD");
                    while (LOAD.isOpen()) {
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
                            
                            //OPTIONS.clear();
                            LOAD.clear();
                            LOAD.display();
                        }
                    }
                }
                
                //Options
                if (x == 2) {
                    app.close();
                    cout << fullscreen << endl;
                    
                    cout << "Options" << endl;
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
                     //   cout << mousePos.x << "-" << mousePos.y << endl;

                        //FULLSCREEN
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1194 && mousePos.x < 1262 && mousePos.y > 186 && mousePos.y < 258) {
                            Time elapsed1 = clock.getElapsedTime();
                            if (elapsed1.asMilliseconds() > 100) {
                                cout << "CLICK" << endl;
                                fullscreen += 1;

                                
                                clock.restart();
                            }
                        }

                        //MUSIC
                        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 1194 && mousePos.x < 1262 && mousePos.y > 335 && mousePos.y < 405) {
                            Time elapsed1 = clock.getElapsedTime();
                            if (elapsed1.asMilliseconds() > 100) {
                                cout << "CLICK" << endl;
                                music += 1;


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
                           
                            
                            
                            cout << windowWidth << windowHeight << endl;
                           

                        }

                        if (music % 2 != 0) {
                            OPTIONS.draw(Music2);
                            MusicPlay = true;
                            
                        }
                        if (music % 2 == 0) {
                            MusicPlay = false;
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
            cout << "YES" << endl;
        }
        if (mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(Obackground);
            cout << "YES" << endl;
        }
        if (mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850) {
            app.draw(Ebackground);
            cout << "YES" << endl;
        }

        if (!((mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850) || mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850 || mousePos.x > 770 && mousePos.x < 950 && mousePos.y > 700 && mousePos.y < 850 || mousePos.x > 970 && mousePos.x < 1150 && mousePos.y > 700 && mousePos.y < 850)) {
            app.draw(background);
        }
        
        mainMenu.draw(app);
        app.display();

       

        //Clear screen
        //app.draw(BackgroundSprite);
        //Update the window
       


    }
    return EXIT_SUCCESS;
};
