#include "../include/Square.h"

#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Unused.h>

Square::Square(gf::Vector2f position, float size, gf::Color4f color)
: m_position(position)
, m_size(size)
, m_color(color)
, m_move(Move::Stop)
{
}

void Square::update(gf::Time time){
	float dt = time.asSeconds();

	switch(m_move){
		case Move::Up:
			m_position.y -= Velocity * dt;
			break;
		case Move::Down:
			m_position.y += Velocity * dt;
			break;
		case Move::Right:
			m_position.x += Velocity * dt;
			break;
		case Move::Left:
			m_position -= Velocity * dt;
			break;
		case Move::Stop:
			break;
	}
}

void Square::render(gf::RenderTarget& target, const gf::RenderStates& states){
	gf::RectangleShape shape({m_size,m_size});
	shape.setPosition(m_position);
	shape.setAnchor(gf::Anchor::Center);
	shape.setColor(m_color);
	target.draw(target, states);
}