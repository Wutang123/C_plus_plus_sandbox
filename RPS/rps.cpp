//=========================================================================================
// File Name: rps.cpp
// File Description: Main rps file
//=========================================================================================

// Library
#include <iostream>
#include <algorithm>
#include <cstdio>
// #include <conio.h> is a MS-DOS library. It cannot be used on linux

// Global Variables
std::string VALID_MOVES[3] = {"rock", "paper", "scissor"};

// Define Operating System
#ifdef __unix__         
#define LINUX
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif
//=========================================================================================

//==========================================================
// Function Name: void console_clear_screen()
// Function Description: Clear console screen
//==========================================================
void console_clear_screen() 
{
    #ifdef OS_Windows
    system("cls");
    #endif

    #ifdef LINUX
    system("clear");
    #endif
}


//==========================================================
// Function Name: void determine_winner(std::string player_1_input, std::string player_2_input, bool is_computer = false)
// Function Description: Logic to figure out with player won
//==========================================================
void determine_winner(std::string player_1_input, std::string player_2_input, bool is_computer = false)
{
    std::string other_player = "Player 2";
    if (is_computer)
    {
        other_player = "Computer";
    }

    std::cout << "Player 1 selected: " << player_1_input << std::endl;
    printf("%s selected: %s \n", other_player.c_str(), player_2_input.c_str());

    // Check if it is a tie
    if (player_1_input == player_2_input)
    {
        std::cout << "==> A TIE has occured!" << std::endl;
    }

    // Player 1 = rock vs Player 2 = paper => Player 2 WINS (paper)
    else if (player_1_input == VALID_MOVES[0] && player_2_input == VALID_MOVES[1])
    {
        printf("==> %s WINS with paper!\n", other_player.c_str());
    }
    
    // Player 1 = rock vs Player 2 = scissor => Player 1 WINS (rock)
    else if (player_1_input == VALID_MOVES[0] && player_2_input == VALID_MOVES[2])
    {
        std::cout << "==> Player 1 WINS with rock!" << std::endl;
    }
    
    // Player 1 = paper vs Player 2 = rock => Player 1 WINS (paper)
    else if (player_1_input == VALID_MOVES[1] && player_2_input == VALID_MOVES[0])
    {
        std::cout << "==> Player 1 WINS with paper!" << std::endl;
    }

    // Player 1 = paper vs Player 2 = scissor => Player 2 WINS (scissor)
    else if (player_1_input == VALID_MOVES[1] && player_2_input == VALID_MOVES[2])
    {
        printf("==> %s WINS with scissor!\n", other_player.c_str());
    }

    // Player 1 = scissor vs Player 2 = rock => Player 2 WINS (rock)
    else if (player_1_input == VALID_MOVES[2] && player_2_input == VALID_MOVES[0])
    {
        printf("==> %s WINS with rock!\n", other_player.c_str());
    }

    // Player 1 = scissor vs Player 2 = paper => Player 1 WINS (scissor)
    else if (player_1_input == VALID_MOVES[2] && player_2_input == VALID_MOVES[1])
    {
        std::cout << "==> Player 1 WINS with scissor!" << std::endl;
    }
}


//==========================================================
// Function Name:
// Function Description: 
//==========================================================
std::string get_user_valid_rps_move()
{
    bool valid_user_input = false;
    std::string user_input;

    while(!valid_user_input)
    {
        
        std::cout << "\n----------------------" << std::endl;
        std::cout << "Player, please select one of the three options:" << std::endl;
        std::cout << "rock" << std::endl;
        std::cout << "paper" << std::endl;
        std::cout << "scissor" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cin >> user_input;

        // Convert user_input to lowercase
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

        // Check if it is a valid move
        for (int i = 0; i < 3; i++)
        {
            if (user_input == VALID_MOVES[i])
            {
                valid_user_input = true;
                break;
            }
        }

        if (!valid_user_input)
        {
            std::cout << "Please enter a valid input (rock, paper, scissor)." << std::endl;
        }
    }

    return user_input;
}

//==========================================================
// Function Name: void play_with_computer()
// Function Description: Logic to start game with computer
//==========================================================
void play_with_computer()
{
    // Get player rps move
    std::string user_input = get_user_valid_rps_move();
    
    // Get computer input
    srand((unsigned) time(NULL)); // Providing a seed value
    int random_number = rand() % 3;

    // Determine winner
    bool is_computer = true;
    determine_winner(user_input, VALID_MOVES[random_number], is_computer);
}


//==========================================================
// Function Name: void play_with_human()
// Function Description: Logic to start game with other human
//==========================================================
void play_with_human()
{
   // Get player 1 and player 2 rps move
    std::cout << std::endl << std::endl;
    std::cout << "Player 1 please select a valid RPS move. Player 2 please look away!";
    std::string user_1_input = get_user_valid_rps_move();
    console_clear_screen(); // Clear console
    // clrscr() is unavaiable for linux due to #include <conio.h> being a MS-DOS library

    std::cout << "Player 2 please select a valid RPS move. Player 1 please look away!";
    std::string user_2_input = get_user_valid_rps_move();
    console_clear_screen(); // Clear console
    // clrscr() is unavaiable for linux due to #include <conio.h> being a MS-DOS library

    // Determine winner
    determine_winner(user_1_input, user_2_input);
}


//==========================================================
// Function Name: main()
// Function Description: Main function to start RPS game
//==========================================================
int main()
{
    std::cout << "Starting Program..." << std::endl;
    std::cout << "Welcome to Rock, Paper, Scissor (RPS)!" << std::endl;

    bool start_program = true;

    while (start_program)
    {
        int user_input = 0;
        std::cout << "\n----------------------" << std::endl;
        std::cout << "Please select one of the following options:" << std::endl;
        std::cout << "1.) Play with computer" << std::endl;
        std::cout << "2.) Play with other player" << std::endl;
        std::cout << "3.) Exit game" << std::endl;
        std::cout << "----------------------" << std::endl;
        std::cin >> user_input;

        if (user_input == 1)
        {
            std::cout << "You have selected option 1." << std::endl;
            play_with_computer();
        }
        else if (user_input == 2)
        {
            std::cout << "You have selected option 2." << std::endl;
            play_with_human();
        }
        else if (user_input == 3)
        {
            std::cout << "You have selected option 3." << std::endl;
            std::cout << "Exiting Program..." << std::endl;
            start_program = false;
        }
        else
        {
            std::cout << "ERROR: User input is not valid. Please select a valid number." << std::endl;
            return -1;
        }
    }

    return 0;
}

//====================================== End of file ======================================