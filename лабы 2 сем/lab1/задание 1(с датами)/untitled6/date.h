#include <iostream>
#include <QDate>

class Date
{
private:
    int day, month, year;
public:
    Date() = default;
    Date(Date *q);
    ~Date() = default;
    static std::string printDate(Date *a);
    Date(int x, int y, int z);
    static Date NextDay(Date *date);
    static Date PreviousDay(Date *date);
    static std::string weekDay(Date *a);
    static bool IsLeap(Date *q1);
    static short WeekNumber(Date *q);
    static int DaysTillYourBirthday(Date *currentdate, Date *birthdaydate);
    static int Duration (Date *date);
    int setDay(int x);
    int setMonth(int y);
    int setYear(int z);
    static int getDay(Date *q);
    static int getMonth(Date *q);
    static int getYear(Date *q);
};
