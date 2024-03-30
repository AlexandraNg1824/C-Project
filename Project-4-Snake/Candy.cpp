
#include "Candy.h"

static const int kCandyMakerSeed = 3278;

Candy Candy::randomCandy(const Snake &snake, int rowCount, int colCount) {
  int row, col, calories, glyph;
  Color color;
  do {
    row = random(0, rowCount);
    col = random(0, colCount);
  } while (snake.intersects(row, col));
  calories = random(1, 10);
  glyph = '0' + calories;
  color = Color(random(1, 8));
  return Candy(row, col, calories, glyph, color);
}

void Candy::draw(GameBoard *board) const {
  board->setTileAt(_row, _col, _glyph, _color);
}

// This method seeds a random generator, giving it an arbitrary value to
// begin a random sequence. For debugging (and class work) we'll always seed 
// with the same value, giving us the same "random" sequence on every run.
mt19937& Candy::generator() {
  // changing seed: chrono::system_clock::now().time_since_epoch().count()
  static mt19937 _generator(kCandyMakerSeed);
  return _generator;
}

// Returns a random integer uniformly distributed between
// a min and a max (excluding the max). Uniform distribution means that
// every number in the given range is equally likely.  Use it as is:
int Candy::random(int min, int max) {
  uniform_int_distribution<int> uniform(min, max-1);
  return uniform(generator());
}

