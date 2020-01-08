#include <gf/Clock.h>
#include <gf/Color.h>
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Shapes.h>
#include <gf/Vector.h>
#include <gf/Window.h>
class Square {
public:
  Square(gf::Vector2f position, float size, gf::Color4f color)
  : m_position(position)
  , m_velocity(0, 0)
  , m_size(size)
  , m_color(color)
  {
  }
  void setVelocity(gf::Vector2f velocity) {
    m_velocity = velocity;
  }
  void update(float dt) {
    m_position += dt * m_velocity;
  }
  void render(gf::RenderTarget& target) {
    gf::RectangleShape shape({ m_size, m_size });
    shape.setPosition(m_position);
    shape.setColor(m_color);
    shape.setAnchor(gf::Anchor::Center);
    target.draw(shape);
  }
private:
  gf::Vector2f m_position; // center of the square
  gf::Vector2f m_velocity;
  float m_size;
  gf::Color4f m_color;
};
class Rectangle
{
public:
  Rectangle(gf::Vector2f position,float length,float width, gf::Color4f color)
  : m_position(position)
  , m_velocity(0,0)
  , m_length(length)
  , m_width(width)
  , m_color(color)
  {
  }
  void setVelocity(gf::Vector2f velocity){
    m_velocity = velocity;
  }
  void update(float dt){
    m_position += dt * m_velocity;
  }
  void render(gf::RenderTarget& target){
    gf::RectangleShape shape({m_length,m_width});
    shape.setPosition(m_position);
    shape.setColor(m_color);
    shape.setAnchor(gf::Anchor::Center);
    target.draw(shape);
  }
private:
  gf::Vector2f m_position;
  gf::Vector2f m_velocity;
  float m_length;
  float m_width;
  gf::Color4f m_color;
};
class Circle
{
public:
  Circle(gf::Vector2f position,float radius, float nbPoint, gf::Color4f color)
  : m_position(position)
  , m_velocity(0,0)
  , m_radius(radius)
  , m_nbPoint(nbPoint)
  , m_color(color)
  {
  }
  void setVelocity(gf::Vector2f velocity){
    m_velocity = velocity;
  }
  void update(float dt){
    m_position += dt * m_velocity;
  }
  void render(gf::RenderTarget& target){
    gf::CircleShape shape({m_radius, m_nbPoint});
    shape.setPosition(m_position);
    shape.setColor(m_color);
    shape.setAnchor(gf::Anchor::Center);
    target.draw(shape);
  }
private:
  gf::Vector2f m_position;
  gf::Vector2f m_velocity;
  float m_radius;
  float m_nbPoint;
  gf::Color4f m_color;
};
int main() {
  // initialization
  static constexpr gf::Vector2u ScreenSize(1000, 1000);
  gf::Window window("It moves", ScreenSize);
  gf::RenderWindow renderer(window);
  static constexpr gf::Vector2f EmplacementRectangle(150,150);
  static constexpr gf::Vector2f EmplacementCercle(700,150);
  // entities
  Square square(ScreenSize / 2, 100.0f, gf::Color::Red);
  Rectangle rectangle(EmplacementRectangle, 200.0f, 150.0f, gf::Color::Blue);
  Circle circle(EmplacementCercle, 100.0f, 700.0f, gf::Color::Yellow);
  // game loop
  gf::Clock clock;
  renderer.clear(gf::Color::Black);
  static constexpr float Speed = 300.0f;
  gf::Vector2f velocity(0, 0);
  gf::Vector2f velocity2(0, 0);
  gf::Vector2f velocity3(0,0);
  while (window.isOpen()) {
    // 1. input
    gf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;
      case gf::EventType::KeyPressed:
        switch (event.key.keycode) {
          case gf::Keycode::Up:
              velocity.y -= Speed;
            break;
          case gf::Keycode::Down:
              velocity.y += Speed;
            break;
          case gf::Keycode::Left:
              velocity.x -= Speed;
            break;
          case gf::Keycode::Right:
              velocity.x += Speed;
            break;
          case gf::Keycode::Z:
              velocity2.y -= Speed;
            break;
          case gf::Keycode::S:
              velocity2.y += Speed;
            break;
          case gf::Keycode::Q:
              velocity2.x -= Speed;
            break;
          case gf::Keycode::D:
              velocity2.x += Speed;
            break;
          case gf::Keycode::O:
              velocity3.y -= Speed;
            break;
          case gf::Keycode::L:
              velocity3.y += Speed;
            break;
          case gf::Keycode::K:
              velocity3.x -= Speed;
            break;
          case gf::Keycode::M:
              velocity3.x += Speed;
            break;
          default:
            break;
        }
        break;
      case gf::EventType::KeyReleased:
        switch (event.key.keycode) {
          case gf::Keycode::Up:
              velocity.y += Speed;
            break;
          case gf::Keycode::Down:
              velocity.y -= Speed;
            break;
          case gf::Keycode::Left:
              velocity.x += Speed;
            break;
          case gf::Keycode::Right:
              velocity.x -= Speed;
            break;
          case gf::Keycode::Z:
              velocity2.y += Speed;
            break;
          case gf::Keycode::S:
              velocity2.y -= Speed;
            break;
          case gf::Keycode::Q:
              velocity2.x += Speed;
            break;
          case gf::Keycode::D:
              velocity2.x -= Speed;
            break;
          case gf::Keycode::O:
              velocity3.y += Speed;
            break;
          case gf::Keycode::L:
              velocity3.y -= Speed;
            break;
          case gf::Keycode::K:
              velocity3.x += Speed;
            break;
          case gf::Keycode::M:
              velocity3.x -= Speed;
            break;
          default:
            break;
        }
        break;
      default:
        break;
      }
    }
    // 2. update
    square.setVelocity(velocity);
    rectangle.setVelocity(velocity2);
    circle.setVelocity(velocity3);
    float dt = clock.restart().asSeconds();
    square.update(dt);
    rectangle.update(dt);
    circle.update(dt);
    // 3. draw
    renderer.clear();
    square.render(renderer);
    rectangle.render(renderer);
    circle.render(renderer);
    renderer.display();
    
  }
  return 0;
}