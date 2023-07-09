#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std ;

    int main() {
        long double k, x, y, a;
        long double r = 0;

        cin >> k;
        cin >> x;
        cin >> y;

        if (k > 0) {

            //точка находится вне квадрата

            if (x >= 0 && y <= 0 && y <= k) r = -y;
            else if (x <= 0 && y >= 0 && y <= k) r = -x;
            else if (x >= k && y >= 0 && y <= k) r = x - k;
            else if (y >= k && x >= 0 && x <= k) r = y - k;
            else if (x < 0 && y > k) r = sqrt(x * x + (y - k) * (y - k));
            else if (x < 0 && y < 0) r = sqrt(x * x + y * y);
            else if (x > k && y > k) r = sqrt((x - k) * (x - k) + (y - k) * (y - k));
            else if (x > k && y < 0) r = sqrt((x - k) * (x - k) + y * y);
		
		//точка находится  внутри квадрата
		else if (y <= x && y <= (k - x)) r = y;
            else if (y >= x && y <= (k - x)) r = x;
            else if (y >= x && y >= (k - x)) r = -k + y;
            else r = -k + x;
        }





        if (k < 0) {

            //точка находится вне квадрата

            if (y <= k && x >= k && x < 0) r = abs(y - k);
            else if (x <= k && y >= k && y <= 0) r = abs(x - k);
            else if (x <= 0 && x >= k && y >= 0) r = y;
            else if (x >= 0 && y >= k && y <= 0) r = x;
            else if (y < k && x < k) r = sqrt((x - k) * (x - k) + (y - k) * (y - k));
            else if (y > 0 && x < k) r = sqrt((x - k) * (x - k) + (y * y));
            else if (y > 0 && x > 0) r = sqrt((x * x) + (y * y));
            else if (y < k && x>0) r = sqrt((x * x) + (y - k) * (y - k));


            //точка находится внутри квадрата

            else if (y <= x && y >= (-k - x)) r = -x;
            else if (y >= x && y >= (-k - x)) r = -y;
            else if (y <= (-k - x) && y <= x) r = -k - y;
            else r = -k - x;
        }
        cout << setprecision(22) << r << endl;
        return 0;
}