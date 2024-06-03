#include "Login.h"

int main() {
    user_info info;
    info.users = nullptr;
    info.num_users = 0;

    // Load the user information from a file
    ifstream file("users.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            user u;
            file >> u.username >> u.password;
            if (u.username != "") {
                user* new_users = new user[info.num_users + 1];
                for (int i = 0; i < info.num_users; i++) {
                    new_users[i] = info.users[i];
                }
                new_users[info.num_users] = u;
                info.users = new_users;
                info.num_users++;

             
            }
        }
        file.close();
    }

    int choice;
    do {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Forgot password" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            register_user(info);
            break;
        case 2:
            system("cls");
            login(info);
            break;
        case 3:
            system("cls");
            forgot_password(info);
            break;
        case 4:
            cout << "Exiting program." << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (true);

    return 0;
}
