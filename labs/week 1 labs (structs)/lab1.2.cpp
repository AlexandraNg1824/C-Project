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
 // Modify this function to print m's glyph and calories after its name.
 // Label each data member with the member name and a colon.
  cout << "name: " << m.name << endl;
  cout << "glyph: " << m.glyph << endl;
  cout << "calories: " << m.calories << endl;
}

Monster MonsterFromString(const string str) {
 // Implement this function to:
 // - Allocate a monster as a local variable.
 Monster m;
 // - Initialize the monster from str - similar to what you did for the Structs Part 1 lab.
 // - Return the monster.
   stringstream ss (str);
   ss >> m.name;
   ss >> m.glyph;
   ss >> m.calories;
   
   return m;
}

void InitMonsterFromString(Monster *m, const string str)
{
 // Implement this function to:
 // - Initialize m from str - similar to what you did for the Structs Part 1 lab.
 // Note that m is a pointer to a Monster. Slightly different syntax is required - arrows vs dots.
 stringstream ss (str);
 ss >> m->name;
 ss >> m->glyph;
 ss >> m->calories;
 
}


int main() {
  string monsterData1 = "Frankenstein f 125";
  string monsterData2 = "Dracula d 200";

  Monster m1 = MonsterFromString(monsterData1);

  PrintMonster(m1);

  Monster m2;

  InitMonsterFromString(&m2, monsterData2);

  PrintMonster(m2);
}

/* Followup q's:

- Try changing PrintMonster to take Monster instead of a Monster reference. Does it still work?

- Try changing InitMonsterFromString to take Monster instead of a Monster pointer. Does it still work?

- Can you explain the difference in behavior?

*/