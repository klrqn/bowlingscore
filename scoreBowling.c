#include <assert.h>
// #include <conio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void print_date_and_time(void);
bool isStrike(string);

int main(void)
{

    print_date_and_time();


    string game = get_string("enter the individual scores of your game (as an array): ");

    int frame = 1;
    int score = 0;
    int strike = 0;

    int gamelength = strlen(game);
    for (int i = 0; i < gamelength; i++)
    {
        // printf("%c\n", game[i]);
        if (isdigit(game[i]))
        {
            // check if a strike is entered
            char strikemaybe[2];
            strikemaybe[0] = game[i];
            strikemaybe[1] = game[i+1];

            if (isStrike(strikemaybe))
            {
                score += 10;
                strike += 2;
                frame++;
                continue;
            } else {
                score += (int) game[i]-'0';
                frame++;
            }

            if (strike > 0)
            {
                score += (int) game[i] - '0';
            }
            // printf("%i\n", (int) game[i]-'0');
        }


    }

    printf("final score:\t %i\n", score);
    printf("final frame:\t %i\n", frame);

}

bool isStrike(char score[2])
{
    // check if a strike is entered
    if (score[0] == '1')
    {
        if (score[1] == '0')
        {
            return true;
        }
    }
    return false;
}

void print_date_and_time()
{
    time_t t;
    char now[20];
    time(&t);
    strcpy(now, ctime(&t));
    printf("%s", now);
}

















// with CL args

// int main(int argc, string argv[])
// {
//     // init variables
//     int frame = 0;
//     int score = 0;
//     printf("%i %i %i\n", frame, score, argc);

//     printf("argv[1]: %s\n", argv[1]);
//     printf("argv[2]: %s\n", argv[2]);
//     printf("argv[3]: %s\n", argv[3]);
//     // printf("%c\n", argv[1][2]);

//     int frames[10] = get_int("enter your round");

//     printf("%i", frames);
// }

















// bool testPrimes(void)
// {
//     // Test Driven Development --- create the tests FIRST, then write the code that qualifies those tests.
//     assert(isPrime(2) == true && "2 should be prime");
//     assert(isPrime(1) == false && "1 should not be prime");
//     assert(isPrime(9) == false && "9 should not be prime");
//     assert(isPrime(11) == false && "11 should be prime");

//     return 0;
// }