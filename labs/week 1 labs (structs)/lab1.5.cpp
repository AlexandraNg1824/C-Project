#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Monster {
  string name;
  int calories;
  char glyph;
};

void PrintMonster(const Monster &m)
{
  cout << "name: " << m.name << ", glyph: " << m.glyph << ", calories: " << m.calories << endl;
}

Monster MonsterFromString(const string str) {
  Monster m;
  stringstream ss(str);
  ss >> m.name >> m.glyph >> m.calories;

  return m;
}

int main() {
  vector<Monster> monsters;

  ifstream file("MonsterData.txt");

  if (!file.is_open()) {
    cout << "Failed to open file\n" ;
    exit(0);
  }

  string line;
  while(getline(file, line)) {
    // Skip empty lines and comments (lines starting with two slashes)
    if (line.size() == 0 || line.find("//") == 0) continue;

   // This line simply prints out the line of the file that was just read in for debugging.
   // You will need to delete it or comment out.
   //cout << line << endl;
   
   // Declare a Monster and initialize it from the input line.
   Monster m2;
   m2 = MonsterFromString(line);
   monsters.push_back (m2);

   // Add the Monster to the monsters vector using push_back.
  }
  
  file.close();

  cout << "Created " << monsters.size() << " monsters:\n";
  
  for (size_t i = 0; i < monsters.size(); ++i) {
    // Use PrintMonster to print each Monster in the monsters vector.
    PrintMonster(monsters[i]);
  }
}