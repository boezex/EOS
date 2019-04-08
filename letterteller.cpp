#include <iostream>
#include <string>
using namespace std;

int main (int argc, char** argv)
{
  string zin, letter;
  int counter = 0;
  getline(cin, zin);
  letter = argv[1];
  for (unsigned int i = 0; i < zin.size(); i++)
  {
      if (zin[i] == letter[0])
	{
	  counter++;
	}
  }

  cout << counter << endl;
  return 0;
}
