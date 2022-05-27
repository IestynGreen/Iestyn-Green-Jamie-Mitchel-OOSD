#include "MainMenu.h"

MainMenu::MainMenu(float Width, float Height) {


    

    MainMenuSelected = -1;
}
MainMenu::~MainMenu() {

}
//Draw MainMenu
void MainMenu::draw(RenderWindow& window) {
    for (int i = 0; i < Max_main_menu; i++) {
        window.draw(mainMenu[i]);

    }
}

//MoveUp
void MainMenu::MoveUp() {
    if (MainMenuSelected - 1 >= 0) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);

        MainMenuSelected--;
        if (MainMenuSelected == -1) {
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

//MoveDown
void MainMenu::MoveDown() {
    if (MainMenuSelected + 1 <= Max_main_menu) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if (MainMenuSelected == 4) {
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}
