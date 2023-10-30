
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;
int main()
{
	queue<string>q;
	queue<int>q8;
	queue<int>q9;
	int s;
	cout << "\nEnter how many players will play game : ";
	cin >> s;
   
   	while(1)
	{
		if(s>=2)
		{
			break;
		}
		else
		{
			cout<<"\nInvalid Number of Players\nMinimum 2 players can play the game\nEnter again the number of player :";
			cin>>s;
		}
	}
	queue<int> q1;
	for (int i = 0; i < s; i++)
	{

		q1.push(0);
		q8.push(0);
		q9.push(0);
	}
	for (int i = 0; i < s; i++)
	{
		cout << "Enter  " << i + 1 << " player name: ";
		string s;
		cin >> s;
		q.push(s);
		cout << endl;
	}
	queue<string>q7 = q;
	cout << "Players you selected are and their currunt score\n";
	while (!q7.empty())
	{
		cout << q7.front() << " :" << q1.front() << endl;
		q1.pop();
		q7.pop();
	}

	int a;
	int c = 0;
	queue<string>q3;
	srand(time(0));
	bool chk2 = 0;
	while (chk2 != 1)
	{
		queue<string>q6 = q;
		q1 = q9;
		q8 = q1;
		while (!q9.empty())
		{
			q9.pop();
		}
		for (int i = 0; i < q.size(); i++)
		{
			if (c == (q.size()) - 1)
			{
				chk2 = 1;
				break;
			}
			if (q8.front() == 100)
			{
				q9.push(q8.front());
				q6.pop();
				q8.pop();
				continue;
			}
			cout << "\nIts " << q6.front() << " turns, Please enter any key to continue\n";
			 getch();
			a = rand() % 6 + 1;
			cout << q6.front() << " got " << a << endl;
			if (q8.front() + a > 100)
			{
				q9.push(q8.front());
				cout << "\ntry in next turn";
				cout << "\nTotal score of " << q6.front() << " is " << q8.front() << endl;
			}

			// For ladder
			else if (q8.front() + a == 20 || q8.front() + a == 60)
			{
				if (q8.front() + a == 20)
				{
					cout << "\nWoW! You got a ladder at 20";
					q8.front() = 40;
				}
				else
				{
					cout << "\nWoW! You got a ladder at 60";
					q8.front() = 75;
				}
				cout << "\nTotal score of " << q6.front() << " is " << q8.front() << endl;
				q9.push(q8.front());
			}

			// for snake

			else if (q8.front() + a == 50 || q8.front() + a == 90)
			{
				if (q8.front() + a == 50)
				{
					cout << "\nOOPS! You are bitten by snake at 50";
					q8.front() = 40;
				}
				else
				{
					cout << "\nOOPS! You are bitten by snake at 90";
					q8.front() = 79;
				}
				cout << "\nTotal score of " << q6.front() << " is " << q8.front() << endl;
				q9.push(q8.front());
			}

			else if (q8.front() + a == 100)
			{
				q8.front() += a;
				q9.push(q8.front());
				cout << q6.front() << " You won!\n";
				q3.push(q6.front());
				c++;
			}

			else
			{
				q8.front() += a;
				cout << "\nTotal score of " << q6.front() << " is " << q8.front() << endl;
				q9.push(q8.front());
			}
			q6.pop();
			q8.pop();
		}
	}
	cout << "\nNow we will decide the positions of Players \n";

	cout << "Winners are\n";
	int k = 1;
	queue<string>q10 = q3;
	while (!q10.empty())
	{
		cout << k << "  " << q10.front() << endl;
		q10.pop();
		k++;
	}

	// checking and inserting looser at last
	cout<<"\n\n---------------\n\n";
	bool chk = 0;
		queue<string>q5 = q;
		while (!q5.empty())
		{
			queue<string>q4 = q3;
			bool ck = 0;
			while (!q4.empty())
			{
				if (q5.front() == q4.front())
				{
					ck=1;
				}
				q4.pop();
			}
			if (ck == 0)
			{
				q3.push(q5.front());
				chk = 1;
				break;
			}
			ck=0;
			q5.pop();
		}
	

	cout << "Positons of players are\n";
	int g = 1;
	while (!q3.empty())
	{
		cout << k << "  " << q3.front() << endl;
		q3.pop();
		g++;
	}

	system("pause");
	return 0;
}