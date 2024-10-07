#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const char *equipmentDetails =
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

struct Participant
{
    int identifier;
    string name;
    string vehicle_id;
};

struct IntelligentVehicle
{
    string vehicle_id;
    string chassis_id;
    string additional_info;
};

class ParticipantManager
{
public:
    vector<Participant> participants;
    vector<IntelligentVehicle> vehicles;
    vector<string> document_names;
    vector<fstream> document_files;
    size_t countVehicles() const
    {
        return vehicles.size();
    }
    size_t countParticipants() const
    {
        return participants.size();
    }
    void registerVehicle(string id, string chassis_id, string additional_info)
    {
        IntelligentVehicle vehicle;
        vehicle.vehicle_id = id;
        vehicle.chassis_id = chassis_id;
        vehicle.additional_info = additional_info;
        vehicles.push_back(vehicle);
        int num = document_names.size() + 1;
        string document_name = "vehicle" + to_string(num) + ".txt";
        ofstream document(document_name);
        if (!document.is_open())
        {
            cout << "无法创建文件 " << endl;
            return;
        }
        document << "车辆ID: " << vehicle.vehicle_id << endl
                 << "车辆底盘ID: " << vehicle.chassis_id << endl
                 << "车辆其他信息: " << vehicle.additional_info << endl;
        document_names.push_back(document_name);
        document.close();
        cout << "车辆信息已保存到文件 " << document_name << endl;
        cout << "车辆信息已注册: " << vehicle.vehicle_id << endl;
    }
    void registerParticipant(int id, string name, string vehicle_id, size_t i)
    {
        Participant participant;
        participant.identifier = id;
        participant.name = name;
        participant.vehicle_id = vehicle_id;
        participants.push_back(participant);
        cout << "参与者信息已添加: " << participant.name << endl;
    }

    void saveToDocument(const string &document_name)
    {
        ofstream document(document_name.c_str()); // 将 std::string 转换为 const char*
        if (!document.is_open())
        {
            cout << "无法创建文件 " << document_name << endl;
            return;
        }
        for (size_t i = 0; i < participants.size(); ++i)
        {
            document << "领用参与者学号：" << participants[i].identifier << "   "
                     << "领用参与者姓名：" << participants[i].name << "   "
                     << "领用车辆编号：" << participants[i].vehicle_id << endl;
        }
        document.close();
        cout << "参与者信息已保存到文件 " << document_name << endl;
    }
    void view(const string &document_name)
    {
        int current_index = 0;
        while (true)
        {
            cout << "打开文件" << document_names[current_index] << endl;
            ifstream vehicle(document_names[current_index]);
            string temp;
            while (getline(vehicle, temp))
            {
                cout << temp << endl;
            }
            if (current_index >= participants.size())
                cout << "未分配参与者" << endl;
            else
                cout << "ID: " << participants[current_index].identifier << ", 姓名: " << participants[current_index].name << ", 车辆编号: " << participants[current_index].vehicle_id << endl;
            char command;
            cout << "输入 'n' 下一个, 'p' 上一个, 'q' 退出 ";
            cin >> command;
            if (command == 'n')
            {
                if (current_index < document_names.size() - 1)
                {
                    current_index++;
                }
                else
                {
                    cout << "已经最后一个了" << endl;
                }
            }
            else if (command == 'p')
            {
                if (current_index > 0)
                {
                    current_index--;
                }
                else
                {
                    cout << "已经第一个了" << endl;
                }
            }
            else if (command == 'q')
            {
                break;
            }
            else
            {
                cout << "无效指令" << endl;
            }
        }
    }
    void listParticipants()
    {
        cout << "当前参与者信息:" << endl;
        for (size_t i = 0; i < participants.size(); ++i)
        {
            cout << "ID: " << participants[i].identifier << ", 姓名: " << participants[i].name << ", 车辆编号: " << participants[i].vehicle_id << endl;
        }
    }
};

int main()
{
    ParticipantManager manager;
    string document_name = "participants.txt";

    int choice;
    do
    {
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

        switch (choice)
        {
        case 1:
        {
            string id;
            string chassis_id;
            string additional_info;
            cout << "输入车辆ID: ";
            cin >> id;
            cout << "输入车辆底盘ID: ";
            cin >> chassis_id;
            cout << "请检查其他信息是否正确 " << endl;
            cout << equipmentDetails << endl;
            cout << "信息是否正确[Y/N]:" << endl;
            char c;
            cin >> c;
            if (c == 'Y')
            {
                cout << "OK" << endl;
                additional_info = equipmentDetails;
                manager.registerVehicle(id, chassis_id, additional_info);
            }
            else
            {
                cout << "不予入库" << endl;
            }
            break;
        }
        case 2:
        {
            int id;
            string name;
            string vehicle_id;
            cout << "输入参与者ID: ";
            cin >> id;
            cout << "输入参与者姓名: ";
            cin >> name;
            bool flag = false;
            cout << "输入分配的车的编号: ";
            cin >> vehicle_id;
            for (size_t i = 0; i < manager.countVehicles(); ++i)
            {
                if (manager.vehicles[i].vehicle_id == vehicle_id)
                {
                    flag = true;
                    manager.registerParticipant(id, name, vehicle_id, i);
                    break;
                }
            }
            if (!flag)
                cout << "没有该车" << endl;
            break;
        }
        case 3:
            manager.listParticipants();
            break;
        case 4:
            manager.saveToDocument(document_name);
            break;
        case 5:
            manager.view(document_name);
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