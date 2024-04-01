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

class MonsterList {
public:
  MonsterList(string filename);

  int count();

  void print();

private:
  vector<Monster *> _monsters;

};

MonsterList::MonsterList(string filename) {
   // Implement this function to:
   // - Create a stream for the specified file.
   // - Read each line from the file.
   // - Create a Monster pointer from that line of the file using new.
   // - Add that Monster to _monsters.
   // - Close the file when you're done adding monsters.
   ifstream file(filename);

  if (!file.is_open()) {
    cerr << "Failed to open file " << filename << endl;
    exit(EXIT_FAILURE);
  }

  string line;
  while (getline(file, line)) {
    if (line.size() == 0 || line.find("//") == 0)
      continue;

    Monster *m = new Monster(line);
    _monsters.push_back(m);
  }

  file.close();
}


int MonsterList::count() {
   return _monsters.size();
   // Implement this (trivial) method to return the number of monsters in the vector.
   // The vector method for returning the number of elements is size.
   // We think 'size' isn't the best choice of name because it's ambiguous.
   // For example, size might mean how many bytes of memory an object occupies - as in the sizeof operator.
   // The term 'count' is unambiguous. It means "how many?"
}

void MonsterList::print() {
   for (Monster *m : _monsters) {
    m->print();
    cout << endl;
  }
   // Implement this method to loop through all the monsters and print each one using its print method.
   // Notice that both the Monster and MonsterList class have a print method.
   // The same method name can be used by different classes, each doing what's appropriate for that class.
   // - The print method on Monster prints a single monster.
   // - The print method on MonsterList prints all the monsters in the list.
}

int main() {

  MonsterList monsters("MonsterData.txt");
  
  cout << "Created " << monsters.count() << " monsters:\n";
  
  monsters.print();
}