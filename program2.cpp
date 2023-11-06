#include <stdio.h>

void ScoringCombos(int score) {
    int td0 = 6;
    int td1 = 7;
    int td2 = 8;
    int safety = 2;
    int fieldgoal = 3;

    printf("possible combos of scoring plays:\n");

    for (int i = 0; i <= score; i++) {
        for (int j = 0; j <= score; j++) {
            for (int k = 0; k <= score; k++) {
                for (int l = 0; l <= score; l++) {
                    for (int m = 0; m <= score; m++) {
                        if (i * safety + j * fieldgoal + k * td0 + l * td1 + m * td2 == score) {
                            printf("%d TD + %dpt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", m, m * 2, l, k, j, i);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int stop;
    do {
        int score = 0;
        printf("Enter score to continue or 0 to stop or 1 to STOP: ");
        scanf("%d", &stop);
        
        if (stop != 0 && stop != 1) {
            printf("Enter the NFL score: ");
            scanf("%d", &score);
            ScoringCombos(score);
        }
    } while (stop != 0 && stop != 1);
    return 0;
}
