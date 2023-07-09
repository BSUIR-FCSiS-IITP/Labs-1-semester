#include <iostream>
#include <regex>
#include <fstream>

std::fstream manipulate ;

std::ofstream output ("output.txt", std::ios::out) ;
int cnt = 0 ;
int cnt1 = 0 ;
bool empty = true ;

struct air {
    long long number{} ;
    std::string type{} ;
    std::string point{};
    std::string time1{};
    std::string time2{};
};

//air *list = (air *)calloc(1000, sizeof(air)) ;
air *list = new air [1000] ;

bool number(std::string const &str)
{
    return std::regex_match(str, std::regex("^([1-9]\\d*)$")) ;
}

bool time(std::string const &str)
{
    return std::regex_match(str, std::regex("^(([0,1][0-9])|(2[0-3])):[0-5][0-9]$")) ;
}


void initialization() {
    empty = false ;
    manipulate.open("work.txt", std::ios::in) ;
    if(!manipulate.is_open()) {
        std::cout << "Ошибка открытия файла!\n";
        output << "Ошибка открытия файла!\n";
    }
    std::cout << "Введите количество рейсов в файле:\n" ;
    output << "Введите количество рейсов в файле:\n" ;
    std::cin >> cnt ;
    output << cnt << '\n' ;
    long long a ;
    for (int i = 0; i < cnt; ++i) {
        manipulate >> list[i].number >> list[i].type >>
        list[i].point >> list[i].time1 >> list[i].time2 ;
        std::string s ;
        getline(manipulate, s) ;
    }
    std::cout << "Данные инициализированы\n" ;
    output << "Данные инициализированы\n" ;
    manipulate.close() ;
}

int add()
{
    manipulate.open("work.txt", std::ios::app | std::ios::ate) ;
    if (!manipulate.is_open()){
        std::cout << "Ошибка открытия файла!\n";
        output << "Ошибка открытия файла!\n";
    }
    std::cout << "Введите количество рейсов, которые необходимо добавить:\n" ;
    output << "Введите количество рейсов, которые необходимо добавить:\n" ;
    cnt1 = 0 ;
    std::string s ;
    int w = 0 ;
    do {
         w = 0;
        getline(std::cin, s) ;
        if (!number(s) || stoll(s) <= 0) {
            std::cerr << "Введите корректные данные:\n" ;
            output << "Введите корректные данные:\n" ;
            ++w ;
        }
        else
            w = 0 ;

    } while (w != 0) ;
    cnt1 = stoi(s) ;
    for (int i = 0, j = cnt; i < cnt1; ++i, ++j) {
        manipulate << '\n' ;
        std::cout << "Введите номер автобуса:\n" ;
        output << "Введите номер автобуса:\n" ;
        std::cin >> list[j].number ;
        manipulate << list[j].number << '\n' ;
        output << list[j].number << '\n' ;
        std::cout << "Введите тип автобуса:\n" ;
        output << "Введите тип автобуса:\n" ;
        std::cin >> list[j].type ;
        manipulate << list[j].type << '\n' ;
        output << list[j].type << '\n' ;
        std::cout << "Введите пункт назначения:\n" ;
        output << "Введите пункт назначения:\n" ;
        std::cin >> list[j].point ;
        manipulate << list[j].point << '\n' ;
        output << list[j].point << '\n' ;
        std::cout << "Введите время отправления:\n" ;
        output << "Введите время отправления:\n";
        std::cin >> list[j].time1 ;
        manipulate << list[j].time1 << '\n' ;
        output << list[j].time1 << '\n' ;
        std::cout << "Введите время прибытия:\n" ;
        output << "Введите время прибытия:\n";
        std::cin >> list[j].time2 ;
        manipulate << list[j].time2 << '\n' ;
        output << list[j].time2 << '\n' ;
    }
    cnt += cnt1 ;
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
        std::string middle = a[(left + right) / 2].time1;
        do {
            while (a[left].time1 < middle)
                ++left ;
            while (a[right].time1 > middle)
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
void *qs5(air *a, int first, int last) {
    if (first < last) {
        int left = first;
        int right = last;
        std::string middle = a[(left + right) / 2].time2;
        do {
            while (a[left].time2 < middle)
                ++left ;
            while (a[right].time2 > middle)
                --right ;
            air tmp = a[left] ;
            if (left <= right) {
                a[left] = a[right] ;
                a[right] = tmp ;
                ++left ;
                --right ;
            }
        } while (left < right) ;
        qs5(a, first, right) ;
        qs5(a, left, last) ;
    }
    return nullptr;
}

void output_all() {
    for (int i = 0; i < cnt; ++i) {
        std::cout << "--------------------------------------------------------------------------\n" <<
                  "Рейс " << i + 1 << ":\n" ;
        std::cout << "Номер рейса: " << list[i].number << '\n' <<
                  "Тип автобуса: " << list[i].type << '\n' <<
                  "Пункт назначения: " << list[i].point << '\n' <<
                  "Время отправления: " << list[i].time1 << '\n' <<
                  "Время прибытия: " << list[i].time2 << '\n' <<
                  "--------------------------------------------------------------------------\n" ;
        output << "--------------------------------------------------------------------------\n" <<
                  "Рейс " << i + 1 << ":\n" ;
        output << "Номер рейса: " << list[i].number << '\n' <<
                  "Тип автобуса: " << list[i].type << '\n' <<
                  "Пункт назначения: " << list[i].point << '\n' <<
                  "Время отправления: " << list[i].time1 << '\n' <<
                  "Время прибытия: " << list[i].time2 << '\n' <<
                  "--------------------------------------------------------------------------\n" ;
    }
}

void search_output() {
    std::cout << "Введите один из параметров(номер рейса, тип автобуса, \n"
                 "пункт назначения, время отправления, время прибытия), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    output << "Введите один из параметров(номер рейса, тип автобуса, \n"
                 "пункт назначения, время отправления, время прибытия), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        output << s << '\n' ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
            output << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    output << "Введите параметр:\n" ;
    if (s == "1") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (std::to_string(list[i].number) == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (std::to_string(list[i].number) == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        output << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "2") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                            "Введите другой параметр:\n";
            }
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].type == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].type == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        output << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "3") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].point == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].point == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs4(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        output << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "4") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time1) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time1 == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time1 == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs1(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО НОМЕРУ:\n\n\n" ;
        output << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО НОМЕРУ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "5") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time2) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        int t = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time2 == ss)
                ++t ;
        }
        air list1[t];
        int j = 0 ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time2 == ss) {
                list1[j] = list[i] ;
                ++j ;
            }
        }
        qs1(list1, 0, t - 1) ;
        std::cout << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО НОМЕРУ:\n\n\n" ;
        output << "НУЖНЫЕ РЕЙСЫ В ОТСОРТИРОВАННОМ ПОРЯДКЕ ПО НОМЕРУ:\n\n\n" ;
        for (int i = 0; i < t; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
}


void delete_few() {
    std::cout << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно удалить элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    output << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно удалить элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        output << s << '\n' ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
            output << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    output << "Введите параметр:\n" ;
    if (s == "1") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        for (int i = 0; i < cnt; ++i) {
            if (std::to_string(list[i].number) == ss) {
                for (int j = i; j < cnt; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
        if (std::to_string(list[cnt].number) == ss)
            --cnt ;
        if (cnt == 1 && std::to_string(list[0].number) == ss) {
            --cnt;
            empty = true;
        }
    }
    else if (s == "2") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (list[cnt].type == ss)
                    find = true ;
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].type == ss) {
                for (int j = i; j < cnt; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
        if (list[cnt].type == ss)
            --cnt ;
        if (cnt == 1 && list[cnt].type == ss)
            --cnt ;
    }
    else if (s == "3") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (list[cnt].point == ss)
                    find = true ;
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].point == ss) {
                for (int j = i; j < cnt; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
        if (list[cnt].point == ss)
            --cnt ;
        if (cnt == 1 && list[cnt].point == ss)
            --cnt ;
    }
    else if (s == "4") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time1) {
                    find = true;
                }
                if (list[cnt].time1 == ss)
                    find = true ;
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time1 == ss) {
                for (int j = i; j < cnt; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
        if (list[cnt].time1 == ss)
            --cnt ;
        if (cnt == 1 && list[cnt].time1 == ss)
            --cnt ;
    }
    else if (s == "5") {
        std::string ss ;
        bool find = false;
        do {
            ss = "" ;
            getline(std::cin, ss) ;
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time2) {
                    find = true;
                }
                if (list[cnt].time2 == ss)
                    find = true ;
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find) ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time2 == ss) {
                for (int j = i; j < cnt; ++j) {
                    list[j] = list[j + 1] ;
                }
                --cnt ;
            }
        }
        if (list[cnt].time2 == ss)
            --cnt ;
        if (cnt == 1 && list[cnt].time2 == ss)
            --cnt ;
    }
}

void change() {
    std::cout << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно изменить элементы элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    output << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно изменить элементы элементы:\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        output << s << '\n' ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
            output << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    std::cout << "Введите параметр:\n" ;
    output << "Введите параметр:\n";
    if (s == "1") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            output << ss << '\n';
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == std::to_string(list[i].number)) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find);
        for (int i = 0; i < cnt; ++i) {
            if (std::to_string(list[i].number) == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новый номер рейса:\n" ;
                output << "Изменение данных расписания вылетов:\n" ;
                output << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новый номер рейса:\n" ;
                int q ;
                std::string s11 ;
                do {
                    s11 = "" ;
                    q = 0;
                    std::cin >> s11 ;;
                    output << s11 ;
                    if (!number(s11)) {
                        ++q;
                        std::cerr << "Введите корректные данные!\n";
                        output << "Введите корректные данные!\n";
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
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].type) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                          "Введите другой параметр:\n";
            }
        } while (!find);
        std::cout << "Введите тип автобуса:\n" ;
        output << "Введите тип автобуса:\n" ;
        for (int i = 0; i < cnt; ++i) {
            if (list[i].type == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                output << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новый тип автобуса:\n" ;
                output << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новый тип автобуса:\n" ;
                std::string s11;
                getline(std::cin, s11) ;
                output << s11 << '\n' ;
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
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].point) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find);
        for (int i = 0; i < cnt; ++i) {
            if (list[i].point == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новую точку назначения:\n" ;
                output << "Изменение данных расписания вылетов:\n" ;
                output << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новую точку назначения:\n" ;
                int q ;
                std::string s11;
                getline(std::cin, s11) ;
                output << s11 << '\n' ;
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
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time1) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                          "Введите другой параметр:\n";
            }
        } while (!find);
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time1 == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новое Время отправления:\n" ;
                output << "Изменение данных расписания вылетов:\n" ;
                output << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новое Время отправления:\n" ;
                int q;
                std::string s11;
                do {
                    s11 = "" ;
                    q = 0;
                    std::cin >> s11 ;
                    output << s11 << '\n';
                    if (!time(s11)) {
                        ++q;
                        std::cerr << "Введите корректные данные!\n";
                        output << "Введите корректные данные!\n";
                    } else break;
                } while (q != 0);
                list[i].time1 = s11 ;
            }
        }
    }
    else if (s == "5") {
        std::string ss;
        bool find = false;
        do {
            ss = "";
            getline(std::cin, ss);
            output << ss << '\n' ;
            find = false;
            for (int i = 0; i < cnt; ++i) {
                if (ss == list[i].time2) {
                    find = true;
                }
                if (find)
                    break;
            }
            if (!find) {
                std::cerr << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
                output << "Рейсы с указанным параметром отсутствуют!\n"
                             "Введите другой параметр:\n";
            }
        } while (!find);
        for (int i = 0; i < cnt; ++i) {
            if (list[i].time2 == ss) {
                std::cout << "Изменение данных расписания вылетов:\n" ;
                std::cout << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новое время отправления:\n" ;
                output << "Изменение данных расписания вылетов:\n" ;
                output << "--------------------------------------------------------------------------\n" <<
                          "Автобус " << i + 1 << " :\n\n" <<
                          "Введите новое Время отправления:\n" ;
                int q ;
                std::string s11;
                do {
                    s11 = "" ;
                    q = 0;
                    std::cin >> s11 ;
                    output << s11 << '\n';
                    if (!time(s11)) {
                        ++q;
                        std::cerr << "Введите корректные данные!\n";
                        output << "Введите корректные данные!\n";
                    } else break;
                } while (q != 0);
                list[i].time2 = s11 ;
            }
        }
    }
}

void sort_output() {
    std::cout << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    output << "Введите один из параметров(номер рейса, Тип автобуса, \n"
                 "пункт назначения, Время отправления), по которому нужно отсортировать расписание\n"
                 "(вместо слов введите цифру 1, 2, 3, 4, 5):\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        output << s << '\n' ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
            output << "Введите корректные данные!\n";
        } else q = 0;
    } while (q != 0) ;
    if (s == "1") {
        air *list1 = list ;
        qs1(list1, 0, cnt - 1) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО НОМЕРУ РЕЙСА:\n\n\n" ;
        output << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО НОМЕРУ РЕЙСА:\n\n\n" ;
        for (int i = 0; i < cnt; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "2") {
        air *list1 = list ;
        qs2(list1, 0, cnt - 1) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО АВТОБУСА:\n\n\n" ;
        output << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО АВТОБУСА:\n\n\n" ;
        for (int i = 0; i < cnt; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "3") {
        air *list1 = list ;
        qs3(list1, 0, cnt - 1) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ПУНКТУ НАЗНАЧЕНИЯ:\n\n\n" ;
        output << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ПУНКТУ НАЗНАЧЕНИЯ:\n\n\n" ;
        for (int i = 0; i < cnt; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "4") {
        air *list1 = list ;
        qs4(list1, 0, cnt - 1) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        output << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ВРЕМЕНИ ОТПРАВЛЕНИЯ:\n\n\n" ;
        for (int i = 0; i < cnt; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
    else if (s == "5") {
        air *list1 = list ;
        qs5(list1, 0, cnt - 1) ;
        std::cout << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ВРЕМЕНИ ПРИБЫТИЯ:\n\n\n" ;
        output << "ОТСОРТИРОВАННОЕ РАСПИСАНИЕ ПО ВРЕМЕНИ ПРИБЫТИЯ:\n\n\n" ;
        for (int i = 0; i < cnt; ++i) {
            std::cout << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            std::cout << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
            output << "--------------------------------------------------------------------------\n" <<
                      "Рейс " << i + 1 << ":\n" ;
            output << "Номер рейса: " << list1[i].number << '\n' <<
                      "Тип автобуса: " << list1[i].type << '\n' <<
                      "Пункт назначения: " << list1[i].point << '\n' <<
                      "Время отправления: " << list1[i].time1 << '\n' <<
                      "Время прибытия: " << list1[i].time2 << '\n' <<
                      "--------------------------------------------------------------------------\n" ;
        }
    }
}


int main_menu() {
    std::cout <<"--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "ГЛАВНОЕ МЕНЮ:\n\n"
                "Введите:\n"
                "1 (запуск инициализации структуры из файла)\n"
                "2 (вывод всей структуры)\n"
                "3 (поиск и вывод рейсов с заданными параметрами)\n"
                "4 (для удаления определённых рейсов)\n"
                "5 (для изменения определённых рейсов)\n"
                "6 (для сортировки структуры по определенному параметру и её вывод)\n"
                "7 (запуск дополнения файла новыми структурами)\n"
                "0 (для завершения программы)\n"
                "--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n" ;
    output <<"--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "--------------------------------------------------------------------------\n"
                "ГЛАВНОЕ МЕНЮ:\n\n"
              "Введите:\n"
              "1 (запуск инициализации структуры из файла)\n"
              "2 (вывод всей структуры)\n"
              "3 (поиск и вывод рейсов с заданными параметрами)\n"
              "4 (для удаления определённых рейсов)\n"
              "5 (для изменения определённых рейсов)\n"
              "6 (для сортировки структуры по определенному параметру и её вывод)\n"
              "7 (запуск дополнения файла новыми структурами)\n"
              "0 (для завершения программы)\n"
              "--------------------------------------------------------------------------\n"
              "--------------------------------------------------------------------------\n"
              "--------------------------------------------------------------------------\n" ;
    std::string s ;
    int q ;
    do {
        s = "" ;
        q = 0;
        getline(std::cin, s) ;
        output << s << '\n' ;
        if (s != "1" && s != "2" && s != "3" && s != "4" && s != "5" && s != "6" && s != "7" && s != "0") {
            ++q;
            std::cerr << "Введите корректные данные!\n";
            output << "Введите корректные данные!\n";
        } else q = 0;
        if (s == "0")
            exit(0) ;
        if (cnt == 0)
            empty = true ;
        if (empty && s != "1" && s != "7") {
            std::cerr << "Структура пуста!!!\n"
                         "Необходимо ввести информацию хотя бы об одном рейсе\n" <<
                      "Введите 1 для заполнения:\n" ;
            output << "Структура пуста!!!\n"
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
                initialization() ;
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
            case 7:
                add();
                break;
            case 0:
                exit(0);
        }
    } while (true) ;
}