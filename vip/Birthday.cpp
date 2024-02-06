#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

using namespace std;

void printWithTypingEffect(string s, int delay) {
    for (int i = 0; i < s.length(); i++) {
    cout << s[i];
    Sleep(delay);
    }
}

void playHappyBirthdayTune() {
    int notes[] = {262, 262, 294, 262, 349, 330,
    262, 262, 294, 262, 392, 349,
    262, 262, 523, 440, 349, 330, 294,
    494, 494, 440, 349, 392, 349};
    int duration[] = {500, 500, 1000, 1000, 1000, 2000,
    500, 500, 1000, 1000, 1000, 2000,
    500, 500, 1000, 1000, 1000, 1000,2000,
    500,500 ,1000 ,1000 ,1000 ,2000};
    for (int i = 0; i < sizeof(notes) / sizeof(int); i++) {
    Beep(notes[i], duration[i]);
    }
}

int main() {
    srand(time(NULL));
    system("cls");

    printWithTypingEffect("24/12 vui ve!\n", 100); 
    printWithTypingEffect("Chuc mung sinh nhat Cong La Ngon... \n", 100); 
    printWithTypingEffect("Day la loi chuc tu Vit :\n", 100); 
    cout << ("Chuc Ngon tuoi gia vui ve, giang sinh khong an lanh :)) \n");

    playHappyBirthdayTune();
    return 0;
}