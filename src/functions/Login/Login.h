#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

struct user {
    string username;
    string password;
};

struct user_info {
    user* users;
    int num_users;
};

void register_user(user_info& info) {
    user new_user;
    cout << "Enter a username: ";
    cin >> new_user.username;
    cout << "Enter a password: ";
    cin >> new_user.password;

    // Check if the username already exists
    for (int i = 0; i < info.num_users; i++) {
        if (info.users[i].username == new_user.username) {
            cout << "Username already exists. Please choose a different username." << endl;
            return;
        }
    }

    // Add the new user to the array
    user* new_users = new user[info.num_users + 1];
    for (int i = 0; i < info.num_users; i++) {
        new_users[i] = info.users[i];
    }
    new_users[info.num_users] = new_user;

    // Update the user_info structure
    info.users = new_users;
    info.num_users++;

    
    // Save the updated user information to a file
    ofstream file("users.txt");
    for (int i = 0; i < info.num_users; i++) {
        file << info.users[i].username << " " << info.users[i].password << endl;
    }
    file.close();

    cout << "Registration successful. You can now log in with your username and password." << endl;
}

void login(user_info info) {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check if the username and password match
    for (int i = 0; i < info.num_users; i++) {
        if (info.users[i].username == username && info.users[i].password == password) {
            cout << "Login successful. Welcome, " << username << "!" << endl;
            return;
        }
    }

    cout << "Incorrect username or password. Please try again." << endl;
}
