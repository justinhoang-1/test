/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   :Justin Hoang
	ID     :021569132
	Email  :jhoang11@myseneca.ca
	Section:NCC
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define GAME_MULTIPLIER 5

struct PlayerInfo
{
	int playerLives;
	int treasureCount;
	char playerSym;
	int currentMove;

};
struct GameInfo
{
	int gameLength;
	int gameMoves;
	int bombInput[MAX_PATH_LENGTH];
	int treasureInput[MAX_PATH_LENGTH];
	char revealedPosition[MAX_PATH_LENGTH];

};

int main(void)
{
	struct PlayerInfo playerData = { 0 };
	struct GameInfo gameSettings = { 0 };

	const double setPercentage = 0.75;
	int maxMoves;
	int a, b;
	char hiddenPosition = '-';

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &playerData.playerSym);

	a = 0;
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &playerData.playerLives);

		if (playerData.playerLives >= 1 && playerData.playerLives <= 10)
		{
			printf("Player configuration set-up is complete\n\n");
			a++;
		}
		else
		{
			printf("     Must be between 1 and 10!\n");
		}
	} while (a < 1);

	printf("GAME Configuration\n");
	printf("------------------\n");
	a = 0;
	do
	{
		printf("Set the path length (a multiple of 5 between %d-%d): ", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		scanf("%d", &gameSettings.gameLength);
		if (gameSettings.gameLength >= MIN_PATH_LENGTH && gameSettings.gameLength <= MAX_PATH_LENGTH && ((gameSettings.gameLength % GAME_MULTIPLIER) == 0))
		{
			a++;
		}
		else
		{
			printf("     Must be a multiple of 5 and between %d-%d!!!\n", MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		}
	} while (a < 1);

	a = 0;
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameSettings.gameMoves);
		maxMoves = (gameSettings.gameLength * setPercentage);
		if (gameSettings.gameMoves < playerData.playerLives || gameSettings.gameMoves > maxMoves)
		{
			printf("    Value must be between %d and %d\n", playerData.playerLives, maxMoves);
		}
		else
		{
			printf("\n");
			a++;
		}
	} while (a < 1);

	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameSettings.gameLength);
	for (a = 0; a < (gameSettings.gameLength); a = a + 5)
	{
		printf("   Positions [%2d-%2d]: ", a + 1, a + 5);
		scanf("%d %d %d %d %d", &gameSettings.bombInput[a], &gameSettings.bombInput[a + 1], &gameSettings.bombInput[a + 2], &gameSettings.bombInput[a + 3], &gameSettings.bombInput[a + 4]);

	}
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameSettings.gameLength);
	for (a = 0; a < (gameSettings.gameLength); a = a + 5)
	{
		printf("   Positions [%2d-%2d]: ", a + 1, a + 5);
		scanf("%d %d %d %d %d", &gameSettings.treasureInput[a], &gameSettings.treasureInput[a + 1], &gameSettings.treasureInput[a + 2], &gameSettings.treasureInput[a + 3], &gameSettings.treasureInput[a + 4]);
	}
	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", playerData.playerSym);
	printf("   Lives      : %d\n", playerData.playerLives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", gameSettings.gameLength);
	printf("   Bombs      : ");
	for (a = 0; a < (gameSettings.gameLength); a++)
	{
		printf("%d", gameSettings.bombInput[a]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (a = 0; a < (gameSettings.gameLength); a++)
	{
		printf("%d", gameSettings.treasureInput[a]);
	}

	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");
	
	do
	{
		printf("   ");
		for (a = 1; a < (playerData.currentMove + 1); a++)
		{
			if (a != playerData.currentMove)
			{
				printf(" ");
			}
			else if (playerData.currentMove == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%c\n", playerData.playerSym);
			}
		}
		
		if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove] == 0)//bomb
		{
			gameSettings.revealedPosition[playerData.currentMove] = '!';
		}
		else if (gameSettings.treasureInput[playerData.currentMove] == 1 && gameSettings.bombInput[playerData.currentMove] == 0)//treasure
		{
			gameSettings.revealedPosition[playerData.currentMove] = '$';
		}
		else if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove ] == 1)// bomb and treasure
		{
			gameSettings.revealedPosition[playerData.currentMove] = '&';
		}
		else if (gameSettings.bombInput[playerData.currentMove ] == 0 && gameSettings.treasureInput[playerData.currentMove] == 0) //nothing
		{
			gameSettings.revealedPosition[playerData.currentMove] = '.';
		}
		
		if (playerData.currentMove == 0)
		{
			for (a = 0; a < (gameSettings.gameLength); a++)
			{
				printf("%c", hiddenPosition);
				gameSettings.revealedPosition[a] = hiddenPosition;
			}
		}
		else
		{
			printf("   ");
			for (a = 0; a < (gameSettings.gameLength); a++)
			{
				printf("%c", gameSettings.revealedPosition[a]);
			}
		}
		printf("\n   ");
		for (a = 1, b = 1; a <= gameSettings.gameLength; a++)
		{
			if (a % 10 == 0)
			{
				printf("%d", b);
				b++;
			}
			else
			{
				printf("|");
			}
		}
		printf("\n   ");
		for (a = 1, b = 1; a <= gameSettings.gameLength; a++)
		{
			if (a % 10 == 0)
			{
				printf("0");
				b = 1;
			}
			else
			{
				printf("%d", b);
				b++;
			}
		}

		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", playerData.playerLives, playerData.treasureCount, gameSettings.gameMoves);
		printf("+---------------------------------------------------+\n");
		
		do
		{
			a = 0;
			printf("Next Move [1-%d]: ", gameSettings.gameLength);
			scanf("%d", &playerData.currentMove);
			if (playerData.currentMove >= 1 && playerData.currentMove <= gameSettings.gameLength)
			{
				printf("\n");
				a++;
			}
			else
			{
				printf("  Out of Range!!!\n");
			}
		} while (a < 1);

		if (gameSettings.revealedPosition[playerData.currentMove] == '-')
		{
			if (gameSettings.bombInput[playerData.currentMove] == 0 && gameSettings.treasureInput[playerData.currentMove] == 0)
			{
				printf("===============> [.] ...Nothing found here... [.]\n\n");
				gameSettings.gameMoves -= 1;
			}
			else if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove] == 0)
			{
				printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
				playerData.playerLives -= 1;
				gameSettings.gameMoves -= 1;
			}
			else if (gameSettings.treasureInput[playerData.currentMove] == 1 && gameSettings.bombInput[playerData.currentMove] == 0)
			{
				printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				playerData.treasureCount += 1;
				gameSettings.gameMoves -= 1;
			}
			else if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove] == 1)
			{
				printf("===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				gameSettings.gameMoves -= 1;
				playerData.treasureCount += 1;
				playerData.playerLives -= 1;
			}
		}
		else
		{
			printf("===============> Dope! You've been here before!\n\n");
		}
	}while (playerData.playerLives != 0 && gameSettings.gameMoves != 0);

	printf("No more LIVES remaining!\n\n");
	
	printf("   ");
	for (a = 1; a < (playerData.currentMove + 1); a++)
	{
		if (a != playerData.currentMove)
		{
			printf(" ");
		}
		else if (playerData.currentMove == 0)
		{
			printf(" ");
		}
		else
		{
			printf("%c\n", playerData.playerSym);
		}
	}

	if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove] == 0)//bomb
	{
		gameSettings.revealedPosition[playerData.currentMove] = '!';
	}
	else if (gameSettings.treasureInput[playerData.currentMove] == 1 && gameSettings.bombInput[playerData.currentMove] == 0)//treasure
	{
		gameSettings.revealedPosition[playerData.currentMove] = '$';
	}
	else if (gameSettings.bombInput[playerData.currentMove] == 1 && gameSettings.treasureInput[playerData.currentMove] == 1)// bomb and treasure
	{
		gameSettings.revealedPosition[playerData.currentMove] = '&';
	}
	else if (gameSettings.bombInput[playerData.currentMove] == 0 && gameSettings.treasureInput[playerData.currentMove] == 0) //nothing
	{
		gameSettings.revealedPosition[playerData.currentMove] = '.';
	}

	if (playerData.currentMove == 0)
	{
		for (a = 1; a < (gameSettings.gameLength + 1); a++)
		{
			printf("%c", hiddenPosition);
			gameSettings.revealedPosition[a] = hiddenPosition;
		}
	}
	else
	{
		printf("   ");
		for (a = 1; a < (gameSettings.gameLength + 1); a++)
		{
			printf("%c", gameSettings.revealedPosition[a]);
		}
	}
	printf("\n   ");
	for (a = 1, b = 1; a <= gameSettings.gameLength; a++)
	{
		if (a % 10 == 0)
		{
			printf("%d", b);
			b++;
		}
		else
		{
			printf("|");
		}
	}
	printf("\n   ");
	for (a = 1, b = 1; a <= gameSettings.gameLength; a++)
	{
		if (a % 10 == 0)
		{
			printf("0");
			b = 1;
		}
		else
		{
			printf("%d", b);
			b++;
		}
	}
	
	printf("\n");
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", playerData.playerLives, playerData.treasureCount, gameSettings.gameMoves);
	printf("+---------------------------------------------------+\n\n");

	printf("##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!!\n");
	
	return 0;
}

