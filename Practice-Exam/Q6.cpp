#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*****************************************************************************/
/*
Declare and define an Artist class. Artists have a single data member, a string
representing their name. The getter should be available to be used by anyone,
and the setter should only be used by subclasses.

Artists have a default constructor, i.e. one that takes no parameters.
Artists have a constructor that takes their name.

Artists have a method perform which prints a performance using cout. The base
class should implement it to print the artist's name and the start of a
sentence:
". When I perform, ".  (notice no newline) Subclasses will print the rest.

Artists have a method, favoritePerformance that takes no parameters. This method
should not have an implementation. Subclasses are required to implement it.

*/

/*** PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Artist ***/

// from try it - try subclassing
// try more subclassing

// DJH - Singluar "Artist" would be a better name
class Artist {
public:
  // getter
  string name() const { return _name; }
  //default constructor
  Artist() = default;
  Artist(string name) { _name = name; }
  virtual void perform() const { cout << _name << ". When I perform, "; }
//methodName must be overridden in subclasses (= 0)
  virtual string favoritePerformance() = 0;

protected:
  // setter
  void setName(string name) { _name = name; }
  string _name = "";
};

/*****************************************************************************/
/*
Artist subclass: Actor

Actors are artists who maintain a vector of movies which are strings that
represent titles of movies the actor has appeared in.

Actors have a constructor that takes the actor's name and a string title of
one of the actor's movies. This constructor should initialize the actor's
name and add the title to the actor's movies.

Override favoritePerformance to return a string this is composed by
concatenating a literal string: "a role in '" with the title of the first movie
in the actor's movies.

Override perform. First have it invoke the base class behavior which prints
the name, then cout a string like "I act out a scene in '" and print the
title of the last movie the actor appeared in.

Provide a method called addMovie that takes a string movie title and adds it
to the actor's movies vector.

*/
class Actor : public Artist {
public:
  // DJH - Not a big deal, but it's possible to call the Artist constructor here as follows...
 //this is how to use the parent class (construtor)
  Actor(string name, string movieTitle) : Artist(name) {
      _movies.push_back(movieTitle);
    }

  // Actor(string name, string movie) {
  //   _name = name;
  //   _movies.push_back(movie);
  // }
  string favoritePerformance() override { 
    return "a role in " + _movies.front(); 
  }
  void perform() const override {
    Artist::perform();
    cout << "I act out a scence in " << _movies.back() << " " << endl;  // DJH added endl
  }

  void addMovie(string movie) { 
    _movies.push_back(movie); 
  }

private:
//doest need a name coz the parent class have it 
  vector<string> _movies;
};
/*** PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Actor ***/

/*****************************************************************************/
/*
Artist subclass: Writer

Writers are artists who keep a pointer to their favorite actor. Declare
a private Actor pointer to represent this. Define a public getter and a private
setter for this member variable.

Writers have a constructor that takes their name and a pointer to their
favorite actor. Provide this constructor and initialize both member variables.

Override favoritePerformance to return a string this is composed by
concatenating a literal string: writing for " with the name of the writer's
favorite actor.

Override perform. First have it invoke the base class behavior which prints
the name, then cout a string like "I write a script for my favorite actor, "
and print the name of the writer's favorite actor.

*/

/*** PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Writer ***/

// DJH - better: singular!
class Writer : public Artist {
public:
  //getter 
  //string name() const {return _name;}
  Actor* actor() const { return _actor; }

  /* DJH - Same comment about the constructor. FYI...
  
      Writer(string name, Actor *favoriteActor) : Artist(name), _favoriteActor(favoriteActor) {
        // or use the setters
      }
  */

  Writer(string name, Actor *actor) {
    _name = name;    
    _actor = actor;
  };
  string favoritePerformance() override {
    return " writing for " + _actor->name(); //can just call the parent class
  }
  void perform() const override {
    Artist::perform();
    cout << "I write a script for my favorite actor, " + _actor->name() << " " << endl; // DJH added endl
  }

private:
  //private setter
  //void setName(string name) { _name = name; }
  Actor * _actor;
  void setActors(Actor *actor) { _actor = actor;}
  //doest need a name coz the parent class have it 
  //string _name = "";
};

/*****************************************************************************/
/*
A Guild is an association of artists. It maintains a private vector of
pointers to artists.

Guilds have a method called addArtist that accepts a pointer to an
artist and adds that pointer to it's vector of artists.

Guilds have a method called allPerform that itrates its artists
and invoke's each artist's perform method.

*/

/*** PROVIDE THE CLASS DECLARATION AND IMPLEMENTATION FOR Guild ***/
class Guild {
public:
  void addArtist(Artist* artist){
    _artists.push_back(artist);
  }
  void allPerform(){
    for (int i = 0; i < _artists.size(); i++){
      _artists[i]->perform();
    }
  }

private:
  vector<Artist*> _artists;
};

void RunQuestion6() {
  /*** UN-COMMENT AND USE THIS CODE TO TEST YOUR CLASSES ***/

  Guild g;
  Actor brando("Marlin Brando", "The Godfather");
  brando.addMovie("A Streetcar Named Desire");

  Actor pacino("Al Pacino", "The Godfather");
  Writer puzo("Mario Puzo", &pacino);

  g.addArtist(&brando);
  g.addArtist(&pacino);
  g.addArtist(&puzo);

  g.allPerform();
  cout << brando.name() << "'s favorite performance was " <<
  brando.favoritePerformance() << endl;
}