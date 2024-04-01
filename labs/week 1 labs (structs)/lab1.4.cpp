#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Monster {
  string name;
  int calories;
  char glyph;
};

void PrintMonster(const Monster &m)
{
  cout << "name: " << m.name << endl;
  cout << "glyph: " << m.glyph << endl;
  cout << "calories: " << m.calories << endl;
}

void InitMonsterFromString(Monster *m, const string str)
{
  stringstream ss(str);
  ss >> m->name >> m->glyph >> m->calories;
}

int main() {
  string monsterData1 = "Frankenstein f 125";
  string monsterData2 = "Dracula d 200";


  // This code creates a locally allocated Monster, just as you've done in previous labs.
  Monster m1;
  InitMonsterFromString(&m1, monsterData1);
  PrintMonster(m1);
  
  // Follow these steps to dynamically allocate another Monster, m2:

  // 1. Declare a Monster pointer, m2 and use new to initialize it.

  // 2. Use InitMonsterFromString to initialize m2.
  
  // 3. Use PrintMonster to print m2.

  // 4. Use delete to free up the storage for m2, now that's it's no longer needed.
  Monster* m2 = new Monster;
  InitMonsterFromString(m2, monsterData2);
  PrintMonster(*m2);
  delete m2;
  
  return 0;

}