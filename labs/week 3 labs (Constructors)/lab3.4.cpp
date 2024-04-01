#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Monster {
public:
  Monster(string str);

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print();
  
private:
  string _name;
  int _calories;
  char _glyph;
};

Monster::Monster(string str)
{
  stringstream ss(str);
  ss >> this->_name >> this->_glyph >> this->_calories;
}

void Monster::print()
{
  cout << "name: " << this->_name << endl;
  cout << "glyph: " << this->_glyph << endl;
  cout << "calories: " << this->_calories << endl;
}


int main() {
  vector<Monster *> monsters;

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
   Monster*m = new Monster(line);
   monsters.push_back(m);
   
   // Declare a Monster pointer and initialize it from the input line using new.

   // Add the Monster to the monsters vector using push_back.
  }
  
  file.close();

  cout << "Created " << monsters.size() << " monsters:\n";
  
  for (size_t i = 0; i < monsters.size(); ++i) {
     monsters[i]->print();
    // Use the Monster's method to print each Monster in the monsters vector.
  }
}