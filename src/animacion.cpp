#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>      
#include <GestorDibujos.hpp> 
#include <cstdlib>

using namespace ftxui;

int main()
{
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    const std::vector<std::u32string> avion = {
        U"           ______",
        U"           _\ _~-\___",
        U"   =  = ==(____AA____D",
        U"               \_____\___________________,-~~~~~~~`-.._",
        U"               /     o O o o o o O O o o o o o o O o  |\_",
        U"               `~-.__        ___..----..                  )",
        U"                     `---~~\___________/------------`````",
        U"                     =  ===(_________D"
    };

    const std::vector<std::u32string> nube1 = {
        U"   ___ ",
        U" -(   )-",
        U"  (___) "
    };
    
    const std::vector<std::u32string> nube2 = {
        U"  _ ",
        U" ( )",
        U"(_,_)"
    };

    const std::vector<std::u32string> ovni = {
        U"      .-""`""-.    ",
        U"  _/`oOoOoOoOo`\_ ",
        U" '.-=-=-=-=-=-=-.'",
        U"   `-=.=-.-=.=-'"
    };


    GestorDibujos gestor;

    gestor.Agregar(Dibujo(10, 10, avion, ftxui::Color::White));

    gestor.Agregar(Dibujo(30, 5, nube1, ftxui::Color::GrayLight)); 
    gestor.Agregar(Dibujo(50, 8, nube2, ftxui::Color::GrayDark));  
    gestor.Agregar(Dibujo(20, 12, nube2, ftxui::Color::GrayLight)); 
    gestor.Agregar(Dibujo(60, 3, nube1, ftxui::Color::GrayDark));  

    gestor.Agregar(Dibujo(70, 2, ovni, ftxui::Color::Green));



    int frame_counter = 0;
    while (true)
    {
        screen.Clear();
        
        gestor.dibujos[1].x -= 1;
        if (gestor.dibujos[1].x < -10) { 
            gestor.dibujos[1].x = 80;    
        }

        gestor.dibujos[2].x -= 2; 
        if (gestor.dibujos[2].x < -10) {
            gestor.dibujos[2].x = 80;
            gestor.dibujos[2].y = 8 + (rand() % 5); 
        }

        gestor.dibujos[3].x -= 1;
        if (gestor.dibujos[3].x < -10) {
            gestor.dibujos[3].x = 80;
        }
        
        if (frame_counter % 2 == 0) {
             gestor.dibujos[4].x -= 1;
        }
        if (gestor.dibujos[4].x < -10) {
            gestor.dibujos[4].x = 80;
        }

        gestor.dibujos[5].x -= 3;
        if (gestor.dibujos[5].x < -15) {
            gestor.dibujos[5].x = 80;    
            gestor.dibujos[5].y = 1 + (rand() % 3);
        }


        gestor.DibujarTodos(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        
        frame_counter++;
    }

    return 0; 
}