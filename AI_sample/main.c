#include "ai_header.h"

int main(void)
{
	//Uusr = 1
	//AI = 2
	//Empty = 0
	int **map = NULL;
	int i, k;
	map = (int**)malloc(sizeof(int*) * 6);
	for (i = 0; i < 6; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * 7);
	}
	for (i = 0; i < 6; i++)
	{
		for (k = 0; k < 7; k++)
			map[i][k] = 0;
	}
	int decide_exit = 100;
	int first;
	int select_ai_search_or_rule;
	int user_turn_x;

	printf("Who start first? 1 -> user 2 -> AI\n");
	scanf("%d", &first);
	print_map(map);

	if (first == 1)
	{
		while (1)
		{
			
			printf("inert location x : ");
			scanf("%d", &user_turn_x);

			user_select(map, --user_turn_x);
			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == USERWIN)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == AIWIN)
			{
				printf("AI Win!\n");
				return 0;
			}

			printf("Select which ai version to use. search algorithm = 1, rule =2\n");
			scanf("%d", &select_ai_search_or_rule);

			if (select_ai_search_or_rule == 1)
				ai_search_function(map);
			else if (select_ai_search_or_rule == 2)
				ai_rule_function(map);
			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == USERWIN)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == AIWIN)
			{
				printf("AI Win!\n");
				return 0;
			}
		}
	}
	else if (first == 2)
	{
		while (1)
		{
			print_map(map);
			printf("Select which ai version to use. search algorithm = 1, rule =2\n");
			scanf("%d", &select_ai_search_or_rule);

			if (select_ai_search_or_rule == 1)
				ai_search_function(map);
			else if (select_ai_search_or_rule == 2)
				ai_rule_function(map);

			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == USERWIN)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == AIWIN)
			{
				printf("AI Win!\n");
				return 0;
			}

			printf("inert location x : ");
			scanf("%d", &user_turn_x);

			user_select(map, --user_turn_x);

			print_map(map);

			decide_exit = decide_win_or_lose_or_continue(map);

			if (decide_exit == USERWIN)
			{
				printf("User Win!\n");
				return 0;
			}
			else if (decide_exit == AIWIN)
			{
				printf("AI Win!\n");
				return 0;
			}
		}
	}

	return 0;
}

void user_select(int **map, int number)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (map[i][number] == 0)
		{
			map[i][number] = 1;
			return;
		}
		if (i == 5)
			printf("Wrong place!\n");
	}
}