#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

/*
-Do việc lưu trữ dữ liệu bằng unordered_map là hợp lý, tuy nhiên không cần tạo thêm 1 class Record như ban đầu 
mà dùng bằng vector.
- Sử dụng vector không sợ bị rò rỉ bộ nhớ
Truy cập Title, Content dễ dàng với biến istance id
*/


class Archive
{
    std::string title;
    std::string content;

public:
    void add(int id, std::string title, std::string content)
    {
        std::vector<std::string> v;
        v.push_back(title);
        v.push_back(content);
        records[id] = v;
        this->id = id;
    }

    void remove(int id)
    {

        records[id].clear();
    }
    void clear()
    {
        records.clear();
    }
    int id;
    std::unordered_map<int, std::vector<std::string>> records;
};

#ifndef RunTests
int main()
{
    Archive archive;

    archive.add(123456, "Hamlet", "Hamlet, Prince of Denmark.");

    std::cout << "ID: " << archive.id << " || Title: " << archive.records[archive.id][0] << " || Content: " << archive.records[archive.id][1] << std::endl;

    archive.add(123457, "Othello", "Othello, the Moore of Venice.");
    std::cout << "ID: " << archive.id << " || Title: " << archive.records[archive.id][0] << " || Content: " << archive.records[archive.id][1] << std::endl;

    archive.remove(123456);
    // Remove luôn khỏi phải truy cập lại

    archive.clear(); // Xoá hết
}
#endif
