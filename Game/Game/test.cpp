//#include <SFML/Graphics.hpp>
//#include <vector>
//
//int main()
//{
//    sf::RenderWindow window({ 480, 480 }, "Board Game");
//
//    std::vector<sf::Vector2f> board;
//    board.push_back({ 75, 75 });
//    board.push_back({ 150, 50 });
//    board.push_back({ 250, 50 });
//    board.push_back({ 325, 75 });
//    board.push_back({ 350, 150 });
//    board.push_back({ 350, 250 });
//    board.push_back({ 325, 325 });
//    board.push_back({ 250, 350 });
//    board.push_back({ 150, 350 });
//    board.push_back({ 75, 325 });
//    board.push_back({ 50, 250 });
//    board.push_back({ 50, 150 });
//
//    sf::CircleShape field(25, 24);
//    field.setFillColor(sf::Color::White);
//    field.setOutlineColor(sf::Color::Black);
//    field.setOutlineThickness(2);
//    field.setOrigin({ 25, 25 });
//
//    sf::CircleShape player(20, 3);
//    player.setFillColor(sf::Color::Red);
//    player.setOutlineColor(sf::Color::Black);
//    player.setOutlineThickness(2);
//    player.setOrigin({ 20, 20 });
//
//    float playerPos = 0.f;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            switch (event.type) {
//            case sf::Event::Closed:
//                window.close();
//                break;
//            default:
//                break;
//            }
//        }
//        window.clear({ 0, 127, 127 });
//        for (auto& pos : board) {
//            field.setPosition(pos);
//            window.draw(field);
//        }
//
//        const sf::Vector2f playerPosLast = board[static_cast<std::size_t>(playerPos)];
//        const sf::Vector2f playerPosNext = board[static_cast<std::size_t>(playerPos + 1) % board.size()];
//        const float step = playerPos - static_cast<std::size_t>(playerPos);
//
//        const sf::Vector2f jumpOffset(0, 25.f * (2.f * (step - .5)) * (2.f * (step - .5)) - 25.f);
//        player.setPosition(playerPosLast + (playerPosNext - playerPosLast) * step + jumpOffset);
//        window.draw(player);
//
//        window.display();
//
//        if ((playerPos += .001f) > board.size())
//            playerPos -= board.size();
//    }
//}