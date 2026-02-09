#include <iostream>
#include <string>
using namespace std;

enum enChoice
{
	rock = 1, paper = 2, scissors = 3
};
enum enResult
{
	player = 1, computer = 2, draw = 3
};

void indentConsole()
{
	cout << "\n\t\t\t\t";
}

int readNumberOfRounds()
{
	int number;
	do
	{

		cout << "How many rounds from 1 to 10" << '\n';
		cin >> number;
	} while (number <= 0 || number > 10);
	return number;
}

int randomNumber(int from, int to)
{
	return rand() % (to - from + 1) + from;
}

void showGameOver(short rounds, short computerWon, short playerWon, short drawTimes)
{
	indentConsole();
	cout << "_____________________________________________";
	indentConsole();
	cout << "          ++ + G a m e  O v e r +++          ";
	indentConsole();
	cout << "_____________________________________________";
	indentConsole();
	cout << "______________ [ Game Result ] ______________";
	indentConsole();
	cout << "Game rounds: " << rounds;
	indentConsole();
	cout << "Player1 winning times" << playerWon;
	indentConsole();
	cout << "Computer winning times" << computerWon;
	indentConsole();
	cout << "Draw times" << drawTimes;
	indentConsole();
	string finalWinner;
	if (playerWon > computerWon) finalWinner = "Player1";
	else
	{
		if (playerWon == computerWon) finalWinner = "No winner";
		else finalWinner = "Computer";
	}
	cout << "Final Winner: " << finalWinner;
	indentConsole();




}

bool readReplayChoice()
{
	char choice;
	cout << "Do you want to play again ? (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		system("cls");
		return true;
	}
	else
	{
		return false;
	}
}

enChoice readPlayerChoice()
{
	short choice;
	do
	{
	cout << "\nYour Choice: [1]: Rock, [2]: Paper, [3]: Scissors:\n";
	cin >> choice;
	if (choice <=0 || choice > 3)
	{
		cout << "Invalid choice, please try again\n\n";
	}
	else
	{
		return (enChoice)choice;
	}

	} while (true);
}

string convertChoiceToString(enChoice choice)
{
	switch (choice)
	{
	case rock:
		return "Rock";
		break;
	case paper:
		return "Paper";
		break;
	case scissors:
		return "Scissors";
		break;
	default:
		break;
	}
}

enResult getWinner(enChoice playerChoice, enChoice computerChoice)
{
	if (playerChoice == computerChoice)
	{
		return enResult::draw;
	}
	else
	{
		if (playerChoice == enChoice::rock)
		{
			if (computerChoice == enChoice::paper) return enResult::computer;
			else return enResult::player;

		}
		else
		{
			if (computerChoice == enChoice::paper) return enResult::player;
			else return enResult::computer;
		}

	}
}

void playRound(short round, short& computerWon, short& playerWon, short& drawTimes)
{
	cout << "Round [" << round << "] begins:";
	enChoice playerChoice = readPlayerChoice();
	enChoice computerChoice = (enChoice)randomNumber(1, 3);
	string playerChoiceName = convertChoiceToString(playerChoice);
	string computerChoiceName = convertChoiceToString(computerChoice);
	enResult result = getWinner(playerChoice, computerChoice);
	cout << "__________ Round [" << round << "] __________\n";
	cout << "Player1  Choice: " << playerChoiceName << '\n';
	cout << "Computer Choice: " << computerChoiceName << '\n';
	cout << "Round Winner   : " ;
	switch (result)
	{
	case player:
		cout << "[Player1]";
		playerWon++;
		system("color 20"); //green

		break;
	case computer:
		cout << "\a[Computer]";
		computerWon++;
		system("color 40"); //red

		break;
	case draw:
		cout << "[No Winner]";
		drawTimes++;
		system("color 60"); //yellow

		break;
	default:
		break;
	}
	cout << "\n_____________________________\n\n";
}

void startGame()
{
	short rounds, computerWon, playerWon, drawTimes;
	bool choice = true;

	while (choice)
	{
		system("color 0f");
		computerWon = 0;
		playerWon = 0;
		drawTimes = 0;

		rounds = readNumberOfRounds();
		for (int i = 0; i < rounds; i++)
		{
			playRound(i + 1, computerWon, playerWon, drawTimes);
		}
		showGameOver(rounds, computerWon, playerWon, drawTimes);
		choice = readReplayChoice();
	}
}


int main()
{
	srand((unsigned)time(NULL));
	startGame();



}