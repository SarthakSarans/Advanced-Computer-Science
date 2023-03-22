#include <iostream>
#include <string>
using namespace std;

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const string& str, const string& sub)
{
	if (sub.length() == 0) return 0;
	int count = 0;
	for (int offset = str.find(sub); offset != string::npos; 
		offset = str.find(sub, offset + sub.length()))
	{
		++count;
	}
	return count;
}

int wordCount( const string& str){
	int total = 0;
	for(int i = 0; i<str.length() - 1; i++){
		if( (str[i] == ' ') && str[i+1] != ' ')
			total++;
	
	}
	return total;
	}




int sentenceCount( const string& str){
int total = 0;
	for(int i = 0; i<str.length(); i++){
		if( (str[i] == '.') )
			total++;
	
	}
	return total;


	
}


int uWord ( const string& str){

	string u = "";
	string wordCheck = "";
	int total = 0;
	for(int i = 0; i < str.length(); i++){
		if (str[i] != ' '){
			wordCheck += str[i];
		}
		else{
			if(u.find(wordCheck, 0) == -1 ){
				u+= wordCheck + ' ';
				wordCheck = "";
				total++;
			}
			else
				wordCheck = "";
		}

		
	}
	return total + 2;
	
}

int lexDen (const string& str){
	float den = (float) uWord(str)/ (float) wordCount(str) * 100;
	return den + .5;
}

int main()
{



   string source = ("I was born in Lousiana down on the ol bayou raised on shrimps and catfish mamas good gumbo.  I got the ramblin fever.  Said goodbye to ma and pa.   Crossed that ol red river and this is what I saw. I saw miles and miles of Texas 1000 stars up in the sky.  I saw miles and miles of Texas gonna live here till I die.");


	cout << "substring count: " << countSubstring(source, "is")        << '\n';

	cout << "word count: " <<  wordCount(source) << '\n';

cout << "Unique word count: " <<  uWord(source) << '\n';

	cout << "Lexical density: " <<  lexDen(source) << "%" << '\n';



	return 0;
}