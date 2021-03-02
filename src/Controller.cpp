#include "Controller.h"

Controller::Controller()
{}

//------------------make outbounding rectangles for characters----------------------
void Controller::make_rectangles_array(sf::RectangleShape* object_array, int size) const
{
	for (int i = 0; i < size; i++)
	{
		object_array[i].setSize(sf::Vector2f(60, 60)); // width of menu boxes
		object_array[i].setFillColor(sf::Color::Transparent);
		object_array[i].setOutlineThickness(4);  //thickness of menu boxes
		object_array[i].setOutlineColor(sf::Color::Black);
		object_array[i].setPosition((70 * i) + 393, 700); //Frame of menu location
	}
}
//----------get from user the size of the Frame and number of stones-----------
void Controller::insert_width_hight_stones(int& width, int& hight, int& stones) const
{
	while (hight < 5 || hight > 10)
	{
		std::cout << "enter num of row (hight) size between 5 to 10" << std::endl;
		std::cin >> hight;
	}

	while (width < 5 || width > 20)
	{
		std::cout << "enter num of column size (width) between 5 to 20" << std::endl;
		std::cin >> width;
	}

	std::cout << "enter num of stones: " << std::endl;
	std::cin >> stones;
}

//-----------------------load the vector from the map-------------------------
void Controller::make_character(std::ifstream& levelfile, int hight, int width)
{
	char chosen;

	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < width; j++)
		{
			levelfile.get(chosen);
			if (chosen != ' ' && chosen != '\n')
				insert_to_vec(chosen, j, i);
		}
		levelfile.get(chosen);
	}
}

//----------insert new character to the vector-----------
void Controller::insert_to_vec(char chosen, int x, int y)
{
	char type = 0;

	if (chosen == '/')
		type = 'P';

	if (chosen == '!')
		type = 'D';

	if (chosen == 'D')
		type = 'C';

	if (chosen == '#')
		type = 'W';

	if (chosen == '@')
		type = 'S';

	sf::Vector2f fixed_location((120 + x * 60) + 4, (60 + y * 60) + 4);

	m_frame.insert(m_window, fixed_location, type);
}

//--main game function--
void Controller::start()
{      
	int width = 0, hight = 0, stones = 0;

	//----------------create graphic window 1400x800------------------
	m_window.create(sf::VideoMode(1400, 800), "Build Board");

	sf::RectangleShape object_array[8];

	//------------Menu buttons------------
	make_rectangles_array(object_array, 8);

	std::ifstream levelfile;

	//-------gets details from file----------
	levelfile.open("Board.txt");
	if (levelfile.is_open())
	{
		char c;
		levelfile >> hight >> width >> stones;
		levelfile.get(c); // for the first newline
		make_character(levelfile, hight, width);
	}
	else
		insert_width_hight_stones(width, hight, stones);  //gets width, hight and stones from user

	sf::Texture frame;
	sf::Sprite table;
	sf::Texture texture;

	auto font = sf::Font();
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");   //load text

	if (!texture.loadFromFile("background.png"))
		std::cout << "Load failed" << std::endl;

	texture.setRepeated(true);   //strech background picture

	if (!frame.loadFromFile("frame.png"))
		std::cout << "error cannot open picture" << std::endl;

	table.setTexture(frame);
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(0, 0, 1400, 800));

	//--------prints text---------
	sf::Text Headline, Menu, Stones;
	Headline.setFont(font);
	Headline.setString("Digger Game Builder");
	Headline.setColor(sf::Color(100, 0, 100, 255));
	Headline.setCharacterSize(40);
	Headline.setPosition(sf::Vector2f(500, 2));
	Headline.setStyle(sf::Text::Bold | sf::Text::Underlined);

	//--------prints text---------
	Menu.setFont(font);
	Menu.setString("Menu");
	Menu.setColor(sf::Color(0, 0, 0, 255));
	Menu.setCharacterSize(70);
	Menu.setPosition(sf::Vector2f(170, 680));
	Menu.setStyle(sf::Text::Bold | sf::Text::Underlined);

	while (m_window.isOpen()) // main window loop
	{
		//-----------print available stones-----------
		std::string stone_string = "stones available: ";
		stone_string += std::to_string(stones);
	
		Stones.setFont(font);
		Stones.setString(stone_string);
		Stones.setColor(sf::Color(100, 100, 0, 255));
		Stones.setCharacterSize(35);
		Stones.setPosition(sf::Vector2f(1020, 705));
		Stones.setStyle(sf::Text::Bold | sf::Text::Underlined);

		m_window.clear();
		m_window.draw(sprite);
		m_window.draw(Headline);
		m_window.draw(Menu);
		m_window.draw(Stones);
		m_menu.draw(m_window, m_frame);

		for (int i = 3; i < width + 3; i++)   //prints the Frame
			for (int j = 1; j < hight + 1; j++)
			{
				table.setPosition((i - 1) * 60, (j) * 60);
				m_window.draw(table);
			}
		for (int i = 0; i < 8; i++)  //draw the bounding Menu rectangles
			m_window.draw(object_array[i]);

		m_frame.draw(m_window); // print vector of characters on table

		sf::Event Event;
		while (m_window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::MouseButtonPressed:
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					int x = Event.mouseButton.x, y = Event.mouseButton.y;
					Color_blue_chosen_object(object_array, x, y);

					if (x > 105 && y > 60 && x < 60 * (width + 2) && y < 60 * (hight + 1)) // if in the Frame limit
					{
						if (check_if_character_was_pressed(object_array)) //check if charcter was pressed
						{
							char character_chosen = which_character(object_array);
							sf::Vector2f fixed_location(60 * (x / 60) + 4, 60 * (y / 60) + 4);
							m_frame.insert(m_window, fixed_location, character_chosen);
						}
						else //delete is pressed
						{
							sf::Vector2f fixed_location(60 * (x / 60) + 4, 60 * (y / 60) + 4);
							m_frame.remove(fixed_location);
						}
					}
					//----------if new button was pressed--------
					if (x > 452 && x < 527 && y > 695 && y < 770)
					{
						m_frame.clear();
						width = 0, hight = 0, stones = 0;
						insert_width_hight_stones(width, hight, stones);
					}
					if (x > 522 && x < 597 && y > 695 && y < 770) // if save pressed
						m_frame.save_to_file(width, hight, stones);
				}
			}
			if (Event.type == sf::Event::Closed)
				m_window.close();
		}
		m_window.display();
	}
}

//-----check which character was chosen if rectangle is blue-----
char Controller::which_character(sf::RectangleShape* object_array) const
{
	char chosen;
	int i;
	for (i = 3; i < 8; i++)
		if (object_array[i].getOutlineColor() == (sf::Color::Blue))
			break;
	switch (i)
	{
	case 3:
		chosen = 'P';
		break;
	case 4:
		chosen = 'D';
		break;
	case 5:
		chosen = 'C';
		break;
	case 6:
		chosen = 'W';
		break;
	case 7:
		chosen = 'S';
		break;
	}
	return chosen;
}

//------------if a button was pushed it draws the bounding rectangle blue-------------- 
void Controller::Color_blue_chosen_object(sf::RectangleShape* object_array, int x, int y) const
{
	int chosen_object = -1;
	if (x > 382 && x < 457 && y > 695 && y < 770)  
		chosen_object = 0; //delete
	if (x > 452 && x < 527 && y > 695 && y < 770)   
		chosen_object = 1; //new
	if (x > 522 && x < 597 && y > 695 && y < 770)   
		chosen_object = 2; //save
	if (x > 595 && x < 670 && y > 695 && y < 770)  
		chosen_object = 3; //digger
	if (x > 660 && x < 735 && y > 695 && y < 770)  
		chosen_object = 4; //demon
	if (x > 732 && x < 807 && y > 695 && y < 770)  
		chosen_object = 5; //diamond
	if (x > 800 && x < 875 && y > 695 && y < 770)  
		chosen_object = 6; //wall
	if (x > 870 && x < 945 && y > 695 && y < 770)   
		chosen_object = 7; //stone

	if (chosen_object != -1)
	{
		if (object_array[chosen_object].getOutlineColor() == (sf::Color::Black))
			object_array[chosen_object].setOutlineColor(sf::Color::Blue);
		else
			object_array[chosen_object].setOutlineColor(sf::Color::Black);

		if (0 <= chosen_object && chosen_object <= 7)
		{
			for (int i = 0; i < 8; i++)
				if (i != chosen_object) //make other rectangles black
					object_array[i].setOutlineColor(sf::Color::Black);
		}
	}
}
//----------check if character was pressed: then we can press on Frame-----------
bool Controller::check_if_character_was_pressed(sf::RectangleShape* object_array) const
{
	int object_counter = 0;
	for (int i = 3; i < 8; i++)
		if (object_array[i].getOutlineColor() == (sf::Color::Blue))
			object_counter++;
	if (object_counter == 1)
		return true;
	else
		return false;
}

Controller::~Controller()
{}
