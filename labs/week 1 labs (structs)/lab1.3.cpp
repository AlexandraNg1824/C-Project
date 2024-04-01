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

Monster MonsterFromString(const string str) {
  Monster m;
  stringstream ss(str);
  ss >> m.name >> m.glyph >> m.calories;

  return m;
}

void EatPassingValue(Monster m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m.calories = calories;
}

void EatPassingPointer(Monster *m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m->calories = m->calories + calories;
}

void EatPassingReference(Monster &m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m.calories = calories + m.calories;
}



int main() {
  string monsterData = "Frankenstein f 125";


  Monster m = MonsterFromString(monsterData);

  PrintMonster(m);
  cout << "---\n";

  // Does EatPassingValue succesfully increase m's calories?
  // You should make sure you understand what's going on.
  EatPassingValue(m, 100);
  PrintMonster(m);
  cout << "---\n";

  //  Note the use of the address operator (&) to get the address of m to pass as a pointer.
  EatPassingPointer(&m, 100);
  PrintMonster(m);
  cout << "---\n";

  //  Note that this call looks just like EatPassingValue.
  //  It's not obvious that a reference is being passed or that m will be modified.
  //  This is why EatPassingPointer is the preferred idiom when modifying a struct parameter.
  EatPassingReference(m, 100);
  PrintMonster(m);
  cout << "---\n";
}