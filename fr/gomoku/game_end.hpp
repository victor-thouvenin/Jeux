#pragma once

#include "msg.hpp"

class GameEnd {
public:
    enum gameState {
        error = -1,
        tie = 0,
        p1_won = 1,
        p2_won = 2,
    };
    GameEnd(const gameState &s) {
        st = s;
        switch (st) {
            case error:
                msg = msg_list["error_general"];
                break;
            case tie:
                msg = msg_list["tie"];
                break;
            case p1_won:
                msg = msg_list["player1_win"];
                break;
            case p2_won:
                msg = msg_list["player2_win"];
                break;
        }
    };
    GameEnd(const gameState &s, char const *str) { st = s; msg = str; };
    ~GameEnd() = default;
    gameState const &state() { return st; };
    char const *how() { return msg; };
private:
    gameState st;
    char const *msg;
};

