// Rezwan Rahman
// spell_check.cc: A simple spell checker.

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <array>
#include <sstream>
//implement all our files
#include "double_hashing.h"
#include "quadratic_probing.h"
#include "linear_probing.h"
using namespace std;

//Hint function 1: Remove punctuations (beginning & end of word)
string RemovePunct(const string& word)
{//start Remove Punctuation
  string str = word;
  //remove beginning punctuation
  if(word.size() > 1)
  {
    if(ispunct(str[0]))
      str.erase(str.begin());
  }

  //remove ending punctuation
  if(word.size() > 1)
  {
    if(ispunct(str[str.size() - 1]))
      str.erase(str.end() - 1);
  }
  return str;
}//end Remove Punctuation

//Hint function 2: Convert to lowercase
string MakeLowercase(const string& word)
{//start MakeLowercase
  string str = word;
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str; 
}//end Make Lowercase

//make string
string makeString( char aCharacter)        
{
	return string(1,aCharacter);         
}

//case A: Add a character to any given position of a word
void caseA(const HashTableDouble<string>& dictionary, string word)
{
      int word_size = word.size();
      for(char alpha='a'; alpha <= 'z'; ++alpha)
      {//start for word.length
        for(size_t look_word = 0; word_size + 1 > look_word ; ++look_word)
        {//start for
          string add_char = " ";
          add_char = word.insert(look_word, makeString(alpha));
          word.erase(look_word, 1);
          if(dictionary.Contains(add_char))
          {//start if
            cout << "** " << word << " -> " << add_char << " ** case A" << endl;
          }//end if
        }//end for
      }//end for
}

//caseB: remove a char from any given position
void caseB(const HashTableDouble<string>& dictionary, string word)
{
  for(size_t i=0; i < word.length(); i++)
      {//loop through word
        string my_input = word;
        my_input.erase(i,1);
        if(dictionary.Contains(my_input))
        {//if in dictionary return needed output
          cout << "** " << word << " -> " << my_input << " ** case B" << endl;
        }//end if
      }//end loop
}

//case C: swap 2 adjacent characters
void caseC(const HashTableDouble<string>& dictionary, string word)
{
  for(int i=0; i < word.length(); i++)
      {//start for
        string my_input = word;
        char c = my_input[i];
        my_input[i] = my_input[i+1];
        my_input[i+1] = c;
        if(dictionary.Contains(my_input))
        {//start if
          cout << "** " << word << " -> " << my_input << " ** case C" << endl;
        }//end if
      }//end for
}
//Create Our own Dictionary:
HashTableDouble<string> MakeDictionary(const string &dictionary_file)
{//start MakeDictionary

  HashTableDouble<string> dictionary_hash;
  // Fill dictionary_hash:
  //create a ifstream and open dictionaryfile
  ifstream dict_file;
  dict_file.open(dictionary_file);

  if(dict_file.fail())
  {//start if my_file failed to open
    cout << "Dictionary file failed to open " << endl;
  }//end my_file failed to open

  //create a string
  string my_line;
  //stroe each line from dictionary into my_line
  while(getline(dict_file, my_line))
  {//start while
    dictionary_hash.Insert(my_line); //store into hash_table
  }//end while

  //once complete, close our files
  dict_file.close();
  //return dictionary_hash
  return dictionary_hash;
}//end MakeDictionary

//SpellChecker: Complete Case A, B, C to test our spelling
void SpellChecker(const HashTableDouble<string>& dictionary, const string &document_file) 
{//start SpellChecker
  //open doc file & run procedure
  ifstream doc_file;
  doc_file.open(document_file);
  if(doc_file.fail())
  {//start if 
    cout << "Document file failed to open " << endl;
  }//end if

  //create string word
  string word;

  //while our file opens
  while(doc_file >> word && !doc_file.fail())
  {//start while

    //Function input: we remove the punctuation and make it lowercase
    word = MakeLowercase(RemovePunct(word));

    //if our dictionary contains the word, it is correct
    if(dictionary.Contains(word))
    {
      cout << word << " is CORRECT" << endl;
    }

    else
    {
      // otherwise we must do the corrections
      cout << word << " is INCORRECT" << endl;
      caseA(dictionary, word);
      caseB(dictionary, word);
      caseC(dictionary, word);
    }//end else

  }//end while
  //end off by closing doc file
  doc_file.close();
}//end SpellChecker

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) 
{//start Spelling
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);

    // Call functions implementing the assignment requirements.
    HashTableDouble<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"
         << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}