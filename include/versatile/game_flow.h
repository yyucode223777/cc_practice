#ifndef GAME_FLOW_H
#define GAME_FLOW_H

class GameFlow {
  public:
    // ゲームを開始
    void startGame();

    // ゲームの概要を説明
    virtual void introduceGame() const = 0;

    // ゲームのメイン処理
    virtual void playGame() = 0;

    // ゲームの再プレイ判定
    void replayGame();

    // ゲームの初期化処理
    virtual void initGame() = 0;
};

#endif