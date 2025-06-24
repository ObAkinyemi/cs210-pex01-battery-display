#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#define BLACK_WHITE 1
#define BLACK_GREEN 2
#define BLACK_RED 3


/**
 * @brief draws one filled charge segment
 */
void drawChargeBlock(WINDOW *win, int y, int x) {
    // TODO: Draw a green filled block at the given coordinates
}

/**
 * @brief draws one empty charge segment
 */
void drawEmptyBlock(WINDOW *win, int y, int x) {
    // TODO: Draw a red empty block at the given coordinates
}


/** ****************************DO NOT ALTER THIS FUNCTION ************************************
 * @brief checks to ensure that the shell window is the correct size
 * of 32x80 rows and columns.  Exits after printing error message or
 * retuns without issue if the size is correct.
 * @return nothing
 */
void checkSize() {
    system("echo -ne '\e[8;32;80t'");   // Be sure to run PEX outside of VSC in
                                        // a dedicated terminal window.
    sleep(1);   // Wait for resize  
    if (COLS != 80 || LINES != 32) {
        move(1, 10);
        printw("Do not run PEX1 in VSC's builtin terminal!");
        refresh();
        sleep(2);
        endwin();
        exit(1);
    }
}

/** ****************************DO NOT ALTER THIS FUNCTION ************************************
 * @brief draws a single battery with given charge (0–10)
 */
void drawBattery(WINDOW *win, int start_y, int start_x, int charge) {
    // Manually draw each of the 10 segments from top to bottom
    if (charge >= 1) drawChargeBlock(win, start_y,     start_x); else drawEmptyBlock(win, start_y,     start_x);
    if (charge >= 2) drawChargeBlock(win, start_y + 1, start_x); else drawEmptyBlock(win, start_y + 1, start_x);
    if (charge >= 3) drawChargeBlock(win, start_y + 2, start_x); else drawEmptyBlock(win, start_y + 2, start_x);
    if (charge >= 4) drawChargeBlock(win, start_y + 3, start_x); else drawEmptyBlock(win, start_y + 3, start_x);
    if (charge >= 5) drawChargeBlock(win, start_y + 4, start_x); else drawEmptyBlock(win, start_y + 4, start_x);
    if (charge >= 6) drawChargeBlock(win, start_y + 5, start_x); else drawEmptyBlock(win, start_y + 5, start_x);
    if (charge >= 7) drawChargeBlock(win, start_y + 6, start_x); else drawEmptyBlock(win, start_y + 6, start_x);
    if (charge >= 8) drawChargeBlock(win, start_y + 7, start_x); else drawEmptyBlock(win, start_y + 7, start_x);
    if (charge >= 9) drawChargeBlock(win, start_y + 8, start_x); else drawEmptyBlock(win, start_y + 8, start_x);
    if (charge >=10) drawChargeBlock(win, start_y + 9, start_x); else drawEmptyBlock(win, start_y + 9, start_x);
}




/**
 * @brief initializes the colors and set the cursor to not display
 * @return nothing
 */
void init() {
    // TODO: Initialize ncurses and color pairs
}



/**
 * @brief Displays the intro screen with title, author, image, and instructions
 * @param win the window to draw to
 */
void drawIntroScreen(WINDOW *win) {
    // TODO: Draw border, title, author name, battery image, and instructions
}

/**
 * @brief Prompts for battery levels and returns them
 */
int getBatteryLevels(WINDOW *win, int batteryNumber) {
    // TODO: Prompt the user for input and store result in input[]
    // The atoi() function converts a string to an int. For example:
    // int charge = atoi("70") returns 70.
    // You must divide the result by 10 to convert 70% to 7 blocks.

    return 0; // TODO: Replace with actual value
}

/**
 * @brief Displays the charge levels of 3 batteries graphically and numerically
 * @param win the window to draw to
 * @param charge1 charge level for battery 1 (0–10)
 * @param charge2 charge level for battery 2 (0–10)
 * @param charge3 charge level for battery 3 (0–10)
 */
void drawBatteryDisplay(WINDOW *win, int charge1, int charge2, int charge3) {
    // TODO: Use drawBattery() to draw each battery and show their percentage values below
}

/**
 * @brief Main function to run the battery viewer program
 * Initializes curses, displays intro, gets input, and draws battery display
 */
int main() {
    int charge1, charge2, charge3;

    init();
    checkSize();

    WINDOW *win = newwin(20, 50, 1, 1);
    drawIntroScreen(win);
    charge1 = getBatteryLevels(win, 1);
    charge2 = getBatteryLevels(win, 2);
    charge3 = getBatteryLevels(win, 3);
    drawBatteryDisplay(win, charge1, charge2, charge3);
    wrefresh(win);
    wgetch(win);

    endwin();
    return 0;
}
