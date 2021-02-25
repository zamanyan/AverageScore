#include <iostream>
#include <vector>

double AverageScore(const std::vector<int>& scores)
{
	int sum = 0;
	for (auto it = scores.begin(); it != scores.end(); it++) {
		sum += *it;
	}
	int number_of_students = scores.size();
	return static_cast<double>(sum) / number_of_students;
}


void PrintVector(const std::vector<int>& vec)
{
	for (auto item : vec) {
		std::cout << item << ' ';
	}
}


int main()
{
	int number;
	do {
		std::cout << "number of students: ";
		std::cin >> number;
	} while (number < 2);
	
	std::vector<int> scores(number);
	int score;
	int student_number = 0;
	std::cout << "Input Scores:\n";
	while (student_number < number) {
		do {
			std::cout << "student " << student_number + 1 << ": ";
			std::cin >> score;
		} while (score < 0 || score > 100);
		scores[student_number] = score;
		student_number++;
	}

	double average_score = AverageScore(scores);
	std::cout << "Average_Score: " << average_score << std::endl;

	int highers = 0;
	for (auto i = 0; i < scores.size(); i++) {
		if (scores[i] > average_score) {
			std::cout << "student " << i << ": " << scores[i] << std::endl;
			highers++;
		}
	}

	std::cout << "The total number of students above average is: " << highers
		<< std::endl;

	return 0;
}