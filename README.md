[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10524610&assignment_repo_type=AssignmentRepo)
# Assignment-3-Code

//Rezwan Rahman

For this project we had to create files for 3 different forms of hashing.
These forms are: double hashing, linear probing, and quadratic probing
We needed 

For double hashing, I made sure to set my Rvalue to the default shown in our create_and_test_hash.
This was 89. Although our quadratic_probing.h file was given, we had to implement our double_hashing
and our linear_probing files. For the most part, i just copied and pasted off the quadratic_probing.h
and made a few changes to the FindPos() function, and set our default Rvalue to 89. 

Create_and_test_hash:
For the most part, we just needed to go through running our file procedure and make sure our hash_table values 
are outputted properly, and follows to output rules on the assignment document.
I compiled this by doing:
g++ -std=c++14 -o create_and_test_hash create_and_test_hash.cc
and tested it by doing:
./create_and_test_hash wordsEn.txt query_words.txt double

Spell_check:
For this part I had to create a dictionary, and then implement the 3 cases for misspelled words:
Case A: Adding 1 character in any possible position
Case B: Removing 1 character
Case C: Swapping two adjacent characters

Problems I encountered:
Originally I had all my cases implemented within my spell_check function. However, I kept encountering
errors where despite my cases being implemented correctly, lack of organisation made it difficult for 
me to track my mistakes. Thus I made 3 separate functions and it finally worked.

I compiled spell_check by inserting this in terminal: 
g++ -std=c++14 -o spell_check spell_check.cc
and tested by inserting this:
./spell_check document1.txt wordsEnglish.txt

For the most part my program compiled and tested all cases correctly perfectly!

Why I was late?: 
For the most part, my messy code and lack of organization made it really difficult for me to understand where I went wrong. Although It would compile for the most part, I would not recieve full credit on gradescope. I was unaware that it would be this difficult to fix it, but I managed to get it done. After reorganizing all my test cases as separate functions, I was finally able to get my entire code to work. I am submitting this 2 hours late. 
