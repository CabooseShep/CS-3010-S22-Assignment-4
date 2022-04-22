/* Nicholas Hortua
   Prof. Edwin Rodriguez, CS 3010 - Spring 2022
   Assignment 4, Exercise 3

   main.cpp - Driver program responsible for asking the user to prompt the value to be used for evaluating the obtained polynomial.
*/

#include <iostream>
#include <vector>
#include <string>

#include "polyInput.hpp"
#include "newtonInterpolation.hpp"

using namespace std;

int main()
{
	int input_eval = 0;
	double final_value = 0.0;
	string input;
	vector<double> x_numbers{};
	vector<double> y_numbers{};
	vector<double> c_numbers{};

	cout << "=== Newton's Interpolation Program == \n \n";

	file_Reading(x_numbers, y_numbers);
	
	newton_method(x_numbers, y_numbers, c_numbers);
	cout << "Polynomial function successfully created! \n \n";
	cout << "Please enter the value you wish to evaluate the polynomial with (enter 'q' to exit the program): ";

	cin >> input;
	cout << "\n \n";

	
	if (input != "q")
	{
		try
		{
			input_eval = stoi(input); 
		}

		// will default to this if any characters besides q by itself are inputted
		
		catch (exception& e)
		{
			cout << "Invalid input entered, exiting program... \n ";
			exit(EXIT_FAILURE);
		}

		final_value = newton_evaluation(x_numbers, c_numbers, input_eval);

		cout << "Value obtained at x = " << input_eval << ": " << final_value;
		cout << "\n \n";

	}

	return 0;

}
