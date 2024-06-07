#include "ScoreView.h"
#include<math.h>

ScoreView::ScoreView(Data* data) : _data(data), _exitfocus(0), _exitselected(0)
{

}
ScoreView::~ScoreView()
{

}
void ScoreView::Init()
{
	cur = 0;
	_title.setFont(_data->_assets->GetFont(LIGHT));
	_title.setString("No      Student ID          Full Name                    Midterm        Final        Other");
	_title.setFillColor(sf::Color::Red);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::Red);

	std::ifstream f("buffer.txt");
	getline(f, tmp);
	f.close();
	std::ifstream file("Score\\" + tmp + ".csv");
	std::string get;
	do
	{
		getline(file, get);
	} while (get.empty());

	std::string No, id, name, mterm, final, other;
	while (!file.eof())
	{
		getline(file, No, ',');
		getline(file, id, ',');
		getline(file, name, ',');
		getline(file, mterm, ',');
		getline(file, final, ',');
		getline(file, other);
		if (No.empty())
		{
			continue;
		}
		_No[cur].setFont(_data->_assets->GetFont(LIGHT));
		_No[cur].setFillColor(sf::Color::Black);
		_No[cur].setPosition(0, cur * 30 + 30);
		_No[cur].setString(No);

		_id[cur].setFont(_data->_assets->GetFont(LIGHT));
		_id[cur].setFillColor(sf::Color::Black);
		_id[cur].setPosition(90, cur * 30 + 30);
		_id[cur].setString(id);

		_name[cur].setFont(_data->_assets->GetFont(LIGHT));
		_name[cur].setFillColor(sf::Color::Black);
		_name[cur].setPosition(310, cur * 30 + 30);
		_name[cur].setString(name);
		_name->setCharacterSize(25);

		_mterm[cur].setFont(_data->_assets->GetFont(LIGHT));
		_mterm[cur].setFillColor(sf::Color::Black);
		_mterm[cur].setPosition(650, cur * 30 + 30);
		_mterm[cur].setString(mterm);

		_final[cur].setFont(_data->_assets->GetFont(LIGHT));
		_final[cur].setFillColor(sf::Color::Black);
		_final[cur].setPosition(800, cur * 30 + 30);
		_final[cur].setString(final);

		_other[cur].setFont(_data->_assets->GetFont(LIGHT));
		_other[cur].setFillColor(sf::Color::Black);
		_other[cur].setPosition(950, cur * 30 + 30);
		_other[cur].setString(other);
		cur++;
	}

}
void ScoreView::ProcessInput()
{
	sf::Event event;
	while (_data->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_data->_window->close();
		}
		if (event.type == sf::Event::MouseMoved)
		{
			_exitfocus = (_exitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);

		}
	}
}
void ScoreView::Update()
{
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;

	}
}
void ScoreView::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	for (int i = 0; i < cur; i++)
	{
		_data->_window->draw(_No[i]);
		_data->_window->draw(_id[i]);
		_data->_window->draw(_name[i]);
		_data->_window->draw(_mterm[i]);
		_data->_window->draw(_final[i]);
		_data->_window->draw(_other[i]);

	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->display();
}










ScoreView1::ScoreView1(Data* data) : _data(data), _exitfocus(0), _exitselected(0)
{

}
ScoreView1::~ScoreView1()
{

}
void ScoreView1::Init()
{
	cur = 0;

	_title.setFont(_data->_assets->GetFont(CHIVOMONO_LIGHT));
	_title.setString("         Course ID      Midterm Final   Other  Total   GPA");
	_title.setCharacterSize(24);
	_title.setFillColor(sf::Color::Red);

	_exitbutton.setSize(sf::Vector2f(150, 40));
	_exitbutton.setFillColor(sf::Color::Black);
	_exitbutton.setOrigin(sf::Vector2f(_exitbutton.getGlobalBounds().width / 2, _exitbutton.getGlobalBounds().height / 2));
	_exitbutton.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 250);

	_exit.setFont(_data->_assets->GetFont(LIGHT));
	_exit.setString("Exit");
	_exit.setOrigin(sf::Vector2f(_exit.getGlobalBounds().width / 2, _exit.getGlobalBounds().height / 2));
	_exit.setPosition(_data->_window->getSize().x / 2, _data->_window->getSize().y / 2 + 240);
	_exit.setFillColor(sf::Color::Red);
	float gpa = 0;
	bool ok = 1;
	std::ifstream f("Studentbuf.txt");
	getline(f, tmp);
	f.close();
	std::ifstream file("StudentScore\\" + tmp + ".txt");
	std::string get;
	std::string id, mterm, final, other;
	while (!file.eof())
	{
		getline(file, id, ',');
		getline(file, mterm, ',');
		getline(file, final, ',');
		getline(file, other);
		if (id.empty())
		{
			continue;
		}

		_cell1[cur].setSize(sf::Vector2f(200.0f, 40.0f));
		_cell1[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell1[cur].setOutlineColor(sf::Color::Black);
		_cell1[cur].setOutlineThickness(1);
		_cell1[cur].setPosition(130, cur * 50 + 40);

		_cell2[cur].setSize(sf::Vector2f(100.0f, 40.0f));
		_cell2[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell2[cur].setOutlineColor(sf::Color::Black);
		_cell2[cur].setOutlineThickness(1);
		_cell2[cur].setPosition(340, cur * 50 + 40);

		_cell3[cur].setSize(sf::Vector2f(100.0f, 40.0f));
		_cell3[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell3[cur].setOutlineColor(sf::Color::Black);
		_cell3[cur].setOutlineThickness(1);
		_cell3[cur].setPosition(450, cur * 50 + 40);

		_cell4[cur].setSize(sf::Vector2f(100.0f, 40.0f));
		_cell4[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell4[cur].setOutlineColor(sf::Color::Black);
		_cell4[cur].setOutlineThickness(1);
		_cell4[cur].setPosition(560, cur * 50 + 40);

		_cell5[cur].setSize(sf::Vector2f(100.0f, 40.0f));
		_cell5[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell5[cur].setOutlineColor(sf::Color::Black);
		_cell5[cur].setOutlineThickness(1);
		_cell5[cur].setPosition(670, cur * 50 + 40);

		_cell6[cur].setSize(sf::Vector2f(100.0f, 40.0f));
		_cell6[cur].setFillColor(sf::Color(214, 219, 223, 240));
		_cell6[cur].setOutlineColor(sf::Color::Black);
		_cell6[cur].setOutlineThickness(1);
		_cell6[cur].setPosition(780, cur * 50 + 40);

		_id[cur].setFont(_data->_assets->GetFont(LIGHT));
		_id[cur].setFillColor(sf::Color::Black);
		_id[cur].setPosition(130, cur * 50 + 40);
		_id[cur].setString(id.substr(id.find("(") + 1, id.find(")") - id.find("(") - 1));


		_mterm[cur].setFont(_data->_assets->GetFont(LIGHT));
		_mterm[cur].setFillColor(sf::Color::Black);
		_mterm[cur].setPosition(350, cur * 50 + 40);
		_mterm[cur].setString(mterm);

		_final[cur].setFont(_data->_assets->GetFont(LIGHT));
		_final[cur].setFillColor(sf::Color::Black);
		_final[cur].setPosition(470, cur * 50 + 40);
		_final[cur].setString(final);

		_other[cur].setFont(_data->_assets->GetFont(LIGHT));
		_other[cur].setFillColor(sf::Color::Black);
		_other[cur].setPosition(570, cur * 50 + 40);
		_other[cur].setString(other);
		if (mterm != "/" && final != "/" && other != "/")
		{
			float mark = (std::stof(mterm) + std::stof(final) * 2 + std::stof(other)) / 4;
			mark = round(mark * 10) / 10;
			
			_finalmark[cur].setFont(_data->_assets->GetFont(LIGHT));
			_finalmark[cur].setFillColor(sf::Color::Black);
			_finalmark[cur].setPosition(680, cur * 50 + 40);
			_finalmark[cur].setString(std::to_string(mark).substr(0 , 3));
			gpa += mark;
		}
			
		else
		{
			_finalmark[cur].setFont(_data->_assets->GetFont(LIGHT));
			_finalmark[cur].setFillColor(sf::Color::Black);
			_finalmark[cur].setPosition(680, cur * 50 + 40);
			_finalmark[cur].setString("/");
			ok = 0;
		}
		cur++;
	}
	if (ok)
	{
		_gpa.setFont(_data->_assets->GetFont(LIGHT));
		_gpa.setFillColor(sf::Color::Black);
		_gpa.setPosition(790, 40);
		_gpa.setString(std::to_string(gpa).substr(0, 3));
	}
	else
	{
		_gpa.setFont(_data->_assets->GetFont(LIGHT));
		_gpa.setFillColor(sf::Color::Black);
		_gpa.setPosition(790, 40);
		_gpa.setString("/");
	}
}
void ScoreView1::ProcessInput()
{
	sf::Event event;
	while (_data->_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_data->_window->close();
		}
		if (event.type == sf::Event::MouseMoved)
		{
			_exitfocus = (_exitbutton.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*_data->_window).x, sf::Mouse::getPosition(*_data->_window).y)) ? 1 : 0);

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_exitselected = (_exitfocus ? 1 : 0);

		}
	}
}
void ScoreView1::Update()
{
	(_exitfocus ? _exitbutton.setFillColor(sf::Color::Yellow) : _exitbutton.setFillColor(sf::Color::Black));
	if (_exitselected)
	{
		_data->_states->RemoveState();
		_exitselected = 0;

	}
}
void ScoreView1::Draw()
{
	_data->_window->clear(sf::Color::White);
	_data->_window->draw(_title);
	for (int i = 0; i < cur; ++i)
	{
		_data->_window->draw(_cell1[i]);
		_data->_window->draw(_cell2[i]);
		_data->_window->draw(_cell3[i]);
		_data->_window->draw(_cell4[i]);
		_data->_window->draw(_cell5[i]);
		_data->_window->draw(_cell6[i]);
	}
	for (int i = 0; i < cur; i++)
	{
		_data->_window->draw(_id[i]);
		_data->_window->draw(_mterm[i]);
		_data->_window->draw(_final[i]);
		_data->_window->draw(_other[i]);
		_data->_window->draw(_finalmark[i]);
	}
	_data->_window->draw(_exitbutton);
	_data->_window->draw(_exit);
	_data->_window->draw(_gpa);
	_data->_window->display();
}









