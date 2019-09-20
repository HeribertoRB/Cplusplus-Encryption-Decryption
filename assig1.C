/***************************************************
Heriberto Bernal
CS211
September 24, 2015

This program will performs different types of encryption or description. You can encrypt or descript between rotation or cryptogram. The outputs will be save in files.  
***************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void getOriginalData(vector<string>& v);
void EncUsingCrypt(const vector<string>& v, vector<string>& EncV);
string encWordCrypt(string wd,const string crypt);
string tolower(string wd);
void Menu(vector<string>& v, vector<string>& EncV, vector<string>& DecV);
void EncUsingRot(const vector<string>& v, int RotNum, vector<string>& EncV);
string EncWordUsingRot(string word, int RotNum);
void firstFile(const vector<string>& EncV);
void secondFile(const vector<string>& EncV);
void thirdFile(const vector<string>& DecV);
void fourthFile(const vector<string>& DecV);
void DecUsingRot(int RotNum, vector<string>& DecV);
void DecUsingCrypt(vector<string>& DecV);
string decWordCrypt(string wd, const string crypt);
string DecWordUsingRot(string word, int RotNum);


int main()
{
  vector<string> v;
  vector<string> EncV;
  vector<string> DecV;

  getOriginalData(v);

  Menu(v, EncV, DecV);

  return 0;
}

//************************************************************************
//ORIGINAL DATA TO VECTOR
void getOriginalData(vector<string>& v)
{
  int count = 0;

  ifstream fin;
  fin.open("original.txt");
  string word;

  while(fin >> word)
    {
      v.push_back(word);
      count++;
    }
  fin.close();
}
//***********************************************************************


//**********************************************************************
//MENU
void Menu(vector<string>& v, vector<string>& EncV, vector<string>& DecV)
{
  int choice;
  int choice2;
  int choice3;
  int key;
  int key2;

  do{
  cout << "Select 1 for encryption, or select 2 for decryption, or select 3 number to end program: ";

  cin >> choice;
  }while(choice > 3);

  if(choice == 1)
    {
      do{
      cout << "Select 1 for rot method, or select 2 for cryptogram method: ";
      cin >> choice2;
      }while(choice2 > 2);

      if(choice2 == 1)
	{
	  cout << "Enter encryption key: ";
	  cin >> key;
	  EncUsingRot(v, key, EncV);
	  firstFile(EncV);
	}
      else 
	{
	  EncUsingCrypt(v, EncV);
	  secondFile(EncV);
	}
    }
  else if(choice == 2)
    {
      do{
      cout << "Select 1 for rot method, or select 2 for cryptogram method: ";
      cin >> choice3;
      }while(choice3 > 2);

      if(choice3 == 1)
	{
	  cout << "Enter encryption key: ";
          cin >> key2;
	  DecUsingRot(key2, DecV);
	  thirdFile(DecV);
	}
       else
      	{
	  DecUsingCrypt(DecV);
	  fourthFile(DecV);
      	}
    }
}
//*********************************************************************

//***********************************************************************
//ROTATION WAY
void EncUsingRot(const vector<string>& v, int RotNum, vector<string>& EncV)
{
  string DecWord;
  int count = 0;

  for(int i=0; i < v.size(); i++)
    {
      DecWord = EncWordUsingRot(v[i], RotNum);
      EncV.push_back(DecWord);
      count++;
    }
}

void DecUsingRot(int RotNum, vector<string>& DecV)
{
  string DecWord;
  int count = 0;
  string word;
  ifstream fin;

  fin.open("encrypt01.txt");

  while(fin >> word)
    {
      DecV.push_back(word);
      count++;
    }


  for(int i=0; i < DecV.size(); i++)
    {
      DecWord = DecWordUsingRot(DecV[i], RotNum);
      DecV[i] = DecWord;
      count++;
    }
}

string DecWordUsingRot(string word, int RotNum)
{
  word = tolower(word);
  string DecWord = word;
  int newChar;

  for(int i=0; i< word.size(); i++)
    {
      if(word[i] >= 'a' && word[i] <= 'z')
        {
          newChar = (int)word[i] - RotNum;

          if(newChar < 'a')
            newChar += 26;

          DecWord[i] = (char)newChar;
        }
    }
  return DecWord;
}

string EncWordUsingRot(string word, int RotNum)
{
  word = tolower(word);
  string EncWord = word;
  int newChar;

  for(int i=0; i< word.size(); i++)
    {
      if(word[i] >= 'a' && word[i] <= 'z')
	{
	  newChar = (int)word[i] + RotNum;

	  if(newChar > 'z')
	    newChar -= 26;

	  EncWord[i] = (char)newChar;
	}
    }
  return EncWord;
}
//******************************************************************************

//********************************************************************************
//FILES
void firstFile(const vector<string>& EncV)
{
  ofstream fout;
  fout.open("encrypt01.txt");

    for(int i=0; i< EncV.size(); i++)
      {
	fout << EncV[i] << " ";
	cout << EncV[i] << " ";
      }
    cout << endl;
  fout.close();
}

void secondFile(const vector<string>& EncV)
{
  ofstream fout;
  fout.open("encrypt02.txt");

    for(int i=0; i< EncV.size(); i++)
      {
        fout << EncV[i] << " ";
	cout << EncV[i] << " ";
      }
    cout << endl;
  fout.close();
}

void thirdFile(const vector<string>& DecV)
{
  ofstream fout;
  fout.open("Decrypt01.txt");

  for(int i=0; i< DecV.size(); i++)
    {
      fout << DecV[i] << " ";
      cout << DecV[i] << " ";
    }
  cout << endl;
  fout.close();
}

void fourthFile(const vector<string>& DecV)
{
  ofstream fout;
  fout.open("Decrypt02.txt");

  for(int i=0; i< DecV.size(); i++)
    {
      fout << DecV[i] << " ";
      cout << DecV[i] << " ";
    }
  cout << endl;
  fout.close();
}
//***********************************************************************

//*************************************************************************
//CRYPTOGRAM WAY
void EncUsingCrypt(const vector<string>& v, vector<string>& EncV)
{
  string crypt;
  string EncWord;
  ifstream fin;

  fin.open("cryptgram.txt"); 
  fin >> crypt;

  for(int i=0; i< v.size();i++)
    {
      EncWord = encWordCrypt(v[i], crypt);
      EncV.push_back(EncWord);
    }
}

string encWordCrypt(string wd,const string crypt)
{
  wd = tolower(wd);
  string EncWord = wd;
  int index;
  char ch;

  for(int i=0; i < wd.size(); i++)
    {
      if(wd[i] >= 'a' && wd[i] <= 'z')
	{
	  index = wd[i] - 'a';
	  EncWord[i] = crypt[index];
	}
    }
  return EncWord;
}

void DecUsingCrypt(vector<string>& DecV)
{
  string crypt;
  string word;
  int count = 0;
  string DecWord;
  ifstream fin;
  ifstream fin2;

  fin.open("cryptgram.txt");
  fin2.open("encrypt02.txt");

  while(fin2 >> word)
    {
      DecV.push_back(word);
      count++;
    }
  fin >> crypt;

  for(int i=0; i< DecV.size();i++)
    {
      DecWord = decWordCrypt(DecV[i], crypt);
      DecV[i] = DecWord;
    }
}

string decWordCrypt(string wd, const string crypt)
{
  string DecWord = wd;
  int index;
  char ch;

  for(int i=0; i < wd.size(); i++)
    {
      if(wd[i] >= 'a' && wd[i] <= 'z')
	{
	  ch = wd[i];
	  index = crypt.find(ch, 0);
	  DecWord[i] = (char)index + 'a';
	}
    }
  return DecWord;
}
//*****************************************************************************

//******************************************************
//TO LOWER UPPER CASES

string tolower(string wd)
{
  for(int i=0; i< wd.size(); i++)
    {
      if(wd[i] >= 'A' && wd[i] <= 'Z')
	wd[i] = wd[i] + 32;
    }

  return wd;
}
//***********************************************************

