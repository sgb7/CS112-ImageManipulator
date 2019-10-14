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
        // string append, instead of a vector?
}

void string_to_int(string const &the_string, vector<int> &int_vector)
{
    int number;
    char delim = ' ';
    vector<string> out;
    split_string(the_string, delim, out);
    for(int i=0; i < out.size(); i++)
    {
        int number = stoi(out[i]);
        int_vector.push_back(number);
        
        /*istringstream iss (out[i]);
        iss >> number;
        int_vector.push_back(number);*/
        /*if (iss.fail())
        {
            cout << "something went wrong" << endl;
        }*/
    }
    // Something is going wrong in converting the string to numbers, in the beginning. 
    // Maybe try using stoi instead and see if that makes a difference?
    // Nope that didn't work. I think it has something to do with the size of the file I'm processing.
    // But how do I fix that?
}


int main()
{
    vector<string> data;
    vector<int> int_data; //that should work
    
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
         << "2. Remove blue" << endl
         << "3. Remove green" << endl
         << "4. Negate red" << endl
         << "5. Negate blue" << endl
         << "6. Negate green" << endl
         << "7. Grayscale" << endl << endl;
    cout << "Please enter the number of your desired effect here: " << endl;
    cout << endl;
    int desired_effect;
    cin >> desired_effect;
    
    //cout << endl;
    //cout << "Here's what was written to the destination file: " << endl;  
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
        
        
        /*cout << data[0] << endl;
        //Good
        
        string height = data[1].substr(0, 1);
        cout << height << endl;
        //Good
        
        string width = data[1].substr(2);
        cout << width << endl;
        //Good
        
        cout << data[2] << endl;
        //Good*/

        for(int i=3; i < data.size(); i++)
        {
            vector<int> temp_vector;
            string_to_int(data[i], temp_vector);
            for(int i=0; i < temp_vector.size(); i++)
            {
                int_data.push_back(temp_vector[i]);
            }
        }
     
        /*for(int i=0; i < int_data.size(); i++)
        {
            cout << int_data[i] << ' ';
        }
        cout << endl;*/
        
        switch(desired_effect)
        {
            case 1:
               for(int i=0; i < int_data.size(); i++)
                {
                    if(i%3==0)
                    {
                        int_data[i]=0;
                    }
                }
               break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                cout << "This is an invalid input." << endl;
        }
     
        for(int i=0; i < int_data.size(); i++)
        {
            cout << int_data[i] << ' ';
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