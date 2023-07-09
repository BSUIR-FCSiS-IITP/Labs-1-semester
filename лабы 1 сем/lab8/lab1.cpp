#include <iostream>
#include <regex>

int cnt = 1 ;
bool empty = true ;

struct air {
    long long number{} ;
    std::string type{} ;
    std::string point{};
    std::string time{};
};

air* list = (air *)calloc(1000, sizeof(air)) ;

bool number(std::string const &str)
{
    return std::regex_match(str, std::regex("^([1-9]\\d*)$")) ;
}

bool time(std::string const &str)
{
    return std::regex_match(str, std::regex("^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$")) ;
}

air* input() {
    empty = false ;
    std::cout << "Ввод данных расписания вылетов:\n" ;
    int w ;
    do {
        w = 0 ;
        std::cout << "--------------------------------------------------------------------------\n" <<
                  "Самолет " << cnt << " :\n\n" <<
                  "Введите номер рейса:\n" ;
        int q ;
        std::string s11 = "";
        do {
            s11 = "" ;
            q = 0;
            getline(std::cin, s11) ;
            if (!number(s11)) {
                ++q;
                std::cerr << "Введите корректные данные!\n";
            } else break;
        } while (q != 0);
        list[cnt - 1].number = std::stoll(s11) ;
        std::cout << "Введите тип самолёта:\n" ;
        getline(std::cin, s11) ;
        list[cnt - 1].type = s11 ;
        std::cout << "Введите пункт назначения:\n" ;
        getline(std::cin, s11) ;
        list[cnt - 1].point = s11 ;
        std::cout << "Введите время вылета(через':'):\n" ;
        do {
            s11 = "" ;
            q = 0;
            getline(std::cin, s11) ;
            if (!time(s11)) {
                ++q;
                std::cerr << "Введите корректные данные!\n";
            } else break;
        } while (q != 0);
        list[cnt - 1].time = s11 ;
        std::cout << "--------------------------------------------------------------------------\n"
                     "Введите 1, если хотите продолжить ввод данных,\n"
                     "или 2, чтобы завершить ввод данных:\n" ;
        s11 = "" ;
        do {
            s11 = "" ;
            q = 0;
            getline(std::cin, s11) ;
            if (s11 != "1" && s11 != "2") {
                ++q;
                std::cerr << "Введите корректные данные!\n";
            } else break;
        } while (q != 0);
        if (s11 == "2") {
            ++cnt ;
            return list;
        }
        else if (s11 == "1")
            w = 1 ;
        ++cnt ;
    } while (w == 1) ;
    return nullptr;
}

void *qs1(air *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        long long middle = a[(left + right) / 2].number;
        do {
            while (a[left].number < middle)
                ++left ;
            while (a[right].number > middle)
                --right ;
            air tmp = a[left] ;
            if (left <= right) {
                a[left] = a[right] ;
                a[right] = tmp ;
                ++left ;
                --right ;
            }
        } while (left < right) ;
        qs1(a, first, right) ;
        qs1(a, left, last) ;
    }
    return nullptr;
}

void *qs2(air *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        std::string middle = a[(left + right) / 2].type;
        do {
            while (a[left].type < middle)
                ++left ;
            while (a[right].type > middle)
                --right ;
            air tmp = a[left] ;
            if (left <= right) {
                a[left] = a[right] ;
                a[right] = tmp ;
                ++left ;
                --right ;
            }
        } while (left < right) ;
        qs2(a, first, right) ;
        qs2(a, left, last) ;
    }
    return nullptr;
}

void *qs3(air *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        std::string middle = a[(left + right) / 2].point;
        do {
            while (a[left].point < middle)
                ++left ;
            while (a[right].point > middle)
                --right ;
            air tmp = a[left] ;
            if (left <= right) {
                a[left] = a[right] ;
                a[right] = tmp ;
                ++left ;
                --right ;
            }
        } while (left < right) ;
        qs3(a, first, right) ;
        qs3(a, left, last) ;
    }
    return nullptr;
}

void *qs4(air *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        std::string middle = a[(left + right) / 2].time;
        do {
            while (a[left].time < middle)
                ++left ;
            while (a[right].time > middle)
                --right ;
            air tmp = a[left] ;
            if (left <= right) {
                a[left] = a[right] ;
                a[right] = tmp ;
                ++left ;
                --right ;
            }
        } while (left < right) ;
        qs4(a, first, right) ;
        qs4(a, left, last) ;
    }
    return nullptr;
}

void output_all() {
    for (int i = 0; i < cnt - 1; ++i) {
        std::cout << "--------------------------------------------------------------------------\n" <<
                  "Рейс " << i + 1 << ":\n" ;
        std::cout << "Номер рейса: " << list[i].number << '\n' <<
                  "Тип самолёта: " << list[i].type << '\n' <<
                  "Пункт назначения: " << list[i].point << '\n' <<
                  "Время вылета: " << list[i].time << '\n' <<
                  "--------------------------------------------------------------------------\n" ;
    }
}

void search_output() {
    std::cout << "Введите один из параметров(номер рейса, тип самолёта, \n"
                 "пункт назначения, время вылета), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4):\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        if (s != "1" && s != "2" && s != "3" && s != "4") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    if (s == "1") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (std::to_string(list[i].number) == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (std::to_string(list[i].number) == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "2") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].type == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].type == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "3") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].point == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].point == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "4") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].time) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].time == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].time == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs1(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО НОМЕРУ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
}


void delete_few() {
    std::cout << "Введите один из параметров(номер рейса, тип самолёта, \n"
                 "пункт назначения, время вылета), по которому нужно удалить элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4:\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        if (s != "1" && s != "2" && s != "3" && s != "4") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    if (s == "1") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (std::to_string(list[i].number) == ss) {
                for (int j = i; j < cnt - 2; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
    }
    else if (s == "2") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].type == ss) {
                for (int j = i; j < cnt - 2; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
    }
    else if (s == "3") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].point == ss) {
                for (int j = i; j < cnt - 2; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
    }
    else if (s == "4") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss ==list[i].time) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find) ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].time == ss) {
                for (int j = i; j < cnt - 2; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
    }
}

void change() {
    std::cout << "Введите один из параметров(номер рейса, тип самолёта, \n"
                 "пункт назначения, время вылета), по которому нужно изменить элементы элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4:\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        if (s != "1" && s != "2" && s != "3" && s != "4") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    if (s == "1") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find);
        for (int i = 0; i < cnt - 1; ++i) {
            if (std::to_string(list[i].number) == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Самолет " << i + 1 << " :\n\n" <<
                          "Введите новый номер рейса:\n" ;
                int q ;
                std::string s11 = "";
                do {
                    s11 = "" ;
                    q = 0;
                    std::cin >> s11 ;;
                    if (!number(s11)) {
                        ++q;
                        std::cerr << "Введите корректные данные!\n";
                    } else break;
                } while (q != 0);
                list[i].number = std::stoll(s11) ;
            }
        }
    }
    else if (s == "2") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find);
        std::cout << "Введите тип самолёта:\n" ;
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].type == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Самолет " << i + 1 << " :\n\n" <<
                          "Введите новый тип самолёта:\n" ;
                std::string s11;
                getline(std::cin, s11) ;
                list[i].type = s11 ;
            }
        }
    }
    else if (s == "3") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find);
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].point == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Самолет " << i + 1 << " :\n\n" <<
                          "Введите новую точку назначения:\n" ;
                int q ;
                std::string s11;
                getline(std::cin, s11) ;
                list[i].point = s11 ;
            }
        }
    }
    else if (s == "4") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            find = false;
            for (int i = 0; i < cnt - 1; ++i) {
                if (ss == list[i].time) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find)
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
        } while (!find);
        for (int i = 0; i < cnt - 1; ++i) {
            if (list[i].time == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Самолет " << i + 1 << " :\n\n" <<
                          "Введите новое время вылета:\n" ;
                int q ;
                std::string s11 = "";
                do {
                    s11 = "" ;
                    q = 0;
                    std::cin >> s11 ;;
                    if (!time(s11)) {
                        ++q;
                        std::cerr << "Введите корректные данные!\n";
                    } else break;
                } while (q != 0);
                list[i].time = s11 ;
            }
        }
    }
}

void sort_output() {
    std::cout << "Введите один из параметров(номер рейса, тип самолёта, \n"
                 "пункт назначения, время вылета), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4:\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        if (s != "1" && s != "2" && s != "3" && s != "4") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    if (s == "1") {
        air *list1 = list ;
        qs1(list1, 0, cnt - 2) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО НОМЕРУ РЕЙСА:\n\n\n" ;
        for (int i = 0; i < cnt - 1; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "2") {
        air *list1 = list ;
        qs2(list1, 0, cnt - 2) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ТИПУ САМОЛЁТА:\n\n\n" ;
        for (int i = 0; i < cnt - 1; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "3") {
        air *list1 = list ;
        qs3(list1, 0, cnt - 2) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ПУНКТУ НАЗНАЧЕНИЯ:\n\n\n" ;
        for (int i = 0; i < cnt - 1; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "4") {
        air *list1 = list ;
        qs4(list1, 0, cnt - 2) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ВРЕМЕНИ ВЫЛЕТА:\n\n\n" ;
        for (int i = 0; i < cnt - 1; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип самолёта: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время вылета: " << list1[i].time << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
}

int main_menu() {
    std::cout <<"--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "ГЛАВНОЕ МЕНЮ:\n\n" <<
              "Введите:\n" <<
              "1 (запуск ввода или дополнения структуры)\n" <<
              "2 (вывод всей структуры)\n" <<
              "3 (поиск и вывод рейсов с заданными параметрами)\n" <<
              "4 (для удаления определённых рейсов)\n" <<
              "5 (для изменения определённых рейсов)\n" <<
              "6 (для сортировки структуры по определенному параметру и её вывод)\n" <<
              "0 (для завершения программы)\n"
              "--------------------------------------------------------------------------\n" <<
              "--------------------------------------------------------------------------\n" <<
              "--------------------------------------------------------------------------\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5" && s != "6" && s != "0") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
        } else q = 0;
        if (s == "0")
            exit(0) ;
        if (cnt == 1)
            empty = true ;
        if (empty && s != "1") {
            std::cerr << "Структура пуста!!!\n"
                         "Необходимо ввести информацию хотя бы об одном рейсе\n" <<
                      "Введите 1 для заполнения:\n" ;
            ++q ;
        } else empty = false  ;
    } while (q != 0 || empty) ;
    return std::stoi(s) ;
}

int main() {
    do {
        switch (main_menu()) {
            case 1:
                input();
                break;
            case 2:
                output_all();
                break;
            case 3:
                search_output();
                break;
            case 4:
                delete_few();
                break;
            case 5:
                change();
                break;
            case 6:
                sort_output();
                break;
            case 0:
                exit(0);
        }
    } while (true) ;
}