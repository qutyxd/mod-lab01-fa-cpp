// Copyright 2022 UNN-IASR
#include <cctype>
#include <vector>
#include <cstring>
#include <cmath>
unsigned int faStr1(const char *str) {
    int i = 0;
    int wordCounter = 0;
    bool anyDigits = false;
    bool inWordFlag = false;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            inWordFlag = true;
            if (isdigit(str[i])) {
                anyDigits = true;
            }
        } else {
            if (inWordFlag) {
                if (!anyDigits)
                    wordCounter++;
                anyDigits = false;
                inWordFlag = false;
            }
        }
        i++;
    }
    if (inWordFlag) {
        if (!anyDigits)
            wordCounter++;
    }
    return wordCounter;
}
unsigned int faStr2(const char *str) {
    int i = 0;
    int wordCounter = 0;
    bool niceWordFlag = false;
    bool inWordFlag = false;
    while (str[i] != '\0') {
        if (!isspace(str[i])) {
            if (!inWordFlag) {
                if (isalpha(str[i]) && isupper(str[i])) {
                    niceWordFlag = true;
                }
                inWordFlag = true;
            } else {
                if (niceWordFlag) {
                    if (!isalpha(str[i])) {
                        niceWordFlag = false;
                    }
                }
            }
        } else {
            if (inWordFlag) {
                if (niceWordFlag)
                    wordCounter++;
                niceWordFlag = false;
                inWordFlag = false;
            }
        }
        i++;
    }
    return wordCounter;
}
unsigned int faStr3(const char *str) {
    using std::vector;
    vector <int> wLength;
    int i = 0;
    int wordCounter = 0;
    bool inWordFlag = false;
    int startIndex = -1;
    int endIndex = -1;
    double Sum = 0;
    whle (str[i] != '\0') {
        if (!isspace(str[i])) {
            inWordFlag = true;
            if (startIndex == -1) {
                startIndex = i;
            }
        } else {
            if (inWordFlag) {
                wordCounter++;
                inWordFlag = false;
                endIndex = i;
                wLength.push_back(endIndex - startIndex);
                startIndex = -1;
                endIndex = -1;
            }
        }
        i++;
    }
    if (inWordFlag) {
        wordCounter++;
        endIndex = strlen(str);
        wLength.push_back(endIndex - startIndex);
    }
    for (int i = 0; i < wLength.size(); i++) {
        Sum += wLength[i];
    }
    Sum = round(Sum / wLength.size());
    return Sum;
}
