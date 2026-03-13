/*
** EPITECH PROJECT, 2018
** name.c
** File description:
** name
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../nim.h"

int check_confirm(void)
{
	char *confirm;

	confirm = get_next_line(0);
	if (confirm == NULL) {
		fputs(get_msg("error_general_try_again"), stderr);
		return -1;
	} if (strcmp(confirm, "y") == 0)
		return 1;
	if (strcmp(confirm, "n") == 0)
		return -1;
	return 0;
}

int confirm_name(char *name, int i)
{
	int c = 0;
	while (c == 0) {
		if (name[0] == '\n')
			printf(get_msg("multi-player_name_blank_confirm"), i + 1);
		else
			printf(get_msg("multi-player_name_confirm"), name);
		fflush(stdout);
		c = check_confirm();
	}
	if (c == -1) {
		return 0;
	}
	return 1;
}

char *set_basic_name(char *name, int i)
{
	name = realloc(name, 8);
	if (name == NULL) {
		fputs(get_msg("error_general_try_again"), stderr);
		return NULL;
	}

	name[0] = 0;
	strcpy(name, get_msg("player_name"));
	name[6] = i + '1';
	name[7] = 0;
	return name;
}

int check_name(char **name, int i)
{
	if (name[i][0] == '\n')
		name[i] = set_basic_name(name[i], i);
	if (name[i] == NULL)
		return 0;

	int j = 0;
	while (j < i) {
		if (strcmp(name[j], name[i]) == 0) {
			fputs(get_msg("error_player_name_taken"), stderr);
			return 0;
		}
		++j;
	}
	return 1;
}

char **choose_name(int player)
{
	char **name = malloc(sizeof(char*)*(player+1));
	int i = 0;

	if (name == NULL)
		return NULL;
	name[0] = NULL;
	while (i < player) {
		if (name[i] == NULL) {
			printf(get_msg("multi-player_name"), i + 1, i + 1);
			fflush(stdout);
			name[i] = get_next_line(0);
			name[i+1] = NULL;
		}
		if (name[i] == NULL) {
			free_tab(name, i+1);
			get_next_line(-1);
			return NULL;
		}
		if (confirm_name(name[i], i) && check_name(name, i))
			++i;
		else {
			free(name[i]);
			name[i] = NULL;
		}
	}
	name[i] = NULL;
	return name;
}
