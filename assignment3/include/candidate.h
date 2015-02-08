#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <iostream>
using namespace std;
class candidate
{
    public:
        candidate();
        candidate(string n, int v);
        virtual ~candidate();
        string GetlastName();
            // return lastName
        void SetlastName(string val);
            // set lastName
        int Getvotes();
            // return votes
        void Setvotes(int val);
            // set votes
        double GetpercentOfTotal();
            // return percentOfTotal;
        double SetpercentOfTotal();
            // set percentOfTotal (votes / totalVotes)
        static void setTotalVotes(int v);
            // keeps running total of totalVotes as a static member
        static int getTotalVotes();
           // return totalVotes


    private:
        string lastName;
        int votes;
        double percentOfTotal;
        static int totalVotes;
};

#endif // CANDIDATE_H
