#include <iostream>
#include <string>
#include <vector>

class WindowManager
{
    std::vector<std::string> v;
public:
    void open(const std::string windowName)
    {
      v.push_back(windowName);//Thêm vào cuối
    }

    void close(const std::string windowName)
    {
    for(int i =0; i<v.size();i++){
        if(v[i]==windowName){
            v.erase(v.begin()+i);
            break;// Tìm đc rồi thì cút thôi
        }
    }
    }

    std::string getTopWindow()
    {
        return v[v.size()-1]; // Trả về phần tử Top( Cuối cùng)
    }
};

#ifndef RunTests
int main()
{
    WindowManager wm;
    wm.open("Calculator");
    wm.open("Browser");
    wm.open("Player");
    wm.close("Browser");
    std::cout << wm.getTopWindow();
}
#endif
