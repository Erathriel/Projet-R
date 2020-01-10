
#include <gf/RenderTarget.h>
#include <gf/Shapes.h>
#include <gf/Unused.h>

#include "../include/Square.h"

Square::Square(gf::Vector2f position,float size, gf::Color4f color)
: m_position(position)
, m_size(size)
, m_color(color)
, m_move(Move::Stop)
{
}

void Square::update(gf::Time time){
	printf("x : %f et y : %f\n",m_position.x,m_position.y );
	float dt = time.asSeconds();
	printf("dt = %f\n", dt );

	switch(m_move){
		case Move::Up:
			if (m_position.y > -300.0f)
			{
				m_position.y -= Velocity * dt;
			}
			break;
		case Move::Down:
			if (m_position.y < 300.0f)
			{
				m_position.y += Velocity * dt;
			}
			break;
		case Move::Right:
			if (m_position.x < 200.0f)
			{
				m_position.x += Velocity * dt;
			}
			break;
		case Move::Left:
			if (m_position.x > -200.0f)
			{
				m_position.x -= Velocity * dt;				
			}
			break;
		case Move::Stop:
			break;
	}
	printf("x : %f et y : %f\n",m_position.x,m_position.y );
}

void Square::render(gf::RenderTarget& target, const gf::RenderStates& states){
	gf::RectangleShape shape({m_size,m_size});
	shape.setPosition(m_position);
	shape.setAnchor(gf::Anchor::Center);
	shape.setColor(m_color);
	target.draw(shape, states);
}