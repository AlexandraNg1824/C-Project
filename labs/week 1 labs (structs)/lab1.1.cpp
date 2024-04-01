#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Add two more data members to the Monster struct;
//  "glyph" a char that represents the monster's first initial
//  "calories", an int that represents the monster's current energy level
struct Monster {
  string name;
  char glyph;
  int calories;
};

int main() {
  // This string contains the Monster's name, glyph, and calories.
  string monsterData = "Frankenstein f 125";

  // An easy way to parse a string is to:
  // - make a stringstream from that string
  // - perform successive reads from the string using the extraction operator (>>)
  
  stringstream ss(monsterData);


  Monster m;

  // Add code to read and initialize m's glyph and calories.
  ss >> m.name;
  ss >> m.glyph;
  ss >> m.calories;

  // Add code to print m's glyph and calories after its name.
  // Label each data member with the member name and a colon.
  cout << "name: " << m.name << endl;
  cout << "glyph: " << m.glyph << endl;
  cout << "calories: " << m.calories << endl;
}