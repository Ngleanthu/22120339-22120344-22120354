#pragma once
#include <fstream>
#include "State.h"
#include "System.h"

class CreateYear : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box;
    sf::Text _text;
    sf::Text _showbox;
    std::string _getbox;
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus;
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    sf::Text _example;
    std::ofstream file;

   public:
    CreateYear(Data *data);
    ~CreateYear();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};
class Create : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box;
    sf::Text _text;
    sf::Text _showbox;
    std::string _getbox;
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus;
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    sf::Text _example;
    std::ofstream file;

   public:
    Create(Data *data);
    ~Create();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};

class AddStudent : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box[7];
    sf::Text _text[7];
    sf::Text _showbox[7];
    std::string _getbox[7];
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus[7];
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    std::fstream file;
    sf::Text _status;

   public:
    AddStudent(Data *data);
    ~AddStudent();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};

class CreateSemester : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box[4];
    sf::Text _text[4];
    sf::Text _showbox[4];
    std::string _getbox[4];
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus[4];
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    std::fstream file;

   public:
    CreateSemester(Data *data);
    ~CreateSemester();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};

class AddCourse : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box[8];
    sf::Text _text[8];
    sf::Text _showbox[8];
    std::string _getbox[8];
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus[8];
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    std::string get;
    std::fstream file;
    sf::Text _status;

   public:
    AddCourse(Data *data);
    ~AddCourse();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};

class UpdateCourse : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box[7];
    sf::Text _text[7];
    sf::Text _showbox[7];
    std::string _getbox[7];
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus[7];
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    std::string get;
    std::fstream file;
    sf::Text _status;

   public:
    UpdateCourse(Data *data);
    ~UpdateCourse();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};

class AddStudent2 : public State
{
   private:
    Data *_data;
    sf::Time time;
    sf::Clock clock;
    sf::RectangleShape _box;
    sf::Text _text;
    sf::Text _showbox;
    std::string _getbox;
    sf::RectangleShape _submitbutton;
    sf::RectangleShape _exitbutton;
    sf::Text _submit;
    sf::Text _exit;
    bool _boxfocus;
    bool _blink;
    bool _exitfocus;
    bool _submitfocus;
    bool _exitselected;
    bool _submitselected;
    std::fstream file;
    sf::Text _status;
    std::string get;

   public:
    AddStudent2(Data *data);
    ~AddStudent2();
    void Init();
    void ProcessInput();
    void Update();
    void Draw();
};