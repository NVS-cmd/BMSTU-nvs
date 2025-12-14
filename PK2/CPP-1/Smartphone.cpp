#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <memory>

using namespace std;

class ElectronicDevice {
protected:
    string brand, model;
    double price;
    vector<string> apps;
    
public:
    ElectronicDevice() = default;
    ElectronicDevice(string b, string m, double p) : brand(b), model(m), price(p) {}
    
    // деструктор
    virtual ~ElectronicDevice() = default;
    
    // полиморфизм
    virtual void display() const = 0;
    virtual string getType() const = 0;
    virtual string getParam() const = 0;
    
    // Геттеры/сеттеры
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }
    void setModel(string m) { model = m; }
    void addApp(const string& app) { apps.push_back(app); }
    
    // Сериализация
    virtual void saveToFile(ofstream& file) const {
        file << getType() << ";" << brand << ";" << model << ";" 
             << fixed << setprecision(2) << price << ";" << getParam();
        for (const auto& app : apps) file << "|" << app;
    }
};

// 2. Smartphone
class Smartphone : public ElectronicDevice {
private:
    string osMemory;
public:
    Smartphone(string b, string m, double p, string param) 
        : ElectronicDevice(b, m, p), osMemory(param) {}
    
    void display() const override {
        cout << "📱 " << brand << " " << model << " | $" 
             << fixed << setprecision(2) << price << " | " << osMemory;
        if (!apps.empty()) {
            cout << " | Apps: ";
            for (size_t i = 0; i < apps.size(); ++i) {
                cout << apps[i];
                if (i < apps.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }
    
    string getType() const override { return "Smartphone"; }
    string getParam() const override { return osMemory; }
    
    int getMemoryGB() const {
        size_t pos = osMemory.find('-');
        if (pos != string::npos) {
            string mem = osMemory.substr(pos + 1);
            if (!mem.empty() && mem.back() == 'B') mem.pop_back();
            try { return stoi(mem); } catch (...) { return 0; }
        }
        return 0;
    }
};

// 3. Laptop
class Laptop : public ElectronicDevice {
private:
    string screenBattery;
public:
    Laptop(string b, string m, double p, string param) 
        : ElectronicDevice(b, m, p), screenBattery(param) {}
    
    void display() const override {
        cout << "💻 " << brand << " " << model << " | $" 
             << fixed << setprecision(2) << price << " | " << screenBattery;
        if (!apps.empty()) {
            cout << " | Apps: ";
            for (size_t i = 0; i < apps.size(); ++i) {
                cout << apps[i];
                if (i < apps.size() - 1) cout << ", ";
            }
        }
        cout << endl;
    }
    
    string getType() const override { return "Laptop"; }
    string getParam() const override { return screenBattery; }
    
    double getScreenSize() const {
        size_t pos = screenBattery.find('-');
        if (pos != string::npos) {
            try { return stod(screenBattery.substr(0, pos)); } 
            catch (...) { return 0.0; }
        }
        return 0.0;
    }
};

// 4. Загрузка из devices.txt
list<ElectronicDevice*> loadDevices(const string& filename) {
    list<ElectronicDevice*> devices;
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "❌ Файл " << filename << " не найден!" << endl;
        return devices;
    }
    
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        
        stringstream ss(line);
        string type, brand, model, priceStr, param, appsStr;
        
        // ✅ ТОЧНЫЙ парсинг по ';'
        if (!getline(ss, type, ';')) continue;
        if (!getline(ss, brand, ';')) continue;
        if (!getline(ss, model, ';')) continue;
        if (!getline(ss, priceStr, ';')) continue;
        if (!getline(ss, param, ';')) continue;
        
        // ✅ ПОСЛЕДНИЙ getline БЕЗ разделителя - берёт остаток строки!
        getline(ss, appsStr);  // ← ВОТ ЗДЕСЬ БЫЛО ';', стало ничего!
        
        double price;
        try { price = stod(priceStr); } catch (...) { continue; }
        
        ElectronicDevice* device = nullptr;
        if (type == "Smartphone") {
            device = new Smartphone(brand, model, price, param);
        } else if (type == "Laptop") {
            device = new Laptop(brand, model, price, param);
        }
        
        if (device) {
            // ✅ Парсинг приложений по '|'
            stringstream appsSS(appsStr);
            string app;
            while (getline(appsSS, app, '|')) {
                if (!app.empty()) device->addApp(app);
            }
            devices.push_back(device);
        }
    }
    cout << "✅ Загружено устройств: " << devices.size() << endl;
    return devices;
}


// 5. Вывод через итераторы
void printAllDevices(const list<ElectronicDevice*>& devices) {
    cout << "\n=== 📋 ВСЕ УСТРОЙСТВА (" << devices.size() << ") ===" << endl;
    for (const auto* device : devices) {
        device->display();
    }
}

// 6. Изменение через указатель
void modifyDevice(ElectronicDevice* device, double newPrice, string newModel, 
                  const string& newApp) {
    device->setPrice(newPrice);
    device->setModel(newModel);
    device->addApp(newApp);
    cout << "✅ Изменено: " << device->getBrand() << " " << newModel 
         << " | $" << fixed << setprecision(2) << newPrice << endl;
}

// 7. Лямбда-функции
void demoLambdas(const list<ElectronicDevice*>& devices) {
    cout << "\n=== 🧮 ЛЯМБДА-ФУНКЦИИ ===" << endl;
    
    // ❌ УДАЛИТЕ for_each - замените на Обычный цикл
    int bigLaptops = 0;
    for (const auto* d : devices) {  // ← Обычный range-based цикл
        Laptop* laptop = dynamic_cast<Laptop*>(const_cast<ElectronicDevice*>(d));
        if (laptop && laptop->getScreenSize() > 15.0) {
            bigLaptops++;
        }
    }
    cout << "📊 Ноутбуков >15\": " << bigLaptops << endl;
    
    // Макс память - тоже обычный цикл
    int maxMem = 0;
    for (const auto* d : devices) {
        if (Smartphone* phone = dynamic_cast<Smartphone*>(const_cast<ElectronicDevice*>(d))) {
            int mem = phone->getMemoryGB();
            if (mem > maxMem) maxMem = mem;
        }
    }
    cout << "🏆 Макс память смартфонов: " << maxMem << "GB" << endl;
}



// 8. Фильтр по цене
void filterByPrice(const list<ElectronicDevice*>& devices, double minPrice) {
    cout << "\n=== 💰 ФИЛЬТР > $" << fixed << setprecision(2) << minPrice << " ===" << endl;
    vector<ElectronicDevice*> filtered;
    
    copy_if(devices.begin(), devices.end(), back_inserter(filtered),
        [minPrice](ElectronicDevice* d) { return d->getPrice() > minPrice; });
    
    for (const auto* d : filtered) d->display();
}

// 9. Поиск смартфона с максимальной памятью
Smartphone* findMaxMemoryPhone(const list<ElectronicDevice*>& devices) {
    auto it = max_element(devices.begin(), devices.end(), 
        [](ElectronicDevice* a, ElectronicDevice* b) {
            if (Smartphone* pa = dynamic_cast<Smartphone*>(a)) {
                if (Smartphone* pb = dynamic_cast<Smartphone*>(b)) {
                    return pa->getMemoryGB() < pb->getMemoryGB();
                }
            }
            return false;
        });
    
    return (it != devices.end() && dynamic_cast<Smartphone*>(*it)) 
           ? dynamic_cast<Smartphone*>(*it) : nullptr;
}

// 10. Сортировка по бренду (возр) + цене (убыв)
void sortDevices(list<ElectronicDevice*>& devices) {
    devices.sort([](ElectronicDevice* a, ElectronicDevice* b) {
        if (a->getBrand() != b->getBrand()) {
            return a->getBrand() < b->getBrand();  // бренд по алфавиту
        }
        return a->getPrice() > b->getPrice();      // цена по убыванию
    });
}

int main() {
    cout << "🚀 Запуск моделирования электронных устройств..." << endl;
    
    // 4. Загрузка данных
    auto devices = loadDevices("devices.txt");
    
    // 5. Вывод всех устройств
    printAllDevices(devices);
    
    // 6. Изменение первого устройства
    if (!devices.empty()) {
        modifyDevice(devices.front(), 950.0, "iPhone 13 Updated", "Camera Pro");
        printAllDevices(devices);
    }
    
    // 7. Лямбда-функции
    demoLambdas(devices);
    
    // 8. Фильтр по цене
    filterByPrice(devices, 900.0);
    
    // 9. Максимальная память
    if (auto* maxPhone = findMaxMemoryPhone(devices)) {
        cout << "\n🔍 Макс память (max_element): " << maxPhone->getBrand() 
             << " " << maxPhone->getModel() << endl;
    }
    
    // 10. Сортировка
    sortDevices(devices);
    printAllDevices(devices);
    
    // ✅ Освобождение памяти
    for (auto* d : devices) delete d;
    
    cout << "\n✅ Программа завершена успешно!" << endl;
    return 0;
}
