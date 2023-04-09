// Rezwan Rahman
#include <fstream>
#include <iostream>
#include <string>

// Uncomment when you implemented linear probing & double hashing
#include "linear_probing.h"
#include "double_hashing.h"
#include "quadratic_probing.h"

using namespace std;


// You can add more functions here

// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table,
			      const string &words_filename,
			      const string &query_filename) 
{//start TestFunction
    hash_table.MakeEmpty();
    // reads our file
    ifstream my_words_file; 
    my_words_file.open(words_filename);

    if(my_words_file.fail())
    {//start if file fail
        cout<< "Error: Fail to open" << words_filename << endl;
    }//end file fail
    
    //create a new line
    string my_line;

    //read all words from words.txt & insert into hash table
    while(getline(my_words_file, my_line))
    {//start while getline
        hash_table.Insert(my_line);
    }//end while getline

    my_words_file.close();

    /*                     Start implementing HashTable Attributes                */
    cout << "number_of_elements: " << hash_table.NumOfElements() << endl;
    cout << "size_of_table: " << hash_table.SizeOfTable() << endl;
    cout << "load_factor: " << hash_table.LoadFactor() << endl;
    cout << "collisions: " << hash_table.TotalNumOfCollisions() << endl;
    cout << "avg_collisions: " << hash_table.AvgNumOfCollisions() << endl;
    cout << endl;
    /*                     End implementing HashTable Attributes                  */

    //Begin query file procedure
    ifstream my_query_file;
    my_query_file.open(query_filename);
    if(my_query_file.fail())
    {//start if query fail
        cout << "Error: Query file failed to open" << words_filename << endl;
    }//end if query fail

   //read all words from words.txt & insert into hash table
    while(getline(my_query_file, my_line))
    {//start while getline
        hash_table.ResetNumOfCollisions();
        if(hash_table.Contains(my_line))
        {
            cout << my_line << " Found " << hash_table.TotalNumOfCollisions() + 1 << endl;
        }
        else
        {
            cout << my_line << " Not_Found " << hash_table.TotalNumOfCollisions() + 1 << endl;
        }
    }//end while getline
    my_query_file.close();


}//end TestFunction

// @argument_count: argc as provided in main
// @argument_list: argv as provided in imain
// Calls the specific testing function for hash table (linear, quadratic, or double).
int testHashingWrapper(int argument_count, char **argument_list) 
{//start testHashWrapper
    const string words_filename(argument_list[1]);
    const string query_filename(argument_list[2]);
    const string param_flag(argument_list[3]);
    int R = 89;
    if (argument_count == 5) 
    {//start if arg=5
	    const string rvalue(argument_list[4]);
	    R = stoi(rvalue);
    }//end if

    if (param_flag == "linear") 
    {//start if linear
        //Uncomment below when you have implemented linear probing.
        HashTableLinear<string> linear_probing_table;
        TestFunctionForHashTable(linear_probing_table, words_filename,
      			 query_filename);
    }//end if linear

    else if (param_flag == "quadratic") 
    {//start if quadratic
	    HashTable<string> quadratic_probing_table;
	    TestFunctionForHashTable(quadratic_probing_table, words_filename,
				 query_filename);
    }//end if quadratic

    else if (param_flag == "double") 
    {//start if double
	cout << "r_value: " << R << endl;
        // Uncomment below when you have implemented double hashing.
	    HashTableDouble<string> double_probing_table;
	    TestFunctionForHashTable(double_probing_table, words_filename,
	 			 query_filename);
    } //end if double

    else 
    {//start else
	    cout << "Unknown tree type " << param_flag
	         << " (User should provide linear, quadratic, or double)" << endl;
    }//end else
    return 0;
}//end testHashWrapper

// Sample main for program create_and_test_hash. DO NOT CHANGE IT.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testHashingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char **argv) {
    if (argc != 4 and argc != 5) {
	cout << "Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag>" << endl;
	cout << "or Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag> <rvalue>" << endl;
	return 0;
    }

    testHashingWrapper(argc, argv);
    return 0;
}
