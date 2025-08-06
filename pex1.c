#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>


/**
 * @brief draws one filled charge segment
 * @param y row location of block
 * @param x column location of block
 */
void drawChargeBlock(int y, int x) {
    // TODO: Draw a filled block at the given coordinates
}

/**
 * @brief draws one empty charge segment
 * @param y row location of block
 * @param x column location of block
 */
void drawEmptyBlock(int y, int x) {
    // TODO: Draw a empty block at the given coordinates
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
}



/**
 * @brief Displays the intro screen with title, author, image, and instructions
 * @return nothing
 */
void drawIntroScreen() {
    // TODO: Draw border, title, author name, battery image, and instructions
}


/**
 * @brief Displays the charge levels of 3 batteries graphically and numerically
 * @param charge1 charge level for battery 1 (0–10)
 * @param charge2 charge level for battery 2 (0–10)
 * @param charge3 charge level for battery 3 (0–10)
 */
void drawBatteryDisplay(int charge1, int charge2, int charge3) {
    // TODO: Use drawBattery() to draw each battery and show their percentage values below
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
