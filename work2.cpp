#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>

using namespace std;

// 前置声明
class Tire;
class Chassis;
class AGXKit;
class DualCamera;
class MultiLineLidar;
class NineAxisGyroscope;
class LCDScreen;
class BatteryModule;
class SmartCar;
class Student;
class StudentManager;

const char* equipmentInfo = 
    "（2）底盘\n"
    "b)型号：SCOUT MINI\n"
    "c)轴距：451mm\n"
    "d)轮距：490mm\n"
    "e)最小离地间隙：115mm\n"
    "f)最小转弯半径：0m\n"
    "g)驱动形式：四轮四驱\n"
    "h)最大行程：10KM\n"
    "i)轮胎（4个）\n"
    "i.型号：公路轮、麦克纳姆轮\n"
    "ii.尺寸：175mm\n"
    "（3）AGX套件（1个）\n"
    "a)型号：AGX Xavier\n"
    "b)AI：32 TOPS\n"
    "c)CUDA核心：512\n"
    "d)Tensor CORE：64\n"
    "e)显存：32G\n"
    "f)存储：32G\n"
    "（4）双目摄像头（1个）\n"
    "a)型号：RealSense D435i\n"
    "b)摄像头：D430\n"
    "c)RGB帧分辨率：1920*1080\n"
    "d)RGB帧率：30\n"
    "e)FOV：87*58\n"
    "f)深度帧率：90\n"
    "（5）多线激光雷达（1个）\n"
    "a)型号：RS-Helios-16p\n"
    "b)通道数：16\n"
    "c)测试范围：100m\n"
    "d)功耗：8W\n"
    "（6）9轴陀螺仪（1个）\n"
    "a)型号：CH110\n"
    "b)厂家：NXP\n"
    "（7）液晶显示屏（1个）\n"
    "a)尺寸：11.6\n"
    "b)型号：super\n"
    "（8）电池模块（1个）\n"
    "a)参数：24V/15Ah\n"
    "b)对外供电：24V\n"
    "c)充电时长：2H";

// 轮胎类
class Tire {
private:
    string type;
    int size;

public:
    Tire() : type("未知"), size(0) {}
    void Set(const string& t, int s) {
        type = t;
        size = s;
    }

    void print() const {
        cout << "轮胎类型: " << type << ", 尺寸: " << size << "mm" << endl;
    }

    void save(ofstream& file) const {
        file << "轮胎类型: " << type << ", 尺寸: " << size << "mm" << endl;
    }
};

// 底盘类
class Chassis {
private:
    string material;
    string model;
    int width;
    int length;
    int groundClearance;
    double turnRadius;
    string driveType;
    int maxRange;

public:
    Chassis() : material("未知"), model("未知"), width(0), length(0), groundClearance(0),
                turnRadius(0), driveType("未知"), maxRange(0) {}
    void Set(const string& m, int w, int l, int gc, double tr, const string& dt, int mr) {
        material = "dp12345678";
        model = m;
        width = w;
        length = l;
        groundClearance = gc;
        turnRadius = tr;
        driveType = dt;
        maxRange = mr;
    }

    void print() const {
        cout << "底盘材质: " << material
             << ", 型号: " << model
             << ", 宽度: " << width << "mm"
             << ", 长度: " << length << "mm"
             << ", 最小离地间隙: " << groundClearance << "mm"
             << ", 最小转弯半径: " << turnRadius << "m"
             << ", 驱动形式: " << driveType
             << ", 最大行程: " << maxRange << "KM" << endl;
    }

    void save(ofstream& file) const {
        file << "底盘材质: " << material
             << ", 型号: " << model
             << ", 宽度: " << width << "mm"
             << ", 长度: " << length << "mm"
             << ", 最小离地间隙: " << groundClearance << "mm"
             << ", 最小转弯半径: " << turnRadius << "m"
             << ", 驱动形式: " << driveType
             << ", 最大行程: " << maxRange << "KM" << endl;
    }
};

// AGX套件类
class AGXKit {
private:
    string model;
    int ai;
    int cudaCores;
    int tensorCores;
    int memory;
    int storage;

public:
    AGXKit() : model("未知"), ai(0), cudaCores(0), tensorCores(0), memory(0), storage(0) {}
    void Set(const string& mod, int a, int cc, int tc, int mem, int sto) {
        model = mod;
        ai = a;
        cudaCores = cc;
        tensorCores = tc;
        memory = mem;
        storage = sto;
    }

    void print() const {
        cout << "AGX套件型号: " << model
             << ", AI性能: " << ai << " TOPS"
             << ", CUDA核心数: " << cudaCores
             << ", Tensor核心数: " << tensorCores
             << ", 显存: " << memory << "G"
             << ", 存储: " << storage << "G" << endl;
    }

    void save(ofstream& file) const {
        file << "AGX套件型号: " << model
             << ", AI性能: " << ai << " TOPS"
             << ", CUDA核心数: " << cudaCores
             << ", Tensor核心数: " << tensorCores
             << ", 显存: " << memory << "G"
             << ", 存储: " << storage << "G" << endl;
    }
};

// 双目摄像头类
class DualCamera {
private:
    string model;
    string camera;
    string resolution;
    int frameRate;
    string fov;
    int depthRate;

public:
    DualCamera() : model("未知"), camera("未知"), resolution("未知"), frameRate(0),
                   fov("未知"), depthRate(0) {}
    void Set(const string& mo, const string& ca, const string& res, int fr, const string& fo, int dr) {
        model = mo;
        camera = ca;
        resolution = res;
        frameRate = fr;
        fov = fo;
        depthRate = dr;
    }

    void print() const {
        cout << "双目摄像头型号: " << model
             << ", 摄像头型号: " << camera
             << ", 分辨率: " << resolution
             << ", 帧率: " << frameRate
             << ", 视场角: " << fov
             << ", 深度帧率: " << depthRate << endl;
    }

    void save(ofstream& file) const {
        file << "双目摄像头型号: " << model
             << ", 摄像头型号: " << camera
             << ", 分辨率: " << resolution
             << ", 帧率: " << frameRate
             << ", 视场角: " << fov
             << ", 深度帧率: " << depthRate << endl;
    }
};

// 多线激光雷达类
class MultiLineLidar {
private:
    string model;
    int channels;
    int range;
    int power;

public:
    MultiLineLidar() : model("未知"), channels(0), range(0), power(0) {}
    void Set(const string& m, int ch, int r, int p) {
        model = m;
        channels = ch;
        range = r;
        power = p;
    }

    void print() const {
        cout << "多线激光雷达型号: " << model
             << ", 通道数: " << channels
             << ", 测试范围: " << range << "m"
             << ", 功耗: " << power << "W" << endl;
    }

    void save(ofstream& file) const {
        file << "多线激光雷达型号: " << model
             << ", 通道数: " << channels
             << ", 测试范围: " << range << "m"
             << ", 功耗: " << power << "W" << endl;
    }
};

// 9轴陀螺仪类
class NineAxisGyroscope {
private:
    string model;
    string manufacturer;

public:
    NineAxisGyroscope() : model("未知"), manufacturer("未知") {}
    void Set(const string& mod, const string& manu) {
        model = mod;
        manufacturer = manu;
    }

    void print() const {
        cout << "9轴陀螺仪型号: " << model
             << ", 厂家: " << manufacturer << endl;
    }

    void save(ofstream& file) const {
        file << "9轴陀螺仪型号: " << model
             << ", 厂家: " << manufacturer << endl;
    }
};

// 液晶显示屏类
class LCDScreen {
private:
    double size;
    string model;

public:
    LCDScreen() : size(0), model("未知") {}
    void Set(double s, const string& m) {
        size = s;
        model = m;
    }

    void print() const {
        cout << "液晶显示屏尺寸: " << size << "英寸"
             << ", 型号: " << model << endl;
    }

    void save(ofstream& file) const {
        file << "液晶显示屏尺寸: " << size << "英寸"
             << ", 型号: " << model << endl;
    }
};

// 电池模块类
class BatteryModule {
private:
    string parameters;
    int outputVoltage;
    int chargeTime;

public:
    BatteryModule() : parameters("未知"), outputVoltage(0), chargeTime(0) {}
    void Set(const string& p, int ov, int ct) {
        parameters = p;
        outputVoltage = ov;
        chargeTime = ct;
    }

    void print() const {
        cout << "电池模块参数: " << parameters
             << ", 对外供电: " << outputVoltage<< "V" << ", 充电时长: " << chargeTime << "小时" << endl;
}

void save(ofstream& file) const {
    file << "电池模块参数: " << parameters
         << ", 对外供电: " << outputVoltage << "V"
         << ", 充电时长: " << chargeTime << "小时" << endl;
}
};

// 智能小车类
class SmartCar {
public:
	string id;
	string other_info;
	Chassis chassis;
	Tire tire;
	AGXKit agxKit;
	DualCamera dualCamera;
	NineAxisGyroscope nineAxisGyroscope;
	MultiLineLidar multiLineLidar;
	LCDScreen lcdScreen;
	BatteryModule batteryModule;
	string studid;

SmartCar() : id("未知"), other_info("无"), studid("无") {}

void Set(const string& info) {
    other_info = info;
    chassis.Set("SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10000);
    tire.Set("公路轮、麦克纳母轮", 175);
    agxKit.Set("AGX Xavier", 32, 512, 64, 32, 32);
    dualCamera.Set("RealSense D435i", "D430", "1920*1080", 30, "87*58", 90);
    multiLineLidar.Set("RS-Helios-16p", 16, 100, 8);
    nineAxisGyroscope.Set("CH110", "NXP");
    lcdScreen.Set(11.6, "super");
    batteryModule.Set("24V/15Ah", 24, 2);
}

void print() const {
    cout << "Smart Car ID: " << id << endl;
    chassis.print();
    tire.print();
    agxKit.print();
    dualCamera.print();
    nineAxisGyroscope.print();
    multiLineLidar.print();
    lcdScreen.print();
    batteryModule.print();
}

void save(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        file << "智能小车信息：" << endl;
        file << "编号：" << id << endl;
        chassis.save(file);
        tire.save(file);
        agxKit.save(file);
        dualCamera.save(file);
        nineAxisGyroscope.save(file);
        multiLineLidar.save(file);
        lcdScreen.save(file);
        batteryModule.save(file);
        file.close();
    } else {
        cerr << "无法打开文件进行写入。" << endl;
    }
}
};

// 学生类
class Student {
public:
string name;
string studentid;
string smartcarid;

Student() : name("未知"), studentid("未知"), smartcarid("未知") {}

void Set(const string& n, const string& id, const string& carid) {
    name = n;
    studentid = id;
    smartcarid = carid;
}

void print() const {
    cout << "学生姓名: " << name << "   学生学号：" << studentid << "   分配的小车：" << smartcarid << endl;
}

void save(const string& filename) const {
    ofstream file(filename, ios::app);
    file << "学生姓名: " << name << "   学生学号：" << studentid << "   分配的小车：" << smartcarid << endl;
}
};

// 学生管理类
class StudentManager {
public:
vector<Student> students;
vector<SmartCar> smartcars;
vector<string> lines;

void addSmartCar() {
    string id, info;
    cout << "输入小车ID: ";
    cin >> id;
    cout << "请检查其他信息是否正确:" << endl << equipmentInfo << endl;
    cout << "信息是否正确[Y/N]: ";
    char c;
    cin >> c;
    if (c == 'Y' || c == 'y') {
        info = equipmentInfo;
        SmartCar smartcar;
        smartcar.id = id;
        smartcar.Set(info);
        smartcars.push_back(smartcar);
        cout << "小车信息已添加: " << smartcar.id << endl;
    } else {
        cout << "不予入库" << endl;
    }
}

void addStudent() {
    string id, name, car_id;
    cout << "输入学生ID: ";
    cin >> id;
    cout << "输入学生姓名: ";
    cin >> name;
    cout << "输入分配的车的编号: ";
    cin >> car_id;
    bool flag = false;
    for (auto& car : smartcars) {
        if (car.id == car_id) {
            flag = true;
            car.studid = id;
            Student student;
            student.Set(name, id, car_id);
            students.push_back(student);
            cout << "学生信息已添加: " << student.name << endl;
            break;
        }
    }
    if (!flag) {
        cout << "没有该车" << endl;
    }
}

void saveToFile(const string& filename) {
    for (auto& car : smartcars) {
        car.save(filename);
        cout << "小车信息已保存到文件 " << filename << endl;
        for (auto& student : students) {
            if (student.studentid == car.studid) {
                student.save(filename);
                cout << "相应学生信息已保存到文件 " << filename << endl;
            }
        }
    }
}

void load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件 " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void displayAll() const {
    cout << "当前学生信息:" << endl;
    for (const auto& student : students) {
        student.print();
    }
    cout << endl << "当前小车信息:" << endl;
    for (const auto& car : smartcars) {
        car.print();
    }
}
};

int main() {
StudentManager manager;
string filename = "students.txt";

int choice;
do {
    cout << "**********欢迎来到智能小车管理系统**********" << endl;
			cout << "你可以进行以下操作:" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         1   添加小车信息并保存           |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         2   添加学生信息并分配           |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         3   显示小车学生分配信息         |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         4   将分配信息保存到文件         |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         5   显示单条相关信息             |" << endl;
			cout << "|------------------------------------------|" << endl;
			cout << "|         0   退出                         |" << endl;
			cout << "|------------------------------------------|" << endl;

        	cout << "请选择【0-5】：" ;
    cin >> choice;

    switch (choice) {
        case 1:
            manager.addSmartCar();
            break;
        case 2:
            manager.addStudent();
            break;
        case 3:
            manager.displayAll();
            break;
        case 4:
            manager.saveToFile(filename);
            break;
        case 5:
            manager.load(filename);
            break;
        case 0:
            cout << "退出系统" << endl;
            break;
        default:
            cout << "无效选择，请重新输入" << endl;
    }
} while (choice != 0);

return 0;
}
