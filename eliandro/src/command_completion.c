#include "minishell.h"

// Carrega os comandos do sistema do diretório /bin
char **load_system_commands(void)
{
    struct dirent *entry;
    DIR *dir = opendir("/bin");
    if (!dir)
        return NULL;

    char **cmds = NULL;
    int count = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_type == DT_REG) // Apenas arquivos regulares
        {
            cmds = realloc(cmds, sizeof(char *) * (count + 2));
            cmds[count] = strdup(entry->d_name);
            cmds[count + 1] = NULL;
            count++;
        }
    }
    closedir(dir);
    return cmds;
}

// Libera os comandos carregados
void free_system_commands(void)
{
    if (commands)
    {
        for (int i = 0; commands[i]; i++)
            free(commands[i]);
        free(commands);
    }
}

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
