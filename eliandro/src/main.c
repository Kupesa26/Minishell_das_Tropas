#include "minishell.h"

// Definição da variável global
char **commands = NULL;

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    // Inicializar os comandos do sistema
    commands = load_system_commands();
    if (!commands)
    {
        fprintf(stderr, "Failed to load system commands.\n");
        return 1;
    }

    // Iniciar o loop do minishell
    minishell_loop();

    // Liberar os comandos antes de sair
    free_system_commands();

    return 0;
}
