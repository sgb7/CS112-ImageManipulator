#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <random>
#include <cmath>

using namespace std;

void split_string(string const& str, const char delim, vector<string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void string_to_int(string const& the_string, vector<int> & int_vector)
{
	int number;
	char delim = ' ';
	vector<string> out;
	split_string(the_string, delim, out);
	for (int i = 0; i < out.size(); i++)
	{
		istringstream iss(out[i]);
		iss >> number;
		int_vector.push_back(number);
		if (iss.fail())
		{
			cout << "something went wrong" << endl;
		}
	}
	// Okay, so something went wrong with this function -- at least I'm assuming that's where
	// the issue was -- on my laptop, but it worked fine on one of the school's computers, so I 
	// think everything should be okay? Just a note just in case.
}


int main()
{
	vector<string> data;
	vector<int> int_data;
	vector<vector<int>> vector_squared;

	cout << "Please enter source file name here: " << endl;
	string source_file_name;
	cin >> source_file_name;

	cout << "Please enter destination file name here: " << endl;
	string destination_file_name;
	cin >> destination_file_name;

	ifstream ppm_file;
	ppm_file.open(source_file_name);
	string line;

	cout << "Possible image effects: " << endl
		<< "1. Remove red" << endl
		<< "2. Remove green" << endl
		<< "3. Remove blue" << endl
		<< "4. Negate red" << endl
		<< "5. Negate green" << endl
		<< "6. Negate blue" << endl
		<< "7. Grayscale" << endl
		<< "8. Add noise" << endl
		<< "9. High contrast" << endl
		<< "10. Flip horizontally" << endl
		<< "11. Flip vertically" << endl
		<< "12. Blur" << endl
		<< "13. Pixelate" << endl
		<< "14. Rotate 90 degrees" << endl << endl;
	cout << "Please enter desired effect number here: " << endl;
	int desired_effect;
	cin >> desired_effect;

	if (ppm_file.fail())
	{
		cout << "Can not open file.";
	}
	else
	{
		string line;
		while (ppm_file.good() == true)
		{
			getline(ppm_file, line);
			data.push_back(line);
		}

		for (int i = 3; i < data.size(); i++)
		{
			vector<int> temp_vector;
			string_to_int(data[i], temp_vector);
			for (int i = 0; i < temp_vector.size(); i++)
			{
				// Change code here to use a two-dimensional vector?
				// Each line is 15 numbers
				// So a for loop with an int i=0, i < 14, i++ ? Test it.
				int_data.push_back(temp_vector[i]);
			}
		}

		//Insert 2D vector here? I think?
		int width = 750;
		vector<int> temp_vector;

		for (int i = 0; i < int_data.size(); i++)
		{
			if ((i + 1) % width == 0)
			{
				temp_vector.push_back(int_data[i]);
				vector_squared.push_back(temp_vector);
				temp_vector = vector<int>{};
			}
			else
			{
				temp_vector.push_back(int_data[i]);
			}

		}

		/*for(int i = 0; i < vector_squared.size(); i++)
		{
			for(int j = 0; j < vector_squared[i].size(); j++)
			{
				cout << "location "<< i << "-" << j << ": " << vector_squared[i][j] << endl;
			}
		}*/


		while (desired_effect != 0)
		{
			switch (desired_effect)
			{
			case 1:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if (j % 3 == 0)
						{
							vector_squared[i][j] = 0;
						}
					}
				}
				break;
			case 2:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if ((j + 2) % 3 == 0)
						{
							vector_squared[i][j] = 0;
						}
					}
				}
				break;
			case 3:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if ((j + 1) % 3 == 0)
						{
							vector_squared[i][j] = 0;
						}
					}
				}
				break;
			case 4:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if (j % 3 == 0)
						{
							vector_squared[i][j] = 255 - vector_squared[i][j];
						}
					}
				}
				break;
			case 5:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if ((j + 2) % 3 == 0)
						{
							vector_squared[i][j] = 255 - vector_squared[i][j];
						}
					}
				}
				break;
			case 6:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if ((j + 1) % 3 == 0)
						{
							vector_squared[i][j] = 255 - vector_squared[i][j];
						}
					}
				}
				break;
			case 7:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if ((j + 1) % 3 == 0)
						{
							int avg_value = (vector_squared[i][j] + vector_squared[i][j - 1] + vector_squared[i][j - 2]) / 3;
							vector_squared[i][j] = avg_value;
							vector_squared[i][j - 1] = avg_value;
							vector_squared[i][j - 2] = avg_value;
						}
					}
				}
				break;
			case 8:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						random_device dev;
						mt19937 rng(dev());
						uniform_int_distribution<mt19937::result_type> dist(-10, 10);
						int random_number = dist(rng);
						int changed_value = vector_squared[i][j] + random_number;
						if (changed_value > 255)
						{
							vector_squared[i][j] = 255;
						}
						else if (changed_value < 0)
						{
							vector_squared[i][j] = 0;
						}
						else
						{
							vector_squared[i][j] = changed_value;
						}
					}
				}
				break;
			case 9:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						if (vector_squared[i][j] > (255 / 2))
						{
							vector_squared[i][j] = 255;
						}
						else
						{
							vector_squared[i][j] = 0;
						}
					}
				}
				break;
			case 10:
				for (int i = 0; i < vector_squared.size(); i++)
				{
					reverse(vector_squared[i].begin(), vector_squared[i].end());
				}
				break;
			case 11:
				reverse(vector_squared.begin(), vector_squared.end());
				break;
			case 12:
				// Set red, blue and green values to the average of the red, green and blue
				// values immediately close to them, both horizontally and vertically.
				// Could have a row avg and a column avg
				// But how would I apply that? That is, which avg comes first? Row or column?
				// Or do I apply them at the same time? Can I apply them at the same time?
				// First things first, we want to run through the numbers, and affect the red,
				// green and blue values individually. 
				for (int i = 0; i < vector_squared.size(); i++)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						// TO DO
					}
				}

				break;
			case 13:
				for (int i = 0; i < vector_squared.size(); i + 2)
				{
					for (int j = 0; j < vector_squared[i].size(); j++)
					{
						int red_ref;
						int green_ref;
						int blue_ref;
						if (j % 3 == 0)
						{
							if (j % 6 == 0)
							{
								red_ref = vector_squared[i][j];
							}
							vector_squared[i][j] = red_ref;
						}
						else if ((j + 2) % 3 == 0)
						{
							if (j % 7 == 0)
							{
								green_ref = vector_squared[i][j];
							}
							vector_squared[]
						}

						int red = vector_squared[i][j];
						int green = vector_squared[i][j + 1];
						int blue = vector_squared[i][j + 2];

						vector_squared[i][j + 3] = red;
						vector_squared[i][j + 4] = green;
						vector_squared[i][j + 5] = blue;
					}
					vector_squared[i + 1] = vector_squared[i];
				}
				break;
			case 14:
				// TO DO
				break;
			default:
				cout << "This is an invalid input." << endl;
			}
			cout << "Apply another effect or enter 0 to quit: " << endl;
			cin >> desired_effect;
		}
	}

	ppm_file.close();

	ofstream output_file;
	output_file.open(destination_file_name);

	output_file << data[0] << endl;
	output_file << data[1] << endl;
	output_file << data[2] << endl;

	for (int i = 0; i < vector_squared.size(); i++)
	{
		for (int j = 0; j < vector_squared[i].size(); j++)
		{
			output_file << vector_squared[i][j] << ' ';
		}
	}

	output_file.close();

	return 0;
}