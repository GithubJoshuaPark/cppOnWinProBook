#include <iostream>
#include "utils.h"
#include "datatypesEx.h"
#include "enumEx.h"
#include "preProcessEx.h"
#include "bitManipulationEx.h"

using namespace std;


/**
 * @brief A function pointer type for our example functions.
 * All example functions must match this signature (take no arguments, return void).
 */
typedef void (*ExampleFunc)(void);

/**
 * @brief A structure to hold the information for a single menu item.
 */
typedef struct MenuItem
{
    const char *description; // The text to display in the menu
    ExampleFunc function;    // A pointer to the function to execute
} MenuItem;

// --- Menu Definition ---

// This array now drives the entire menu and dispatch logic.
// To add a new item, just add a new line here.
MenuItem menu_items[] = {
    {"sayHello", sayHello},
    {"Data Types (데이터 타입)", datatypesEx},
    {"Enums (열거형)", enumEx},
    {"preProcessEx", preProcessEx},
    {"bitManipulationEx", bitManipulationEx},
};

// Calculate the number of items in the menu array.
const int num_menu_items = sizeof(menu_items) / sizeof(menu_items[0]);

// --- Menu Display and Interaction Logic ---
void show_menu(void)
{
    printLine("C Language Interactive Examples");
    for (int i = 0; i < num_menu_items; i++)
    {
        printf("%2d. %s\n", i + 1, menu_items[i].description);
    }
    printf("-------------------------------------\n");
    printf("99. Exit\n");
    printf("=====================================\n");
}

/**
 * @brief The main function that drives the menu interaction.
 */
int main(void)
{
    // Set console to UTF-8 to display Korean characters correctly.
    // The output of chcp is redirected to NUL to keep the console clean.
    system("chcp 65001 > NUL");

    int choice = 0;

    while (choice != 99)
    {
        clear_screen();
        show_menu();
        printf("Enter your choice: ");
        fflush(stdout);

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            clear_input_buffer();
            printf("Press Enter to continue...");
            getchar(); // Wait for user to press Enter
            continue;
        }
        clear_input_buffer();

        if (choice == 99)
        {
            printf("\nExiting the program.\n");
            break;
        }

        // The choice is 1-based, our array is 0-based.
        int index = choice - 1;

        if (index >= 0 && index < num_menu_items)
        {
            clear_screen();
            // Execute the function using the function pointer from the array
            menu_items[index].function();
            printf("\nPress Enter to return to the menu...");
            getchar(); // Wait for user to press Enter
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
            printf("Press Enter to continue...");
            getchar(); // Wait for user to press Enter
        }
    }
    return 0;
}