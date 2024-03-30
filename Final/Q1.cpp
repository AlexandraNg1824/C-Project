#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//from practice exam Q6
// PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Animal
class Animal{
public:
  float weight() const {return _weight;}
  Animal() = default;
  Animal(float weight) {_weight = weight;}
  virtual ~Animal(){};

  // DJH: -10 Methods that should be const: name(), canEat();
  virtual string name() = 0;
  virtual bool canEat (Animal* anotherAnimal) {
    bool result = true;
    if (name() == anotherAnimal->name()){
      result = false;
    }
    return result;
  }

protected:
  float _weight = 0.0;
  void setWeight (float weight){_weight = weight;}
};
// PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Fox
class Fox : public Animal{
public:
  string name() override {return "Fox";}
  // DJH: Derived canEat() doesn't call super
  bool canEat(Animal* anotherAnimal) override {
    bool result = false;
    if(anotherAnimal->name() == "Rabbit"){
      result = true;
    }
    return result;
  }
};
// PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Rabbit
class Rabbit : public Animal{
public:
  string name() override {return "Rabbit";}
  bool canEat(Animal* anotherAnimal) override {
    bool result = false;
    if(anotherAnimal->name() == "Grasshopper"){
      result = true;
    }
    return result;
  }
};
// PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Grasshopper
class Grasshopper : public Animal{
public:
  string name() override {return "Grasshopper";}
  bool canEat(Animal* anotherAnimal) override {
    // bool result = false;
    // if(Animal::canEat(anotherAnimal)) return false;
    return false; // just return false no matter what coz can eat none
  }
};
// PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Cage
class Cage{
public:
  Cage() = default;
  int animalCount(){
    return _animals.size();
  }
  void addAnimal(Animal* animal){
    _animals.push_back(animal);
  }
  string toString();
  bool areCompatible();

private:
  vector<Animal*> _animals;
};
// UN-COMMENT AND USE THIS METHOD IMPLEMENTATION AS-IS

bool Cage::areCompatible() {
  bool compatible = true;
  for (int i=0; i<animalCount() && compatible; i++) {
    for (int j=0; j<animalCount(); j++) {
      if (_animals[i]->canEat(_animals[j])) {
        compatible = false;
        break;
      }
    }
  }

  return compatible;
}


/*** UN-COMMENT AND USE THIS METHOD IMPLEMENTATION AS-IS ***/

string Cage::toString() {
  ostringstream oss;
  int count = animalCount();
  for (int i=0; i<count; i++) {
    oss << _animals[i]->name() << (i < count-1 ? ", " : "");
  }
  return oss.str();
}


void RunQuestion1() {
  // UN-COMMENT AND USE THIS CODE TO TEST YOUR CLASSES

  
  Cage cage1;

  cage1.addAnimal(new Grasshopper());
  cout << cage1.toString() << (cage1.areCompatible() ? ": ok" : ": incompatible") << endl;

  cage1.addAnimal(new Fox());
  cout << cage1.toString() << (cage1.areCompatible() ? ": ok" : ": incompatible") << endl;

  cage1.addAnimal(new Rabbit());
  cout << cage1.toString() << (cage1.areCompatible() ? ": ok" : ": incompatible") << endl;
  
}


// DJH: 90