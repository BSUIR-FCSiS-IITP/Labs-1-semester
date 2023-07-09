#include "date.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <regex>
#include <invaliddatetype.h>

std::vector<std::string> main_day = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};


/**@brief Массив для месяцев
 */
int a[12] = {31, 28, 31, 30, 31, 30, 31,31,30,31,30,31};


bool check_vis(int q) {
    if ((q % 4 == 0 && q % 100 != 0) || (q % 400 == 0))
        return true ;
    else
        return false ;
}





Date::Date(int x, int y, int z)
{
    this -> day = x;
    this -> month = y;
    this -> year = z;
}

Date::Date(Date *q) {
    this -> day = q -> day;
    this -> month = q -> month;
    this -> year = q -> year;
};

Date::setDay(int x)
{
    this -> day = x;
}

Date::setMonth(int y)
{
    this -> month = y;
}

Date::setYear(int z)
{
    this -> year = z;
}

Date::getDay(Date *q)
{
   return q -> day;
}

Date::getMonth(Date *q)
{
   return q -> month;
}

Date::getYear(Date *q)
{
   return q -> year;
}

std::string Date::printDate(Date *q) {
    return (std::to_string(q -> day) + '.' + std::to_string(q -> month) + '.' +
            std::to_string(q -> year));
}

Date Date::NextDay(Date *date)
{
    int x = date -> day;
    int y = date -> month;
    int z = date -> year;
    if (a[y - 1] == 31) {
        if (x < 31)
            ++x ;
        else if (x == 31) {
            if (y < 12) {
                x = 1 ;
                ++y ;
            }
            else if (y == 12) {
                x = 1 ;
                y = 1 ;
                ++z ;
            }
        }
    }
    else if (a[y - 1] == 30) {
        if (x < 30)
            ++x ;
        else if (x == 30) {
            if (y < 12) {
                x = 1 ;
                ++y ;
            }
            else if (y == 12) {
                x = 1 ;
                y = 1 ;
                ++z ;
            }
        }
    }
    else if (a[y - 1] == 28 || a[y - 1] == 29) {
        if (check_vis(z))
            a[y - 1] = 29 ;
        else
            a[y - 1] = 28 ;
        if (x < a[y - 1])
            ++x ;
        else if (x == a[y - 1]) {
            if (y < 12) {
                x = 1 ;
                ++y ;
            }
            else if (y == 12) {
                x = 1 ;
                y = 1 ;
                ++z ;
            }
        }
    }
    return {x, y, z};
}

std::string Date::weekDay(Date *q) {
    int d, m, ye;
    d = q -> day;
    m = q -> month;
    ye = q -> year;
    int x = 1 ;
    int y = 1 ;
    int z = 1 ;
    int index = 0;
    while (x != d || y != m || z != ye) {
        if (a[y - 1] == 31) {
            if (x < 31)
                ++x ;
            else if (x == 31) {
                if (y < 12) {
                    x = 1 ;
                    ++y ;
                }
                else if (y == 12) {
                    x = 1 ;
                    y = 1 ;
                    ++z ;
                }
            }
        }
        else if (a[y - 1] == 30) {
            if (x < 30)
                ++x ;
            else if (x == 30) {
                if (y < 12) {
                    x = 1 ;
                    ++y ;
                }
                else if (y == 12) {
                    x = 1 ;
                    y = 1 ;
                    ++z ;
                }
            }
        }
        else if (a[y - 1] == 28 || a[y - 1] == 29) {
            if (check_vis(z))
                a[y - 1] = 29 ;
            else
                a[y - 1] = 28 ;
            if (x < a[y - 1])
                ++x ;
            else if (x == a[y - 1]) {
                if (y < 12) {
                    x = 1 ;
                    ++y ;
                }
                else if (y == 12) {
                    x = 1 ;
                    y = 1 ;
                    ++z ;
                }
            }
        }
        if (index < 6)
            ++index ;
        else if (index == 6)
            index = 0 ;
    }
    return ("День недели для даты " + std::to_string(q -> day) + '.' +
            std::to_string(q -> month) + '.' + std::to_string(q -> year) + " :" + main_day[index]) ;
}

Date Date::PreviousDay(Date *date)
{
    int x = date -> day;
    int y = date -> month;
    int z = date -> year;
    if (y > 1)
    {
        if (x > 1)
        {
            --x;
        }
        else if (x == 1)
        {
            if (y == 3 && check_vis(z))
                a[y - 1] = 29;
            else a[y - 1] = 28;
            x = a[y - 2];
            --y;
        }
    }
    else if (y == 1)
    {
        if (x > 1)
        {
            --x;
        }
        else if (x == 1)
        {
            --z;
            x = 31;
            y = 12;
        }
    }
    return {x, y, z};
}

bool Date::IsLeap(Date *q1)
{
    int q = q1 -> year;
    if ((q % 4 == 0 && q % 100 != 0) || (q % 400 == 0))
        return true ;
    else
        return false ;
}

short Date::WeekNumber(Date *q)
{
    int x = 1;
    int y = 1;
    int z = q -> year;
    short t = 0;
    while (x != q -> day || y != q -> month) {
        if (a[y - 1] == 31) {
            if (x < 31) {
                ++x;
                ++t;
            } else if (x == 31) {
                if (y < 12) {
                    x = 1;
                    ++y;
                    ++t;
                } else if (y == 12) {
                    x = 1;
                    y = 1;
                    ++z;
                    ++t;
                }
            }
        } else if (a[y - 1] == 30) {
            if (x < 30) {
                ++x;
                ++t;
            } else if (x == 30) {
                if (y < 12) {
                    x = 1;
                    ++y;
                    ++t;
                } else if (y == 12) {
                    x = 1;
                    y = 1;
                    ++z;
                    ++t;
                }
            }
        } else if (a[y - 1] == 28 || a[y - 1] == 29) {
            if (check_vis(z))
                a[y - 1] = 29;
            else
                a[y - 1] = 28;
            if (x < a[y - 1]) {
                ++x;
                ++t;
            } else if (x == a[y - 1]) {
                if (y < 12) {
                    x = 1;
                    ++y;
                    ++t;
                } else if (y == 12) {
                    x = 1;
                    y = 1;
                    ++z;
                    ++t;
                }
            }
        }
    }
    return ((t / 7) + 1);
}

int Date::DaysTillYourBirthday(Date *currentdate, Date *birthdaydate)
{
    QDate a(currentdate -> year, currentdate -> month, currentdate -> day);
    QDate b(a.year(),birthdaydate -> month, birthdaydate -> day);
        int countOfDays = (a.daysTo(b));
            if (countOfDays < 0)
                countOfDays += 365;
    return countOfDays;
}

int Date::Duration(Date *date) {
    int t = 0;
    std::time_t q = std::time(nullptr);
    std::tm *now = std::localtime(&q);
    int x = now->tm_mday;
    int y = now->tm_mon + 1;
    int z = now->tm_year + 1900;

    int x1 = date -> day;
    int y1 = date -> month;
    int z1 = date -> year;
    if (z1 > z || (z1 == z && y1 > y) || (z1 == z && y1 == y && x1 > x))
    {
        while (z != z1 || y != y1 || x != x1)
        {
            if (a[y - 1] == 31) {
                if (x < 31) {
                    ++x;
                    ++t;
                }
                else if (x == 31) {
                    if (y < 12) {
                        x = 1;
                        ++y;
                        ++t;
                    } else if (y == 12) {
                        x = 1;
                        y = 1;
                        ++z;
                        ++t;
                    }
                }
            } else if (a[y - 1] == 30) {
                if (x < 30) {
                    ++x;
                    ++t;
                }
                else if (x == 30) {
                    if (y < 12) {
                        x = 1;
                        ++y;
                        ++t;
                    } else if (y == 12) {
                        x = 1;
                        y = 1;
                        ++z;
                        ++t;
                    }
                }
            } else if (a[y - 1] == 28 || a[y - 1] == 29) {
                if (check_vis(z))
                    a[y - 1] = 29;
                else
                    a[y - 1] = 28;
                if (x < a[y - 1]) {
                    ++x;
                    ++t;
                }
                else if (x == a[y - 1]) {
                    if (y < 12) {
                        x = 1;
                        ++y;
                        ++t;
                    } else if (y == 12) {
                        x = 1;
                        y = 1;
                        ++z;
                        ++t;
                    }
                }
            }
        }
    }
    else if (z1 < z || (z1 == z && y1 < y) || (z1 == z && y1 == y && x1 < x))
    {
        while (z1 != z || y1 != y || x1 != x)
        {
            if (a[y1 - 1] == 31) {
                if (x1 < 31) {
                    ++x1;
                    ++t;
                }
                else if (x1 == 31) {
                    if (y1 < 12) {
                        x1 = 1;
                        ++y1;
                        ++t;
                    } else if (y1 == 12) {
                        x1 = 1;
                        y1 = 1;
                        ++z1;
                        ++t;
                    }
                }
            } else if (a[y1 - 1] == 30) {
                if (x1 < 30) {
                    ++x1;
                    ++t;
                }
                else if (x1 == 30) {
                    if (y1 < 12) {
                        x1 = 1;
                        ++y1;
                        ++t;
                    } else if (y1 == 12) {
                        x1 = 1;
                        y1 = 1;
                        ++z1;
                        ++t;
                    }
                }
            } else if (a[y1 - 1] == 28 || a[y1 - 1] == 29) {
                if (check_vis(z1))
                    a[y1 - 1] = 29;
                else
                    a[y1 - 1] = 28;
                if (x1 < a[y1 - 1]) {
                    ++x1;
                    ++t;
                }
                else if (x1 == a[y1 - 1]) {
                    if (y1 < 12) {
                        x1 = 1;
                        ++y1;
                        ++t;
                    } else if (y1 == 12) {
                        x1 = 1;
                        y1 = 1;
                        ++z1;
                        ++t;
                    }
                }
            }
        }
    }
    return t;
}
