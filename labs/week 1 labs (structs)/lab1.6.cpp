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
   // Implement this function to loop through all the monsters and print each one using PrintMonster.
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
   // Implement this function to:
   // - Create a stream for the specified file.
   // - Read each line from the file.
   // - Create a Monster from that line of the file.
   // - Add that Monster to monsters.
   // - Close the file when you're done adding monsters.
ifstream file(fileName);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Monster newMonster = MonsterFromString(line);
            monsters->push_back(newMonster);
        }

        file.close();
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }
   
}


// Notice how much shorter and more readable main() is now that we factored out most of the logic.
int main() {
  vector<Monster> monsters;

  AddMonstersFromFile(&monsters, "MonsterData.txt");
  
  cout << "Created " << monsters.size() << " monsters:\n";
  
  PrintMonsters(monsters);
}