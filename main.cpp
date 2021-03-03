#include <iostream>
#include <string>
#include <set>
#include <thread>
#include <fstream>
#include <algorithm>

struct Pizza
{    
    int pizzaItterator = 0;
    int numOfIngredients = 0;
    bool* ingredientArray = NULL;
    int* ingrediantItterator = NULL;
    std::string* ingredientStrings = NULL;
};

struct team2
{
    int pizzasItterator[2];
    int numUniqueIngrediants = 0;
};

struct team3
{
    int pizzasItterator[3];
    int numUniqueIngrediants = 0;
};

struct team4
{
    int pizzasItterator[4] = { 0 };
    int numUniqueIngrediants = 0;
    int numPizzas = 0;
};

//struct IngredentIndex
//{
//    set<string> topping;
//    int ID;
//};

/*
class Pizza {
public:
	Pizza(int uniqueIngredients)

private:
	int pizzaNumber;
	bool* ingredientArray looks like [1,0,1,0...]

}
[1,1,0,1...
[0,1,1,0...

Treat arrays as binary strings maybe
110100101
011010010
|
111110111

bool* enumerateIngredients(data) {


};


Pizza array
[0, olive, cheese, whatever]
[1, olive, not cheese , whatever]

[0, 1, 0, 1, 1]
[1, 1, 1 , 1, 0]
{} []
[
    [0,1,23,3]
]



bool ingrediants[MaxNumIngrediants]


int maxPosition = 0
int maxValue = 0
for(x in pizzas)
	if x.array > maxValue
		maxValue = x.arrayvalue
		maxPosition = x

Remove x from the list of pizzas and store it in an array of chosen pizzas

for(x in pizzas)
	if x.array|chosen.array > maxValue //OR the pizza arrays together and then find the total number of unique ingredients
		maxValue = x.arrayvalue
		maxPosition = x

Answers will look like
# of teams
#of people in team, pizza#, pizza#, etc
#of people in team, pizza#, pizza#, etc

4 [array of included pizzas]


*/
/*
bool* makeArrays(int numPizzas, int uniqueIngredients, string* pizzas) {
	bool* ingredients = new bool[numPizzas][uniqueIngredients];

	for(int i=0;i<numPizzas;i++) {
		bool* tempPizzaArray = new bool[uniqueIngredients];

	};

	return ingredients
};

int badBruteForce(int numPizzas, int uniqueIngredients, string* pizzas) {
	int score = 0;


};

int findPizzas(bool* pizzas) {


   return score; //return the amount of score the delivery adds to the total
};

==================================================================================================
										Algo Notes:
==================================================================================================
People per order = L : L e {2,3,4}
No. Pizzas = M : 0 < M < 100,000
No ingredients in a pizza = I : 0 < I < 10,000

First, sort pizzas by unique ingredients		O(log M) quicksort

Start with orders of 4 people, then 3, then 2 

First pizza per delivery will always be the pizza with the most unique ingredients		O(1)
	from this choice, we have an array of ingredients already included
	remove our chosen pizza from the main list

The next pizzas will be ones that add the most unique ingredients <-----
	Iterate through included ingredients and check each pizza for total added ingredients		O(M^2 I) I think?
	remove chosen pizza from the main list and onto a temporary list
	For the next pizza choose the pizza that adds the most unique ingredients

Add the amount of score for the order to a total from the temporary list 

*/

/*

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    // sort a single string
    std::string text = "Michael" ;
    std::sort( text.begin(), text.end() ) ;
    std::cout << text << '\n' ;

    // sort an array of strings
    std::string array[5] { "zero", "one", "two", "three", "four" } ;
    std::sort( array, array+5 ) ;
    for( const auto& str : array ) std::cout << str << ' ' ;
    std::cout << '\n' ;

    // sort a vector of strings
    std::vector<std::string> vec { "five", "six", "seven", "eight", "nine" };
    std::sort( vec.begin(), vec.end() ) ;
    for( const auto& str : vec ) std::cout << str << ' ' ;
    std::cout << '\n' ;
}


#include<bits/stdc++.h>
using namespace std;
int binarySearchString(string arr[], string x, int n) {
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (arr[mid]))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (arr[mid]))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}


*/

void quickSort(std::string allTheDifferentIngrediants[], std::string allTheDifferentIngrediantsUnordered[], int allTheDifferentIngrediantsUnorderedItterator[], 
    const int& numDifferentIngrediants, int start, int end, const std::string& insert, bool& done, bool& lastRound, bool& firstTime);
void quickFind(std::string allTheDifferentIngrediants[], int allTheDifferentIngrediantsUnorderedItterator[], int start, int end, 
    const std::string& insert, int& itt, bool& foundIngrediant, bool& lastRound, bool& secondToLastRound, const int& numDifferentIngrediants);
void quickSortPizza(Pizza pizza[], const int& numPizzas,
    int start, int end, Pizza insert, bool& done, bool& lastRound, bool& firstTime);

int main(int argc, char** argv)
{
    int numPizzas = 0;
    int num2PersonTeams = 0;
    int num3PersonTeams = 0;
    int num4PersonTeams = 0;
    int numDifferentIngrediants = 0;
    std::string* allTheDifferentIngrediants = new std::string[10000];
    std::string* allTheDifferentIngrediantsUnordered = new std::string[10000];
    int* allTheDifferentIngrediantsUnorderedItterator = new int[10000];
    short timesResizedDifferentIngrediants = 2;
    bool firstTime = true;
    //a_example
    //b_little_bit_of_everything.in
    //c_many_ingredients.in
    //d_many_pizzas.in
    //e_many_teams.in

    std::ifstream inFile;
    inFile.open("b_little_bit_of_everything.in");
    if (inFile)
    {
        inFile >> numPizzas;
        Pizza* pizza = new Pizza[numPizzas];
        inFile >> num2PersonTeams;
        inFile >> num3PersonTeams;
        inFile >> num4PersonTeams;
        for(int i = 0; i < numPizzas; i++)
        {
            inFile >> pizza[i].numOfIngredients;
            pizza[i].pizzaItterator = i;
            pizza[i].ingredientStrings = new std::string[pizza[i].numOfIngredients];
            pizza[i].ingrediantItterator = new int[pizza[i].numOfIngredients];
            for (int ingrediants = 0; ingrediants < pizza[i].numOfIngredients; ingrediants++)
            {
                inFile >> pizza[i].ingredientStrings[ingrediants];
                //std::cout << pizza[i].ingredientStrings[ingrediants] << " ";
                bool foundIngrediant = false;
                bool lastRound = false;
                bool secondToLastRound = false;
                quickFind(allTheDifferentIngrediants, allTheDifferentIngrediantsUnorderedItterator, 0, numDifferentIngrediants - 1,  pizza[i].ingredientStrings[ingrediants], 
                    pizza[i].ingrediantItterator[ingrediants], foundIngrediant, lastRound, secondToLastRound, numDifferentIngrediants);
               /* 
               //this is for if there are more than 10,000 ingredients, but none of the examples trigger this
               if (!foundIngrediant && numDifferentIngrediants >= (timesResizedDifferentIngrediants - 1) * 10000)
                {
                    std::string* temp = new std::string[timesResizedDifferentIngrediants * 10000];
                    std::string* temp2 = new std::string[10000];
                    int* temp3 = new int[10000];
                    for (int j = 0; j < numDifferentIngrediants; j++)
                    {
                        temp[j] = allTheDifferentIngrediants[j];
                        temp2[j] = allTheDifferentIngrediantsUnordered[j];
                        temp3[j] = allTheDifferentIngrediantsUnorderedItterator[j];
                    }
                    delete[] allTheDifferentIngrediants;
                    delete[] allTheDifferentIngrediantsUnordered;
                    delete[] allTheDifferentIngrediantsUnorderedItterator;
                    allTheDifferentIngrediants = temp;
                    allTheDifferentIngrediantsUnordered = temp2;
                    allTheDifferentIngrediantsUnorderedItterator = temp3;
                    timesResizedDifferentIngrediants++;
                    std::cout << "resized\n";
                }*/
                if (!foundIngrediant)
                {
                    bool done = false;
                    bool lastRound = false;
                    quickSort(allTheDifferentIngrediants, allTheDifferentIngrediantsUnordered, allTheDifferentIngrediantsUnorderedItterator, numDifferentIngrediants, 
                        0, numDifferentIngrediants, pizza[i].ingredientStrings[ingrediants], done, lastRound, firstTime);
                    pizza[i].ingrediantItterator[ingrediants] = numDifferentIngrediants;
                    numDifferentIngrediants++;
                }
            }
        }
        inFile.close();
        //int sortedPizzaCount = 0; 
        for (int i = 1; i < numPizzas; i++)
        {
            for (int p = 0; p < i; p++)
            {
                /*  bool done = false;
                bool lastRound = false;
                firstTime = true;
                quickSortPizza(pizza, numPizzas, 0, sortedPizzaCount, pizza[p], done, lastRound, firstTime);
                sortedPizzaCount++;*/
                if (pizza[i].numOfIngredients < pizza[p].numOfIngredients)
                {
                    for (int j = i; j > p; j--)
                    {
                        Pizza temp = pizza[j];
                        pizza[j] = pizza[j - 1];
                        pizza[j - 1] = temp;
                    }
                    break;
                }
            }
        }
        for (int p = 0; p < numPizzas; p++)
        {
            pizza[p].ingredientArray = new bool[numDifferentIngrediants] {false};
            for (int i = 0; i < pizza[p].numOfIngredients; i++)
            {
                pizza[p].ingredientArray[pizza[p].ingrediantItterator[i]] = true;
            }
        }
        //int sizeIngredientTeamList = 0;
        //for (int i = numPizzas - 1; i > numPizzas - 5; i--)
        //    sizeIngredientTeamList += pizza[i].numOfIngredients;
        ////std::cout << sizeIngredientTeamList;
        //int* ingrediantItteratorListGroup4 = new int[sizeIngredientTeamList] {0};
        //std::cout << numDifferentIngrediants;
        bool* ingrediantArrayGroup4 = new bool[numDifferentIngrediants] {false};
        bool firstPizza = true;
        team4* outputTeams = new team4[num2PersonTeams + num3PersonTeams + num4PersonTeams];
        int fourPersonTeamsServed = 0;
        int threePersonTeamsServed = 0;
        int twoPersonTeamsServed = 0;
        int numPizzasToFind = 4;
        int pizzasFound = 0;
        bool done = false;
        bool skip = false;
        int* numUnique = new int[numPizzas] { 0 };
        do
        {
            //if (twoPersonTeamsServed == 65)
            //    std::cout << "hi 60";
            if (numPizzasToFind > numPizzas)
            {
                if (numPizzas <= 1)
                    done = true;
                else if (threePersonTeamsServed >= num3PersonTeams && numPizzas <= 2)
                    done = true;                
                else if (twoPersonTeamsServed >= num2PersonTeams && numPizzas <= 1)
                    done = true;
                else
                    numPizzasToFind = numPizzas;
            }
            else if (threePersonTeamsServed < num3PersonTeams && fourPersonTeamsServed >= num4PersonTeams && numPizzasToFind == 4)
                numPizzasToFind = 3;
            else if (twoPersonTeamsServed < num2PersonTeams && fourPersonTeamsServed >= num4PersonTeams && threePersonTeamsServed >= num3PersonTeams && numPizzasToFind == 3)
                numPizzasToFind = 2;
            else if (fourPersonTeamsServed >= num4PersonTeams && threePersonTeamsServed >= num3PersonTeams && twoPersonTeamsServed >= num2PersonTeams)
                done = true;
            if (!done)
            {
                team4 team;
                pizzasFound = 0;
                skip = false;
                while (pizzasFound < numPizzasToFind && !skip)
                {
                //fourPersonTeamsServed < num4PersonTeams
                    if (firstPizza)
                    {
                        team.numUniqueIngrediants = pizza[numPizzas - 1].numOfIngredients;
                        //std::cout << "\n";
                        for (int i = 0; i < team.numUniqueIngrediants; i++)
                        {
                            //std::cout << pizza[numPizzas - 1].ingrediantItterator[i] << " ";
                            ingrediantArrayGroup4[pizza[numPizzas - 1].ingrediantItterator[i]] = true;
                        }
                        firstPizza = false;
                        team.pizzasItterator[pizzasFound] = pizza[numPizzas - 1].pizzaItterator;
                        numPizzas--;
                        team.numPizzas++;
                        pizzasFound++;
                    }
                    else
                    {
                        double ratio =  0.0 ;
                        double bestRatio = 0.0;
                        int mostAddedUnique = 0;
                        int bestPizzaItterator = 0;
                        int bestPizzaItterator2 = 0;
                        for (int p = numPizzas - 1, j=0; p >= 0 && pizza[p].numOfIngredients >= bestRatio; p--,j++ )
                        {
                            numUnique[j] = pizza[p].numOfIngredients;
                            //std::cout << "\n";
                            for (int i = 0; i < pizza[p].numOfIngredients; i++)
                            {
                                //std::cout << pizza[p].ingrediantItterator[i] << " ";
                                if (ingrediantArrayGroup4[pizza[p].ingrediantItterator[i]])
                                    numUnique[j]--;
                            }
                            if (pizza[p].numOfIngredients - numUnique[j])
                            {
                                ratio = numUnique[j] /(pizza[p].numOfIngredients -  double(numUnique[j]));
                                if ((ratio == bestRatio && numUnique[j] > mostAddedUnique) || ratio > bestRatio) //Ian maybe I'll come back to this with mostAddedUnique
                                {
                                    bestRatio = ratio;
                                    mostAddedUnique = numUnique[j];
                                    bestPizzaItterator = p;
                                    bestPizzaItterator2 = j;
                                }
                            }
                            else
                            {
                                ratio = numUnique[j];
                                if (ratio >= bestRatio)
                                {
                                    bestRatio = ratio;
                                    mostAddedUnique = numUnique[j];
                                    bestPizzaItterator = p;
                                    bestPizzaItterator2 = j;
                                }
                            }
                        }       
                        if (bestRatio == 0)
                        {
                            bestPizzaItterator = 0;
                            bestPizzaItterator2 = numPizzas - 1;
                            if (twoPersonTeamsServed < num2PersonTeams && pizzasFound == 1)                          
                                skip = true;                           
                            else if (threePersonTeamsServed < num3PersonTeams && pizzasFound == 2)
                                skip = true;
                        }
                        team.numUniqueIngrediants += numUnique[bestPizzaItterator2];
                        for (int i = 0; i < pizza[bestPizzaItterator].numOfIngredients; i++)
                        {
                            if(!ingrediantArrayGroup4[pizza[bestPizzaItterator].ingrediantItterator[i]])
                                ingrediantArrayGroup4[pizza[bestPizzaItterator].ingrediantItterator[i]] = true;
                        }
                        team.pizzasItterator[pizzasFound] = pizza[bestPizzaItterator].pizzaItterator;
                        for (int i = bestPizzaItterator; i < numPizzas - 1; i++)                        
                            pizza[i] = pizza[i + 1];                       
                        team.numPizzas++;
                        //if (team.numPizzas > 4)
                        //    std::cout << "";
                        numPizzas--;
                        pizzasFound++;
                    }                
                }
                if (team.numPizzas == 3 && skip && numPizzasToFind != 3)
                    std::cout << "";
                outputTeams[fourPersonTeamsServed + threePersonTeamsServed + twoPersonTeamsServed] = team;
                //if (outputTeams[fourPersonTeamsServed + threePersonTeamsServed + twoPersonTeamsServed].numPizzas > 4)
                //    std::cout << "";
                if (!skip)
                {
                    /*if (twoPersonTeamsServed >= num2PersonTeams - 1 && numPizzasToFind == 2)
                    {
                        std::cout << "";
                    }
                    else*/ if (threePersonTeamsServed >= (num3PersonTeams - 2) && numPizzasToFind != 3)
                    {
                        std::cout << "";
                    }
                    if (numPizzasToFind == 4)
                        fourPersonTeamsServed++;
                    else if (numPizzasToFind == 3)
                        threePersonTeamsServed++;
                    else
                        twoPersonTeamsServed++;
                }
                else
                {
                    if (twoPersonTeamsServed < num2PersonTeams && pizzasFound == 2)
                    {
                        twoPersonTeamsServed++;
                    }
                    else if (threePersonTeamsServed < num3PersonTeams && pizzasFound == 3)
                    {
                        threePersonTeamsServed++;
                    }
                }

                firstPizza = true;
            }          
        } while (!done);
        //delete[] numUnique;
        int score = 0;
        std::ofstream outFile;
        outFile.open("OUT_b_little_bit_of_everything.in");
        outFile << fourPersonTeamsServed + threePersonTeamsServed + twoPersonTeamsServed;
        int j = 0;
        int preScore = 0;
        //    std::cout << threePersonTeamsServed << " " << num3PersonTeams << " ";
        for (int i = 0; i < fourPersonTeamsServed + threePersonTeamsServed + twoPersonTeamsServed; i++)
        {
            //std::cout << score << "\n";
            preScore += outputTeams[i].numUniqueIngrediants;
            score += outputTeams[i].numUniqueIngrediants * outputTeams[i].numUniqueIngrediants;
            outFile << "\n" << outputTeams[i].numPizzas << " ";
            //if (outputTeams[i].numPizzas == 3)
            //    std::cout << ++j << " ";
            for (int p = 0; p < outputTeams[i].numPizzas; p++)
            {

                //if (outputTeams[i].numPizzas == 2 && i > 59)
                //    std::cout << "hi";
                outFile << outputTeams[i].pizzasItterator[p] << " ";
            }
        }
        outFile.close();
        std::cout << preScore << " " << score;
        
        /*for (int p = 0; p < numPizzas; p++)
        {
            std::cout << pizza[p].numOfIngredients << "\n";
        }*/
        /*std::cout << "\n";
        for (int i = 0; i < numDifferentIngrediants; i++)
        {
            std::cout << allTheDifferentIngrediants[i] << " " << allTheDifferentIngrediantsUnorderedItterator[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < numDifferentIngrediants; i++)
        {
            std::cout << allTheDifferentIngrediantsUnordered[i] << " ";
        }
        for (int i = 0; i < numPizzas; i++)
        {
            std::cout << "\n";
            for (int ingrediants = 0; ingrediants < pizza[i].numOfIngredients; ingrediants++)
            {
                std::cout << pizza[i].ingrediantItterator[ingrediants] << " " << pizza[i].ingredientStrings[ingrediants] << " ";
            }
        }*/
    }
    else
        std::cout << "\n\n***** Error DUMMY, the file didn't open *****\n\n";
	return 0;
}

void quickSort(std::string allTheDifferentIngrediants[], std::string allTheDifferentIngrediantsUnordered[], int allTheDifferentIngrediantsUnorderedItterator[], const int& numDifferentIngrediants,
    int start, int end, const std::string& insert, bool& done, bool& lastRound, bool& firstTime)
{
    int it = 0;
    if ((end - start) % 2)
        it = (end - start) / 2 + start + 1; //could result with it == end
    else
        it = (end - start) / 2 + start; //could result with it == start
    //if(it == end || it == start)
     //   lastRound = true;
    if (it != end && it != start)
    {
        if (insert < allTheDifferentIngrediants[it])
        {
            quickSort(allTheDifferentIngrediants, allTheDifferentIngrediantsUnordered, allTheDifferentIngrediantsUnorderedItterator, numDifferentIngrediants, start, it, insert, done, lastRound, firstTime);
        }
        else
        {
            quickSort(allTheDifferentIngrediants, allTheDifferentIngrediantsUnordered, allTheDifferentIngrediantsUnorderedItterator, numDifferentIngrediants, it, end, insert, done, lastRound, firstTime);
        }
    }
    if (!done)
    {
        if (it == end && end != 0)
            it--;

        if (!firstTime && it == start && insert > allTheDifferentIngrediants[it])
        {
            allTheDifferentIngrediantsUnordered[numDifferentIngrediants] = insert;
            for (int i = numDifferentIngrediants; i > it + 1; i--)
            {
                allTheDifferentIngrediants[i] = allTheDifferentIngrediants[i - 1];
                allTheDifferentIngrediantsUnorderedItterator[i] = allTheDifferentIngrediantsUnorderedItterator[i - 1];
            }
            allTheDifferentIngrediants[it + 1] = insert;
            allTheDifferentIngrediantsUnorderedItterator[it + 1] = numDifferentIngrediants;
        }
        else //if (!firstTime && insert < allTheDifferentIngrediants[it])
        {
            allTheDifferentIngrediantsUnordered[numDifferentIngrediants] = insert;
            for (int i = numDifferentIngrediants; i > it; i--)
            {
                allTheDifferentIngrediants[i] = allTheDifferentIngrediants[i - 1];
                allTheDifferentIngrediantsUnorderedItterator[i] = allTheDifferentIngrediantsUnorderedItterator[i - 1];
            }
            allTheDifferentIngrediants[it] = insert;
            allTheDifferentIngrediantsUnorderedItterator[it] = numDifferentIngrediants;
        }
        /*else
        {
            allTheDifferentIngrediantsUnordered[numDifferentIngrediants] = insert;
            for (int i = numDifferentIngrediants; i > it; i--)
            {
                allTheDifferentIngrediants[i] = allTheDifferentIngrediants[i - 1];
                allTheDifferentIngrediantsUnorderedItterator[i] = allTheDifferentIngrediantsUnorderedItterator[i - 1];
            }
            allTheDifferentIngrediants[it] = insert;
            allTheDifferentIngrediantsUnorderedItterator[it] = numDifferentIngrediants;
        }*/
        done = true;
        if (firstTime)
            firstTime = false;
        //std::cout << "\n";
        //for (int i = 0; i < numDifferentIngrediants + 1; i++)
        //{
        //    std::cout << allTheDifferentIngrediants[i] << " ";
        //}
    }
}


void quickFind(std::string allTheDifferentIngrediants[], int allTheDifferentIngrediantsUnorderedItterator[], int start, int end,
    const std::string& insert, int& itt, bool& foundIngrediant, bool& lastRound, bool& secondTolastRound, const int& numDifferentIngrediants)
{
    if (numDifferentIngrediants && !lastRound)
    {
        int it = 0;
        if (!(end - start))
            lastRound = true;
        if ((end - start) == 1)
        {
            if (!secondTolastRound)
            {
                it = (end - start) / 2 + start; 
                secondTolastRound = true;
            }
            else
            {
                it = (end - start) / 2 + start + 1; 
                lastRound = true;
            }
        } else
            it = (end - start) / 2 + start; 
        if (insert < allTheDifferentIngrediants[it])
        {
            quickFind(allTheDifferentIngrediants, allTheDifferentIngrediantsUnorderedItterator, start, it, insert, itt, foundIngrediant, lastRound, secondTolastRound, numDifferentIngrediants);
        }
        else if (insert > allTheDifferentIngrediants[it])
        {
            quickFind(allTheDifferentIngrediants, allTheDifferentIngrediantsUnorderedItterator, it, end, insert, itt, foundIngrediant, lastRound, secondTolastRound, numDifferentIngrediants);
        }
        else if (insert == allTheDifferentIngrediants[it])
        {
            itt = allTheDifferentIngrediantsUnorderedItterator[it];
            foundIngrediant = true;
        }
    }
}


void quickSortPizza(Pizza pizza[], const int& numPizzas,
    int start, int end, Pizza insert, bool& done, bool& lastRound, bool& firstTime)
{
    int it = 0;
    if ((end - start) % 2)
        it = (end - start) / 2 + start + 1; //could result with it == end
    else
        it = (end - start) / 2 + start; //could result with it == start
    //if(it == end || it == start)
     //   lastRound = true;
    if (it != end && it != start)
    {
        if (insert.numOfIngredients < pizza[it].numOfIngredients)
        {
            quickSortPizza(pizza, numPizzas, start, it, insert, done, lastRound, firstTime);
        }
        else
        {
            quickSortPizza(pizza, numPizzas, it, end, insert, done, lastRound, firstTime);
        }
    }
    if (!done)
    {
        if (it == end && end != 0)
            it--;

        if (!firstTime && it == start && insert.numOfIngredients > pizza[it].numOfIngredients)
        {
            for (int i = numPizzas; i > it + 1; i--)
            {
                pizza[i] = pizza[i - 1];
            }
            pizza[it + 1] = insert;
        }
        else //if (!firstTime && insert.numOfIngredients < pizza[it].numOfIngredients)
        {
            for (int i = numPizzas; i > it; i--)
            {
                pizza[i] = pizza[i - 1];
            }
            pizza[it] = insert;
        }
        //else
        //{
        //   for (int i = numPizzas; i > it; i--)
        //    {
        //        pizza[i] = pizza[i - 1];
        //    }
        //    pizza[it] = insert;
        //}
        done = true;
        if (firstTime)
            firstTime = false;
    }
}