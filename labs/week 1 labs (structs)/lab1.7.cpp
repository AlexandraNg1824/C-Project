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

void PrintMonsters(const vector<Monster> &monsters)
{
  for (size_t i = 0; i < monsters.size(); ++i) {
    PrintMonster(monsters[i]);
  }
}

Monster MonsterFromString(const string str) {
  Monster m;
  stringstream ss(str);
  ss >> m.name >> m.glyph >> m.calories;

  return m;
}

void AddMonstersFromFile(vector<Monster> *monsters, string fileName) {
  ifstream file(fileName);

  if (!file.is_open()) {
    cout << "Failed to open file: " << fileName << endl;
    exit(0);
  }

  string line;
  while(getline(file, line)) {
    // Skip empty lines and comments (lines starting with two slashes)
    if (line.size() == 0 || line.find("//") == 0) continue;

    // cout << line << endl;
    Monster m = MonsterFromString(line);

    monsters->push_back(m);
  }
  
  file.close();
}

int IndexOfLeastCaloricMonster(const vector<Monster> &monsters)
{
 // Implement this function to return the index, in monsters, of the monster with the least calories.
 // If monsters is empty, return -1.
   if(monsters.empty())
      return -1;
   int indexOfLeastCaloric = 0;
   int minCalories = monsters[0].calories;

   for (size_t i = 1; i < monsters.size(); ++i) {
     if (monsters[i].calories < minCalories) {
       minCalories = monsters[i].calories;
       indexOfLeastCaloric = static_cast<int>(i);
    }
  }

  return indexOfLeastCaloric;
}

void RemoveLeastCaloricMonster(vector<Monster> *monsters)
{
 // Implement this function to remove the monster, from monsters, which has the least calories.
 // Hint: Use IndexOfLeastCaloricMonster in your implementation.
 // Hint: Use the erase vector method to remove an element from a vector.
 //  E.g. To remove the 3rd element you'd write code like: someVector.erase(someVector.begin() + 3);
   int indexOfLeastCaloric = IndexOfLeastCaloricMonster(*monsters);
   if (indexOfLeastCaloric != -1) {
      monsters->erase(monsters->begin() + indexOfLeastCaloric);
   }
}

int main() {
  vector<Monster> monsters;

  AddMonstersFromFile(&monsters, "MonsterData.txt");

  RemoveLeastCaloricMonster(&monsters);
  
  cout << "Now contains " << monsters.size() << " monsters:\n";
  
  PrintMonsters(monsters);
}