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
int main() {
  // initialization
  static constexpr gf::Vector2u ScreenSize(500, 500);
  gf::Window window("It moves", ScreenSize);
  gf::RenderWindow renderer(window);
  // entities
  Square entity(ScreenSize / 2, 50.0f, gf::Color::Red);
  // game loop
  gf::Clock clock;
  renderer.clear(gf::Color::Black);
  static constexpr float Speed = 100.0f;
  gf::Vector2f velocity(0, 0);
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
          default:
            break;
        }
        break;
      default:
        break;
      }
    }
    // 2. update
    entity.setVelocity(velocity);
    float dt = clock.restart().asSeconds();
    entity.update(dt);
    // 3. draw
    renderer.clear();
    entity.render(renderer);
    renderer.display();
  }
  return 0;
}