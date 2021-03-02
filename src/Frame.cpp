#include "Frame.h"

Frame::Frame()
{}

//-----delete all the objects in the vector-----
void Frame::clear()
{
	int origion_size = m_frame_shape.size();
	for (int i = 0; i < origion_size; i++)
	{
		m_frame_shape.erase(m_frame_shape.begin());
	}
}

//-----------------deletes one object--------------
void Frame::remove(sf::Vector2f location)
{
	for (int i = 0; i < m_frame_shape.size(); i++)
		if (location == m_frame_shape[i]->get_m_position())
		{
			m_frame_shape.erase(m_frame_shape.begin() + i);
		}
}

//--------------------------inserts an new charcter to the vector----------------------
void Frame::insert(sf::RenderWindow& window, sf::Vector2f location, char object_chosen) 
{
	bool exist = false;
	//----check if the location already exists-----
	for (int i = 0; i < m_frame_shape.size(); i++)
		if (m_frame_shape[i]->get_m_position().x == location.x
			&& m_frame_shape[i]->get_m_position().y == location.y)
			exist = true;
	if (!exist)
	{
		bool find = false;
		switch (object_chosen) // all the options of object
		{
		case 'P':   //digger player
			for (int i = 0; i < m_frame_shape.size(); i++)
				if (m_frame_shape[i]->get_m_type() == '/')
				{
					m_frame_shape[i] = (std::make_unique<Digger>(window, location));
					find = true;
				}
			if (!find)
				m_frame_shape.push_back(std::make_unique<Digger>(window, location));
			break;

		case 'D':  //Demon
			m_frame_shape.push_back(std::make_unique<Demon>(window, location));
			break;
		case 'C':  //Diamond
			m_frame_shape.push_back(std::make_unique<Diamond>(window, location));
			break;
		case 'W':  //Wall
			m_frame_shape.push_back(std::make_unique<Wall>(window, location));
			break;
		case 'S':  //Stone
			m_frame_shape.push_back(std::make_unique<Stone>(window, location));
			break;
		}
	}
}

//-------------draw all the objects---------------
void Frame::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_frame_shape.size(); i++)
		m_frame_shape[i]->draw();
}

//-----save all objects to vector to print in file------
void Frame::save_to_file(int width, int hight, int stones) const
{
	std::vector<std::vector<char>> map;
	map.assign(hight, std::vector<char>(width, ' '));

	int x = 0, y = 0; 
	int lines, columns;

	for (int i = 0; i < m_frame_shape.size(); i++)
	{
		char type = m_frame_shape[i]->get_m_type();
		columns = m_frame_shape[i]->get_m_position().x;
		lines = m_frame_shape[i]->get_m_position().y;

		x = (60 * (columns / 60) - 120) / 60,
			y = (60 * (lines / 60) - 60) / 60;

		map[y][x] = type;
	}
	if (m_frame_shape.size() != 0)
		write_to_file(map, x, y, stones);
}

//--------------------write saved vector objects to the file--------------------------
void Frame::write_to_file(std::vector<std::vector<char>> map, int x, int y, int stones) const
{
	std::ofstream levelfile;

	levelfile.open("Board.txt");
	if (!levelfile.is_open())
		std::cout << "cannot open file" << std::endl;

	levelfile << map.size() << " " << map[0].size() << " " << stones << std::endl;

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			levelfile << map[i][j];
		}
		levelfile << std::endl;
	}

	levelfile.close();
}

Frame::~Frame()
{}