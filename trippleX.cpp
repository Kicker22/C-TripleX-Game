#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou must now...\n";
    std::cout << "hack into a lvl: " << Difficulty << " vault..\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // declaring 3 number codes
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    // maths
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // printing maths
    std::cout << std::endl;
    std::cout << "There are 3 numbers in the code \n";
    std::cout << "The code adds up to " << CodeSum << std::endl;
    std::cout << "The code multiplies to give " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProd == CodeProduct)
    {
        std::cout << "!*!*!*!*!*!*!*!* \n";
        std::cout << "Breach Succesful!";
        return true;
    }
    else
    {
        std::cout << "Your presence been detected...\n";
        std::cout << "Try Again";
        return false;
    };
}

int main()
{
    srand(time(NULL)); // Creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 10;

    while (LevelDifficulty <= MaxLevel) //loop the game untill all levels are completed
    {

        bool LevelComplete = PlayGame(LevelDifficulty);
        // PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        // increase level difficulty
        if (LevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\nWell done you have cracked all of the vaults";
    // funtion exit
    return 0;
}
