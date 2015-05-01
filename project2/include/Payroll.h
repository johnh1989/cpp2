#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>

using namespace std;
class Payroll
{
    public:
        Payroll();
        Payroll(int en, string ln, string fn, int dn, double pr, double hw);
        virtual ~Payroll();
        Payroll(const Payroll& other);
        Payroll& operator=(const Payroll& other);

        bool operator>=(const Payroll &other);
        bool operator==(const Payroll &other);

        int GetEmployeeNumber() { return EmployeeNumber; }
        void SetEmployeeNumber(int val) { EmployeeNumber = val; }

        string GetLastName() { return LastName; }
        void SetLastName(string val) { LastName = val; }

        string GetFirstName() { return FirstName; }
        void SetFirstName(string val) { FirstName = val; }

        int GetDeptNumber() { return DeptNumber; }
        void SetDeptNumber(int val) { DeptNumber = val; }

        double GetPayRate() { return PayRate; }
        void SetPayRate(double val) { PayRate = val; }

        double GetHoursWorked() { return HoursWorked; }
        void SetHoursWorked(double val) { HoursWorked = val; }

        double GetPayAmount() { return PayAmount; }
        //void SetPayAmount(double val) { PayAmount = val; }

        void PrintPayroll() const;

        double CalculatePayAmount();


    protected:
    private:
        int EmployeeNumber;
        string LastName;
        string FirstName;
        int DeptNumber;
        double PayRate;
        double HoursWorked;
        double PayAmount;
        friend ostream &operator<<(ostream&, const Payroll&);
};

#endif // PAYROLL_H
