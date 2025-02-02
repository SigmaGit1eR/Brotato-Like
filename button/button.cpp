#include "button.h"
void button::draw()
{
	m_window.draw(m_body);
	m_window.draw(m_text);
}
bool button::isMouseFocus()
{
	bool isFocused = false;
	if (Mouse::getPosition(m_window).x >= m_body.getPosition().x and Mouse::getPosition(m_window).x <= m_body.getPosition().x + m_size.x)
	{
		if (Mouse::getPosition(m_window).y >= m_body.getPosition().y and Mouse::getPosition(m_window).y <= m_body.getPosition().y + m_size.y)
		{
			isFocused = true;
		}
	}
	else
	{
		isFocused = false;
	}
	return isFocused;
}
bool button::isMouseClicked()
{
	return (isMouseFocus() and Mouse::isButtonPressed(Mouse::Left));
}
void button::setPosition(Vector2f position)
{
	m_body.setPosition(position);
	m_text.setPosition(m_body.getPosition().x + m_size.x / 2.0f, m_body.getPosition().y + m_size.y / 2.0f);
}
button::button(Vector2f size, Color color, string text, RenderWindow& window, Color textColor, Vector2f position) : m_size(size), m_body(size), m_window(window),
m_message(text)
{
	m_body.setPosition(position);
	m_body.setFillColor(color);
	font;
	font.loadFromFile("font.ttf");
	m_text.setFont(font);
	m_text.setCharacterSize(size.y / 3);
	m_text.setFillColor(textColor);
	m_text.setString(text);
	FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_text.setPosition(m_body.getPosition().x + m_size.x / 2.0f, m_body.getPosition().y + m_size.y / 2.0f);
}