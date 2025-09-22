

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
		ofs << questions[i] << "\n";//write contents of the questions array to a file
	}

	ofs.close();//close writer
}


int main()
{
	string questionsPath = "c:\\Temp\\Questions.txt";
	string quizResultsPath = "c:\\Temp\\QuizResults.txt";

	
	//vector to hold quiz questions
	vector<string> storedQuestions;
	//vector to hold users response to the question
	vector<string> results;


	//create questions file
	CreateQuestionsFile(questionsPath);

	
	
	string question;//to store the question

	ifstream ifs;//create reader
	ifs.open(questionsPath);//open file
	while (getline(ifs, question))//read each line and store it in the question variable
	{
		storedQuestions.push_back(question);//store the question to a vector
	}
	
	ifs.close();//close the reader
	

	//initialize the random number generator
	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		// get a random number between 1 & 10
		int randomNumber = rand() % 10 + 1;
		string answer;//to store the users answer as a string
		string Q = (storedQuestions[(randomNumber - 1)] + " = ");//to store the quiz question
		cout << "Question " << (i+1) << ": " + Q + "\n";
		cout << "Enter your answer: ";
		cin >> answer; 
		results.push_back(Q+answer);//add question and users answer to vector
		cout << "\n";

		if (i == 2)//display after the final question
		{
			cout << "Results saved to QuizResults.txt";
		}
	}
	
	ofstream ofs;//create writer
	ofs.open(quizResultsPath);//open file
	for (const string& j : results)//write contents of the vector to the file
	{
		ofs << j << "\n";
	}

	ofs.close();//close writer
	
	

	(void)_getch();
	return 0;
}