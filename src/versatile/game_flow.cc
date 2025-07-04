#include <iostream>

#include "../../include/versatile/game_flow.h"

void GameFlow::startGame() {
    introduceGame();
    playGame();
}

void GameFlow::replayGame() {
    std::cout << "もう一度遊びますか? (1=Yes; 0=No)" << std::endl;
    int selectNum;
    std::cin >> selectNum;
    if (selectNum == 1) {
        initGame();
        playGame();
    } else {
        std::cout << "ゲーム終了です。お疲れ様でした。" << std::endl;
    }
}