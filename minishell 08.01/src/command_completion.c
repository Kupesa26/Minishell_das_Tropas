#include "minishell.h"


char **command_completion(const char *text, int start, int end)
{
    (void)start;
    (void)end;
    return rl_completion_matches(text, command_generator);
}

char *command_generator(const char *text, int state)
{
    static int  i;
    static int  len;
    char        *cmd;

    if (!state)
    {
        i = 0;
        len = strlen(text);
    }

    while (commands && (cmd = commands[i++]))
    {
        if (strncmp(cmd, text, len) == 0)
            return strdup(cmd); // Libera responsabilidade de gerenciamento ao readline
    }

    return NULL;
}
