#include <iostream>
#include<cstdlib>
#include<new>
using namespace std;

//create structure for new data type which we need it to inculde each person data
struct persons {
    string name,mass_index;
    int age;
    float weight;
    double BMR, BMI;
    float height;
    char gender;
};
struct statistics {
    int sum_males, sum_females;
    double BMR_males, BMR_females,avg_males, avg_females;
};
persons person(int N)
{
    persons* Persons_arr = nullptr;
    Persons_arr = new persons[N];
    for (int i = 0; i < N; i++)
    {
        cout << "For person number: "; N; " Enter his/her name, age in years, gender M or F, weight in kg then enter height in cm respectivly \n";
        cin >> Persons_arr[i].name >> Persons_arr[i].age >> Persons_arr[i].gender >> Persons_arr[i].weight >> Persons_arr[i].height;
    }
    return Persons_arr[N];
};
statistics  BMR(persons Person_arr[],int N)
{
    statistics stats;
    for (int i = 0; i < N; i++)
        if (Person_arr[i].gender == 'm')
        {
            Person_arr[i].BMR = 66+(13.7 * Person_arr[i].weight)+(5 * Person_arr[i].height)-(6.8 * Person_arr[i].age);
            stats.BMR_males += Person_arr[i].BMR;
            stats.sum_males++;
        }
        else if (Person_arr[i].gender == 'f')
        {
            Person_arr[i].BMR = 655 + (9.6 * Person_arr[i].weight) + (1.8 * Person_arr[i].height)-(4.7 * Person_arr[i].age);
            stats.BMR_females += Person_arr[i].BMR;
            stats.sum_females++;
        }
    stats.avg_males = stats.BMR_males / stats.sum_males;
    stats.avg_females = stats.BMR_females / stats.sum_females;
    return stats;
};
void BMI(persons Person_arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        Person_arr[i].BMI= Person_arr[i].weight / ((Person_arr[i].height / 100) * (Person_arr[i].height / 100));
        if (Person_arr[i].BMI < 18.5)
            Person_arr[i].mass_index= "Underweight";
        else if (25>= Person_arr[i].BMI&&Person_arr[i].BMI>=18.5)
            Person_arr[i].mass_index = "Optimal weight";
        else
            Person_arr[i].mass_index = "Overweight";
    }
}
void main()
{
    int N;
    statistics Persons_stats;
    cout << "Enter the number of persons \n";
    cin >> N;
    persons Person_arr = person(N);
    Persons_stats=BMR(&Person_arr,N);
    BMI(&Person_arr,N);
}