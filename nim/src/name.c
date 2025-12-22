/*
** EPITECH PROJECT, 2018
** name.c
** File description:
** name
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../matchstick.h"
#include "../my_printf/print.h"

int check_confirm(void)
{
	char *confirm;

	confirm = get_next_line(0);
	if (confirm == NULL) {
		puterror("an error occured, please try again\n");
		return 0;
	} if (strcmp(confirm, "y") == 0)
		return 1;
	if (strcmp(confirm, "n") == 0)
		return -1;
	return 0;
}

int confirm_name(char *name, int i)
{
	if (name[0] == '\0')
		return 0;

	int c = 0;
	while (c == 0) {
		if (name[0] == '\n')
			my_printf("do you want to play as player%i[y/n]:", i + 1);
		else
			my_printf("do you want to play as %s[y/n]:", name);
		c = check_confirm();
	}
	return c;
}

char *set_basic_name(char *name, int i)
{
	name = realloc(name, 8);

	if (name == NULL) {
		puterror("an error occured, please try again\n");
		return NULL;
	}
	name[0] = 0;
	strcpy(name, "player");
	name[6] = i + '1';
	name[7] = 0;
	return name;
}

int check_name(char **name, int i, int c)
{
	int j = 0;

	if (c == 1 && (name[i][0] == '\n'))
		name[i] = set_basic_name(name[i], i);
	if (name[i] == NULL)
		return i;
	while (c == 1 && name[j]) {
		if (j != i && strcmp(name[j], name[i]) == 0) {
			write(2, "this name is not available\n", 28);
			c = -1;
		}
		++j;
	}
	if (c == -1) {
		free(name[i]);
		name[i] = NULL;
	}
	return (c == 1 ? i + 1 : i);
}

char **choose_name(int player)
{
	char **name = malloc(sizeof(char*)*(player+1));
	int i = 0;
	int c = 0;

	if (name == NULL)
		return NULL;
	name[0] = NULL;
	while (i < player) {
		if (name[i] == NULL) {
			my_printf("player%i enter your username (live empty for player%i):", i + 1, i + 1);
			name[i] = get_next_line(0);
			name[i+1] = NULL;
		}
		if (name[i] == NULL) {
        	puterror("an error occured");
			free_tab(name, i+1);
			get_next_line(-1);
			return NULL;
		}
		c = confirm_name(name[i], i);
		i = check_name(name, i, c);
	}
	name[i] = NULL;
	return name;
}
