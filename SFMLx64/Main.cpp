#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "playerClass.h"
#include "MainMenu.h"



int windowWidth = 1536;
int windowHeight = 865;

using namespace sf;
using namespace std;

int main() {
    cout << "fart" << endl;
    //Create the main window
    RenderWindow app(VideoMode(windowWidth, windowHeight), "Platformer");
    MainMenu mainMenu(app.getSize().x, app.getSize().y);
    bool playerUp, playerDown, playerLeft, playerRight = false;
    playerClass playerObject;
    Texture texture, back;

    texture.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/animation.png");

    back.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/bckgrnd.png");

    IntRect Size(0, 432, 865, 1563);
    Sprite bckgrnd(back, Size);

    IntRect rectSourceSprite(0, 0, 50, 50);
    IntRect rectSourceSprite2(0, 50, 50, 50);
    IntRect rectSourceSprite3(0, 100, 50, 50);
    IntRect rectSourceSprite4(0, 150, 50, 50);
    Sprite sprite(texture, rectSourceSprite4);
    Clock clock;



    //set background
    RectangleShape background;
    background.setSize(Vector2f(1536, 865));
    Texture Maintexture;
    Maintexture.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/mainMenu.png");
    background.setTexture(&Maintexture);

    //photo to the game
    RectangleShape Pbackground;
    Pbackground.setSize(Vector2f(1536, 865));
    Texture back_texture;
    back_texture.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/background.png");
    Pbackground.setTexture(&back_texture);

    //set background
    RectangleShape NGbackground;
    NGbackground.setSize(Vector2f(1536, 865));
    Texture NGMaintexture;
    NGMaintexture.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/main_menu(ng).png");
    NGbackground.setTexture(&NGMaintexture);

    //set background
    RectangleShape Lbackground;
    Lbackground.setSize(Vector2f(1536, 865));
    Texture LMaintexture;
    LMaintexture.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/images/main_menu(l).png");
    Lbackground.setTexture(&LMaintexture);



    Music level1;
    level1.openFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/Audio/level1.wav");
    level1.play();

    
    SoundBuffer buffer1;
    if (!buffer1.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/Audio/jumpsound.wav")) {
        cout << "Error" << endl;
    }

    Sound jump;
    jump.setBuffer(buffer1);

    SoundBuffer buffer2;
    if (!buffer2.loadFromFile("C:/Users/iesty/Documents/GLP/SFMLx64/assets/Audio/falling.wav")) {
        cout << "Error" << endl;
    }

    Sound fall;
    fall.setBuffer(buffer2);

    

     //Start the game loop
    while (app.isOpen())
    {
       
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
        if (Mouse::isButtonPressed(Mouse::Left) && mousePos.x > 740 && mousePos.x < 815 && mousePos.y > 700 && mousePos.y < 850) {
            cout << "YESY" << endl;
            x = 2;
            

        }
        
        
                cout << x << endl;
                
                if (x == 0)
                {
                    
                    while (app.isOpen()) {
                        Event aevent;
                        while (app.pollEvent(aevent)) {
                            if (aevent.type == Event::Closed) {
                                app.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    app.close();
                                }
                            }
                        }
                        //OPTIONS.close();
                        //ABOUT.close();
                        //Play.clear();
                        //Play.display();
                        app.draw(Pbackground);
                        app.draw(sprite);
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
                        app.display();
                        playerObject.update(playerUp, playerDown, playerRight, playerLeft);
                    }
                }
                if (x == 1) {
                    RenderWindow OPTIONS(VideoMode(960, 720), "OPTIONS");
                    
                    while (OPTIONS.isOpen()) {
                        Event aevent;
                        while (OPTIONS.pollEvent(aevent)) {
                            if (aevent.type == Event::Closed) {
                                OPTIONS.close();
                            }
                            if (aevent.type == Event::KeyPressed) {
                                if (aevent.key.code == Keyboard::Escape) {
                                    OPTIONS.close();
                                }
                            }
                        }
                        app.close();
                        OPTIONS.clear();
                      //  ABOUT.close();

                        OPTIONS.display();
                    }
                }
                if (x == 2) {
                    RenderWindow ABOUT(VideoMode(960, 720), "ABOUT");
                    while (ABOUT.isOpen()) {
                        while (ABOUT.isOpen()) {
                            Event aevent;
                            while (ABOUT.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    ABOUT.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        ABOUT.close();
                                    }
                                }
                            }
                            app.close();
                            //OPTIONS.clear();
                            ABOUT.clear();
                            ABOUT.display();
                        }
                    }
                    if (x == 3)
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

        if (!(mousePos.x > 390 && mousePos.x < 565 && mousePos.y > 700 && mousePos.y < 850)|| mousePos.x > 585 && mousePos.x < 760 && mousePos.y > 700 && mousePos.y < 850) {
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
