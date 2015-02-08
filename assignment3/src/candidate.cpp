#include "candidate.h"
#include <string>

using namespace std;

candidate::candidate(){}

candidate::candidate(string n, int v){
    lastName = n;
    votes = v;
}

candidate::~candidate(){}

string candidate::GetlastName() {
    return lastName;
}
void candidate::SetlastName(string val) {
    lastName = val;
}
int candidate::Getvotes() {
    return votes;
}
void candidate::Setvotes(int val){
    votes = val;
}

double candidate::GetpercentOfTotal(){
    return percentOfTotal;
}

double candidate::SetpercentOfTotal(){
    percentOfTotal = (static_cast<double>(votes) / static_cast<double>(totalVotes)) * (100);
}

//static method
void candidate::setTotalVotes(int v){
    totalVotes += v;
}
//static method
int candidate::getTotalVotes(){
    return totalVotes;
}

