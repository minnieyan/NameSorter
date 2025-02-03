#include <stdio.h>

#define MAXNAMES 100

int main(void) {
    int userMaxNames;

    do {
        printf("How many names are you sorting?: ");
        scanf("%d", &userMaxNames);
        if (userMaxNames > MAXNAMES) {
            printf("Too many names. Maximum allowed is %d.", MAXNAMES);
        }
    } while (userMaxNames > MAXNAMES);

    char nameArray[userMaxNames][50];

    for (int i = 0; i < userMaxNames; i++) {
        printf("Enter the name (%d Remaining): ", userMaxNames - i);
        scanf("%s", &nameArray[i]);
    }

    for (int x = 0; x < userMaxNames - 1; x++) {
        for (int i = 0; i < userMaxNames - 1; i++) {
            if ((int)nameArray[i][0] > (int)nameArray[i + 1][0] ) {
                char tempName[50];
                for (int n = 0; n < 50; n++) {
                    tempName[n] = nameArray[i + 1][n];
                    nameArray[i + 1][n] = nameArray[i][n];
                    nameArray[i][n] = tempName[n];
                }
            }
        }
    }

    printf("Here is your sorted list: \n");
    for (int i = 0; i < userMaxNames; i++) {
        if (i < userMaxNames - 1) {
            printf("%s, ", nameArray[i]);
        } else {
            printf("%s.\n", nameArray[i]);
        }
    }

    return 0;
}