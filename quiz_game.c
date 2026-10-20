#include <stdio.h>
#include <stdlib.h>
float playQuiz(char teamName[]);
float askQuestion(char q[], char a[], char b[], char c[], char d[], int correct);
int tieBreaker(char teamName[]);

int main() {
    float team1Score, team2Score;
    char team1[30], team2[30];

    printf("===== TWO TEAM ONLINE QUIZING GAME =====\n");

    printf("Enter Team 1 Name: ");
    scanf("%s", team1);

    printf("Enter Team 2 Name: ");
    scanf("%s", team2);

    printf("\n========== QUIZ START ==========\n");

    printf("\n--- %s's Turn ---\n", team1);
    team1Score = playQuiz(team1);

    printf("\n--- %s's Turn ---\n", team2);
    team2Score = playQuiz(team2);

    printf("\n=========== FINAL SCORES ===========\n");
    printf("%s Score: %.1f\n", team1, team1Score);
    printf("%s Score: %.1f\n", team2, team2Score);

    printf("\n============= RESULT =============\n");

    if (team1Score > team2Score) {
        printf("WINNER: %s\n", team1);
        printf("RUNNER: %s\n", team2);
    }
    else if (team2Score > team1Score) {
        printf("WINNER: %s\n", team2);
        printf("RUNNER: %s\n", team1);
    }
    else {
        printf("Scores are TIED! Proceeding to TIEBREAKER ROUND...\n");

        printf("\n--- TieBreaker: %s ---\n", team1);
        int tb1 = tieBreaker(team1);

printf("\n--- TieBreaker: %s ---\n", team2);
        int tb2 = tieBreaker(team2);

        printf("\n========= TIEBREAKER RESULT =========\n");
        printf("%s TB Score: %d\n", team1, tb1);
        printf("%s TB Score: %d\n", team2, tb2);

        if (tb1 > tb2) {
            printf("TIEBREAKER WINNER: %s\n", team1);
        }
        else if (tb2 > tb1) {
            printf("TIEBREAKER WINNER: %s\n", team2);
        }
        else {
            printf("Even TieBreaker is TIED! Judges must decide manually.\n");
        }
    }

    return 0;
}
float playQuiz(char teamName[]) {
    float score = 0;

    score += askQuestion(
        "1) Which language is used for system programming?",
        "Java", "Python", "C", "PHP", 3
    );
    printf("\n");

score += askQuestion(
        "2) Who invented the C language?",
        "James Gosling", "Dennis Ritchie", "Bjarne Stroustrup", "Ada Lovelace", 2
    );
    printf("\n");
    
    score += askQuestion(
        "3) Which is the correct extension of a C file?",
        ".txt", ".exe", ".c", ".class", 3
    );
    printf("\n");
    
    score += askQuestion(
        "4) Which symbol is used for comments (single line)?",
        "//", "/* */", "#", "<-->", 1
    );
    printf("\n");
    
    score += askQuestion(
        "5) Which function is used for input in C?",
        "print()", "cout", "printf()", "scanf()", 4
    );
    printf("\n");
    return  score;
}
float askQuestion(char q[], char a[], char b[], char c[], char d[], int correct) {
    int ans;

    printf("\n%s\n", q);
    printf("1) %s\n2) %s\n3) %s\n4) %s\n", a, b, c, d);

    printf("Your 1st attempt: ");
    scanf("%d", &ans);

    if (ans == correct) 
    { printf("correct!(1 point)");
        return 1.0;}

    printf("Wrong! Try again.\n");

    printf("Your 2nd attempt: ");
    scanf("%d", &ans);

    if (ans == correct)
    { printf("correct in 2nd try(0.5 point)");
        return 0.5;}
        
    printf("wrong!(0 point)");
    return 0.0;
}
int tieBreaker(char teamName[]) {
    int ans, score = 0;

    printf("\n===== TIEBREAKER ROUND for %s =====\n", teamName);

    printf("\nTB1) Which is the fastest programming language?\n");
    printf("1) C\n2) Python\n3) Java\n4) Ruby\n");
    printf("Your answer: ");
    scanf("%d", &ans);
    if (ans == 1) score++;

    printf("\nTB2)\n Who created Python?\n");
    printf("1) Dennis Ritchie\n2) Bill Gates\n3) Guido van Rossum\n4) James Gosling\n");
    printf("Your answer: ");
    scanf("%d", &ans);
    if (ans == 3) score++;

    printf("\nTB3)\n Which memory is fastest?\n");
    printf("1) RAM\n2) Cache\n3) Hard Disk\n4) Pendrive\n");
    printf("Your answer: ");
    scanf("%d", &ans);
    if (ans == 2) score++;
    return score;
}
