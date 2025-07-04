#include <array>
#include <iostream>

#include "../../include/poker/hand_role.h"
#include "../../include/poker/player.h"
#include "../../include/poker/poker.h"

Poker::Poker() : rounds(5), deck(), discards(), gamePlayer(), dealer() {
    deck.init();
    deck.shuffle();
}

void Poker::introduceGame() const {
    std::cout << "⭐︎︎ ポーカー ⭐︎" << std::endl;
    std::cout << "配られた5枚の手札を相手と比べてより強い役を持っているプレイヤ"
                 "ーが勝ちです。"
              << std::endl;
    std::cout << "-------------------------------------------------------------"
                 "------------"
              << std::endl;
}

void Poker::playGame() {
    for (int i = 0; i < rounds; ++i) {
        std::cout << "【" << i + 1 << "ラウンド】" << std::endl;

        // カードの配布
        distributeCard(dealer);
        distributeCard(gamePlayer);

        // 手札の表示
        std::cout << "対戦相手の手札 -> ";
        dealer.printHand();
        std::cout << "あなたの手札   -> ";
        gamePlayer.printHand();
        std::cout << std::endl;

        // 手札の交換
        if (confirmCardTrade()) {
            std::array<bool, 5> selectedDiscards = selectDiscard();

            for (size_t i = 0; i < selectedDiscards.size(); ++i) {
                if (selectedDiscards.at(i)) {
                    // 手札から捨てたカードをdiscardsに追加
                    auto gamePlayerDiscard = gamePlayer.getDiscard(i);
                    discards.push_back(std::move(gamePlayerDiscard));
                    if (deck.getDeck().size() > 0) {
                        gamePlayer.addToHand(deck.draw(), i);
                    } else {
                        deck.reuse(std::move(discards));
                        deck.shuffle();
                        gamePlayer.addToHand(deck.draw(), i);
                    }
                }
            }

            std::cout << std::endl;
            std::cout << "<---- 手札交換後 ---->" << std::endl;
            std::cout << "あなたの手札   -> ";
            gamePlayer.printHand();
            std::cout << std::endl;
        }

        // 対戦相手と自分の役と役の強さを取得
        HandRole dealerHandRole = dealer.getHandRole();
        HandRole gamePlayerHandRole = gamePlayer.getHandRole();

        std::cout << "対戦相手の役    ->" << handRoleToString(dealerHandRole) << std::endl;
        std::cout << "あなたの役      ->" << handRoleToString(gamePlayerHandRole) << std::endl;

        // ラウンドの結果を表示
        std::cout << "\n" << "ラウンドの結果 -> ";
        if (gamePlayerHandRole > dealerHandRole) {
            std::cout << "あなたの勝ちです!!!" << std::endl;
        } else if (gamePlayerHandRole == dealerHandRole) {
            std::cout << "引き分けです" << std::endl;
        } else {
            std::cout << "あなたの負けです..." << std::endl;
        }

        // 対戦相手と自分の手札を初期化(std::unique_ptr<Card>をplayer.handからdiscardsに移動)
        while (!gamePlayer.getHand().empty()) {

            // discards.push_back(std::move(dealer.getDiscard()));
            // discards.push_back(std::move(gamePlayer.getDiscard()));

            //-> コンパイルエラー(下のエラーメッセージ)が出る
            // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
            // [with _Tp = Card; _Dp = std::default_delete<Card>]'

            // 一度変数にstd::unique_ptr<Card>の戻り値を格納してからdiscardsに追加するとコンパイルが通る

            auto dealerDiscard = dealer.getDiscard();
            auto gamePlayerDiscard = gamePlayer.getDiscard();

            discards.push_back(std::move(dealerDiscard));
            discards.push_back(std::move(gamePlayerDiscard));
        }

        std::cout << "残りの山札の枚数 -> " << deck.getDeck().size() << "枚だよー" << std::endl;
        std::cout << "捨てカードの枚数 -> " << discards.size() << "枚だよー" << std::endl;
        std::cout << std::endl;
    }

    // 再プレイ判定
    replayGame();
}

void Poker::initGame() {
    std::cout << "初期化処理を行います。" << std::endl;
    // デッキの初期化
    deck.init();
    deck.shuffle();
    // discardsの初期化
    discards.clear();
    // 対戦相手とプレイヤーの手札を初期化
    dealer.initHand();
    gamePlayer.initHand();
}

void Poker::distributeCard(Player &p) {
    const int distributeNum = 5;
    for (int i = 0; i < distributeNum; ++i) {
        if (deck.getDeck().size() > 0) {
            p.addToHand(deck.draw());
        } else {
            deck.reuse(std::move(discards));
            deck.shuffle();
            p.addToHand(deck.draw());
        }
    }
}

bool Poker::confirmCardTrade() {
    std::cout << "手札の中から不要なカードを捨てて、新しいカードをドローします"
                 "か? (1=Yes; 0=No)"
              << std::endl;
    int selectNum;
    std::cin >> selectNum;
    std::cout << std::endl;
    if (selectNum == 1) {
        return true;
    }
    return false;
}

std::array<bool, 5> Poker::selectDiscard() {
    std::array<bool, 5> isDiscardArr;
    isDiscardArr.fill(false);

    bool isContinue = true;
    do {
        std::cout << "交換するカードを選択してください (0 ~ "
                     "4の整数を入力してください)"
                  << std::endl;
        int selectIndex;
        std::cin >> selectIndex;
        if (selectIndex < isDiscardArr.size() && selectIndex >= 0) {
            isDiscardArr.at(selectIndex) = true;
        }

        std::cout << "他に交換するカードはありますか？ (1=Yes; 0=No)" << std::endl;
        int inputValue;
        std::cin >> inputValue;
        if (inputValue != 1) {
            isContinue = false;
        }
    } while (isContinue);

    return isDiscardArr;
}
