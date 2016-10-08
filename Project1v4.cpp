/***********************************************************************
* Program:
*    Project 04, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Cook, CS124
* Author:
*    Austin Davis
* Summary:
*        the main function initializes the variables and then defines c.out.
*        the main then calls the getInput function which prompts the user
*        for the variables and then stores that value in the
*        variable and then it returns to the main, the
*        main then calls the output function which uses
*        the setw() command to format the output and
*        then output the monthly budget table to the console.
*        The purpose of this progran is to run and get user input regarding
*        their monthly budget and then give them an outputed table which
*        displays calculated values for the various fields.
*
*    Estimated:  4.5 hrs
*    Actual:     2.0 hrs
*      The most difficult part of this program was definatley formating the
*      output to the console and writing all the functions and variables.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
/*variable list:
   monthlyIncome
   budgetLivingExpense
   actualLivingExpense
   taxes
   tithing
   otherExpenses*/

//Prototyping:
void getInput(double &income, double &budgetLivingExpense,
              double &actualLivingExpense, double &actualTaxes,
              double &actualTithing, double &actualOtherExpenses);
void output(double income, double actualTaxes, double budgetTaxes,
            double budgetTithing, double actualTithing,
            double budgetLivingExpense, double budgetOther,
            double differenceActual, double actualLivingExpense,
            double actualOtherExpenses, double differenceBudget);
double computeTithing(double income);
double getBudgetOther(double income, double budgetLivingExpense,
                     double budgetTithing, double budgetTaxes);
double computeTax(double income);
double getDifferenceActual(double income, double actualTaxes,
                           double actualTithing, double actualLivingExpense,
                           double actualOtherExpenses);
double getDifferenceBudget(double income, double budgetTaxes,
                           double budgetTithing, double budgetLivingExpense,
                           double budgetOther);
/**********************************************************************
 * the main function initializes the variables and then defines c.out.
 * the main then calls the getInput function which prompts the user for the
 * variables and then stores that value in the variables and then it returns
 * to the main, The maint hen sets the values of various variables by calling
 * several calculation functions which return their respective values.
 * The main then calls the output function which uses the setw()
 * command to format the output and then output the monthly budget table to
 * the console.
 ***********************************************************************/
int main()
{
   //Initialization:
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double income;
   //budgeted variables
   double budgetTaxes;
   double budgetTithing;
   double budgetLivingExpense;
   double budgetOther;
   //actual variables
   double actualTaxes;
   double actualTithing;
   double actualLivingExpense;
   double actualOtherExpenses;
   double differenceBudget;
   double differenceActual;

   getInput(income, budgetLivingExpense, actualLivingExpense, actualTaxes,
            actualTithing, actualOtherExpenses);
   /*calc();*/
   budgetTaxes = computeTax(income);
   budgetTithing = computeTithing(income);
   budgetOther = getBudgetOther(income, budgetLivingExpense, budgetTithing,
                                budgetTaxes);
   differenceBudget = getDifferenceBudget(income, budgetTaxes, budgetTithing,
                                          budgetLivingExpense, budgetOther);
   differenceActual = getDifferenceActual(income, actualTaxes, actualTithing,
                                          actualLivingExpense,
                                          actualOtherExpenses);
   output(income, actualTaxes, budgetTaxes,
          budgetTithing, actualTithing, budgetLivingExpense, budgetOther,
          differenceActual, actualLivingExpense, actualOtherExpenses,
          differenceBudget);

   return 0;
}

//Calculations:
//Calculateds the other portion of the budget table.
double getBudgetOther(double income, double budgetLivingExpense,
                     double budgetTithing, double budgetTaxes)
{
   double budgetOther = income - budgetTithing - budgetLivingExpense
                     - budgetTaxes;
   return budgetOther;
}

//calculates the difference for the budget portion of the table.
double getDifferenceBudget(double income, double budgetTaxes,
                           double budgetTithing, double budgetLivingExpense,
                           double budgetOther)
{
   double diff = income - budgetTaxes - budgetTithing - budgetLivingExpense
               - budgetOther;



   return (unsigned)diff;
}

//gets the difference for the Actual portion of the table.
double getDifferenceActual(double income, double actualTaxes,
                           double actualTithing, double actualLivingExpense,
                           double actualOtherExpenses)
{
   double diffA = income - actualTaxes - actualTithing - actualLivingExpense
                - actualOtherExpenses;
   return diffA;
}

//Computes the tithing based upon given monthly income.
double computeTithing(double income)
{
   double tithing = income * 0.1;
   return tithing;
}

//Computes the monthly taxes due based upon the given monthly income.
double computeTax(double income)
{
   double yIncome = income * 12;
   double yTax;
   if(yIncome >= 0 && yIncome <= 15099)
   {
      yTax = yIncome * 0.10;
   }
   if(yIncome >= 15100 && yIncome <= 61299)
      yTax = 1510 + 0.15 * (yIncome - 15100);
   if(yIncome >= 61300 && yIncome <= 123699)
      yTax = 8440 + 0.25 * (yIncome - 61300);
   if(yIncome >= 123700 && yIncome <= 188449)
      yTax = 24040 + 0.28 * (yIncome - 123700);
   if(yIncome >= 188450 && yIncome <= 336549)
      yTax = 42170 + 0.33 * (yIncome - 188450);
   if(yIncome >= 336550)
      yTax = 91043 + 0.35 * (yIncome - 336550);

      double budgetTaxes = yTax / 12;
    return budgetTaxes;
}


/*The getInput prompts the user for the
* variables and then stores that value in the variables and then it returns
* to the main,*/
void getInput(double &income, double &budgetLivingExpense,
              double &actualLivingExpense,
              double &actualTaxes, double &actualTithing,
              double &actualOtherExpenses)
{
   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl;
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLivingExpense;
   cout << "\tYour actual living expenses: ";
   cin >> actualLivingExpense;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;
   cout << "\tYour actual other expenses: ";
   cin >> actualOtherExpenses;
   cout << endl;
}

/* The output function uses the setw()
* command to format the output and then output the monthly budget table to
* the console.*/
void output(double income, double actualTaxes, double budgetTaxes,
            double budgetTithing, double actualTithing,
            double budgetLivingExpense,
            double budgetOther, double differenceActual,
            double actualLivingExpense, double actualOtherExpenses,
            double differenceBudget)
{
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem" << setw(24) << "Budget" << setw(16) << "Actual" << endl;
   cout << "\t===============" << " " << "===============" << " "
      << "===============" << endl;
   cout << "\tIncome" << setw(11) << "$" << setw(11) << income << setw(5)
      << "$" << setw(11) << income << endl;
   cout << "\tTaxes" << setw(12) << "$" << setw(11) << budgetTaxes << setw(5)
      << "$" << setw(11) << actualTaxes << endl;
   cout << "\tTithing" << setw(10) << "$" << setw(11) << budgetTithing
      << setw(5) << "$" << setw(11) << actualTithing << endl;
   cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetLivingExpense <<
      setw(5) << "$" << setw(11) << actualLivingExpense << endl;
   cout << "\tOther" << setw(12) << "$" << setw(11) << budgetOther <<
      setw(5) << "$" << setw(11) << actualOtherExpenses << endl;
   cout << "\t===============" << " " << "===============" << " "
      << "===============" << endl;
   //cout << "\n\n\n\n: > " << differenceBudget << endl;
   cout << "\tDifference" << setw(7) << "$" << setw(11) << differenceBudget <<
      setw(5) << "$" << setw(11) << differenceActual << endl;
}
