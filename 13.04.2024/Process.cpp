#include "Process.h"
#include <conio.h>
#include <chrono>
#include <thread>

int random(int a, int b) { return a + rand() % (b - a + 1); }

void Process::getState() {
    if (state) {
        state->getState();
    }
    else {
        std::cout << "Состояние не установлено" << std::endl;
    }
}

void Process::livecycle() {
    Create state1;
    Ready state2;
    Launch state3;
    Expectation state4;
    Finish state5;
    char ans;
    srand(time(NULL));

    setState(&state1);
    getState();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    setState(&state2);
    getState();
    ans = 'n';
    while (ans != 'y') {
        std::cout << "Do we launch process? (y/n)" << std::endl;
        ans = _getch();
    }
    setState(&state3);
    getState();
    std::this_thread::sleep_for(std::chrono::seconds(random(1,5)));
    std::cout << "Oops. We need data from ROM..." << std::endl;
    setState(&state4);
    getState();
    std::this_thread::sleep_for(std::chrono::seconds(random(1, 5)));
    setState(&state2);
    getState();
    ans = 'n';
    while (ans != 'y') {
        std::cout << "The data has been received. Do we launch process? (y/n)" << std::endl;
        ans = _getch();
    }
    setState(&state3);
    getState();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Something went wrong. Someone urgently needs computing power..." << std::endl;
    setState(&state2);
    getState();
    ans = 'n';
    while (ans != 'y') {
        std::cout << "Well, now it seems that's it. Do we launch process? (y/n)" << std::endl;
        ans = _getch();
    }
    setState(&state3);
    getState();
    std::this_thread::sleep_for(std::chrono::seconds(random(1, 3)));
    setState(&state5);
    getState();
}