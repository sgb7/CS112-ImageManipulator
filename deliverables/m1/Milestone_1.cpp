// Summer Banister, CS 112, Milestone 1

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void split_string(string const &str, const char delim, vector<string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void string_to_int(string const &the_string, vector<int> &int_vector)
{
    int number;
    char delim = ' ';
    vector<string> out;
    split_string(the_string, delim, out);
    for(int i=0; i < out.size(); i++)
    {
        int number;
        istringstream iss (out[i]);
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
         << "7. Grayscale" << endl << endl;
    cout << "Please enter the number of your desired effect here: " << endl;
    int desired_effect;
    cin >> desired_effect;
    
    if(ppm_file.fail())
    {
        cout << "Can not open file.";
    }
    else
    {
        string line;
        while(ppm_file.good() == true)
        {
            getline(ppm_file, line);
            data.push_back(line);
        }
        
        for(int i=3; i < data.size(); i++)
        {
            vector<int> temp_vector;
            string_to_int(data[i], temp_vector);
            for(int i=0; i < temp_vector.size(); i++)
            {
                int_data.push_back(temp_vector[i]);
            }
        }
        
        switch(desired_effect)
        {
            case 1:
               for(int i=0; i < int_data.size(); i++)
                {
                    if(i%3==0)
                    {
                        int_data[i] = 0;
                    }
                }
               break;
            case 2:
                for(int i=0; i < int_data.size(); i++)
                {
                    if((i+2)%3==0)
                    {
                        int_data[i]=0;
                    }
                }
                break;
            case 3:
                for(int i=0; i < int_data.size(); i++)
                {
                    if((i+1)%3==0)
                    {
                        int_data[i] = 0;
                    }
                }
                break;
            case 4:
                for(int i=0; i < int_data.size(); i++)
                {
                    if(i%3==0)
                    {
                        int_data[i] = 255 - int_data[i];
                    }
                }
                break;
            case 5:
                for(int i=0; i < int_data.size(); i++)
                {
                    if((i+2)%3==0)
                    {
                        int_data[i] = 255 - int_data[i];
                    }
                }
                break;
            case 6:
                for(int i=0; i < int_data.size(); i++)
                {
                    if((i+1)%3==0)
                    {
                        int_data[i] = 255 - int_data[i];
                    }
                }
                break;
            case 7:
                for(int i=0; i < int_data.size(); i++)
                {
                    if((i+1)%3==0)
                    {
                        int avg_value = (int_data[i] + int_data[i-1] + int_data[i-2])/3;
                        int_data[i] = avg_value;
                        int_data[i-1] = avg_value;
                        int_data[i-2] = avg_value;
                    }
                }
                break;
            default:
                cout << "This is an invalid input." << endl;
        }
    }
           
    ppm_file.close();
    
    ofstream output_file;
    output_file.open(destination_file_name);
    
    output_file << data[0] << endl;
    output_file << data[1] << endl;
    output_file << data[2] << endl;
    
    for(int i=0; i < int_data.size(); i++)
    {
        output_file << int_data[i] << ' ';
    }

    output_file.close();
    
    return 0;
}