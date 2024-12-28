#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <SFML/Graphics/RenderWindow.h>
#include "../include/my.h"

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            my_putstr("CREDIT : Jawed Lahrouri\n");
            my_putstr("commande: esc = close the game\n");
            return 0;
        }
    }
    return 84;
}