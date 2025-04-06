#include <iostream>
#include <stdexcept> // for std::out_of_range

using namespace std;

class GameEntry {				// a game score entry
public:
	GameEntry(const string& n="", int s=0);	// constructor
	string getName() const;			// get player name
	int getScore() const;			// get score
	void print();
private:
	string name;				// player's name
	int score;					// player's score
};

GameEntry::GameEntry(const string& n, int s)	// constructor
    : name(n), score(s) { }
  						// accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }
void GameEntry::print() {
	cout << name << endl;
}



class Scores {				// stores game high scores
public:
	Scores(int maxEnt = 10);			// constructor
	~Scores();					// destructor
	void add(const GameEntry& e);		// add a game entry
	GameEntry remove(int i) throw(std::out_of_range);// remove the ith entry
	GameEntry get(int i);
private:
	int maxEntries;				// maximum number of entries
	int numEntries;				// actual number of entries
	GameEntry* entries;				// array of game entries
};

Scores::Scores(int maxEnt) {			// constructor
	maxEntries = maxEnt;			// save the max size
	entries = new GameEntry[maxEntries];	// allocate array storage
	numEntries = 0;				// initially no elements
}

Scores::~Scores() {				// destructor
    delete[] entries;
}

void Scores::add(const GameEntry& e) {	// add a game entry
	int newScore = e.getScore();		// score to add
	if (numEntries == maxEntries) {		// the array is full
		if (newScore <= entries[maxEntries-1].getScore())
			return;					// not high enough - ignore
    	}
	else numEntries++;				// if not full, one more entry
  
	int i = numEntries-2; 			// start with the next to last
	while ( i >= 0 && newScore > entries[i].getScore() ) {
		entries[i+1] = entries[i];		// shift right if smaller
      		i--;
    	}
    	entries[i+1] = e;				// put e in the empty spot
}

GameEntry Scores::get(int i) {
	return entries[i];
}

GameEntry Scores::remove(int i) throw (std::out_of_range) {
	try {
		if ((i < 0) || (i >= numEntries)) {		// invalid index
			throw std::out_of_range("Index Out Of Range!");
		}
		
	} catch (std::out_of_range &e){

		cout << e.what() << endl;
	}
    	GameEntry e = entries[i];			// save the removed object 
    	for (int j = i+1; j < numEntries; j++)
      	entries[j-1] = entries[j];		// shift entries left
	
    	numEntries--;				// one fewer entry
    	return e;					// return the removed object
}

int main(){

	Scores my_array;
	my_array.add(GameEntry ("mike",100));
	my_array.add(GameEntry ("Andy",5100));
	my_array.add(GameEntry ("Pual",200));
	GameEntry e0 = my_array.get(0);
	GameEntry e1 = my_array.get(1);
	GameEntry e2 = my_array.get(2);
	e0.print();
	e1.print();
	e2.print();
	GameEntry e = my_array.remove(0);
	e.print();
	e0 = my_array.get(0);
	e0.print();
	my_array.remove(9);
	return 0;
}

