#pragma once
#include "State.h"
#include "System.h"

class NotStaff : public State
{
   private:
    Data *_data;
    sf::Sprite _profilepic;
    sf::RectangleShape _background;
    sf::Text _username;
    sf::Text _logout;
    bool _logoutfocus;
    bool _logoutselected;
    sf::Text _changepass;
    bool _changepassfocus;
    bool _changepassselected;
    std::string username;
    sf::RectangleShape _namebox;
    sf::RectangleShape _genderbox;
    sf::RectangleShape _idbox;
    sf::RectangleShape _socialIDbox;
    sf::RectangleShape _classbox;
    sf::RectangleShape _viewScoreBox;
    sf::Text _viewCourse;
    sf::RectangleShape _viewCourseBox;
    sf::RectangleShape _logoutBox;
    sf::RectangleShape _changeBox;
    sf::RectangleShape _dobBox;
    sf::Text _gender;
    sf::Text gender;
    sf::Text _id;
    sf::Text id;
    sf::Text _socialID;
    sf::Text socialID;
    sf::Text _dob;
    sf::Text dob;
    sf::Text _class;
    sf::Text str_class;
    sf::Text _viewScore;
    // sf::RectangleShape _studentbox;
    // sf::Text _student;
    // bool _studentfocus;
    // bool _studentselected;
    // sf::RectangleShape _coursebox;
    // sf::Text _course;
    // bool _coursefocus;
    // bool _courseselected;

   public:
    NotStaff(Data *data);
    ~NotStaff();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};
