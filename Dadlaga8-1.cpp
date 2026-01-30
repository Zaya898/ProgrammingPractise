#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *roman;
    int value;
} RomanMap;

RomanMap roman_map[] = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
    {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
};

bool isValidRoman(const char *s) {
    int i = 0;
    while (*s && i < sizeof(roman_map)/sizeof(RomanMap)) {
        int len = strlen(roman_map[i].roman);
        while (strncmp(s, roman_map[i].roman, len) == 0) {
            s += len;
        }
        i++;
    }
    return *s == '\0';
}

void intToRoman(int num, char *result) {
    result[0] = '\0';
    for (int i = 0; i < sizeof(roman_map)/sizeof(RomanMap); i++) {
        while (num >= roman_map[i].value) {
            strcat(result, roman_map[i].roman);
            num -= roman_map[i].value;
        }
    }
}

int romanToInt(const char *s) {
    int total = 0;
    int i = 0;
    while (*s && i < sizeof(roman_map)/sizeof(RomanMap)) {
        int len = strlen(roman_map[i].roman);
        if (strncmp(s, roman_map[i].roman, len) == 0) {
            total += roman_map[i].value;
            s += len;
        } else {
            i++;
        }
    }
    return total;
}

int main() {
    char input[100];
    printf("a)Rom tsipr oruul(zuv esehiig shalgana): ");
    scanf("%s", input);
    if (isValidRoman(input)) {
        printf("Zuv bichigleltei rom tsipr baina d.\n");
    } else {
        printf("Buruu bichigleltei rom tsipr baina.\n");
    }

    int number;
    printf("\nb) 1-1999 hoorond too oruulna uu: ");
    scanf("%d", &number);
    if (number < 1 || number > 1999) {
        printf("Hyzgaaraas hetersen too baina!\n");
    } else {
        char roman[50];
        intToRoman(number, roman);
        printf("Rom tsipr: %s\n", roman);
    }
    char romanInput[100];
    printf("\nc) Rom tsipr oruul(too ruu horvuulne): ");
    scanf("%s", romanInput);
    if (!isValidRoman(romanInput)) {
        printf("Buruu bichigleltei rom tsipr baina.\n");
    } else {
        int value = romanToInt(romanInput);
        printf("Aravtiin too: %d\n", value);
    }
    return 0;
}

