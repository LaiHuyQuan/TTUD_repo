#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#pragma comment(lib, "winmm.lib")
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
cout << "11 / 9 vui ve ❤!\n";
cout << "Hay nhap ten ban: ";
string name;
cin >> name;
cout << "Xin chao " << name << ", hom nay la ngay sinh nhat cua ai?\n";
cout << "Hay nhap ten nguoi ban muon chuc mung: ";
string birthdayName;
cin >> birthdayName;
cout << "Ban muon gui loi chuc gi den " << birthdayName << "?\n";
cout << "Hay nhap loi chuc cua ban: ";
cin.ignore();
string message;
getline(cin,message);
system("cls");
cout << "Chuan bi chuc mung sinh nhat cho " << birthdayName << "...\n";
Sleep(3000);
system("cls");
printWithTypingEffect("Chuc mung sinh nhat ", 100); // In ra chuá»�i vá»�i hiá»�u á»©ng gÃµ phÃ­m
cout << (birthdayName + "!!!\n\n"); // In ra tÃªn ngÆ°á»�i Ä�Æ°á»£c chÃºc má»«ng vá»�i hiá»�u á»©ng mÃ u sáº¯c
printWithTypingEffect("Day la loi chuc tu " + name + ":\n\n", 100); // In ra chuá»�i vá»�i hiá»�u á»©ng gÃµ phÃ­m
cout << (message + "\n\n");
playHappyBirthdayTune();
cout << "\n\nCam on ban da bo ra it thoi gian cua minh!\n";
cout << "Chuc " << birthdayName << " mot ngay sinh nhat vui ve!\n";
getch();
return 0;
}