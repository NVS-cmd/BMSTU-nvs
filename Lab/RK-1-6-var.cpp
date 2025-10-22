#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

// Функция для преобразования числа из строки вручную
double parseNumber(const char* p) {
    string num = "";
    // Пока символ — цифра, минус, точка
    while ((*p >= '0' && *p <= '9') || *p == '.' || *p == '-') {
        num += *p;
        p++;
    }
    return stod(num); // превращаем в double
}

int main() {
    // Входные данные
    vector<string> navData = {
        "LAT:55.7522;LON:37.6156;ALT:180.5;SPD:7.4",
        "LAT:55.7519;LON:37.6161;ALT:182.3;SPD:7.8",
        "LAT:55.7515;LON:37.6169;ALT:183.1;SPD:8.1"
    };

    vector<double> lat, lon, alt, spd;

    for (string s : navData) {
        const char* p = s.c_str();

        // Ищем метки
        const char* latPos = strstr(p, "LAT:") + 4;
        const char* lonPos = strstr(p, "LON:") + 4;
        const char* altPos = strstr(p, "ALT:") + 4;
        const char* spdPos = strstr(p, "SPD:") + 4;

        // Добавляем в векторы
        lat.push_back(parseNumber(latPos));
        lon.push_back(parseNumber(lonPos));
        alt.push_back(parseNumber(altPos));
        spd.push_back(parseNumber(spdPos));
    }

    // Средняя высота
    double sumAlt = 0;
    for (auto x : alt) sumAlt += x;
    double avgAlt = sumAlt / alt.size();

    // Максимальная скорость
    double maxSpd = spd[0];
    for (auto x : spd) if (x > maxSpd) maxSpd = x;

    // Средняя разница широт/долгот
    double shift = 0;
    for (int i = 1; i < lat.size(); i++) {
        double dLat = fabs(lat[i] - lat[i - 1]);
        double dLon = fabs(lon[i] - lon[i - 1]);
        shift += (dLat + dLon) / 2.0;
    }
    shift /= (lat.size() - 1);

    // Проверяем равномерность движения
    for (int i = 1; i < spd.size(); i++) {
        if (fabs(spd[i] - spd[i - 1]) > 0.5) {
            cout << "Warning: неравномерное движение между точками " 
                 << i << " и " << i + 1 << "\n";
        }
    }

    cout << "Average altitude: " << avgAlt << " m\n";
    cout << "Max speed: " << maxSpd << " m/s\n";
    cout << "Average lat/lon shift: " << shift << "\n";

    return 0;
}
