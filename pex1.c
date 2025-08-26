#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define BLACK_RED 1
#define BLACK_GREEN 2

/**
 * @brief draws one filled charge segment
 * @param y row location of block
 * @param x column location of block
 */
void drawChargeBlock(int y, int x) {
    // TODO: Draw a filled block at the given coordinates
    start_color();
    init_pair(BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(BLACK_GREEN));
    
    move (y, x);
    printw("[x]");
    
    attroff(COLOR_PAIR(BLACK_GREEN));
    
}

/**
 * @brief draws one empty charge segment
 * @param y row location of block
 * @param x column location of block
 */
void drawEmptyBlock(int y, int x) {
    // TODO: Draw a empty block at the given coordinates
    start_color();
    init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
    attron(COLOR_PAIR(BLACK_RED));
    move (y, x);
    printw("[x]");
    attroff(COLOR_PAIR(BLACK_RED));
    
}



/** ****************************DO NOT ALTER THIS FUNCTION ************************************
 * @brief Prompts for battery levels and returns them
 * @param battery battery number (1-3) being requested from user
 * @return charge - the number (1-10) of charged blocks
 */
int getBatteryLevels(int battery) {
    char input[4];                              //creates variable to save battery charge
    move(battery, 2);                           //moves cursor to row = battery and column = 2
    printw("Enter charge for Battery %d: ", battery); //asks user for the charge for the battery
    refresh();                                  //Renders screen
    getnstr(input, 3);                          //Gets input from the user
    int charge = atoi(input) / 10;              //Converts the input to an int (1 to 10)
    return charge;                              //returns the number of charged blocks
}
//*********************************************************************************************


/** ****************************DO NOT ALTER THIS FUNCTION ************************************
 * @brief draws a single battery with given charge (0–10)
 * @param start_y  vertical or y location of the battery
 * @param start_x  horizontal or x location of the battery
 * @param charge  charge level of the battery
 */
void drawBattery(int start_y, int start_x, int charge) {
    // Manually draw each of the 10 segments from top to bottom
    if (charge >= 1) drawChargeBlock(start_y,     start_x); else drawEmptyBlock(start_y,     start_x);
    if (charge >= 2) drawChargeBlock(start_y + 1, start_x); else drawEmptyBlock(start_y + 1, start_x);
    if (charge >= 3) drawChargeBlock(start_y + 2, start_x); else drawEmptyBlock(start_y + 2, start_x);
    if (charge >= 4) drawChargeBlock(start_y + 3, start_x); else drawEmptyBlock(start_y + 3, start_x);
    if (charge >= 5) drawChargeBlock(start_y + 4, start_x); else drawEmptyBlock(start_y + 4, start_x);
    if (charge >= 6) drawChargeBlock(start_y + 5, start_x); else drawEmptyBlock(start_y + 5, start_x);
    if (charge >= 7) drawChargeBlock(start_y + 6, start_x); else drawEmptyBlock(start_y + 6, start_x);
    if (charge >= 8) drawChargeBlock(start_y + 7, start_x); else drawEmptyBlock(start_y + 7, start_x);
    if (charge >= 9) drawChargeBlock(start_y + 8, start_x); else drawEmptyBlock(start_y + 8, start_x);
    if (charge >=10) drawChargeBlock(start_y + 9, start_x); else drawEmptyBlock(start_y + 9, start_x);
}
//*********************************************************************************************




/**
 * @brief starts curses mode, initializes the colors, echoes typed characters
 * @return nothing
 */
void init() {
    // TODO: Initialize ncurses and color pairs. Start echo() of typed characters
    initscr();
    start_color();
    echo();
}



/**
 * @brief Displays the intro screen with title, author, image, and instructions
 * @return nothing
 */
void drawIntroScreen() {
    // TODO: Draw border, title, author name, battery image, and instructions
    int x = 20;
    move(1, 40-x);
    printw("Battery Viewer");
    move(2, 35-x);
    printw("Created by C3C Akinyemi");
    
    start_color();
    init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
    init_pair(BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
    attron(COLOR_PAIR(BLACK_GREEN));
   
    move (4, 40-x);
    printw("+----+");
    move (5, 40-x);
    printw("|[  ]|");
    move (6, 40-x);
    printw("|[  ]|");
    move (7, 40-x);
    printw("|[  ]|");

    attroff(COLOR_PAIR(BLACK_GREEN));
    attron(COLOR_PAIR(BLACK_RED));
    
    move (8, 40-x);
    printw("|[  ]|");
    move (10, 40-x);
    printw("+----+");
    
    
    attroff(COLOR_PAIR(BLACK_GREEN));
    move(12, 25-x);
    printw("Please enter 3 battery levels.");
    move(13, 25-x);
    printw("Each level will be displayed as a");
    move(14, 25-x);
    printw("multiple of 10%% using visual blocks.");
    
    
    move(15, 25-x);
    printw("Press Any key to continue...");
    getch();
}


/**
 * @brief Displays the charge levels of 3 batteries graphically and numerically
 * @param charge1 charge level for battery 1 (0–10)
 * @param charge2 charge level for battery 2 (0–10)
 * @param charge3 charge level for battery 3 (0–10)
 */
void drawBatteryDisplay(int charge1, int charge2, int charge3) {
    // TODO: Use drawBattery() to draw each battery and show their percentage values below
    move(1, 1);
    printw("Battery Charge Display");

    move(3, 5);
    printw("Battery 1");
    drawBattery(5, 8, charge1);
    move(17, 3);
    printw("%d%%", charge1);
    
    
    move(3, 25);
    printw("Battery 2");
    drawBattery(5, 28, charge2);
    move(17, 25);
    printw("%d%%", charge2);
    
    move(3, 45);
    printw("Battery 3");
    drawBattery(5, 48, charge3);
    move(17, 45);
    printw("%d%%", charge3);
    
    move(19, 1);
    printw("Press Any key to continue...");
    getch();
    endwin();
}

/**
 * @brief Main function to run the battery viewer program
 * Initializes curses, displays intro, gets input, and draws battery display
 */
int main() {
    int charge1, charge2, charge3;

    init();                         //TODO: Complete this function definition

    drawIntroScreen();              //Function for intro screen
    erase();                        // Clear screen for next display


    //** ******************DO NOT ALTER THIS CODE  ***************************
    //Get battery charges. This code will ask the user for the battery levels
    //This code should run AFTER your intro screen and BEFORE the battery display
    charge1 = getBatteryLevels(1);  //Ask for the first battery's level
    charge2 = getBatteryLevels(2);  //Ask for the second battery's level
    charge3 = getBatteryLevels(3);  //Ask for the third battery's level
    erase();                        // Clear screen for next display
    //** ******************DO NOT ALTER THIS CODE  ***************************


    //draw the screen with the batteries' charges
    drawBatteryDisplay(charge1, charge2, charge3);

    endwin();                       //ends curses and clears screen
    return 0;
}
