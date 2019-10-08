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
        int number;
        istringstream iss (out[i]);
        iss >> number;
        int_vector.push_back(number);
        if (iss.fail())
        {
            cout << "something went wrong" << endl;
        }
    }
}


int main()
{
    vector<string> data;
    vector<int> data_line_1;
    vector<int> data_line_2;
    vector<int> data_line_3;
    vector<int> data_line_4;
    //Shouldn't need these extra vectors. Just one other vector should do.
    vector<int> int_data; //that should work
    
    cout << "Please enter source file name here: " << endl;
    string source_file_name;
    cin >> source_file_name;
    //Good
    
    cout << "Please enter destination file name here: " << endl;
    string destination_file_name;
    cin >> destination_file_name;
    //Good
    
    ifstream ppm_file;
    ppm_file.open(source_file_name);
    string line;
    //Good
    
    cout << endl;
    cout << "Here's what was written to the destination file: " << endl;  
    if(ppm_file.fail())
    {
        cout << "Can not open file.";
    }
    // Good
    else
    {
        string line;
        while(ppm_file.good() == true)
        {
            getline(ppm_file, line);
            data.push_back(line);
        }
        //Good
        
        cout << data[0] << endl;
        //Good
        
        string height = data[1].substr(0, 1);
        cout << height << endl;
        //Good
        
        string width = data[1].substr(2);
        cout << width << endl;
        //Good
        
        cout << data[2] << endl;
        //Good

        
        // New code:
        for(int i=3; i < data.size(); i++)
        {
            vector<int> temp_vector;
            string_to_int(data[i], temp_vector);
            for(int i=0; i < temp_vector.size(); i++)
            {
                int_data.push_back(temp_vector[i]);
            }
        }
     
        for(int i=0; i < int_data.size(); i++)
        {
            cout << int_data[i] << ' ';
        }
        cout << endl;
        
        for(int i=0; i < int_data.size(); i++)
        {
            if(i%3==0)
            {
                int_data[i]=0;
            }
        }
        
        for(int i=0; i < int_data.size(); i++)
        {
            cout << int_data[i] << ' ';
        }
        
        // New code end.
            
        /*string_to_int(data[3], data_line_1);
        data_line_1[3] = 0;
        data_line_1[9] = 0;
        for(int i=0; i < data_line_1.size(); i++)
        {
            cout << data_line_1[i] << ' ';
        }
        cout << endl;
        
        string_to_int(data[4], data_line_2);
        for(int i=0; i < data_line_2.size(); i++)
        {
            cout << data_line_2[i] << ' ';
        }
        cout << endl;
        
        string_to_int(data[5], data_line_3);
        for(int i=0; i < data_line_3.size(); i++)
        {
            cout << data_line_3[i] << ' ';
        }
        cout << endl;
        
        string_to_int(data[6], data_line_4);
        data_line_4[0] = 0;
        data_line_4[9] = 0;
        for(int i=0; i < data_line_4.size(); i++)
        {
            cout << data_line_4[i] << ' ';
        }
        cout << endl;*/
    }
           
    ppm_file.close();
    
    ofstream output_file;
    output_file.open(destination_file_name);
    
    output_file << data[0] << endl;
    output_file << data[1] << endl;
    output_file << data[2] << endl;
    for(int i=0; i < data_line_1.size(); i++)
    {
        output_file << data_line_1[i] << ' ';
    }
    cout << endl;
    for(int i=0; i < data_line_2.size(); i++)
    {
        output_file << data_line_2[i] << ' ';
    }
    cout << endl;
    for(int i=0; i < data_line_3.size(); i++)
    {
        output_file << data_line_3[i] << ' ';
    }
    cout << endl;
    for(int i=0; i < data_line_4.size(); i++)
    {
        output_file << data_line_4[i] << ' ';
    }
    cout << endl;

    output_file.close();
    
    return 0;
}