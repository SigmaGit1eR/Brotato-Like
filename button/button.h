#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class button
{
public:
	button(Vector2f size, Color color, string text, RenderWindow& window, Color textColor = Color::White, Vector2f position = Vector2f(0, 0));

	void           draw();
	bool           isMouseFocus();
	bool           isMouseClicked();
	void           setPosition(Vector2f position);
	Vector2f       getPosition() { return m_body.getPosition(); }

private:
	RenderWindow&  m_window;
	RectangleShape m_body;
	Vector2f       m_size;
	Text           m_text;
	string         m_message;
	Font           font;
};