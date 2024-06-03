#include "functions/FileIO/FileIO.h"
#include "functions/Login/Login.h"
#include "global.h"
int main()
{
    std::string loggedInUsername = login();

    if (loggedInUsername == "")
    {
        std::cout << "Login failed" << std::endl;
        return 0;
    }
    std::cout << "Login successful" << std::endl;
    // TODO: Hiển thị menu:
    // TODO: Gồm: xem profile người dùng hiện tại (từ file CSV), Logout, đổi pass
    // TODO: Và menu cho các phần liên quan đến Giáo vụ
}