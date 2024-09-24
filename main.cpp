#include <vector>

#include "SFML/Graphics.hpp"
#include "../src/sysrect.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAIL 1

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(1000, 800),
        "Shapes");
    window.setFramerateLimit(60); // Set the framerate limit to 60 FPS
    sf::Event e;

    Canvas canvas(30, 30);
    sf::View view(sf::FloatRect(0, 0, canvas.width, canvas.height));
    SysRectFactory rectFactory;

    std::vector<SysRect> rectangles = {
        rectFactory.CreateRect(15, 6, 4, 5),
        rectFactory.CreateRect(8, 6, 6, 4),
        rectFactory.CreateRect(0, 9, 5, 21),
        rectFactory.CreateRect(15, 24, 9, 6),
        rectFactory.CreateRect(22, 13, 8, 6),
        rectFactory.CreateRect(10, 0, 10, 6),
        rectFactory.CreateRect(24, 19, 6, 11),
        rectFactory.CreateRect(15, 11, 7, 12),
        rectFactory.CreateRect(0, 0, 8, 9),
        rectFactory.CreateRect(20, 0, 10, 11),
        rectFactory.CreateRect(5, 10, 10, 20)
    };


    window.setView(view);

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        rectFactory.DrawAllRects(window, rectangles);
        window.display();
    }

    return 0;
}