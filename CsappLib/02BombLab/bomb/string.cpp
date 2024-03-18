#include<iostream>
#include<string>
#include<fstream>

int main() {
    std::ifstream file("asciidata.txt"); // 打开输入文件
    if (!file.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) { // 逐行读取文件
        std::string translatedData; // 用于存储翻译后的字符数据
        for (size_t i = 0; i < line.length(); i += 2) { // 每两个字符表示一个ASCII码
            std::string byte = line.substr(i, 2); // 从line中提取两个字符
            char ch = std::stoi(byte, nullptr, 16); // 将两个字符转换为一个字符
            translatedData.push_back(ch); // 将字符添加到translatedData中
        }

        std::cout << "翻译后的数据: " << translatedData << std::endl;
    }

    file.close(); // 关闭文件

    return 0;
}
