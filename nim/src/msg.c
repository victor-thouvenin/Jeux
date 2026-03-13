#include <string.h>
#include "../nim.h"

// char *lang = "fr";
// char *langs[LANG_NUM] = {"fr", "en"};

const struct msg_list msg_list[] = {
    {"command_stop", {
        {"en", "end"},
        {"fr", ""}}
    }, {"ask_line", {
        {"en", "Line: "},
        {"fr", ""}}
    }, {"ask_match", {
        {"en", "Matches: "},
        {"fr", ""}}
    },

    {"player_name", {
        {"en", "player"},
        {"fr", ""}}
    }, {"player_turn", {
        {"en", "\nYour turn:"},
        {"fr", ""}}
    }, {"player_played", {
        {"en", "%s removed %i match(es) from line %i\n"},
        {"fr", ""}}
    }, {"player_lost", {
        {"en", "You lost, too bad..."},
        {"fr", ""}}
    }, {"AI_turn", {
        {"en", "\nAI's turn..."},
        {"fr", ""}}
    }, {"AI_played", {
        {"en", "AI removed %d match(es) from line %d\n"},
        {"fr", ""}}
    }, {"AI_lost", {
        {"en", "I lost... snif... but I'll get you next time!!"},
        {"fr", ""}}
    },

    {"multi-player_name", {
        {"en", "player%i enter your username (live empty for player%i): "},
        {"fr", ""}}
    }, {"multi-player_name_confirm", {
        {"en", "do you want to play as %s[y/n]: "},
        {"fr", ""}}
    }, {"multi-player_name_blank_confirm", {
        {"en", "do you want to play as player%i[y/n]: "},
        {"fr", ""}}
    }, {"multi-player_turn", {
        {"en", "\n%s's turn:\n"},
        {"fr", ""}}
    }, {"multi-player_lost", {
        {"en", "\n%s lost\n"},
        {"fr", ""}}
    }, {"multi-player_gave_up", {
        {"en", "\n%s gave up\n"},
        {"fr", ""}}
    }, {"multi-players_win", {
        {"en", "\n%s win\n"},
        {"fr", ""}}
    }, {"multi-players_remaining", {
        {"en", "\n%i players remaining\n\n"},
        {"fr", ""}}
    },

    {"error_player_name_taken", {
        {"en", "this name is not available\n"},
        {"fr", ""}}
    }, {"error_input", {
        {"en", "Error: invalid input (positive integer expected)\n"},
        {"fr", ""}}
    }, {"error_line_out_of_range", {
        {"en", "Error: this line is out of range\n"},
        {"fr", ""}}
    }, {"error_no_remove", {
        {"en", "Error: you have to remove at least one match\n"},
        {"fr", ""}}
    }, {"error_too_much_remove", {
        {"en", "Error: you cannot remove more than %u matches per turn\n"},
        {"fr", ""}}
    }, {"error_not_enough_matches", {
        {"en", "Error: not enough matches on this line\n"},
        {"fr", ""}}
    }, {"error_memory", {
        {"en", "an error occured\n"},
        {"fr", ""}}
    }, {"error_general_try_again", {
        {"en", "an error occured, please try again\n"},
        {"fr", ""}}
    }, {"error_general", {
        {"en", "an error occured\n"},
        {"fr", ""}}
    },

    {"error_missing_parameter", {
        {"en", "ERROR: between 1 and 3 arguments needed got %i\n"},
        {"fr", ""}}
    }, {"error_line", {
        {"en", "ERROR: number of line must be a integer between 2 and 99\n"},
        {"fr", ""}}
    }, {"error_match", {
        {"en", "ERROR: maximum match removal number must be a integer greater than 1\n"},
        {"fr", ""}}
    }, {"error_multi", {
        {"en", "ERROR: number of player must be a integer between 1 and 9\n"},
        {"fr", ""}}
    }, {NULL, {}}
};

const char *get_msg(const char *str) {
    const struct msg_list *list = msg_list;
    while (list->ind != NULL) {
        if (strcmp(list->ind, str) == 0)
            break;
        ++list;
    }
    if (list->ind == NULL)
        return "";

    // int j = 0;
    // while (j < LANG_NUM) {
    //     if (strcmp(list[i].lang, lang) == 0)
    //         break;
    // }
    // if (j == LANG_NUM)
    //     return "";

    return list->list[0].msg;
}