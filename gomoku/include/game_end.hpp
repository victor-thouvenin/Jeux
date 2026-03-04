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
                msg = get_msg("error_general");
                break;
            case tie:
                msg = get_msg("tie");
                break;
            case p1_won:
                msg = get_msg("player1_win");
                break;
            case p2_won:
                msg = get_msg("player2_win");
                break;
        }
    };
    GameEnd(const gameState &s, char const *str) { st = s; msg = str; };
    ~GameEnd() = default;
    gameState const &state() const { return st; };
    const char *how() const { return msg.c_str(); };
private:
    gameState st;
    std::string msg;
};

