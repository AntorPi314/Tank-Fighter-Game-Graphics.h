#include <graphics.h>
#include <iostream>
using namespace std;
int page=0, score=0, tx=50, ty=550, fx=tx+50, fy=50;
int enemy=1, fire=0;

void show_int_value(int x, int y, int value) {
    char int_as_string[10];
    itoa(value, int_as_string, 10);
    outtextxy(x, y, int_as_string);
}

void gamebg() {
    setbkcolor(BLUE);
    cleardevice();
    rectangle(20, 20, 1000, 700);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(150, 150, WHITE);
    
    rectangle(20, 500, 1000, 530);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(29, 509, WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 30);
    outtextxy(1100, 300, "SCORE");
    show_int_value(1130, 330, score);
}

void myTank() {
    int x=tx, y=ty;
    readimagefile("tank1.jpg", x, y, x+100, y+120);
}

void changeEnemy() {
    if(fire==1) {
        if(enemy==1) {
            enemy=2;
        } else if(enemy==2) {
            enemy=3;
        } else {
            enemy=1;
        }
        score++;
        fire=0;
    }
}

void showEnemy() {
    if(enemy==1) {
        int x=200, y=110;
        readimagefile("tank2.jpg", x, y, x+89, y+110);
    }
    if(enemy==2) {
        int x=700, y=110;
        readimagefile("tank2.jpg", x, y, x+89, y+110);
    }
    if(enemy==3) {
        int x=450, y=110;
        readimagefile("tank2.jpg", x, y, x+89, y+110);
    }
}

void ifEnemy(int x, int y) {
    if(enemy==1) {
        if(x>200 && x<289 && y>110 && y<170) {
            changeEnemy();
        }
    }
    if(enemy==2) {
        if(x>700 && x<789 && y>110 && y<170) {
            changeEnemy();
        }
    }
    if(enemy==3) {
        if(x>450 && x<539 && y>110 && y<170) {
            changeEnemy();
        }
    }
}

void fireRun() {
    int x=tx+42, y=fy+482, add=15;
    while(y>40) {
        setactivepage(page);
        setvisualpage(1-page);

        gamebg();
        myTank();
        readimagefile("fire.jpg", x, y, x+22, y+22);
        showEnemy();
        ifEnemy(x, y);

        page=1-page;

        delay(10);
        y-=add;
        add+=5;
        delay(1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(1280, 720, "Tank Fighter", 120, 40, false, true);

    gamebg();
    myTank();

    int x = 100, y = 100, widtht = 50, heightt = 30;
    while (1) {
        if (GetAsyncKeyState(VK_UP)) {
            fire=1;
            fireRun();
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            //
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            if(tx>50)
                tx -= 30;
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            if(tx<860)
                tx += 30;
        }
        setactivepage(page);
        setvisualpage(1-page);
        gamebg();
        myTank();
        showEnemy();
        page=1-page;
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
