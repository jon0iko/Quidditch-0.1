#pragma once

#include "./globals.h"

void saveScore(int score, char *name) {
    FILE *fp;
    fp = fopen("scores.txt", "a");
    fprintf(fp, "%s %d\n", name, score);
    fclose(fp);
}

// void sortScores() {
//     FILE *fp;
//     fp = fopen("scores.txt", "r");
//     char name[20];
//     int score;
//     int i = 0;
//     while (fscanf(fp, "%s %d\n", name, &score) != EOF) {
//         scores[i].score = score;
//         strcpy(scores[i].name, name);
//         i++;
//     }
//     fclose(fp);

//     int j;
//     SCORE temp;
//     for (i = 0; i < 10; i++) {
//         for (j = i + 1; j < 10; j++) {
//             if (scores[i].score < scores[j].score) {
//                 temp = scores[i];
//                 scores[i] = scores[j];
//                 scores[j] = temp;
//             }
//         }
//     }
// }

// void printScores() {
//     sortScores();
//     int i;
//     for (i = 0; i < 10; i++) {
//         printf("%s %d\n", scores[i].name, scores[i].score);
//     }
// }
