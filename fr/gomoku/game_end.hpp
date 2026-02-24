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
                msg = msg_list["error_general"].c_str();
                break;
            case tie:
                msg = msg_list["tie"].c_str();
                break;
            case p1_won:
                msg = msg_list["player1_win"].c_str();
                break;
            case p2_won:
                msg = msg_list["player2_win"].c_str();
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

