#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

struct Choice {
    int id;
    int beats;
    const char *name;
};

struct Choice choices[] = {{ROCK, SCISSORS, "Rock"},
                           {PAPER, ROCK, "Paper"},
                           {SCISSORS, PAPER, "Scissors"}};

int getCpuChoice() { return rand() % 3; }

int getPlayerInput() {
    int choice;
    printf("Welcome to Rock Paper Scissors!\n");
    printf("Please choose:\n");
    printf("1: Rock\n");
    printf("2: Paper\n");
    printf("3: Scissors\n");
    scanf("%d", &choice);
    return choice;
}

void printResult(struct Choice player, struct Choice cpu) {
    printf("You chose %s. CPU chose %s.\n", player.name, cpu.name);

    if (player.id == cpu.id) {
        printf("Tie!\n");
    } else if (player.beats == cpu.id) {
        printf("You win!\n");
    } else {
        printf("CPU wins!\n");
    }
}

int main() {
    srand(time(NULL));

    int playerChoiceId = getPlayerInput();
    int cpuChoiceId = getCpuChoice();

    struct Choice playerChoice = choices[playerChoiceId - 1];
    struct Choice cpuChoice = choices[cpuChoiceId - 1];

    printResult(playerChoice, cpuChoice);

    return 0;
}
