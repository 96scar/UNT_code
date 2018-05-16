#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string solve(int year)
{
    // Complete this function
    string answer, dd, mm, yyyy;
    int days=0;
    int i=0;
    int gregorian[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int julian[12]    = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(year%4 == 0) //leap year Julian
    {
        julian[1] = 29;
    }
    
    if(year%400==0 || (year%4==0 && year%100!=0)) //leap year Gregorian
    {
        gregorian[1] = 29;
    }
    
    yyyy = to_string(year);
    
    while(days!=256)
    {
        if(year == 1918) //transition year
        {
            if(i==0)//julian
            {
                days += julian[i];
            }
            else if(i==1) //skipped over days, now gregorian
            {
                days += gregorian[i];
                days -= 13;
            }
            else if(i>1 && i<=12)
            {
                if(days+gregorian[i]==256)//found day
                {
                    if(i+1 < 10)
                        mm = '0' + to_string(i+1);
                    else
                        mm = to_string(i+1);
                    if(gregorian[i] < 10)
                        dd = '0' + to_string(gregorian[i]);
                    else
                        dd = to_string(gregorian[i]);
                    days += gregorian[i];
                }
                else if(days+gregorian[i] > 256) //went over
                {
                    if(i+1 < 10)
                        mm = '0' + to_string(i+1);
                    else
                        mm = to_string(i+1);
                    if(gregorian[i] - (days+gregorian[i]-256) < 10)
                        dd = '0' + to_string(gregorian[i] - (days+gregorian[i]-256));
                    else
                        dd = to_string(gregorian[i] - (days+gregorian[i]-256));
                    days += gregorian[i] - (days+gregorian[i]-256);
                }
                else if(days+gregorian[i] < 256) //keep looking
                {
                    days += gregorian[i];
                }
            }
        }   
        else if(year <= 1917 && year >= 1700) //julian calendar
        {
            if(days+julian[i] == 256) //found day
            {
                if(i+1 < 10)
                    mm = '0' + to_string(i+1);
                else
                    mm = to_string(i+1);
                if(julian[i] < 10)
                    dd = '0' + to_string(julian[i]);
                else
                    dd = to_string(julian[i]);
                days += julian[i];
            }
            else if(days+julian[i] > 256) //went over too much
            {
                if(i+1 < 10)
                    mm = '0' + to_string(i+1);
                else
                    mm = to_string(i+1);
                if(julian[i] - (days+julian[i]-256) < 10)
                    dd = '0' + to_string(julian[i] - (days+julian[i]-256));
                else
                    dd = to_string(julian[i] - (days+julian[i]-256));
                days += julian[i] - (days+julian[i]-256);
            }
            else if(days+julian[i] < 256) //keep looking
            {
                days += julian[i];
            }    
        }
        else if(year >= 1919 && year <= 2700) //gregorian calendar
        {
            if(days+gregorian[i]==256)//found day
            {
                if(i+1 < 10)
                    mm = '0' + to_string(i+1);
                else
                    mm = to_string(i+1);
                if(gregorian[i] < 10)
                    dd = '0' + to_string(gregorian[i]);
                else
                    dd = to_string(gregorian[i]);
                days += gregorian[i];
            }
            else if(days+gregorian[i] > 256) //went over
            {
                if(i+1 < 10)
                    mm = '0' + to_string(i+1);
                else
                    mm = to_string(i+1);
                if(gregorian[i] - (days+gregorian[i]-256) < 10)
                    dd = '0' + to_string(gregorian[i] - (days+gregorian[i]-256));
                else
                    dd = to_string(gregorian[i] - (days+gregorian[i]-256));
                days += gregorian[i] - (days+gregorian[i]-256);
            }
            else if(days+gregorian[i] < 256) //keep looking
            {
                days += gregorian[i];
            }
        } 
        else
            exit(1);
        i++;
    }
    
    answer=dd+'.'+mm+'.'+yyyy;
    
    return answer;
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}
