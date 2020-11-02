// C++ implementation of the TSP using GA
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// Number of cities in TSP
#define V 5

// Names of the cities
#define GENES ABCDE

// Starting Node Value
#define START 0

// Structure of a GNOME string defines the path traversed by the salesman while the fitness value of the path is stored in an integer
struct individual {
  string gnome;
  int fitness;
};

// Function to return a random number from start and end
int rand_num(int start, int end)
{
  int r = end - start;
  int rnum = start + rand() % r;
  return rnum;
}

// Function to check if the character has already occurred in the string
bool repeat(string s, char ch)
{
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ch)
    return true;
  }
  return false;
}
// Function to return a mutated GNOME
// Mutated GNOME is a string with a random interchange of two genes to create variation in species
string mutatedGene(string gnome)
{
  while (true) {
    int r = rand_num(1, V);
    int r1 = rand_num(1, V);
    if (r1 != r) {
     char temp = gnome[r];
      gnome[r] = gnome[r1];
      gnome[r1] = temp;
      break;
    }
  }
  return gnome;
}

// Function to return a valid GNOME string required to create the population
string create_gnome()
{ 
  string gnome = "0";
  while (true) {
    if (gnome.size() == V) {
      gnome += gnome[0];
      break;
    }
    int temp = rand_num(1, V);
    if (!repeat(gnome, (char)(temp + 48)))
      gnome += (char)(temp + 48);
  }
  return gnome;
}

// Function to return the fitness value of a gnome.
// The fitness value is the path length of the path represented by the GNOME.
int cal_fitness(string gnome)
{
  int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },{ 2, 0, 4, 8, INT_MAX },{ INT_MAX, 4, 0, 3, 3 },{ 12, 8, 3, 0, 10 },{ 5, INT_MAX, 3, 10, 0 } };
  int f = 0;
  for (int i = 0; i < gnome.size() - 1; i++) {
      if (map[gnome[i] - 48][gnome[i + 1] - 48] == INT_MAX)
          return INT_MAX;
      f += map[gnome[i] - 48][gnome[i + 1] - 48];
    }
  return f;
}
// Function to return the updated value of the cooling element.
int cooldown(int temp)
{
  return (90 * temp) / 100;
}

// Comparator for GNOME struct.
bool lessthan(struct individual t1,struct individual t2)
{
  return t1.fitness < t2.fitness;
}

// Utility function for TSP problem.
void TSPUtil(int map[V][V], int g, int POP_SIZE)
{

  // Generation Number
  int gen = 1;
  // Number of Gene Iterations
  int gen_thres = g;
  vector<struct individual> population;
  struct individual temp;
  // Populating the GNOME pool.
  for (int i = 0; i < POP_SIZE; i++) {
    temp.gnome = create_gnome();
    temp.fitness = cal_fitness(temp.gnome);
    population.push_back(temp);
  }
  cout << "\nInitial population: " << endl<< "GNOME FITNESS VALUE\n";
  for (int i = 0; i < POP_SIZE; i++)
  cout << population[i].gnome << " "<< population[i].fitness << endl;
  cout << "\n";
  bool found = false;

  int temperature = 10000;
// Iteration to perform population crossing and gene mutation.

  while (temperature > 1000 && gen <= gen_thres) {
    sort(population.begin(), population.end(), lessthan);
    cout << "\nCurrent temp: " << temperature << "\n";
    vector<struct individual> new_population;
    for (int i = 0; i < POP_SIZE; i++) {
      struct individual p1 = population[i];
      while (true) {
          string new_g = mutatedGene(p1.gnome);
          struct individual new_gnome;
          new_gnome.gnome = new_g;
          new_gnome.fitness = cal_fitness(new_gnome.gnome);
          if (new_gnome.fitness <= population[i].fitness) {
            new_population.push_back(new_gnome);
            break;
          }
          else {
           // Accepting the rejected children at a possible probablity above threshold.
              float prob = pow(2.7,-1 * ((float)(new_gnome.fitness - population[i].fitness) / temperature));
              if (prob > 0.5) {
                new_population.push_back(new_gnome);
                break;
                }
          }
        }
    } 
  temperature = cooldown(temperature);
  population = new_population;
  cout << "Generation " << gen << " \n";
  cout << "GNOME FITNESS VALUE\n";
  for (int i = 0; i < POP_SIZE; i++)
    cout << population[i].gnome << " "<< population[i].fitness << endl;
  gen++;
  }
}

//Driver function
int main()
{
int map[V][V] = { { 0, 2, INT_MAX, 12, 5 },{ 2, 0, 4, 8, INT_MAX },{ INT_MAX, 4, 0, 3, 3 },{ 12, 8, 3, 0, 10 },{ 5, INT_MAX, 3, 10, 0 } };
int g,POP_SIZE;
// Input the generation threshold for the algorithm
cout<<"Enter the generation threshold: ";
cin>>g;
// Input the population size for the algorithm
cout<<"Enter the Population size: ";
cin>>POP_SIZE;
TSPUtil(map,g,POP_SIZE);
}

/*
INPUT AND OUTPUT

---------------------------------------------Example 1:------------------------------------------
Enter the generation threshold: 6
Enter the Population size: 8

Initial population: 
GNOME FITNESS VALUE
043210 24
023410 2147483647
031420 2147483647
034210 31
043210 24
023140 2147483647
032410 2147483647
012340 24


Current temp: 10000
Generation 1 
GNOME FITNESS VALUE
034210 31
042310 21
042310 21
031240 32
024310 2147483647
013420 2147483647
032140 2147483647
034210 31

Current temp: 9000
Generation 2 
GNOME FITNESS VALUE
012340 24
012340 24
043210 24
043210 24
034210 31
014320 2147483647
014320 2147483647
023140 2147483647

Current temp: 8100
Generation 3 
GNOME FITNESS VALUE
042310 21
042310 21
013240 21
034210 31
031240 32
034120 2147483647
041320 2147483647
021340 2147483647

Current temp: 7290
Generation 4 
GNOME FITNESS VALUE
012340 24
042130 32
031240 32
031240 32
034210 31
024130 2147483647
021340 2147483647
031240 32

Current temp: 6561
Generation 5 
GNOME FITNESS VALUE
012430 31
043210 24
012430 31
034210 31
034210 31
034210 31
042130 32
021430 2147483647

Current temp: 5904
Generation 6 
GNOME FITNESS VALUE
013240 21
012340 24
042130 32
043210 24
031240 32
043210 24
042310 21
041230 2147483647

---------------------------------------------Example 2:------------------------------------------
Enter the generation threshold: 10
Enter the Population size: 5

Initial population: 
GNOME FITNESS VALUE
043210 24
023410 2147483647
031420 2147483647
034210 31
043210 24


Current temp: 10000
Generation 1 
GNOME FITNESS VALUE
042310 21
013240 21
043210 24
013420 2147483647
034120 2147483647

Current temp: 9000
Generation 2 
GNOME FITNESS VALUE
042130 32
012340 24
013240 21
013240 21
014320 2147483647

Current temp: 8100
Generation 3 
GNOME FITNESS VALUE
043210 24
043210 24
042310 21
012430 31
014230 2147483647

Current temp: 7290
Generation 4 
GNOME FITNESS VALUE
043210 24
034210 31
034210 31
012340 24
034210 31

Current temp: 6561
Generation 5 
GNOME FITNESS VALUE
034210 31
012430 31
031240 32
043210 24
031240 32

Current temp: 5904
Generation 6 
GNOME FITNESS VALUE
013240 21
031240 32
042130 32
013240 21
013240 21

Current temp: 5313
Generation 7 
GNOME FITNESS VALUE
012340 24
012340 24
031240 32
013240 21
012430 31

Current temp: 4781
Generation 8 
GNOME FITNESS VALUE
012340 24
013240 21
042310 21
042130 32
034210 31

Current temp: 4302
Generation 9 
GNOME FITNESS VALUE
043210 24
042130 32
042310 21
043210 24
042310 21

Current temp: 3871
Generation 10 
GNOME FITNESS VALUE
012340 24
012340 24
013240 21
034210 31
012430 31

---------------------------------------------Example 3:------------------------------------------
Enter the generation threshold: 7
Enter the Population size: 4

Initial population: 
GNOME FITNESS VALUE
043210 24
023410 2147483647
031420 2147483647
034210 31


Current temp: 10000
Generation 1 
GNOME FITNESS VALUE
034210 31
043210 24
032410 2147483647
021430 2147483647

Current temp: 9000
Generation 2 
GNOME FITNESS VALUE
034210 31
031240 32
034210 31
012430 31

Current temp: 8100
Generation 3 
GNOME FITNESS VALUE
043210 24
043210 24
012340 24
013240 21

Current temp: 7290
Generation 4 
GNOME FITNESS VALUE
043210 24
034210 31
013240 21
013240 21

Current temp: 6561
Generation 5 
GNOME FITNESS VALUE
043210 24
012340 24
034210 31
031240 32

Current temp: 5904
Generation 6 
GNOME FITNESS VALUE
013240 21
042310 21
043210 24
034210 31

Current temp: 5313
Generation 7 
GNOME FITNESS VALUE
031240 32
043210 24
034210 31
043210 24
*/
