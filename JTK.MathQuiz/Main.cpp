

//Asignment 5 Math Quiz
//Jordan Klotz
//10/18/2025

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

void CreateQuestionsFile(string questionsPath)
{
	const int size = 10;
	string questions[size] = { "1 + 1", "2 * 3", "4 / 2", "5 - 3", "6 + 4", "8 * 2", "10 / 5", "7 - 2", "9 + 1", "3 * 5" };

	//create questions file and store array in it
	ofstream ofs;
	ofs.open(questionsPath);
	for (int i = 0; i < size; i++)
	{
		ofs << questions[i] << "\n";
	}

	ofs.close();
}

vector<string> StoreQuestionsVector()
{

}

int main()
{
	string questionsPath = "c:\\Temp\\Questions.txt";
	string quizResultsPath = "c:\\Temp\\QuizResults.txt";

	

	vector<string> storedQuestions;

	vector<string> results;



	CreateQuestionsFile(questionsPath);
	
	
	
	string question;

	ifstream ifs;
	ifs.open(questionsPath);
	while (getline(ifs, question))
	{
		storedQuestions.push_back(question);
	}
	
	ifs.close();

	for (const string& i : storedQuestions)
	{
		cout << i << "\n";
	}
	cout << "\n";


	//initialize the random number generator
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		// get a random number between 1 & 10
		int randomNumber = rand() % 10 + 1;

		string Q = (storedQuestions[(randomNumber - 1)] + " = ");
			cout << Q;
		string answer;
		cin >> answer;
		results.push_back(Q+answer);
		cout << "\n";
	}
	
	ofstream newofs;
	newofs.open(quizResultsPath);
	for (const string& j : results)
	{
		newofs << j << "\n";
	}

	newofs.close();
	
	

	(void)_getch();
	return 0;
}