#include <iostream>
#include "candidate.h"
#include <string>
#include <iomanip>

using namespace std;

int candidate::totalVotes = 0;
string findWinner(candidate*, int);
int main()
{
    int numOfCandidates;
    string lastName, winner;
    int  votes;
    candidate* candidates;
    cout << "how many candidates do you want to enter: ";
    cin >> numOfCandidates;
    candidates = new candidate[numOfCandidates];
    for (int i = 0; i < numOfCandidates; i++){
        cout << "Enter last name: ";
        cin.ignore().clear();
        getline(cin, lastName);
        candidates[i].SetlastName(lastName);

        cout << "Enter Number of votes received: ";
        cin >> votes;
        candidates[i].Setvotes(votes);
        candidate::setTotalVotes(votes);
    }

    // after all votes are entered, calculate percent of total for each candidate
    for (int i = 0; i < numOfCandidates; i++){
         candidates[i].SetpercentOfTotal();
    }

    cout << left << setw(13) << "Candidate" << right << setw(16) << "Votes Received" << right << setw(14) << "% of total" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < numOfCandidates; i++){
        cout << left << setw(13) << candidates[i].GetlastName() <<
                right << setw(16) << candidates[i].Getvotes() <<
                right << setw(14) << fixed << setprecision(2) <<
                candidates[i].GetpercentOfTotal() << "%" << endl;
    }

    winner = findWinner(candidates, numOfCandidates);
    if ( winner == "There is a tie"){
        cout << winner << endl;
    }else{
    cout << endl << winner << " has won this election!" << endl;
    }
    return 0;
}

//function finds candidate with most votes and returns their last name
string findWinner(candidate* candidates, int index){
    int temp = 0;
    string winner = "no one";
    for (int i = 0; i < index; i++){
        if( candidates[i].Getvotes() > temp ){
            temp = candidates[i].Getvotes();
            winner = candidates[i].GetlastName();
        }else if(candidates[i].Getvotes() == temp){
            winner = "There is a tie";
        }
    }
    return winner;
}
